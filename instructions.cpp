/**
 * @brief the Instructions class - Contains the instructions for the game
 * @author Amanda Sambawa
 */

#include "instructions.h"

#include <ctime>
#include <cstdlib>
#include <QString>

/**
 * @brief Instructions constructor
 * @param parent is the QWidget parent
 */
Instructions::Instructions(QWidget* parent):
    QWidget(parent)
{
    this->setWindowTitle("Instructions");

    // Sets the top widget
    top = new QWidget;
    top->setStyleSheet("QLabel {background-color: white; color: black; font-size : 20px}");

    QVBoxLayout *layout = new QVBoxLayout(top);

    // ****************CHANGE FILE PATHS OF THE KNIGHT, DRAGON, HEART, AND SWORD IMAGES HERE **************
    QString fileName1("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Knight.jpg");
    QString fileName2("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Dragon.jpg");
    QString fileName3("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Heart.jpg");
    QString fileName4("/Qt/Tools/QtCreator/bin/DefeatDragonsGameFinal/Sword.jpg");

    // Sets the knight, dragon, heart, and sword images
    QPixmap* image1 = new QPixmap(fileName1);
    QPixmap* image2 = new QPixmap(fileName2);
    QPixmap* image3 = new QPixmap(fileName3);
    QPixmap* image4 = new QPixmap(fileName4);
    QLabel* knight_image = new QLabel();
    knight_image->setPixmap(*image1);
    QLabel* dragon_image = new QLabel();
    dragon_image->setPixmap(*image2);
    QLabel* heart_image = new QLabel();
    heart_image->setPixmap(*image3);
    QLabel* sword_image = new QLabel();
    sword_image->setPixmap(*image4);

    QLabel* knight_label = new QLabel("Knight:");
    knight_label->setStyleSheet("font-size: 14px");
    QLabel* dragon_label = new QLabel("Enemy Dragon:");
    dragon_label->setStyleSheet("font-size: 14px");
    QLabel* heart_label = new QLabel("Life:");
    heart_label->setStyleSheet("font-size: 14px");
    QLabel* sword_label = new QLabel("Attack Power:");
    sword_label->setStyleSheet("font-size: 14px");

    // Sets the instructions on how to play the game
    QLabel* title = new QLabel("Instructions");
    title->setStyleSheet("font-size: 18pt");
    QLabel* goal_description = new QLabel("Goal: To defeat the specified number of dragons within a limited amount of time.");
    goal_description->setStyleSheet("font-size: 14pt");
    QLabel* description1 = new QLabel("You will play as the knight, which you can control using the arrow keys. The hearts on the board represent \nthe lives you can obtain. When the knight is on a heart tile and the space bar is pressed, a life will be added \nto the knight’s lives. You need swords to defeat the dragons. When the knight is on a sword tile and the space \nbar is pressed, a sword will be added to the knight’s attack power. The dragons on the board are the enemies \nthat need to be defeated. When the knight is on a dragon tile and the space bar is pressed, the dragon will \nbe defeated and it will disappear from the board (this will only work if the knight has enough attack power). \nAn attack power will also be subtracted. If the knight does not have enough attack power and he attacks a \ndragon, the knight will lose a life.  When an element disappears on the board, either a sword, heart, or \ndragon will reappear in that tile.");
    description1->setStyleSheet("font-size: 12pt");
    QLabel* description2 = new QLabel("There are three levels – Easy, Medium, and Difficult. On Easy, only one sword is needed to defeat a dragon. \nOn Medium, two swords are needed to defeat a dragon. On Hard, three swords are needed to defeat a \ndragon.");
    description2->setStyleSheet("font-size:12pt");

    QSpacerItem* horizontal_space = new QSpacerItem(50,20);

    // Adds the instruction and images to the layout
    layout->addWidget(title);
    layout->setAlignment(title, Qt::AlignHCenter);
    layout->addWidget(goal_description);
    layout->addSpacerItem(horizontal_space);
    layout->addWidget(description1);
    layout->addSpacerItem(horizontal_space);
    layout->addWidget(description2);
    layout->addSpacerItem(horizontal_space);

    QHBoxLayout* hLayout1 = new QHBoxLayout;
    hLayout1->addWidget(knight_label);
    hLayout1->addWidget(dragon_label);
    hLayout1->addWidget(heart_label);
    hLayout1->addWidget(sword_label);
    layout->addLayout(hLayout1);

    QHBoxLayout* hLayout2 = new QHBoxLayout;
    hLayout2->addWidget(knight_image);
    hLayout2->addWidget(dragon_image);
    hLayout2->addWidget(heart_image);
    hLayout2->addWidget(sword_image);
    layout->addLayout(hLayout2);

    this->setFixedSize(800,500);
    this->setLayout(layout);
}

/**
 * @brief Instructions destructor
 */
Instructions::~Instructions() {
}

/**
 * @brief Sets the Main Window
 * @param main_window is the MainWindow that gets passed in
 */
void Instructions::setMainWindow(MainWindow* main_window){
    mw = main_window;
}
