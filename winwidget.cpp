/**
 * @brief The WinWidget class - Contains the widget that shows the user they have won the game
 * @author Amanda Sambawa
 */

#include "winwidget.h"
#include <QHBoxLayout>

/**
 * @brief WinWidget constructor
 * @param parent is the QWidget parent
 */
WinWidget::WinWidget(QWidget *parent) :
    QWidget(parent)
{
    // Sets the label and push button
    win_label = new QLabel("Congratulations! You won!");
    win_label->setStyleSheet("font: 14pt");
    ok = new QPushButton("OK");

    // Adds the label and push button to the layout
    QVBoxLayout* win_layout = new QVBoxLayout;
    win_layout->addWidget(win_label);
    win_layout->addWidget(ok);

    setFixedSize(300,100);
    this->setLayout(win_layout);

    // If the user clicks ok push button, will close the windows
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));
}

/**
 * @brief WinWidget destructor
 */
WinWidget::~WinWidget()
{ }



