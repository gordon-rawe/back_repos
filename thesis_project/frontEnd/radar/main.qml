// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "radar"

Rectangle {
    id:container
    width: 640
    height: 480
    color: "#67a8c1"
    Radar{
        scale:0.4
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 150
    }
}
