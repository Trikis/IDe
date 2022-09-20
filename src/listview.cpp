#include "ListView.h"

ListView::ListView(QWidget* parent) : QListView(parent){
}

void ListView::mousePressEvent(QMouseEvent *event){
    if (event ->button() == Qt::RightButton){

    } else  QListView::mousePressEvent(event);
}

