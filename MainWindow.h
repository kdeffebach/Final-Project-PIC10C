#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QCloseEvent>
#include <QRadioButton>
#include <QPixmap>
#include <QPushButton>
#include <QButtonGroup>
#include <QSpacerItem>
#include "quitwidget.h"
#include "instructionswidget.h"
#include "gameboard.h"

class GameBoard;

/**
 * @class MainWindow
 * @brief The MainWindow class creates and configures the window the user first sees upon launch of the application. It
 *        includes instructions, options for gameplay, and a button to launch the gameboard.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

friend class GameBoard;

public:
    /**
     * @brief MainWindow constructor
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
     * @brief closeEvent is called when close() is called on the MainWindow object
     *        (usually when the user presses the x to close the window as usual)
     * @param e is the internal function call of closeEvent
     */
    void closeEvent(QCloseEvent *e);

    /**
     * @brief setQuitWidget assigns a QuitWidget object to the MainWindow (details in quitwidget.h)
     * @param quit_widget is the QuitWidget object now associated with the MainWindow object
     */
    void setQuitWidget(QuitWidget* quit_widget);

    /**
     * @brief setGameBoard assigns a GameBoard object to be associated to the MainWindow object so that the
     *        GameBoard can be launched from the MainWindow
     * @param b is the GameBoard object to be assigned
     */
    void setGameBoard(GameBoard* b);

    /**
     * @brief setInstructions assigns an InstructionsWidget object to be associated to the MainWindow object so that the
     *        instructions can be viewed from the MainWindow
     * @param i is the InstructionsWidget to be assigned
     */
    void setInstructions(InstructionsWidget* i);

    /**
     * @brief setRobber initializes the GameBoard object with the correct value of robbers for the chosen level
     * @returns an int that determines the number of robbers are introduced to the game before the game is lost (easy is a higher number)
     */
    int setRobber();

    /**
     * @brief setCity initializes the GameBoard object with the correct value for cities to be built for the chosen level
     * @returns an int that determines the number of cities that must be built in order to win the game (easy is a lower number)

     */
    int setCity();

    /**
     * @brief setVillage initializes the GameBoard object with the correvt vaulue for villages to be built for the chosen level
     * @returns an int that determines the number of villages that must be build in order to win the gaem
     */
    int setVillage();

    ~MainWindow();

    QPushButton* go; /**< the button the user presses to launch the GameBoard*/

    QRadioButton* village; /**< sets board for the easier mode (7 villages, 3 cities to win)*/
    QRadioButton* city; /**< sets board for the harder mode (5 cities, 8 villages to win)*/

    QRadioButton* settler; /**< sets board for the easiest mode (500 robbers before game over)*/
    QRadioButton* invader; /**< sets board for the medium mode (400 robbers before game over)*/
    QRadioButton* conquest; /**< sets board for the hardes mode (300 robbers before game over)*/

private:
    GameBoard* board;

    QuitWidget* quit;
    QWidget* central;
    InstructionsWidget* instructions_widget;
    QPixmap* title_pic;

    QLabel* title;

    QVBoxLayout* gameMode;
    QLabel* mode;


    QButtonGroup* modeGroup;

    QVBoxLayout* gameDifficulty;
    QLabel* difficulty;


    QHBoxLayout* optionMenu;

    QSpacerItem* hspace;
    QSpacerItem* vspace;

    QPushButton* instructions;

    QVBoxLayout* mainLayout;
};

#endif // MAINWINDOW_H
