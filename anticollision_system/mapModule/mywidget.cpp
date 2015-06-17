#include "mywidget.h"
#include "ui_mywidget.h"


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    setUpParameters();
    setUpConnections();

    map = new MapLayer;
    scene = new QGraphicsScene;
    map->beginDrawOnCanvas(scene);
    ui->graphicsView->setScene(scene);
    setGUI();

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(changePosition()));
    timer->start();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::zoomSlot(int value)
{
    qreal s;
    if(value>zoom)
        s = pow(1.04,(value-zoom));
    else		// zoom out
        s = pow((1/1.04),(zoom-value));
    ui->graphicsView->scale(s,s);
    zoom = value;
}

void MyWidget::setGUI()
{
//    ui->slider->setEnabled(false);
//    int width = 700;
//    int height = 400;//800/map->getProportion();
//    ui->graphicsView->setGeometry(50,40,width,height);

    //去除滚动条区域
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

//    setFixedSize(width,height);
}

void MyWidget::setUpParameters()
{
    zoom = 50;
    ui->slider->setValue(zoom);
    ui->graphicsView->scale(10,10);
    track = getCoordinates();
    ui->label->setPixmap(QPixmap("ui/images/background.png"));
}

void MyWidget::setUpConnections()
{
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(zoomSlot(int)));
}

void MyWidget::lookAt(QPointF p)
{
    ui->graphicsView->centerOn(p.x(),p.y());
}

QList<QPointF> MyWidget::getCoordinates()
{
    QList<QPointF> ret;
    file = new QFile;
    file->setFileName("mapModule/data/in.txt");
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) return ret;
    while (!file->atEnd()) {
        QString line = QString(file->readLine()).trimmed();
        QStringList list = line.split(" ");
        //        double lat = list.at(0).toFloat();
        //        double lon = list.at(1).toFloat();
        ret.append(QPointF(list.at(0).toFloat(),list.at(1).toFloat()));
    }
    return ret;
}

void MyWidget::changePosition()
{
    static int index = 0;
    if(index!=0) scene->removeItem(self);
    if(index < track.count()){
        QPointF p = track.at(index);
        lookAt(p);
        //绘制一个小点来表示自己
        self = new QGraphicsEllipseItem;
        self->setRect(p.x()-0.5,p.y()-0.5,1,1);//得减掉自己的半径
        self->setPen(QPen(Qt::blue,0.1));
        self->setBrush(QBrush(Qt::blue));
        scene->addItem(self);
        index ++;
    }else index = 0;

}

void MyWidget::on_pushButton_clicked()
{
    emit goToPage(0);
}
