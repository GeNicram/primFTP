#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QVector>
#include <QJsonObject>
#include <QStringList>

#include "ftprecord.h"

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = 0);
    int WriteRecord(int id, const QString name, const QString address, const QString path, const QString user, const QString password);
    void ReadRecord(int id, QString& name, QString& address, QString& path, QString& user, QString& password) const;

    Q_INVOKABLE QStringList GetRecords();

    void LoadFromFile(QString path);
    void SaveToFile(const QString path);
    void ClearStorage(const QString path);

signals:

public slots:

private:
    QVector<FtpRecord> records_;
};

#endif // STORAGE_H
