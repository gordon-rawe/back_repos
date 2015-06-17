// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root
    property double l:30
    property double alpha:45.0

    property double rule: 290/40

    function generateRandomPosition(){
        root.l = 40*Math.random();
        root.alpha = Math.random()*360;
    }

    Timer {
        interval:400
        running:true
        onTriggered: root.generateRandomPosition()
        repeat: true
    }

    Image {
        id: bg
        source: "./radarbg.png"
        width: 776
        height: 776
        Repeater {
            id:numRules
            model:4
            Text {
                text: 250*(index+1)
                font.pixelSize: 25
                color:"lightgreen"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: 73*(index+1)
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Repeater {
            id: circleRules
            model: 24
            Text {
                x:{if(index!=0) 365;else 380}
                y:10
                id:te
                font.pixelSize: 30
                text: index*15
                color:"lightgray"
                transform: Rotation {
                    id:circleRotation
                    origin.x:te.width/2
                    origin.y:380
                    angle: index* 15
                }
            }
        }
    }

    Image {
        id:dot

        anchors.horizontalCenter: bg.horizontalCenter
        anchors.verticalCenter: bg.verticalCenter
        anchors.verticalCenterOffset: 2+Math.cos((alpha+90)*Math.PI/180)*l*rule
        anchors.horizontalCenterOffset: 1+l*Math.sin((alpha+90)*Math.PI/180)*rule
        source: "dot.png"
    }

    Image {
        id: mask
        x:380
        y:100
        source: "./mask.png"
        transform: Rotation{
            id:maskRotate
            origin.x:10
            origin.y:290
            angle: 360
        }
        Timer{
            interval: 10
            repeat: true
            running: true
            onTriggered: {
                maskRotate.angle -= 1;
                if(maskRotate.angle<0)  maskRotate.angle=360;
            }
        }
    }


}
