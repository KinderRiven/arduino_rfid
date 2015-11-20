#include "ksettingswindow.h"
#include "ui_ksettingswindow.h"

kSettingsWindow::kSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kSettingsWindow){
    ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);


	ui->OK->setFlat(true);
	connect(ui->OK, SIGNAL(clicked()), this, SLOT(buttonOK()));
	
	ui->EXIT->setFlat(true);
	connect(ui->EXIT, SIGNAL(clicked()), this, SLOT(buttonExit()));

	ui->PassWord_Edit->setEchoMode(QLineEdit::Password);
}

kSettingsWindow::~kSettingsWindow()
{
    delete ui;
}

/*
	button
*/

void kSettingsWindow::buttonOK(){
	
	kUserData::IP		= ui -> IP_Edit -> text().toStdString();
	kUserData::Port		= ui -> Port_Edit -> text().toStdString();
	kUserData::UserName = ui -> UserName_Edit -> text().toStdString();
	kUserData::PassWord = ui -> PassWord_Edit -> text().toStdString();

	//Save
	kUserData::SaveData();
	hide();
	warningWindow.kShow(0);
}

void kSettingsWindow::buttonExit(){
	hide();
}

void kSettingsWindow::kShow(){

	setMinimumHeight(0);

	resize(QSize(385, 0));

	setWindowOpacity(0.3);
	//MUSIC
	kMusicData::settingSound();


	//动画
	timeid = startTimer(10);
	
	show();

	/*
		Load Config
	*/
	kUserData::LoadData();
	/*
		Load Data
	*/
	QString qstr;

	qstr = QString::fromStdString(kUserData::IP);
	ui -> IP_Edit -> setText(qstr);

	qstr = QString::fromStdString(kUserData::Port);
	ui -> Port_Edit->setText(qstr);

	qstr = QString::fromStdString(kUserData::UserName);
	ui -> UserName_Edit->setText(qstr);

	qstr = QString::fromStdString(kUserData::PassWord);
	ui -> PassWord_Edit->setText(qstr);
	/*
		Move
	*/
	//QDesktopWidget* desktop = QApplication::desktop();
	//move((desktop->width() - 580) / 2, (desktop->height() - 270) / 2);
	move((ComputerSystem::screenWidth - 580) / 2, (ComputerSystem::screenHeight - 270) / 2);
}

/*
	MouseEvent
*/
void kSettingsWindow::mousePressEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void kSettingsWindow::mouseMoveEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//窗口移动公式
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		move(QPoint(posX, posY));

		mousePrepos = mousePos;
	}
}

void kSettingsWindow::timerEvent(QTimerEvent *event){

	if (event->timerId() == timeid){
		int now_height = height();
		double op = windowOpacity();

		if (now_height + 25 <= 425)
			resize(width(), now_height + 25);

		else if (op + 0.1 <= 0.8)
			setWindowOpacity(op + 0.1);

		else{
			setMinimumHeight(height());
			killTimer(timeid);
		}
	}
}