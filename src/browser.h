#ifndef BROWSER_H
#define BROWSER_H

#include <QDir>
#include <QObject>
#include <QQmlContext>
#include <QStringList>

class Browser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString files READ files)
public:
    explicit Browser(QObject *parent = 0) :
        act_dir_(QDir::home())
    {}

    Q_INVOKABLE QString getHome() {
        return QDir::home().absolutePath();
    }

    QString files() {
        return getDirContent();
    }

    void setPath(QString path);

    QString path() {
        return act_dir_.absolutePath();
    }

    Q_INVOKABLE QStringList getCurrentContent();

    Q_INVOKABLE void updateList(QString containter_id);
    void setQmlContext(QQmlContext* ctx) {
        ctx_ = ctx;
    }

    //! Try to enter to deeper dir
    Q_INVOKABLE void push(QString ndir);
    //! Leave last enterned dir
    void pop();

signals:
    void pathChanged();

private:
    QString getDirContent();
    QString files_;

    QDir act_dir_;
    QQmlContext* ctx_;
};

#endif // BROWSER_H
