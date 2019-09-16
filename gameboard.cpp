/**
 * @brief The GameBoard class - Displays the GameBoard where the user will play the game
 * @author Amanda Sambawa
 */

#include "gameboard.h"

#include <ctime>
#include <cstdlib>
#include <QString>
#include <sstream>
#include <iostream>

/**
 * @brief Constructs the GameBoard
 * @param parent is the QWidget parent
 */
GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent), board_size(5)
{
    this->setWindowTitle("Defeat the Dragons Game");
    this->setStyleSheet("background-color: #66CCCC");

    // Sets the top bar
    top = new QWidget;
    top->setStyleSheet("QLabel {background-color: #66CCCC; color: red; font-size : 18px; padding: 2px}");
    top_bar = new QHBoxLayout(top);

    // ****************CHANGE FILE PATH OF THE KNIGHT IMAGE HERE **************
    QString fileName1("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Knight.jpg");
    knight_image = new QPixmap(fileName1);

    // Sets the variables that are used in the game
    dragons_defeated = 0;
    lives_remaining = 5;
    attack_power = 3;
    seconds_left = 30;
    goal = 15;

    QSpacerItem* horizontal_space = new QSpacerItem(90,10);

    // Sets the top part of the GameBoard with the goal, dragons defeated, and seconds left
    QLabel* goal_text;
    if (goal == 15)
        goal_text = new QLabel("Goal: Defeat 15 Dragons");
    goal_text->setStyleSheet("font-family: Consolas; font-size: 24px; color: white; padding: 3px");

    dragons_defeated_label = new QLabel("Dragons Defeated: ");
    QString s1 = QString::number(dragons_defeated);
    dragons_number = new QLabel(s1);
    top_bar->addWidget(dragons_defeated_label);
    top_bar->addWidget(dragons_number);

    seconds_left_label = new QLabel("Seconds Left: ");
    QString s2 = QString::number(seconds_left);
    seconds_number = new QLabel(s2);
    top_bar->addSpacerItem(horizontal_space);
    top_bar->addWidget(seconds_left_label);
    top_bar->addWidget(seconds_number);

    //Creates the board
    Board = new QWidget;
    labels = new QLabel*[board_size*board_size];
    values = new int[board_size*board_size];
    QGridLayout *SquareGrid = new QGridLayout(Board);

    SquareGrid->setGeometry(QRect());
    SquareGrid->setSpacing(0);

    // Initializes the board array
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0;j < 5; j++)
        {
            board_array[i][j] = 0;
        }
    }

    srand(time(0));
    // ****************CHANGE FILE PATHS OF THE DRAGON, HEART, AND SWORD IMAGES HERE **************
    QString fileName2("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Dragon.jpg");
    QString fileName3("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Heart.jpg");
    QString fileName4("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Sword.jpg");

    dragon_image = new QPixmap(fileName2);
    heart_image = new QPixmap(fileName3);
    sword_image = new QPixmap(fileName4);

    // 0 - knight
    // 1 - dragon
    // 2 - heart
    // 3 - sword

    int x = 0;

    // Sets the board array with random values (from 1 to 3) and the corresponding labels array with images
    for (int i= 0; i <board_size;i++)
    {
        for (int j = 0; j < board_size;j++)
        {
            labels[i*board_size+j] = new QLabel;
            labels[i*board_size+j]->setMinimumSize(80,80);
            labels[i*board_size+j]->setMaximumSize(80,80);
            labels[i*board_size+j]->setFrameStyle(3);
            labels[i*board_size+j]->setAlignment(Qt::AlignCenter);

            x = (rand()%3)+1;

            if (x==1)
            {
                labels[i*board_size+j]->setPixmap(*dragon_image);
                board_array[i][j] = 1;
            }
            else if (x==2)
            {
                labels[i*board_size+j]->setPixmap(*heart_image);
                board_array[i][j] = 2;
            }
            else if (x==3)
            {
                labels[i*board_size+j]->setPixmap(*sword_image);
                board_array[i][j] = 3;
            }


            SquareGrid->addWidget(labels[i*board_size+j], i, j);
        }
    }

    // Places the knight at coordinate (0,0)
    knight_position = new QPoint(0,0);
    labels[0]->setPixmap(*knight_image);
    board_array[0][0] = 1;

    setFixedSize(500,550);

    // Sets the bottom part of the GameBoard with lives remaining and attack power
    bottom = new QWidget;
    bottom->setStyleSheet("QLabel {background-color: #66CCCC; color: red; font-size : 18px; padding: 2px}");
    QHBoxLayout *bottom_bar = new QHBoxLayout(bottom);

    lives_remaining_label = new QLabel("Lives Remaining: ");
    QString s3 = QString::number(lives_remaining);
    lives_number = new QLabel(s3);
    bottom_bar->addWidget(lives_remaining_label);
    bottom_bar->addWidget(lives_number);

    attack_power_label = new QLabel("Attack Power: ");
    QString s4 = QString::number(attack_power);
    attack_number = new QLabel(s4);
    bottom_bar->addSpacerItem(horizontal_space);
    bottom_bar->addWidget(attack_power_label);
    bottom_bar->addWidget(attack_number);

    // Places all the elements on the layout
    QVBoxLayout *piece_together = new QVBoxLayout;
    piece_together->addWidget(goal_text);
    piece_together->setAlignment(goal_text, Qt::AlignHCenter);
    piece_together->addWidget(top, 0, Qt::AlignCenter);
    piece_together->addWidget(Board, 0, Qt::AlignCenter);
    piece_together->addWidget(bottom, 0, Qt::AlignCenter);

    this->setLayout(piece_together);
    this->setStyleSheet("QLabel {background-color : black; color : white; }");

    // Sets up the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateClock()));
}
/**
 * @brief GameBoard destructor
 */
