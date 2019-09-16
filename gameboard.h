/**
 * @brief The GameBoard class - Displays the GameBoard where the user will play the game
 * @author Amanda Sambawa
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QKeyEvent>

#include "mainwindow.h"
#include "quitwidget.h"
#include "winwidget.h"
#include "losewidget.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public slots:
    void updateClock();

public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();

    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *e);

    bool getTile(int x, int y);
    void updateKnight(int px, int py, int nx, int ny);
    bool attackDragon(int x, int y);

    void setQuitWidget(QuitWidget* quit_widget);
    void setWinWidget(WinWidget* win_widget);
    void setLoseWidget(LoseWidget* lose_widget);
    void closeEvent(QCloseEvent *e);
    void setMainWindow(MainWindow* main_window);

private:
    // Image variables for the GameBoard
    QPixmap* knight_image;
    QPixmap* heart_image;
    QPixmap* sword_image;
    QPixmap* dragon_image;

    // The position of the knight
    QPoint *knight_position;

    // The target number of dragons to defeat
    int goal;

    //Top bar variables
    QWidget* top;
    QHBoxLayout* top_bar;
    int dragons_defeated;
    QLabel* dragons_defeated_label;
    QLabel* dragons_number;
    QTimer *timer;
    QLabel* seconds_left_label;
    int seconds_left;
    QLabel* seconds_number;

    //Bottom bar variables
    QWidget* bottom;
    int lives_remaining;
    QLabel* lives_remaining_label;
    QLabel* lives_number;
    QLabel** lives;
    int attack_power;
    QLabel* attack_power_label;
    QLabel* attack_number;

    //Board Variables
    QWidget* Board;
    int board_size;
    QLabel** labels;
    int* values;
    int board_array[5][5];

    QuitWidget* qwidget;
    WinWidget* wwidget;
    LoseWidget* lwidget;
    MainWindow* mw;
};

#endif // GAMEBOARD_H
