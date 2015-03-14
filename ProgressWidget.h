#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include "gameboard.h"

class GameBoard;

/**
 * @class Progress Widget
 * @brief The ProgressWidget class displays a window after a certain amount of robbers have progressed in the game
 */

class ProgressWidget : public QWidget
{
    Q_OBJECT

    friend class GameBoard;

public:
    explicit ProgressWidget(QWidget *parent = 0);
    ~ProgressWidget();

private:
    QLabel* label; /**< the label with the message that the robbers have progressed a particular amount*/
    QVBoxLayout* layout;

    GameBoard* board; /**< the associated GameBoard widget*/

};

#endif // PROGRESSWIDGET_H
