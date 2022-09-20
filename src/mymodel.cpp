#include "mymodel.h"

MyClass::MyClass(QWidget* pwgt) : QWidget(pwgt){
    lbl = new QLabel("Пусто");
    button = new QPushButton("CLick on me");

    QObject::connect(button , SIGNAL(clicked()) , this , SLOT(doit()));

    QHBoxLayout* la = new QHBoxLayout;
    la -> addWidget(lbl);
    la -> addWidget(button);

    this->setLayout(la);
}

void MyClass::doit(){
    num++;
    lbl ->setText(QString::number(num));
}
