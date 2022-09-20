#pragma once
#include <QtWidgets>

class MyClass : public QWidget{
    Q_OBJECT
private:
    int num = 0;
public:
    QPushButton* button;
    QLabel* lbl;
    MyClass(QWidget* wgt = 0);
public slots:
    void doit();
};
