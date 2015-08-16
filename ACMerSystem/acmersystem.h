#ifndef ACMERSYSTEM_H
#define ACMERSYSTEM_H

#include "kHead.h"
#include <kloginwindow.h>

#include <QtWidgets/QMainWindow>
#include "ui_acmersystem.h"

class ACMerSystem : public QMainWindow
{
	Q_OBJECT

public:
	ACMerSystem(QWidget *parent = 0);
	~ACMerSystem();

public slots:
	void menuExit();
	void menuLogin();
protected:
	void paintEvent(QPaintEvent*);						//绘图
	void mousePressEvent(QMouseEvent *event);			//重写鼠标点击事件
	void mouseMoveEvent(QMouseEvent *event);			//重写鼠标移动事件
	void contextMenuEvent(QContextMenuEvent *event);	//重写右键菜单

private:
	Ui::ACMerSystemClass ui;
	QPixmap windowImage;		//窗口
	QPoint  mousePrepos;		//记录鼠标之前的位置
	QAction *menuAction[10];	//菜单指针

	kLoginWindow loginWindow;
};

#endif // ACMERSYSTEM_H