GameBoard::~GameBoard() {
    delete[] values;
    delete[] knight_position;
}

/**
 * @brief Updates the number of seconds left according to the clock
 */
void GameBoard::updateClock()
{
    seconds_left--;
    repaint();
}

/**
 * @brief Updates the position of the knight according to the key pressed event
 * @param event to find the key pressed (either right key, left key, up key, down key, or space bar)
 */
void GameBoard::keyPressEvent(QKeyEvent *event)
{
    if (seconds_left == 30)
        timer->start(1000);

    int x = knight_position->rx();
    int y = knight_position->ry();

    int rand_num = 0;

    switch(event->key()){
    case Qt::Key_Left:
        if(knight_position->rx() != 0)
            updateKnight(x,y,x-1,y);
        break;

    case Qt::Key_Right:
        if (knight_position->rx() != board_size-1)
            updateKnight(x,y,x+1,y);
        break;

    case Qt::Key_Up:
        if (knight_position->ry() != 0)
            updateKnight(x,y,x,y-1);
        break;

    case Qt::Key_Down:
        if (knight_position->ry()!=board_size-1)
            updateKnight(x,y,x,y+1);
        break;

    case Qt::Key_Space:
        getTile(x,y);
        rand_num = (rand()%3)+1;
        board_array[y][x] = rand_num;
        labels[y*board_size+x]->clear();
        if (board_array[y][x] == 1)
             labels[y*board_size+x]->setPixmap(*dragon_image);
         else if (board_array[y][x] == 2)
             labels[y*board_size+x]->setPixmap(*heart_image);
         else if (board_array[y][x] == 3)
             labels[y*board_size+x]->setPixmap(*sword_image);
        break;

    default:
        QWidget::keyPressEvent(event);
    }

    // If the user defeats the target number of dragons, will display a window saying they won;
    // Else if the user has no more lives and no more attack power, will display a window saying they lose
    if (dragons_defeated >= goal)
    {
        wwidget->show();
    }
    else if (lives_remaining == 0 && attack_power == 0)
    {
        timer->stop();
        lwidget->show();
    }
    repaint();
    return;
}

/**
 * @brief Paints the GameBoard
 * @param e is the QPaintEvent
 */
