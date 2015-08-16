#include "kloginwindow.h"
#include "ui_kloginwindow.h"

kLoginWindow::kLoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kLoginWindow)
{
    ui->setupUi(this);

	//Setting
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowOpacity(0.9);

	//Button
	ui->butExit->setFlat(true);
	connect(ui->butExit, SIGNAL(clicked()), this, SLOT(buttonExit()));

	ui->butLogin->setFlat(true);

	//TestLine
	ui->txtPassWord->setEchoMode(QLineEdit::Password);

}

kLoginWindow::~kLoginWindow()
{
    delete ui;
}

/*
	Exit;
*/
void kLoginWindow::buttonExit(){

	this->hide();
}

/*
MouseAction;
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

