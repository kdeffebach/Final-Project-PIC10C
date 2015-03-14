#include "instructionswidget.h"

InstructionsWidget::InstructionsWidget(QWidget *parent) : QWidget(parent)
{
    text = new QLabel("You and your clan of adventurers have travelled to a new territory seeking"
                      "fertile land and a new life. The life of a settler is hard and riddled with "
                      "many dangers, including robbers. You must build to protect your land and "
                      "your family before the robbers ransack you."
                    );
    text->setMaximumWidth(600);
    text->setMaximumHeight(600);
    text->setWordWrap(true);
    text->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    how_to_play = new QLabel("How to Play:");
    how_to_play->setStyleSheet("QLabel {font: bold 24px georgia; "
                               "background-color:rgb(218,165,32,150)}");


    text2 = new QLabel("Move around the board with the arrow keys.");
    text2->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    hspace = new QSpacerItem(175,55);
    hspace2 = new QSpacerItem(250,55);

    info = new QHBoxLayout;
    player_image = new QPixmap(":/Images/player.jpg");
    player = new QLabel;
    player->setPixmap(*player_image);
    player->setScaledContents(true);
    player_label = new QLabel("You:");
    player_label->setAlignment(Qt::AlignCenter);
    player->setMaximumSize(55,55);
    player->setMinimumSize(55,55);
    player_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    info->addSpacerItem(hspace);
    info->addWidget(player_label);
    info->addWidget(player);
    info->addSpacerItem(hspace2);
    info->addSpacerItem(hspace2);
    info->addSpacerItem(hspace);

    done = new QPushButton("I'm ready to play");
    done->setStyleSheet("QPushButton {background:goldenrod; font: bold georgia; border: 2px inset black}");

    text3 = new QLabel("The board is covered in squares, and each has a resource and a number associated to it.");
    text3->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    resources = new QLabel("Resources:");
    resources->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    wood = new QHBoxLayout;
    wood_label = new QLabel("wood");
    wood_label->setAlignment(Qt::AlignCenter);
    wood_label->setMaximumWidth(55);
    wood_label->setMinimumWidth(55);
    wood_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 18px}");
    wood_board = new QLabel;
    wood_board->setStyleSheet("QLabel {background-image:url(:/Images/wood_icon.jpg); background-repeat:no repeat}");
    wood_board->setScaledContents(true);
    wood_board->setMaximumSize(55,55);
    wood_board->setMinimumSize(55,55);
    wood_icon = new QLabel;
    wood_icon->setStyleSheet("QLabel {background-image:url(:/Images/wood.jpg); background-repeat:no repeat}");
    wood_icon->setScaledContents(true);
    wood_icon->setMaximumSize(55,55);
    wood_icon->setMinimumSize(55,55);
    wood->addSpacerItem(hspace2);
    wood->addWidget(wood_board);
    wood->addWidget(wood_label);
    wood->addWidget(wood_icon);
    wood->addSpacerItem(hspace2);

    wheat = new QHBoxLayout;
    wheat_label = new QLabel("wheat");
    wheat_label->setAlignment(Qt::AlignCenter);
    wheat_label->setMaximumWidth(55);
    wheat_label->setMinimumWidth(55);
    wheat_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 18px}");
    wheat_board = new QLabel;
    wheat_board->setStyleSheet("QLabel {background-image:url(:/Images/wheat_icon.jpg); background-repeat:no repeat}");
    wheat_board->setScaledContents(true);
    wheat_board->setMaximumSize(55,55);
    wheat_board->setMinimumSize(55,55);
    wheat_icon = new QLabel;
    wheat_icon->setStyleSheet("QLabel {background-image:url(:/Images/wheat.jpg); background-repeat:no repeat}");
    wheat_icon->setScaledContents(true);
    wheat_icon->setMaximumSize(55,55);
    wheat_icon->setMinimumSize(55,55);
    hspace = new QSpacerItem(175,55);
    wheat->addSpacerItem(hspace2);
    wheat->addWidget(wheat_board);
    wheat->addWidget(wheat_label);
    wheat->addWidget(wheat_icon);
    wheat->addSpacerItem(hspace2);


    brick = new QHBoxLayout;
    brick_label = new QLabel("brick");
    brick_label->setAlignment(Qt::AlignCenter);
    brick_label->setMaximumWidth(55);
    brick_label->setMinimumWidth(55);
    brick_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 18px}");
    brick_board = new QLabel;
    brick_board->setStyleSheet("QLabel {background-image:url(:/Images/brick_icon.jpg); background-repeat:no repeat}");
    brick_board->setScaledContents(true);
    brick_board->setMaximumSize(55,55);
    brick_board->setMinimumSize(55,55);
    brick_icon = new QLabel;
    brick_icon->setStyleSheet("QLabel {background-image:url(:/Images/brick.jpg); background-repeat:no repeat}");
    brick_icon->setScaledContents(true);
    brick_icon->setMaximumSize(55,55);
    brick_icon->setMinimumSize(55,55);
    hspace = new QSpacerItem(175,55);
    brick->addSpacerItem(hspace2);
    brick->addWidget(brick_board);
    brick->addWidget(brick_label);
    brick->addWidget(brick_icon);
    brick->addSpacerItem(hspace2);


    ore = new QHBoxLayout;
    ore_label = new QLabel("ore");
    ore_label->setAlignment(Qt::AlignCenter);
    ore_label->setMaximumWidth(55);
    ore_label->setMinimumWidth(55);
    ore_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 18px}");
    ore_board = new QLabel;
    ore_board->setStyleSheet("QLabel {background-image:url(:/Images/ore_icon.jpg); background-repeat:no repeat}");
    ore_board->setScaledContents(true);
    ore_board->setMaximumSize(55,55);
    ore_board->setMinimumSize(55,55);
    ore_icon = new QLabel;
    ore_icon->setStyleSheet("QLabel {background-image:url(:/Images/ore.jpg); background-repeat:no repeat}");
    ore_icon->setScaledContents(true);
    ore_icon->setMaximumSize(55,55);
    ore_icon->setMinimumSize(55,55);
    hspace = new QSpacerItem(175,55);
    ore->addSpacerItem(hspace2);
    ore->addWidget(ore_board);
    ore->addWidget(ore_label);
    ore->addWidget(ore_icon);
    ore->addSpacerItem(hspace2);

    dice_image = new QPixmap(":/Images/dice.jpg");
    dice_label = new QLabel;
    dice_label->setPixmap(*dice_image);
    dice_label->setScaledContents(true);
    dice_label->setMaximumSize(55,55);
    dice_label->setMinimumSize(55,55);
    text4 = new QLabel("In the upper right hand corner there is a pair of dice with a number next to it.");
    text4->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    dice = new QHBoxLayout;
    dice->addWidget(text4);
    dice->addWidget(dice_label);

    text5 = new QLabel("You can collect a resource with the spacebar if the square you're on has a number that "
                       "matches the die roll. You build defenses against the robbers with resources.");
    text5->setWordWrap(true);
    text6 = new QLabel("Press 'v' to build a village (one of each resource), you get 1 point.");
    text7 = new QLabel("Press 'c' to build a city (2 ore and 3 wheat), you get 2 points.");
    text8 = new QLabel("Press 'b' to build a road (one brick and one wood), you get one point for 6 in a row.");
    text5->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    text6->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    text7->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
    text8->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    text9 = new QLabel("You need 13 points before the robbers reach you to win.");
    text9->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(text);
    mainLayout->addWidget(how_to_play);
    mainLayout->addWidget(text2);
    mainLayout->addLayout(info);
    mainLayout->addWidget(text3);
    mainLayout->addWidget(resources);
    mainLayout->addLayout(wood);
    mainLayout->addLayout(wheat);
    mainLayout->addLayout(brick);
    mainLayout->addLayout(ore);
    mainLayout->addLayout(dice);
    mainLayout->addWidget(text5);
    mainLayout->addWidget(text6);
    mainLayout->addWidget(text7);
    mainLayout->addWidget(text8);
    mainLayout->addWidget(text9);
    mainLayout->addWidget(done);

    mainLayout->setSpacing(0);

    this->setLayout(mainLayout);
    this->setMinimumHeight(750);
    this->setMaximumWidth(650);

    QPalette palette;
    palette.setBrush((this->backgroundRole()), QBrush(QPixmap(":/Images/background.jpg")));
    this->setPalette(palette);

    QObject::connect(done, SIGNAL(clicked()), this, SLOT(hide()));
}

InstructionsWidget::~InstructionsWidget()
{

}

