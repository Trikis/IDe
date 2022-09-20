#include "splitter.h"
#include "menu.h"

int main(int argc , char** argv){
    QApplication app(argc , argv);

    QWidget mainwgt;
    mainwgt.setWindowFlags(Qt::WindowStaysOnTopHint);
    mainwgt.setWindowTitle("Text Editor");

    Splitter* spl = new Splitter;
    spl -> resize(1800 ,900);

    QMenu* menu = new QMenu("&Menu");
    menu -> addAction("quit",&app , SLOT(quit()) , Qt::CTRL + Qt::Key_Q);
    menu -> addAction("open", spl , SLOT(add_file()),Qt::CTRL + Qt::Key_O);
    menu -> addAction("Save current Open File", spl , SLOT(save()), Qt::CTRL + Qt::Key_S);
    menu -> addAction("Delete current item from workdpace" , spl , SLOT(del()) , Qt::Key_Delete);

    QMenuBar* mainMenu = new QMenuBar;
    QFont font("Lucida Console",10,QFont::Normal);
    mainMenu -> setFont(font);
    mainMenu -> addMenu(menu);

    QVBoxLayout* vert = new QVBoxLayout;
    vert -> setMenuBar(mainMenu);
    vert -> addWidget(spl);

    mainwgt.setLayout(vert);
    mainwgt.resize(1800,900);
    mainwgt.show();

    return app.exec();
}
