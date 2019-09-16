/**
 * @brief The LoseWidget class - Contains the widget that shows the user they have lost the game
 * @author Amanda Sambawa
 */

#ifndef LOSEWIDGET_H
#define LOSEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class LoseWidget : public QWidget
{
public:
    explicit LoseWidget(QWidget *parent = 0);
    ~LoseWidget();

    QPushButton* ok;

private:
    QLabel* lose_label;
};



#endif // LOSEWIDGET_H
