// import QtQimagesck 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1 as Desk
import QtWebKit 1.0

Rectangle {
    property string name: ""
    property string safeLevel: "Safe"
    property int speed: 0
    property int direction: 0
    property double latitude: 0.0
    property double longitude: 0.0
    property int neighbourCount: 10
    property double nearestDistance:101.10
    property int zigbeeSignal: 0
    property int gpsSignal: 0
    property int nanoTrackSignal: 0
    property int safe: 100

    Component.onCompleted: {
        //update();
    }


    //辅助参数
    property int spinerAngle: 0
    property string runningStatus: "Ready..."
    property string toggleText: "Start"


    id:root
    width: 800
    height: 480

    Image {
        id: background
        source: "images/background.png"
    }

    Item{
        id:main
        opacity: 1
        Image {
            id: staticElements
            source: "images/staticElements.png"
        }

        Image {
            id: safePointer
            x:273
            y:170
            smooth: true
            source: "images/safety_pointer.png"
            transform: Rotation {
                origin.x: 24
                origin.y: 81
                angle: direction*2
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.4
                        damping: .15
                    }
                }
            }
        }

        Image {
            id: speedPointer
            x:93
            y:56
            smooth: true
            source: "images/speed_pointer.png"
            transform: Rotation {
                origin.x: 14
                origin.y: 44.5
                angle: speed
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.4
                        damping: .15
                    }
                }
            }
        }

        Image {
            id: directionPointer
            x:465
            y:56
            smooth: true
            source: "images/compass_pointer.png"
            transform: Rotation {
                origin.x: 14
                origin.y: 44.5
                angle: direction
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.4
                        damping: .15
                    }
                }
            }
        }

        Image {
            id: zigbeeSignalPointer
            source: "images/triangle.png"
            x:605+150*zigbeeSignal/100//755//605
            y:72
            Behavior on x {
                SpringAnimation {
                    spring: 1.4
                    damping: .15
                }
            }
        }

        Image {
            id: gpsSignalPointer
            source: "images/triangle.png"

            x:605+150*gpsSignal/100//755//605
            y:119
            Behavior on x {
                SpringAnimation {
                    spring: 1.4
                    damping: .15
                }
            }
        }

        Image {
            id: nanoSignalPointer
            source: "images/triangle.png"

            x:605+150*nanoTrackSignal/100//755//605
            y:165
            Behavior on x {
                SpringAnimation {
                    spring: 1.4
                    damping: .15
                }
            }
        }

        Text {
            id: speedText
            x:205;y:74
            color:"#11be5a"
            font.pixelSize: 16
            text: qsTr(speed + "m/s")
        }

        Text {
            id: directionText
            x:350;y:74
            color:"#11be5a"
            font.pixelSize: 16
            text: qsTr(direction + "°")
        }

        Text {
            id: lonogitudeText
            x:470;y:390
            color:"#11be5a"
            font.pixelSize: 25
            text: qsTr(longitude + "°")
        }

        Text {
            id: latitudeText
            x:100;y:390
            color:"#11be5a"
            font.pixelSize: 25
            text: qsTr(latitude + "°")
        }

        Text {
            id: neighbourCountText
            x:690;y:230
            color:"#11be5a"
            font.pixelSize: 18
            text: neighbourCount
        }

        Text {
            id: nearestDistanceText
            x:690;y:253
            color:"#11be5a"
            font.pixelSize: 18
            text: nearestDistance+"m"
        }

        Text {
            id: safeLevelText
            x:278;y:350
            color:"#11be5a"
            font.pixelSize: 28
            text: safeLevel
        }

        Text {
            id: runningStatusText
            color:"#11be5a"
            x:690;y:369
            font.pixelSize: 14
            font.bold: true
            text: runningStatus
        }

        Rectangle{
            id:toggle
            width: 70
            height: 25
            radius: 5
            opacity: 1
            color: "#11be5a"
            x:646
            y:393
            Text{
                anchors.centerIn: parent
                text: toggleText
                color: "#222222"
            }

            function navigate(){
                if(runningStatus == "Running..."){
                    toggleText = "Start";
                    runningStatus = "Ready...";
                    timer.stop();
                }else{
                    toggleText = "Stop";
                    runningStatus = "Running...";
                    timer.start();
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    toggle.navigate();
                    //timer.start();
                }
            }
        }

        Rectangle{
            id:seeMap
            x:607
            y:280
            radius: 8
            width: 72
            height: 25
            opacity: 0.1
            color:"lightblue"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    core.goToPage(1);
                }
            }
        }

        Rectangle{
            id:setParameters
            x:690
            y:180
            radius: 8
            width: 72
            height: 25
            opacity: 0.1
            color:"lightblue"
            MouseArea{
                anchors.fill: parent
                onClicked: showSet();
            }
        }

        Rectangle{
            id:seeList
            x:690
            y:280
            radius: 8
            width: 72
            height: 25
            opacity: 0.1
            color:"lightblue"
            MouseArea{
                anchors.fill: parent
                onClicked: mainToList();
            }
        }
        Behavior on opacity {
            NumberAnimation{
                duration: 500
            }
        }
    }

    Item{
        id:list
        opacity: 0

        Image {
            id: page2_staticElements
            source: "images/listBackground.png"
        }

        Image {
            id: texts
            source: "images/texts.png"
        }

        Rectangle{
            id:listBack
            x:643
            y:386
            radius: 8
            width: 110
            height: 40
            opacity: 0.1
            color:"lightblue"
            MouseArea{
                anchors.fill: parent
                onClicked: listToMain();
            }
        }

        Image {
            id: spiner
            x:80
            y:373
            smooth: true
            source: "images/spiner.png"
            transform: Rotation {
                origin.x: 25
                origin.y: 25
                angle: spinerAngle
                Behavior on angle {
                    SpringAnimation {
                        spring: 1.4
                        damping: .15
                    }
                }
            }
            Timer{
                running: true
                repeat: true
                interval: 3
                onTriggered: spinerAngle +=1;
            }

        }

        Behavior on opacity {
            NumberAnimation{
                duration: 500
            }
        }
    }

