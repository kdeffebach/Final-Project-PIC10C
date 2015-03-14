#ifndef INSTRUCTIONSWIDGET_H
#define INSTRUCTIONSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPixmap>

/**
 * @class InstructionsWidget
 * @brief The InstructionsWidget class provides a set of instructions to the player through the main window.
 */
class InstructionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionsWidget(QWidget* parent = 0);
    ~InstructionsWidget();

    QPushButton* done;

private:
    QLabel* text;

    QLabel* how_to_play;

    QLabel* text2;

    QHBoxLayout* info;

    QPixmap* player_image;
    QLabel* player;
    QLabel* player_label;

    QLabel* text3;
    QLabel* resources;

    QLabel* text4;
    QLabel* dice_label;

    QHBoxLayout* dice;

    QPixmap* dice_image;

    QHBoxLayout* wood;
    QHBoxLayout* wheat;
    QHBoxLayout* brick;
    QHBoxLayout* ore;

    QLabel* wood_board;
    QLabel* wood_icon;
    QLabel* wheat_board;
    QLabel* wheat_icon;
    QLabel* brick_board;
    QLabel* brick_icon;
    QLabel* ore_board;
    QLabel* ore_icon;

    QLabel* wood_label;
    QLabel* wheat_label;
    QLabel* brick_label;
    QLabel* ore_label;

    QLabel* text5;
    QLabel* text6;
    QLabel* text7;
    QLabel* text8;
    QLabel* text9;

    QSpacerItem* hspace;
    QSpacerItem* hspace2;

};

#endif // INSTRUCTIONSWIDGET_H
