// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import "radar"

Rectangle {
    id:container
    width: 500
    height: 500
    color: "#67a8c1"
    Radar{
        scale:0.5
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.top: parent.top
        anchors.topMargin: 50
    }
}