//    Item{
//        id:map
//        opacity: 0
//        Image {
//            id: mapBackground
//            source: "images/mapPage.png"
//        }



//        WebView {
//            id:mapview
//            width: 800
//            height: 480
//            html: "<p>hello world!</p>"
//        }

//        Rectangle{
//            id:mapBack
//            x:643
//            y:386
//            radius: 8
//            width: 110
//            height: 38
//            opacity: 0.5
//            color:"lightblue"
//            MouseArea{
//                anchors.fill: parent
//                onClicked: mapToMain();
//            }
//        }

//        Behavior on opacity {
//            NumberAnimation{
//                duration: 500
//            }
//        }
//    }

    Rectangle{
        id:set
        x:595
        y:25
        opacity: 0
        Image{
            width: setBackground.width
            height: setBackground.height
            source:"images/background.png"
            fillMode: Image.Tile
        }

        Image{
            id:setBackground
            source: "images/setPage.png"
        }

        Repeater{
            id:group
            model: 6
            Desk.ComboBox{
                id:portname
                x:90;y:48+31*index
                width: 60
                model:ListModel{
                    id:selections_name
                }
                Component.onCompleted: portname.addItems()
                function addItems(){
                    switch(index){
                    case 0:
                        selections_name.append({"text":"COM1"});
                        selections_name.append({"text":"COM2"});
                        selections_name.append({"text":"COM3"});
                        selections_name.append({"text":"COM4"});
                        break;
                    case 1:
                        selections_name.append({"text":9600});
                        selections_name.append({"text":38400});
                        selections_name.append({"text":115200});
                        break;
                    case 2:
                        selections_name.append({"text":5});
                        selections_name.append({"text":6});
                        selections_name.append({"text":7});
                        selections_name.append({"text":8});
                        break;
                    case 3:
                        selections_name.append({"text":"odd"});
                        selections_name.append({"text":"even"});
                        break;
                    case 4:
                        selections_name.append({"text":1});
                        selections_name.append({"text":1.5});
                        selections_name.append({"text":2});
                        break;
                    case 5:
                        selections_name.append({"text":"zigbee"});
                        selections_name.append({"text":"gps"});
                        selections_name.append({"text":"nanoTrack"});
                        break;
                    default:
                        break;
                    }
                }
            }
        }

        Rectangle{
            id:setback
            x:93
            y:245
            radius: 8
            width:70
            height: 31
            opacity: 0.1
            color:"lightblue"
            MouseArea{
                anchors.fill: parent
                onClicked: hideSet();
            }
        }

        Behavior on opacity {
            NumberAnimation{
                duration: 500
            }
        }
    }

    function mainToList(){
        main.opacity = 0;
        list.opacity = 1;
    }

    function listToMain(){
        list.opacity = 0;
        main.opacity = 1;
    }

//    function mainToMap(){
//        main.opacity = 0;
//        map.opacity = 1;
//    }

//    function mapToMain(){
//        map.opacity = 0;
//        main.opacity = 1;
//    }

    function showSet(){
        timer.stop();
        set.opacity = 1;
    }

    function hideSet(){
        set.opacity = 0;
        timer.start();
    }

    function update(){
        name = core.getName();
        speed = core.getSpeed();
        direction = core.getDirection();
        longitude = core.getLongitude();
        latitude = core.getLatitude();
        safeLevel = core.getSafeLevel();
        neighbourCount = core.getNeighbourCount();
        nearestDistance = core.getNearestDistance();
        zigbeeSignal = core.getZigbeeSignal();
        gpsSignal = core.getGpsSignal();
        nanoTrackSignal = core.getNanoTrackSignal();
        safe = core.getSafe();
    }

    Timer{
        id:timer
        interval: 20
        repeat: true
        onTriggered: {
            //            direction+=1;
            //            speed +=1;
            //            zigbeeSignal+=2;
            //            gpsSignal+=2;
            //            nanoTrackSignal+=1;
            //            latitude+=1;
            //            longitude+=1;
            update();
            //            check();
        }
        //        function check(){
        //            if(direction > 360) direction = 0;
        //            if(speed > 360) speed = 0;
        //            if(zigbeeSignal > 100) zigbeeSignal = 0;
        //            if(gpsSignal > 100) gpsSignal = 0;
        //            if(nanoTrackSignal > 100) nanoTrackSignal = 0;
        //        }

    }

}
