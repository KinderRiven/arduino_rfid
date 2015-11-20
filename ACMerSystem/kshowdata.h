#ifndef KSHOWDATA_H
#define KSHOWDATA_H

#include <QWidget>
#include "kHead.h"

namespace Ui {
class kShowData;
}

class kShowData : public QWidget
{
    Q_OBJECT

public:
    explicit kShowData(QWidget *parent = 0);
    ~kShowData();
	void kShow();
	void upDate();

	string cid;
public slots:
	void buttonUpdate();
	void buttonExit();


private:
	int timeid;
    Ui::kShowData *ui;
	QPoint mousePrepos;
	
	string re_name;
	string re_id;
	string re_age;
	string re_tle;
	string re_cid;
	string re_class;
	

protected:
	void mousePressEvent(QMouseEvent *event);			//重写鼠标点击事件
	void mouseMoveEvent(QMouseEvent *event);			//重写鼠标移动事件
	void timerEvent(QTimerEvent *event);
};

#endif // KSHOWDATA_H
