#include "kstartwindow.h"
#include "ui_kstartwindow.h"

kStartWindow::kStartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kStartWindow)
{
    //ui->setupUi(this);
	//Òþ²Ø
	setWindowFlags(Qt::FramelessWindowHint);

	//Í¸Ã÷
	setAttribute(Qt::WA_TranslucentBackground, true);

	//¼ÓÔØ
	windowImage.load("Resources\\image\\start2");
}

kStartWindow::~kStartWindow(){

    delete ui;
}

void kStartWindow::kShow(){

	setWindowOpacity(0.0);
	cost = 0.005;
	timeid = startTimer(10);
	show();
}

void kStartWindow::paintEvent(QPaintEvent*){

	QPainter painter(this);
	resize(windowImage.width(), windowImage.height());
	painter.drawPixmap(0, 0, windowImage.width(), windowImage.height(), windowImage);
}

void kStartWindow::timerEvent(QTimerEvent *event){

	if (event->timerId() == timeid){
		double op = windowOpacity();
		if (cost > 0){
			if (op + cost <= 0.8)
				setWindowOpacity(op + cost);
			else
				cost = -cost;
		}
		else if (cost < 0){
			if (op + cost >= 0.0)
				setWindowOpacity(op + cost);
			else{
				hide();
				Sleep(1000);
				mainWindow.kShow();
				killTimer(timeid);
			}
		}
	}
}