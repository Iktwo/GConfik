import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.0

Page {
    id: keyTypeDoublePage

    tools: insideEntryTools

    function setFullKeyPath(path){
        fullKeyPath.text = path;
    }

    function restoreValue(){
        value.text=storedValue.text;
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
                    wMain.setKey(fullKeyPath.text,value.text);
infoBanner.text="Set key "+keyName;
                    infoBanner.show();
                }
            }

            MenuItem {
                text: qsTr("Unset")
                onClicked: {
                    wMain.unsetKey(fullKeyPath.text);
                    wMain.getDoubleKey(fullKeyPath.text);
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
        width: keyTypeDoublePage.width
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
        y: lblKeyName.y + lblKeyName.height + 10;
        x: 5
    }

    TextField{
        id: value;
        text: doubleValue
        y: lblValue.y + lblValue.height + 10;
        x: 5;
        width: parent.width-10
        inputMethodHints: Qt.ImhFormattedNumbersOnly | Qt.ImhNoPredictiveText
    }

    TextField{
        id: storedValue;
        text: doubleValue
        opacity: 0
    }

}
