/**
 * @brief the Instructions class - Contains the instructions for the game
 * @author Amanda Sambawa
 */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include "mainwindow.h"

class Instructions : public QWidget
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = 0);
    ~Instructions();

    void setMainWindow(MainWindow* main_window);

private:
     QWidget* top;
     MainWindow* mw;
};

#endif // INSTRUCTIONS_H
