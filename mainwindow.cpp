/**
 * @brief The MainWindow class - Contains the Main Window of the game (the menu screen)
 * @author Amanda Sambawa
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"
#include "instructions.h"

/**
 * @brief MainWindow constructor
 * @param parent is the QWidget parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowTitle("Defeat the Dragons Game");
    this->setStyleSheet("background-color: #66CCCC");

    // Sets the labels
    welcome = new QLabel("Defeat the Dragons!");
    welcome->setStyleSheet("font-family: Consolas;font: 22pt; color: red;");

    QSpacerItem* horizontal_space = new QSpacerItem(50,20);

    difficulty = new QLabel("Difficulty Level: ");
    difficulty->setStyleSheet("font-family: Consolas; font: 14pt;");

    // Sets the radio buttons and the push buttons
    easy = new QRadioButton("Easy (Squire)");
    easy->setChecked(true);
    easy->setStyleSheet("font-family: Consolas; font: 12pt");
    medium = new QRadioButton("Medium (Knight)");
    medium->setStyleSheet("font-family: Consolas;font: 12pt");
    hard = new QRadioButton("Hard (Dragon Slayer)");
    hard->setStyleSheet("font-family: Consolas; font: 12pt");

    start = new QPushButton("START GAME");
    start->setMinimumWidth(250);
    start->setStyleSheet("padding: 5px; font: 20pt; color: red; font-family: Courier New; font-weight: bold");
    instruction = new QPushButton("Instructions");
    instruction->setMinimumWidth(200);
    instruction->setStyleSheet("padding: 3px; font: 14pt; color:white; font-family: Courier New");

    // Adds the labels, radio buttons, and push buttons to the layout
    layout = new QVBoxLayout;
    layout->addSpacerItem(horizontal_space);
    layout->addWidget(welcome);
    layout->addSpacerItem(horizontal_space);
    layout->addWidget(difficulty);
    layout->addWidget(easy);
    layout->addWidget(medium);
    layout->addWidget(hard);
    layout->addSpacerItem(horizontal_space);

    layout->addWidget(start);
    layout->setAlignment(start, Qt::AlignHCenter);
    layout->addSpacerItem(horizontal_space);
    layout->addWidget(instruction);
    layout->setAlignment(instruction, Qt::AlignHCenter);
    layout->addSpacerItem(horizontal_space);

    setFixedSize(375,350);
    layout->setAlignment(Qt::AlignHCenter);

    central = new QWidget;
    central->setLayout(layout);

    this->setCentralWidget(central);
}

/**
 * @brief MainWindow destructor
 */
MainWindow::~MainWindow()
{
}

/**
 * @brief sets the GameBoard
 * @param game_board is the GameBoard that gets passed in
 */
void MainWindow::setGameBoard(GameBoard *game_board)
{
    board = game_board;
    QObject::connect(start, SIGNAL(clicked()), board, SLOT(show()));
}

/**
 * @brief displays the Instructions window
 * @param instructions is the Instructions that gets passed in
 */
void MainWindow::displayInstructions(Instructions *instructions)
{
    instructions_board = instructions;
    QObject::connect(instruction, SIGNAL(clicked()), instructions_board, SLOT(show()));
}

/**
 * @brief closes the Event
 * @param e is the QCloseEvent that gets passed in
 */
void MainWindow::closeEvent(QCloseEvent *e)
{
    e->ignore();
    qwidget->show();
}

/**
 * @brief sets the Quit Widget
 * @param quit_widget is the QuitWidget that gets passed in
 */
void MainWindow::setQuitWidget(QuitWidget* quit_widget)
{
    qwidget = quit_widget;
}
