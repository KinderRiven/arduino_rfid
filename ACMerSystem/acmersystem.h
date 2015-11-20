#ifndef ACMERSYSTEM_H
#define ACMERSYSTEM_H

#include "kHead.h"
#include "ktable.h"
#include <kloginwindow.h>
#include <ksettingswindow.h>

#include <QtWidgets/QMainWindow>
#include "ui_acmersystem.h"
#include "computerSystem.h"
#include "kshowdata.h"

class ACMerSystem : public QMainWindow
{
	Q_OBJECT

public:
	ACMerSystem(QWidget *parent = 0);
	~ACMerSystem();
	void kShow();

public slots:
	void menuExit();
	void menuLogin();
	void menuSetting();
	void startRun();
	void showData();
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
	kSettingsWindow settingsWindow;
	kTable userTable;
};

#endif // ACMERSYSTEM_H
