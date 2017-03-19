import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page
    Button {
        text: "Browse"
        onClicked: {
            var component = Qt.createComponent("DirectoryContent.qml");
            if (component.status === Component.Ready) {
                browser.path = browser.getHome();
                var newPage = component.createObject(page, {"pagePath": browser.path});
                pageStack.push(newPage);
            }
        }
    }
}


