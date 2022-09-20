#include "splitter.h"

Splitter::Splitter(QWidget* parent ) : QSplitter(Qt::Horizontal, parent)
{
    pmodel = new QStringListModel;
    files = new ListView();
    files -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    files -> setModel(pmodel);

    ide = new TextEdit();

    QObject::connect(files , SIGNAL(clicked(const QModelIndex&)) , this ,SLOT(rackyrivaem_index(const QModelIndex&)));
    this -> addWidget(files);
    this -> addWidget(ide);
    this -> setStretchFactor(0 , 2);
    this -> setStretchFactor(1,8);
    this->setStyleSheet("QSplitter::handle{background: #444444;}");
}

void Splitter::add_file(){
    QString filename = QFileDialog::getOpenFileName(this , "Выберите файл", QDir::currentPath());
    QStringList strlist = pmodel -> stringList();
    strlist.append(filename);
    strlist.removeDuplicates();
    pmodel -> setStringList(strlist);
}
void Splitter::chng_workspace_file(QString filepath){
    QFile file(filepath);
    file.open(QFile::ReadOnly);
    ide -> setPlainText(QLatin1String(file.readAll()));
}
void Splitter::rackyrivaem_index(const QModelIndex& index){
    QString Data = files ->model() -> data(index).toString();
    chng_workspace_file(Data);
}
void Splitter::save(){
   QModelIndex index = files  -> currentIndex();
   QString filename = files -> model() -> data(index).toString();

   QString Data = ide->toPlainText();
   QFile file(filename);
   file.open(QFile::WriteOnly);
   QTextStream out(&file);
   out << Data;
   file.close();
}

void Splitter::del(){
    QModelIndex index = files -> currentIndex();
    QString filename = files -> model() -> data(index).toString();
    QStringList tmp;
    for (auto str : pmodel ->stringList()){
        if (str != filename) tmp.append(str);
    }
    pmodel -> setStringList(tmp);
    ide -> setPlainText("");
}
