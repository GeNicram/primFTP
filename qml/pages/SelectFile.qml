import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: page

    SilicaListView {
        id: listView
        anchors.fill: parent
        model: fileList
        header: PageHeader { title: "Select file" }
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
            onClicked: pageStack.push(Qt.resolvedUrl(page))
        }
        VerticalScrollDecorator {}
    }
}


