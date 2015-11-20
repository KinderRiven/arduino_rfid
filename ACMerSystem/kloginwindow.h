#ifndef KLOGINWINDOW_H
#define KLOGINWINDOW_H

#include <QWidget>
#include <kHead.h>
#include <kMusicData.h>
#include "kUserData.h"
#include "kwarningwindow.h"
#include "computerSystem.h"
/*
	580 X 285
*/
namespace Ui {
class kLoginWindow;
}

class kLoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kLoginWindow(QWidget *parent = 0);
    ~kLoginWindow();
	void kShow();
public slots:
	void buttonExit();
	void buttonOK();
protected:
	void mousePressEvent(QMouseEvent *event);			//重写鼠标点击事件
	void mouseMoveEvent(QMouseEvent *event);			//重写鼠标移动事件
	void timerEvent(QTimerEvent *event);
private:
    Ui::kLoginWindow *ui;
	QPoint mousePrepos;
	kWarningWindow warningWindow;
	int kHeight;
	int kWidth;
	int timeid;
};

#endif // KLOGINWINDOW_H
