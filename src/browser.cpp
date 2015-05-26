#include "browser.h"

#include <QDir>

void Browser::setPath(QString path) {
    QDir dir(act_dir_);

    if(!dir.cd(path)) {
        qDebug("bad link");
        return;
    }

    act_dir_ = dir;
}

void Browser::push(QString ndir) {
    QDir dir(act_dir_);

    if(!dir.cd(ndir)) {
        qDebug("can't enter");
        return;
    }

    act_dir_ = dir;
}

void Browser::pop() {
    push("..");
}

void Browser::updateList() {
    qDebug(QString("Act path: ").arg(act_dir_.absolutePath()).toLatin1());
    act_dir_.setFilter(QDir::Dirs | QDir::Files | QDir::NoSymLinks | QDir::NoDot);
    act_dir_.setSorting(QDir::DirsFirst);

    QFileInfoList list = act_dir_.entryInfoList();

    file_list_.clear();
    for (auto& file : list) {
        file_list_.append(file.fileName());
    }

    qDebug("update list");
    qDebug(act_dir_.absolutePath().toLatin1());

    ctx_->setContextProperty("fileList", QVariant::fromValue(file_list_));
}

QString Browser::getDirContent() {
    act_dir_.setFilter(QDir::Dirs | QDir::NoSymLinks);
    act_dir_.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = act_dir_.entryInfoList();

    QString result;
    for (auto& file : list) {
        result += qPrintable(QString("%1 %2\n").arg(file.size(), 10)
                                             .arg(file.fileName()));
    }

    return result;
}
