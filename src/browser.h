#ifndef BROWSER_H
#define BROWSER_H

#include <QDir>
#include <QObject>
#include <QQmlContext>

class Browser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString files READ files)
public:
    explicit Browser(QObject *parent = 0) :
        act_dir_(QDir::home())
    {}

    QString files() {
        return getDirContent();
    }

    void setPath(QString path);

    QString path() {
        return path_;
    }

    Q_INVOKABLE void updateList();
    void setQmlContext(QQmlContext* ctx) {
        ctx_ = ctx;
    }


signals:
    void pathChanged();

private:
    QString getDirContent();
    QString files_;
    QString path_;

    QDir act_dir_;
    QStringList file_list_;
    QQmlContext* ctx_;
};

#endif // BROWSER_H
