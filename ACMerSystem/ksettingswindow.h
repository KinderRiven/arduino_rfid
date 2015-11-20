#ifndef KSETTINGSWINDOW_H
#define KSETTINGSWINDOW_H

#include <QWidget>
#include "kHead.h"
#include "kUserData.h"
#include "kwarningwindow.h"
#include "computerSystem.h"
#include "kMusicData.h"


namespace Ui {
class kSettingsWindow;
}

class kSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit kSettingsWindow(QWidget *parent = 0);
    ~kSettingsWindow();
	void kShow();
public slots:
	void buttonExit();
	void buttonOK();
protected:
	void mousePressEvent(QMouseEvent *event);			//重写鼠标点击事件
	void mouseMoveEvent(QMouseEvent *event);			//重写鼠标移动事件
	void timerEvent(QTimerEvent *event);
private:
    Ui::kSettingsWindow *ui;
	QPoint mousePrepos;
	kWarningWindow warningWindow;
	int timeid;
};

#endif // KSETTINGSWINDOW_H