void GameBoard::paintEvent(QPaintEvent *e){

    int x = knight_position->rx();
    int y = knight_position->ry();

    // If time runs out, stops the timer and displays a window saying they lose
    if (seconds_left <= 0)
    {
        seconds_left = 0;
        timer->stop();
        lwidget->show();
    }

    // Sets the text for the number of dragons defeated
    QString s1 = QString::number(dragons_defeated);
    dragons_number->setText(s1);

    // Sets the text for the number of seconds left
    QString s2 = QString::number(seconds_left);
    seconds_number->setText(s2);

    // Sets the text for the number of lives remaining
    QString s3 = QString::number(lives_remaining);
    lives_number->setText(s3);

    // Sets the text for the attack power
    QString s4 = QString::number(attack_power);
    attack_number->setText(s4);

    labels[y*board_size+x]->setPixmap(*knight_image);
}

/**
 * @brief updates the position of the knight
 * @param px the previous x-coordinate of the knight's position
 * @param py the previous y-coordinate of the knight's position
 * @param nx the new x-coordinate of the knight's position
 * @param ny the new y-coordinate of the knight's position
 */
void GameBoard::updateKnight(int px, int py, int nx, int ny) {
   labels[py*board_size+px]->clear();

   if (board_array[py][px] == 1)
        labels[py*board_size+px]->setPixmap(*dragon_image);
    else if (board_array[py][px] == 2)
        labels[py*board_size+px]->setPixmap(*heart_image);
    else if (board_array[py][px] == 3)
        labels[py*board_size+px]->setPixmap(*sword_image);

    knight_position->setX(nx);
    knight_position->setY(ny);
    repaint();

}

/**
 * @brief Gets the tile at the given coordinate
 * @param x is the x-coordinate to get the tile of
 * @param y is the y-coordinate to get the tile of
 * @return true if the user got the tile, else returns false
*/
bool GameBoard::getTile(int x, int y)
{
    if (values[y*board_size]){
       if (board_array[y][x] == 1)
       {
           attackDragon(x,y);
           return true;
       }
       else if (board_array[y][x] == 2)
       {
           lives_remaining++;
           return true;
       }
       else if (board_array[y][x] == 3)
       {
            attack_power++;
            return true;
       }
       else
       {
            return false;
       }
    }
    return true;
}

/**
 * @brief Checks to see if the knight can attack the dragon; if yes, then attacks it
 * @param x is the x-coordinate of the dragon to attack
 * @param y is the y-coordinate of the dragon to attack
 * @return true if the attack was successful, else return false
 */
bool GameBoard::attackDragon(int x, int y)
{
    if (attack_power > 0 && lives_remaining > 0)
    {
        dragons_defeated++;
        attack_power--;
        labels[y*board_size+x]->clear();
        return true;
    }
    else if (lives_remaining > 0)
    {
        lives_remaining--;
        labels[y*board_size+x]->clear();
        return false;
    }
}

/**
 * @brief Sets the Quit Widget
 * @param quit_widget the QuitWidget that gets passed in
 */
void GameBoard::setQuitWidget(QuitWidget* quit_widget) {
    qwidget = quit_widget;
}

/**
 * @brief Closes the event
 * @param e is the QCloseEvent that gets passed in
 */
void GameBoard::closeEvent(QCloseEvent *e) {
    e->ignore();
    qwidget->show();
}

/**
 * @brief Sets the Main Window
 * @param main_window is the MainWindow that gets passed in
 */
void GameBoard::setMainWindow(MainWindow* main_window){
    mw = main_window;
}

/**
 * @brief Sets the Win Widget
 * @param win_widget is the WinWidget that gets passed in
 */
void GameBoard::setWinWidget(WinWidget* win_widget)
{
    wwidget = win_widget;
}

/**
 * @brief Sets the Lose Widget
 * @param lose_widget is the LoseWidget that gets passed in
 */
void GameBoard::setLoseWidget(LoseWidget *lose_widget)
{
    lwidget = lose_widget;
}

