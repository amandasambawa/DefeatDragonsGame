/**
 * @brief The QuitWidget class - Contains the widget that asks the user if they want to quit the game
 * @author Amanda Sambawa
 */

#include "quitwidget.h"
#include <QHBoxLayout>

/**
 * @brief QuitWidget constructor
 * @param parent is the QWidget parent
 */
QuitWidget::QuitWidget(QWidget *parent) :
    QWidget(parent)
{
    // Sets the label and push buttons
    quit_label = new QLabel("Are you sure you want to quit?");
    quit_ok = new QPushButton("Quit");
    quit_cancel = new QPushButton("Cancel");

    // Adds the label and the push buttons to the layout
    QHBoxLayout* quit_hlayout = new QHBoxLayout;
    quit_hlayout->addWidget(quit_ok);
    quit_hlayout->addWidget(quit_cancel);

    QVBoxLayout* quit_vlayout = new QVBoxLayout;
    quit_vlayout->addWidget(quit_label);
    quit_vlayout->addLayout(quit_hlayout);

    setFixedSize(200,100);
    this->setLayout(quit_vlayout);

    // If the user clicks Cancel, then does not close all the windows
    QObject::connect(quit_cancel, SIGNAL(clicked()), this, SLOT(hide()));
    // If the user clicks Quit, then closes all the windows
    QObject::connect(quit_ok, SIGNAL(clicked()), this,SLOT(close()));
}

/**
 * @brief QuitWidget destructor
 */
QuitWidget::~QuitWidget()
{ }
