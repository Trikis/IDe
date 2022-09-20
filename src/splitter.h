#pragma once
#include <QtWidgets>
#include "TextEdit.h"
#include "ListView.h"

class Splitter : public QSplitter{
    Q_OBJECT
private:
    QStringListModel* pmodel;
private:
    ListView* files;
    TextEdit* ide;
public:
    Splitter(QWidget *parent = 0);
    void chng_workspace_file(QString filepath);
public slots:
    void rackyrivaem_index(const QModelIndex&);
    void add_file();
    void save();
    void del();
};
