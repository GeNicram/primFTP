#include "storage.h"

#include <QVector>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

Storage::Storage(QObject *parent) : QObject(parent)
{

}

int Storage::WriteRecord(int id, const QString name, const QString address,
    const QString path, const QString user, const QString password) {
    FtpRecord record;

    record.id = id;
    record.name = name;
    record.address = address;
    record.path = path;
    record.user = user;
    record.password = password;

    records_.append(record);

    return id;
}

void Storage::ReadRecord(int id, QString& name, QString& address, QString& path,
    QString& user, QString& password) const {

}

void Storage::LoadFromFile(QString path) {
    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    records_.clear();

    QByteArray data = loadFile.readAll();

    QJsonDocument loadedJSON(QJsonDocument::fromJson(data));

    QJsonArray ftpRecords = loadedJSON.object()["storedFtp"].toArray();
    for (int i = 0; i < ftpRecords.size(); ++i) {
        FtpRecord new_record;

        QJsonObject record = ftpRecords[i].toObject();
        new_record.id = record["is"].toInt();
        new_record.name = record["name"].toString();
        new_record.address = record["address"].toString();
        new_record.path = record["path"].toString();
        new_record.user = record["user"].toString();
        new_record.password = record["password"].toString();

        records_.append(new_record);
    }
}

void Storage::SaveToFile(const QString path) {
    QFile saveFile(path);

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return;
    }

    QJsonArray records;
    foreach (const FtpRecord row, records_) {
        QJsonObject record;

        record["is"] = row.id;
        record["name"] = row.name;
        record["address"] = row.address;
        record["path"] = row.path;
        record["user"] = row.user;
        record["password"] = row.password;

        records.append(record);
    }

    QJsonObject storage;
    storage["storedFtp"] = records;

    QJsonDocument saveJSON(storage);
    saveFile.write(saveJSON.toJson());

    return;
}
