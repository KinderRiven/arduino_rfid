#include "kshowdata.h"
#include "kUserData.h"
#include "kMusicData.h"
#include "ui_kshowdata.h"
#include "computerSystem.h"

kShowData::kShowData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kShowData)
{
    ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	
	ui->UPDATE->setFlat(true);
	connect(ui->UPDATE, SIGNAL(clicked()), this, SLOT(buttonUpdate()));
	ui->EXIT->setFlat(true);
	connect(ui->EXIT, SIGNAL(clicked()), this, SLOT(buttonExit()));
}

void kShowData::upDate(){

	string path = kUserData::userdata_path + cid;
	fstream fs(path);
	int num = 0;
	char str[128];
	while (fs.getline(str, sizeof(str))){

		switch (num++){
			case 0:
				re_id = string(str);
				break;
			case 1:
				re_name = string(str);
				break;
			case 2:
				re_age = string(str);
				break;
			case 3:
				re_class = string(str);
				break;
			case 4:
				re_tle = string(str);
				break;
			case 5:
				re_cid = string(str);
				break;
			default:
				break;
		}
	}

	ui -> id -> setText(QString::fromStdString(re_id));
	ui -> name -> setText(QString::fromStdString(re_name));
	ui -> clss -> setText(QString::fromStdString(re_class));
	ui -> tle -> setText(QString::fromStdString(re_tle));
	ui -> cid -> setText(QString::fromStdString(re_cid));
}

kShowData::~kShowData()
{
    delete ui;
}

void kShowData::mousePressEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void kShowData::mouseMoveEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//窗口移动公式
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		move(QPoint(posX, posY));

		mousePrepos = mousePos;
	}
}

void kShowData::kShow(){


	upDate();

	setMinimumHeight(0);

	resize(QSize(0, 0));

	setWindowOpacity(0.3);

	kMusicData::settingSound();
	timeid = startTimer(5);
	move((ComputerSystem::screenWidth - 580) / 2, (ComputerSystem::screenHeight - 270) / 2);
	show();
}

void kShowData::buttonUpdate(){
	upDate();
}

void kShowData::buttonExit(){
	hide();
}

void kShowData::timerEvent(QTimerEvent *event){

	if (event->timerId() == timeid){
		int now_height = height();
		int now_width = width();
		double op = windowOpacity();
		int ok = 0;
		if (now_height + 17 <= 425){
			now_height += 17;
			ok = 1;
		}

		if (now_width + 22 <= 550){
			ok = 1;
			now_width += 22;
		}

		if (op + 0.1 <= 0.8){
			ok = 1;
			setWindowOpacity(op + 0.1);
		}
		if (ok)
			resize(now_width, now_height);
		if(!ok){
			setMinimumHeight(height());
			killTimer(timeid);
		}
	}
}