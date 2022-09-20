#pragma once

#include <QMainWindow>
#include <QApplication>

class Menu : public QMainWindow {
  Q_OBJECT
  public:
    Menu(QWidget *parent = nullptr);
};
