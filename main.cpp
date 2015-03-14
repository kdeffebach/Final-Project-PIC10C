#include "mainwindow.h"
#include "quitwidget.h"
#include "gameboard.h"
#include "progresswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;

    int _robber = w->setRobber();
    int _city = w->setCity();
    int _village = w->setVillage();

    GameBoard* b = new GameBoard(0, _robber, _city, _village);

    QuitWidget* qwidget = new QuitWidget;
    InstructionsWidget* iwidget = new InstructionsWidget;
    ProgressWidget* pwidget = new ProgressWidget;
    w->setQuitWidget(qwidget);
    w->setInstructions(iwidget);

    b->setProgressWidget(pwidget);

    b->setMainWindow(w);
    w->setGameBoard(b);

    QObject::connect(w->go, SIGNAL(clicked()), b, SLOT(show()));

    QObject::connect(qwidget->quit_ok, SIGNAL(clicked()), &a, SLOT(quit()));

    w->show();

    return a.exec();
}
