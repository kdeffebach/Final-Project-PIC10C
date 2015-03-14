#ifndef QUITWIDGET_H
#define QUITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

/**
 * @class QuitWidget
 * @brief The QuitWidget class provides a window to ask the user if they really want to exit the game.
 */

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
