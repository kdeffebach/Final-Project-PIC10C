#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    title = new QLabel("");

    gameMode = new QVBoxLayout;
    mode = new QLabel("Mode");
    mode->setStyleSheet("QLabel {font: bold 24px georgia; background-color:rgb(218,165,32,150); border: 2px inset black}");
    mode->setAlignment(Qt::AlignCenter);
    village = new QRadioButton("Village");
    village->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); font:bold georgia; border: 2px inset black}");
    village->setChecked(true);
    city = new QRadioButton("City");
    city->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); font:bold georgia; border: 2px inset black}");
    //robber = new QRadioButton("Robber");
    //robber->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); font:bold georgia; border: 2px inset black}");

    modeGroup = new QButtonGroup;
    modeGroup->addButton(village);
    modeGroup->addButton(city);
    //modeGroup->addButton(robber);

    gameMode->addWidget(mode);
    gameMode->addWidget(village);
    gameMode->addWidget(city);
    //gameMode->addWidget(robber);

    gameDifficulty = new QVBoxLayout;
    difficulty = new QLabel("Difficulty");
    difficulty->setStyleSheet("QLabel {font: bold 24px georgia; background-color:rgb(218,165,32,150); border: 2px inset black}");
    difficulty->setAlignment(Qt::AlignCenter);
    settler = new QRadioButton("Settler");
    settler->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); border: 2px inset black; font: bold georgia}");
    settler->setChecked(true);
    invader = new QRadioButton("Invader");
    invader->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); border: 2px inset black; font: bold georgia}");
    conquest = new QRadioButton("Conquest");
    conquest->setStyleSheet("QRadioButton {background-color:rgb(218,165,32,150); border: 2px inset black; font: bold georgia}");
    gameDifficulty->addWidget(difficulty);
    gameDifficulty->addWidget(settler);
    gameDifficulty->addWidget(invader);
    gameDifficulty->addWidget(conquest);

    hspace = new QSpacerItem(275,10);

    optionMenu = new QHBoxLayout;
    optionMenu->addLayout(gameMode);
    optionMenu->addLayout(gameDifficulty);
    optionMenu->addSpacerItem(hspace);

    go = new QPushButton("GO!");
    go->setStyleSheet("QPushButton {background-color:rgb(160,82,45); font: bold georgia; border: 2px inset black}");

    instructions = new QPushButton("Instructions");
    instructions->setStyleSheet("QPushButton {background-color:rgb(160,82,45); font: bold georgia; border: 2px inset black}");

    vspace = new QSpacerItem(10,50);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(title);
    mainLayout->addWidget(instructions);
    mainLayout->addLayout(optionMenu);
    mainLayout->addWidget(go);
    mainLayout->addSpacerItem(vspace);

    central = new QWidget;
    central->setLayout(mainLayout);

    this->setCentralWidget(central);
    this->setStyleSheet("QMainWindow {background-image:url(:/Images/title.jpg); background-repeat:no repeat; border:3px solid gold}");
    this->setMinimumSize(600, 500);
    this->setMaximumSize(600, 500);
}
MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *e) {

    e->ignore();
    quit->show();

}

void MainWindow::setQuitWidget(QuitWidget* quit_widget)
{
    quit = quit_widget;
}


void MainWindow::setGameBoard(GameBoard* b)
{
    board = b;
}

void MainWindow::setInstructions(InstructionsWidget* i){

    instructions_widget = i;

    QObject::connect(instructions, SIGNAL(clicked()), instructions_widget, SLOT(show()));

}

int MainWindow::setRobber(){
    if(settler->isChecked()) return 400;
    else if(invader->isChecked()) return 300;
    else if(conquest->isChecked()) return 200;
    else return 350;
}

int MainWindow::setCity(){
    if(city->isChecked()) return 7;
    else if(village->isChecked()) return 3;
    else return 5;
}

int MainWindow::setVillage(){
    if(city->isChecked()) return 3;
    else if(village->isChecked()) return 7;
    else return 5;
}






