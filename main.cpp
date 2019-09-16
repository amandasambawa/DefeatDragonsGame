/**
 * @brief The main class - Starts the application
 * @author Amanda Sambawa
 */
#include "mainwindow.h"
#include "gameboard.h"
#include "instructions.h"
#include "quitwidget.h"
#include "losewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creates the Quit, Win, and Lose widgets
    QuitWidget* qwidget = new QuitWidget;
    WinWidget* wwidget = new WinWidget;
    LoseWidget* lwidget = new LoseWidget;

    // Creates the Main, GameBoard, and Instructions windows
    MainWindow* w = new MainWindow;
    GameBoard* b = new GameBoard;
    Instructions* r = new Instructions;

    w->setQuitWidget(qwidget);
    b->setQuitWidget(qwidget);
    b->setWinWidget(wwidget);
    b->setLoseWidget(lwidget);

    w->setGameBoard(b);
    w->displayInstructions(r);
    b->setMainWindow(w);
    w->show();

    QObject::connect(qwidget->quit_ok, SIGNAL(clicked()), &a, SLOT(quit()));
    QObject::connect(wwidget->ok, SIGNAL(clicked()), &a, SLOT(quit()));
    QObject::connect(lwidget->ok, SIGNAL(clicked()), &a, SLOT(quit()));
    return a.exec();
}
