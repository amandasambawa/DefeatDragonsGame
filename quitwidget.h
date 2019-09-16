/**
 * @brief The QuitWidget class - Contains the widget that asks the user if they want to quit the game
 * @author Amanda Sambawa
 */
#ifndef QUITWIDGET_H
#define QUITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class QuitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuitWidget(QWidget *parent = 0);
    ~QuitWidget();

    QPushButton* quit_ok;

private:
    QLabel* quit_label;
    QPushButton* quit_cancel;

};

#endif // QUITWIDGET_H
