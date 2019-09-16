/**
 * @brief The MainWindow class - Contains the Main Window of the game (the menu screen)
 * @author Amanda Sambawa
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QObject>

#include "quitwidget.h"

class GameBoard;
class Instructions;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

    void setGameBoard(GameBoard* game_board);
    void closeEvent(QCloseEvent *e);
    void setQuitWidget(QuitWidget* quit_widget);
    void displayInstructions(Instructions *instructions);

private:
    GameBoard* board;
    Instructions* instructions_board;

    // Labels displayed on the main window
    QLabel* welcome;
    QLabel* difficulty;

    // Push buttons and radio buttons displayed on the main window
    QPushButton* start;
    QPushButton* instruction;
    QRadioButton* easy;
    QRadioButton* medium;
    QRadioButton* hard;

    QVBoxLayout* layout;
    QWidget* central;

    QuitWidget* qwidget;
};

#endif // MAINWINDOW_H
