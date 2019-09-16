/**
 * @brief The LoseWidget class - Contains the widget that shows the user they have lost the game
 * @author Amanda Sambawa
 */

#include "losewidget.h"
#include <QHBoxLayout>

/**
 * @brief LoseWidget constructor
 * @param parent is the QWidget parent
 */
LoseWidget::LoseWidget(QWidget* parent) :
    QWidget(parent)
{
    // Sets the label and push button
    lose_label = new QLabel("Sorry, you lost.");
    lose_label->setStyleSheet("font: 14pt");
    ok = new QPushButton("OK");

    // Adds the label and push button to the layout
    QVBoxLayout* lose_layout = new QVBoxLayout;
    lose_layout->addWidget(lose_label);
    lose_layout->addWidget(ok);

    setFixedSize(200,100);
    this->setLayout(lose_layout);

    // If the user clicks the ok push button, will close the windows
    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));
}

/**
 * @brief LoseWidget destructor
 */
LoseWidget::~LoseWidget()
{ }


