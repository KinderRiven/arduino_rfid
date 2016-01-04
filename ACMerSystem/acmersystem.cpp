#include "acmersystem.h"

ACMerSystem::ACMerSystem(QWidget *parent)
	: QMainWindow(parent){

	//ui.setupUi(this);
	//隐藏
	setWindowFlags(Qt::FramelessWindowHint);
	
	//透明
	setAttribute(Qt::WA_TranslucentBackground,true);

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	
	//加载
	windowImage.load("Resources\\image\\start");

	ComputerSystem::getScren();

}

/*
	Draw window;
*/

void ACMerSystem::paintEvent(QPaintEvent*){
	
	QPainter painter(this);
	resize(windowImage.width(), windowImage.height());
	painter.drawPixmap(0, 0, windowImage.width(), windowImage.height(), windowImage);
}

/*
	MouseAction;
*/

void ACMerSystem::mousePressEvent(QMouseEvent *event){
	
	if (event->buttons() == Qt::LeftButton){
		mousePrepos = cursor().pos();
		update();
	}
}

void ACMerSystem::mouseMoveEvent(QMouseEvent *event){
	
	if (event->buttons() == Qt::LeftButton){
		QPoint mousePos = cursor().pos();

		//窗口移动公式
		int posX = pos().x() + mousePos.x() - mousePrepos.x();
		int posY = pos().y() + mousePos.y() - mousePrepos.y();

		if (posX < 0) posX = 0;
		if (posY < 0) posY = 0;

		if (posX + width() > ComputerSystem::screenWidth)	 
			posX = ComputerSystem::screenWidth - width();
		if (posY + height() > ComputerSystem::screenHeight) 
			posY = ComputerSystem::screenHeight - height();

		move(QPoint(posX, posY));
		mousePrepos = mousePos;
	}
}

/*
	delete;
*/

ACMerSystem::~ACMerSystem(){

}

/*
	Menu
*/
void ACMerSystem::contextMenuEvent(QContextMenuEvent *event){

	//MUSCI
	kMusicData::menuSound();

	QMenu *menu = new QMenu(this);

	//字体设置
	QFont menuFont;
	menuFont.setFamily(QStringLiteral("SAO UI"));
	menuFont.setPointSize(12);

	//用户登陆
	menuAction[1] = new QAction(QIcon("Resources\\image\\user"), tr("Login"), this);
	menuAction[1]->setFont(menuFont);
	connect(menuAction[1], SIGNAL(triggered()), this, SLOT(menuLogin()));
	menu->addAction(menuAction[1]);

	//用户设置
	menuAction[2] = new QAction(QIcon("Resources\\image\\Tool"), tr("Setting"), this);
	menuAction[2]->setFont(menuFont);
	connect(menuAction[2], SIGNAL(triggered()), this, SLOT(menuSetting()));
	menu->addAction(menuAction[2]);

	if (kUserData::isLogin == false)
		menuAction[2]->setDisabled(true);

	//开始监听刷卡
	menuAction[3] = new QAction(QIcon("Resources\\image\\eye"), tr("Start"), this);
	menuAction[3]->setFont(menuFont);
	connect(menuAction[3], SIGNAL(triggered()), this, SLOT(startRun()));
	menu->addAction(menuAction[3]);

	//if (kUserData::isLogin == false)
		menuAction[3]->setDisabled(true);


	menuAction[4] = new QAction(QIcon("Resources\\image\\eye"), tr("Show"), this);
	menuAction[4]->setFont(menuFont);
	connect(menuAction[4], SIGNAL(triggered()), this, SLOT(showData()));
	menu->addAction(menuAction[4]);

	if (kUserData::isLogin == false)
		menuAction[4]->setDisabled(true);

	//退出
	menuAction[0] = new QAction(QIcon("Resources\\image\\exit"), tr("Exit"), this);
	menuAction[0]->setFont(menuFont);
	connect(menuAction[0], SIGNAL(triggered()), this, SLOT(menuExit()));
	menu->addAction(menuAction[0]);

	//弹出位置
	menu->exec(cursor().pos());
}


/*
	Exit;
*/

void ACMerSystem::menuExit(){

	
	exit(0);
}


/*
	Login
*/


void ACMerSystem::menuLogin(){

	loginWindow.kShow();
}

void ACMerSystem::menuSetting(){

	settingsWindow.kShow();

}

void ACMerSystem::showData(){
	userTable.kShow();
}

void ACMerSystem::startRun(){


}
/*
	Show
*/
void ACMerSystem::kShow(){
	move(ComputerSystem::screenWidth - width(), 0);
	show();
}