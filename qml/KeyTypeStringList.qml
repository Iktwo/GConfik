import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: keyTypeStringListPage

    tools: insideEntryTools

    function setFullKeyPath(path){
        fullKeyPath.text = path;
    }

    /*function restoreValue(){
        value.text=storedValue.text;
    }*/

    Label{
        id: fullKeyPath;
        opacity: 0;
    }

    InfoBanner{
        id: infoBanner
        timerEnabled: true
        timerShowTime: 3500
        z: 1
        topMargin: 72+10+separator.height
    }

    ToolBarLayout {
        id: insideEntryTools
        visible: true

        ToolIcon {
            id: btnBack;
            platformIconId: "toolbar-back"
            anchors.left: (parent === undefined) ? undefined : parent.left
            onClicked: {
                pageStack.pop();
                keyMenu.close();
            }
        }

        ToolIcon {
            id: btnAdd;
            platformIconId: "toolbar-add"
            x: (parent.width/2) - (btnSave.width/2)
            onClicked: {
                wMain.addValueToList();
                infoBanner.text="Added";
                infoBanner.show();
            }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: {
                infoBanner.hide();
                (keyMenu.status == DialogStatus.Closed) ? keyMenu.open() : keyMenu.close()
            }
        }
    }

    Menu {
        id: keyMenu
        visualParent: pageStack
        MenuLayout {

            MenuItem {
                text: qsTr("Set")
                onClicked: {
                    wMain.setListKeys(fullKeyPath.text);
                    infoBanner.text="Set key "+keyName;
                    infoBanner.show();
                }
            }

            MenuItem {
                text: qsTr("Unset")
                onClicked: {
                    wMain.unsetKey(fullKeyPath.text);
                    wMain.getStringListKey(fullKeyPath.text);
                    infoBanner.text="Unset key "+keyName;
                    infoBanner.show();
                }
            }

            MenuItem {
                text: qsTr("About")
                onClicked: {
                    myDialog.open();
                }
            }
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
        id: separator
        color: "black"
        width: parent.width
        height: lblKey.height+lblKeyName.height + 10 + 10 + 10
        y: tittleBar.height
        z: 2

        Label{
            id: lblKey;
            text: "Key:"
            //y: tittleBar.height + 10;
            y: 10
            x: 5
        }

        Flickable{
            id: flickKeyName
            contentHeight: lblKeyName.height
            contentWidth: lblKeyName.width
            width: keyTypeStringPage.width+5
            height: separator.height

            Label{
                id: lblKeyName;
                y: lblKey.y + lblKey.height + 10;
                x: 5
                text: keyName
                font.pixelSize: 30;
                wrapMode: Text.WrapAnywhere
            }
        }

        ScrollDecorator {
            flickableItem: flickKeyName
        }
    }


    ListView {
        id: listview
        cacheBuffer: 100;
        //y: savedContainer.y+savedContainer.height
        y: separator.height+separator.y

        //height: mainPage.height-72-savedContainer.height;

        height: keyTypeStringListPage.height-tittleBar.height-separator.height-insideEntryTools.height

        //anchors.top: separator.bottom
        //anchors.bottom: insideEntryTools.top

        width: mainPage.width
        model: listKeys

        delegate: ListDelegate{

            TextField {
                id: txtValue;
                text: value
                font.pixelSize: 30
                anchors.verticalCenter: parent.verticalCenter
                x: 5
                width: parent.width - 5 - btnRemove.width
                onTextChanged: {
                    wMain.modifyContentOfList(txtValue.text,index);
                }
            }

            Image {
                id: btnRemove
                width: 56
                height: parent.height
                anchors.right: parent.right;
                source: "qrc:/images/remove.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        wMain.removeValueFromList(index);
                        infoBanner.text="Removed";
                        infoBanner.show();
                    }
                }
            }

            /*Label {
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
            }*/

            /*Label{
                id: entryType
                text: type
                //opacity: 0
            }*/
        }
    }


    /*Label{
        id: lblValue;
        text: "Value:"
        y: lblKeyName.y + lblKeyName.height + 10;
        x: 5
    }

    TextField{
        id: value;
        text: stringValue
        y: lblValue.y + lblValue.height + 10;
        x: 5;
        width: parent.width-10
    }

    TextField{
        id: storedValue;
        text: stringValue
        opacity: 0
    }*/
}
