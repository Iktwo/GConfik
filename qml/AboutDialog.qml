import QtQuick 1.0
import com.nokia.meego 1.0

QueryDialog {
    id: aboutDialog

    titleText: "GConfik by Iktwo " + "1.1.0"
    icon: "qrc:/images/iktwo.png"
    message: qsTr("GConf Editor. View, set or unset all your system's gconf keys, when a key is unset the default value is restored but remember to be careful when changing key values. StringList is supported <br><br> &copy; Iktwo 2011<br><br>Bugs/Comments <br> Contact me <br><br> <a href=\"mailto:elmaildeliktwo@gmail.com\"> Email:</a> elmaildeliktwo@gmail.com <br><br> Twitter: @iktwo")
}
