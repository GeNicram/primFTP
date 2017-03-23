#include <QtQuick>
#include <sailfishapp.h>

#include "browser.h"
#include "storage.h"

#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    Storage storage;
    storage.LoadFromFile("dupa.json");

    Browser browser;
    QQmlContext* ctx = view->rootContext();
    browser.setQmlContext(ctx);
    browser.updateList("fileList");

    ctx->setContextProperty("storage", &storage);
    ctx->setContextProperty("browser", &browser);

    //view->engine()->addImportPath("qrc:/qml/");
    view->setSource(QUrl(SailfishApp::pathTo("qml/primFTP.qml")));
    view->showFullScreen();

    return app->exec();
}

