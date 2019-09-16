/**
 * @brief The WinWidget class - Contains the widget that shows the user they have won the game
 * @author Amanda Sambawa
 */

#ifndef WINWIDGET_H
#define WINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class WinWidget : public QWidget
{
public:
    explicit WinWidget(QWidget *parent = 0);
    ~WinWidget();

    QPushButton* ok;

private:
    QLabel* win_label;
};

#endif // WINWIDGET_H
