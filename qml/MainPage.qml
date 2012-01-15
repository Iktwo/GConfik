import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: mainPage

    tools: insideDirectoryTools

    ToolBarLayout {
        id: insideDirectoryTools
        visible: true

        ToolIcon {
            id: btnBack;
            platformIconId: "toolbar-up"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                wMain.leaveDirectory(currentDirectoryFullPath.text);
            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status == DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    TittleBar{
        id: tittleBar;
        tittle: "GConfik";
        author: "By Iktwo";
        color: "green";
        //tittleLink: "http://store.ovi.mobi/content/213823";
        authorLink: "http://store.ovi.mobi/publisher/Iktwo/";
        z: 1;
    }

    Rectangle{
        id: savedContainer;
        color: "#222222"
        x: 0
        y: 72
        width: parent.width
        height: lblSaved.height;
        Label {
            id: lblSaved;
            text: wMain.shortname(actualDir);
            font.pixelSize: 40
        }
        z:1;

        MouseArea{
            anchors.fill: parent
            onClicked: {
                bannerFullPath.show();
            }
        }
    }

    InfoBanner{
        id: bannerFullPath
        text: actualDir
        timerEnabled: true
        timerShowTime: 3500
        z: 1
        topMargin: 90+10
        //height: 100;
    }

    Label{
        id: currentDirectoryFullPath
        opacity: 0;
    }

    ListView {
        id: listview
        y: savedContainer.y+savedContainer.height
        height: mainPage.height-72-savedContainer.height;
        width: mainPage.width
        model: gconfKeysModel

        delegate: ListDelegate{

            Label {
                id: lblName;
                text: wMain.shortname(name);
                font.pixelSize: 30
                anchors.verticalCenter: parent.verticalCenter
                onTextChanged: {
                    currentDirectoryFullPath.text=wMain.parentDir(name);
                }
            }

            Image {
                id: iconDir
                source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            Image {
                id: iconEntry
                source: "image://theme/icon-m-common-search" + (theme.inverted ? "-inverse" : "")
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                id: lblIsEntry
                text: isEntry
                opacity: 0;
                onTextChanged: {
                    if (text=="true"){
                        iconDir.visible=false;
                        iconEntry.visible=true;
                    }else{
                        iconDir.visible=true;
                        iconEntry.visible=false;
                    }
                }
            }

            Label{
                id: entryType
                text: type
                //opacity: 0
            }

            onClicked: {
                if (lblIsEntry.text=="false"){
                    wMain.enterDirectory(name);
                }else{
                    if (entryType.text=="Bool"){

                        wMain.getBoolKey(name);

                        keyTypeBool.setFullKeyPath(name);
                        keyTypeBool.restoreValue();

                        pageStack.push(keyTypeBool)

                    }else if (entryType.text=="String"){

                        wMain.getStringKey(name);

                        keyTypeString.setFullKeyPath(name);
                        keyTypeString.restoreValue();

                        pageStack.push(keyTypeString)

                    }else if (entryType.text=="StringList"){

                        wMain.getStringListKey(name);

                        keyTypeStringList.setFullKeyPath(name);
                        //keyTypeStringList.restoreValue();

                        pageStack.push(keyTypeStringList)

                    }else if (entryType.text=="Int"){

                        wMain.getIntKey(name);

                        keyTypeInt.setFullKeyPath(name);
                        keyTypeInt.restoreValue();

                        pageStack.push(keyTypeInt)

                    }else if (entryType.text=="Double"){

                        wMain.getDoubleKey(name);

                        keyTypeDouble.setFullKeyPath(name);
                        keyTypeDouble.restoreValue();

                        pageStack.push(keyTypeDouble)
                    }
                }
            }
        }
    }

    ScrollDecorator {
        flickableItem: listview
    }

    KeyTypeBool{
        id: keyTypeBool;
        anchors.fill: parent;
    }

    KeyTypeString{
        id: keyTypeString;
        anchors.fill: parent;
    }

    KeyTypeStringList{
        id: keyTypeStringList;
        anchors.fill: parent;
    }

    KeyTypeInt{
        id: keyTypeInt;
        anchors.fill: parent;
    }

    KeyTypeDouble{
        id: keyTypeDouble;
        anchors.fill: parent;
    }
}
