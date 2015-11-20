#include "kloginwindow.h"
#include "ui_kloginwindow.h"

kLoginWindow::kLoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kLoginWindow)
{
    ui->setupUi(this);
	//
	kHeight = 270;
	kWidth  = 580;

	//Setting
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowOpacity(0.9);

	//Button
	ui->butExit->setFlat(true);
	connect(ui->butExit, SIGNAL(clicked()), this, SLOT(buttonExit()));

	ui->butLogin->setFlat(true);
	connect(ui->butLogin, SIGNAL(clicked()), this, SLOT(buttonOK()));
	//TestLine
	ui->txtPassWord->setEchoMode(QLineEdit::Password);

	//
	hide();

}

kLoginWindow::~kLoginWindow()
{
    delete ui;
}

/*
	Exit
*/
void kLoginWindow::buttonExit(){

	this->hide();
}

void kLoginWindow::buttonOK(){

	QString qstr = ui -> txtUserName -> text();
	QString pstr = ui -> txtPassWord -> text();
	if (qstr == "admin" && pstr == "123456"){
		kUserData::isLogin = true;
		warningWindow.kShow(0);
		hide();
	}
	else
		warningWindow.kShow(1);
}
/*
	MouseAction
*/

void kLoginWindow::mousePressEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void kLoginWindow::mouseMoveEvent(QMouseEvent *event){

	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//窗口移动公式
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		move(QPoint(posX, posY));

		mousePrepos = mousePos;
	}
}

/*
	Show
*/

void kLoginWindow::kShow(){
	
	//Music
	//kMusicData::systemSound();
	kMusicData::settingSound();
	//Size
	resize(QSize(0, 0));

	setWindowOpacity(0.3);

	show();

	//Timer
	timeid = startTimer(10);

	//初始化窗口位置
	//QDesktopWidget* desktop = QApplication::desktop();
	//move((desktop->width() - 580) / 2, (desktop->height() - 270) / 2);
	move((ComputerSystem::screenWidth - 580) / 2, (ComputerSystem::screenHeight - 270) / 2);
	//
}


void kLoginWindow::timerEvent(QTimerEvent *event){
	if (event -> timerId () == timeid){
		int now_height = height();
		int now_width = width();
		double op = windowOpacity();


		if (now_height + 27 <= 270)
			resize( QSize ( now_width + 58,  now_height + 27 ) );
		else if (op + 0.025 <= 0.8)
			setWindowOpacity(op + 0.025);
		else
			killTimer(timeid);
	}
}