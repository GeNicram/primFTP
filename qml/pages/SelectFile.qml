import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    SilicaListView {
        id: listView
        anchors.fill: parent
        model: fileList
        header: PageHeader { title: browser.path }
        section {
            property: 'section'
            delegate: SectionHeader {
                text: section
            }
        }
        delegate: BackgroundItem {
            width: listView.width
            Label {
                id: firstName
                text: modelData
                color: highlighted ? Theme.highlightColor : Theme.primaryColor
                anchors.verticalCenter: parent.verticalCenter
                x: Theme.paddingLarge
            }
            onClicked: pageStack.push(deeperDir)
        }
        VerticalScrollDecorator {}
    }

    Component {
        id: deeperDir
        Page {
            Column {
                id: column
                width: parent.width
                spacing: Theme.paddingLarge

                PageHeader { title: browser.path }

                Button {
                    text: 'Push'
                    anchors.horizontalCenter: parent.horizontalCenter
                    onClicked: pageStack.push(deeperDir)
                }
                Button {
                    text: 'Pop'
                    anchors.horizontalCenter: parent.horizontalCenter
                    onClicked: pageStack.pop(undefined)
                }
            }
        }
    } // deeperDir
}


