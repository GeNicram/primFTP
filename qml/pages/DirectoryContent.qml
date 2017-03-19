import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    property string pagePath: ""

    SilicaListView {
        id: fileList
        anchors.fill: parent
        width: parent.width
        model: browser.getCurrentContent()
        spacing: Theme.paddingLarge
        header: PageHeader { title: pagePath }
        delegate: BackgroundItem {
            width: parent.width
            Label {
                text: modelData
                color: highlighted ? Theme.highlightColor : Theme.primaryColor
                anchors.verticalCenter: parent.verticalCenter
                x: Theme.horizontalPageMargin
            }
            onClicked: {
                var component = Qt.createComponent("DirectoryContent.qml");
                if (component.status === Component.Ready) {
                    browser.path = pagePath + "/" + modelData;
                    var newPage = component.createObject(page, {"pagePath": browser.path});
                    pageStack.push(newPage)
                }
            }
        }
        VerticalScrollDecorator {}
    }
}
