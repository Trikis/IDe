#pragma once
#include <QtWidgets>

class ListView : public QListView{
    Q_OBJECT
public:
    ListView(QWidget* parent = 0);
protected:
    virtual void mousePressEvent(QMouseEvent* event);
};
