import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: keyTypeBoolPage

    function setFullKeyPath(path){
        fullKeyPath.text = path;
    }

    function restoreValue(){
        value.checked=storedValue.checked;
    }

    Label{
        id: fullKeyPath;
        opacity: 0;
    }

    InfoBanner{
        id: infoBanner
        timerEnabled: true
        timerShowTime: 3500
        z: 1
        topMargin: 90+10
    }

    tools: insideEntryTools

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
                    wMain.setKey(fullKeyPath.text,value.checked);
                    infoBanner.text="Set key "+keyName;
                    infoBanner.show();
                }
            }

            MenuItem {
                text: qsTr("Unset")
                onClicked: {
                    wMain.unsetKey(fullKeyPath.text);
                    wMain.getBoolKey(fullKeyPath.text);
                    restoreValue();
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

    Label{
        id: lblKey;
        text: "Key:"
        y: tittleBar.height + 10;
        x: 5
    }

    Flickable{
        id: flickKeyName
        contentHeight: lblKeyName.height
        contentWidth: lblKeyName.width+5
        width: keyTypeBoolPage.width
        height: 200

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

    Label{
        id: lblValue;
        text: "Value:"
        anchors.verticalCenter: value.verticalCenter
        x: 5
    }

    Switch{
        id: value;
        y: lblKeyName.y + lblKeyName.height + 10;
        x: lblValue.width + 15;
        checked: boolValue;
        platformStyle: SwitchStyle {
            switchOn: "image://theme/color2-meegotouch-switch-on"
        }
    }

    Switch{
        id: storedValue;
        opacity: 0;
        checked: boolValue;
    }
}
