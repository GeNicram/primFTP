#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

#include "browser.h"

#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    Browser browser;
    QQmlContext* ctx = view->rootContext();
    browser.setQmlContext(ctx);
    browser.updateList();

    ctx->setContextProperty("browser", &browser);

    //view->engine()->addImportPath("qrc:/qml/");
    view->setSource(QUrl(SailfishApp::pathTo("qml/primFTP.qml")));
    view->showFullScreen();

    return app->exec();
}

