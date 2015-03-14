#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class MainWindow;

#include <QDebug>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QWidget>
#include <QCloseEvent>
#include <QCoreApplication>
#include <vector>
#include <QObject>
#include <QLabel>
#include <QTimer>
#include <random>
#include <QGridLayout>
#include <QPalette>
#include <chrono>
#include <QString>
#include <ctime>
#include <iostream>
#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QSpacerItem>
#include <QStackedWidget>
#include "quitwidget.h"
#include "mainwindow.h"
#include "progresswidget.h"

class MainWindow; //forward declaration
class ProgressWidget; //forward declaration
class TradeWidget; //forward declaration

/**
 * @class GameBoard
 * @brief The GameBoard class is the main center of gameplay. Contains a grid board on which the player moves around trying to collect resources: wood, wheat
 *ore or brick. Each of the squares on the grid board has a resource and a number associated to it. The player can collect the resource by pressing the
 * spacebar if the die roll matches the number on the square they are trying to collect. If it is a valid collection the count of that particular
 * resource increases.
 * The player can build three different structures with the resources: villages, cities, or roads. A village is worth one point, a city is worth two points,
 * and 5 roads in a row is worth one point. The player needs 10 points to win on settler difficulty, 12 on invader difficulty, and 15 on conquest difficulty.
 * Villages cost one of each resource, roads cost one brick and one wood, and cities cost two ore and one wheat. The player builds a road by pressing 'b', a
 * village by pressing 'v' and a city by pressing 'c'.
 * While the player is trying to build structures, a random number generator determines when robbers are added to the count, and if the robbers get to a
 * certain count (300,400,500) for the different levels before the player gets the required number of points the game is over and the player loses. If the
 * player earns the required amount of points before the number of robbers is breached they win.
 */

class GameBoard : public QWidget
{
    Q_OBJECT

friend class MainWindow;
friend class ProgressWidget;
friend class TradeWidget;

public slots:
    void updateDice();

public:

    /**
     * @brief GameBoard constructor, builds the main game play screen with the board for play and a top bar of information for the player
     * @param parent is set to 0 since it should be its own independent widget
     * @param robbers is the amount of robbers present before the game is over
     * @param cities is the amount of cities to be built before the player can win
     * @param villages is the amount of cities to be built before the player can win
     * NOTE: the game is over when either robbers is reached or the required amount of cities and villages are built.
     */
    explicit GameBoard(QWidget *parent = 0, int robbers = 400, int cities = 5, int villages = 5);
    ~GameBoard();

    /**
     * @brief setMainWindow asssigns a given MainWindow to be associated to the GameBoard Widget.
     * @param main_window is the widndow to be assigned
     */
    void setMainWindow(MainWindow* main_window);

    /**
     * @brief setQuitWidget assigns a given QuitWidget to be associated to the GameBoard Widget.
     * @param quit_widget is the quit widget to be assigned
     */
    void setQuitWidget(QuitWidget* quit_widget);

    /**
     * @brief keyPressEvent dictates what happens when the user presses the space bar and arrow, c, or v keys. This will call the
     * movePlayer, buildVillage, or collectResource functions.
     * @param event is the internal call after the user presses a key
     */
    void keyPressEvent(QKeyEvent* event);

    /**
     * @brief paintEvent updates the GameBoard widget with the latest information like where the player is on the board, what the counts
     * are for buildings or resources, how many robbers have advanced and should be shown, and how many walls are up.
     * @param event is the internal call each time repaint() is called
     */
    void paintEvent(QPaintEvent *event);

    /**
     * @brief closeEvent is called when close() is called on the GameBoard object, it displays either a congratulations screen or a
     * sorry screen.
     * @param event is the internal function call when close() is called;
     */
    void closeEvent(QCloseEvent* event);

    /**
     * @brief collectResource determines whether the player is allowed to collect the resource on the current square. Called when the
     * space bar is pressed in KeyPressEvent. A resource can be collected if the number associated with the square in the constructor
     * matches the current value of the die roll.
     * @param x is the x coordinate of the current square
     * @param y is the y coordinate of the current square
     * @return true if the resource can be collected, false otherwise.
     */
    bool collectResource(int x, int y);

    /**
     * @brief afterCollection updates the square after the resource square has been collected (or tried to be collected). It paints the
     * square red if it was collected and back to its original resource if it wasn't.
     * @param flag is set in collectResource, true if the square was collected and false if it wasn't.
     */
    void afterCollection(bool flag);

    /**
     * @brief movePlayer moves the player from the current position to the new position. Called in the keyPressEvent when an
     * arrow key is pressed.
     * @param px is the current x coordinate of the player
     * @param py is the current y value of the player
     * @param nx is the new x coordinate of the player
     * @param ny is the new y coordinate of the player
     */
    void movePlayer(int px, int py, int nx, int ny);

    /**
     * @brief buildVillage is called in the KeyPressEvent when the v key is pressed. It checks to see if the player has enough resources
     * to build a village (one of each resource) and proceeds accordingly. If there are adequate resources a village is added and the
     * resources are deducted from their respective counts.
     */
    void buildVillage();

    /**
     * @brief buildCity is called in the KeyPressEvent when the c key is pressed. It checks to see if the player has enough resources
     * to build a city (two ore and three wheat) and proceeds accordingly. If there are adequate resources a city is added and the
     * resources are deducted from their respective counts.
     */
    void buildCity();

    /**
     * @brief buildRoad is called in the KeyPressEvent when the b key is pressed. It checks to see if the player has enough resources
     * to build a road (one brick and one wood) and proceeds accordingly. If there are adequate resources a road is built and the
     * resources are deducted from their respective counts.
     */
    void buildRoad();

    /**
     * @brief runTimer starts the timer after it is stopped.
     */
    void runTimer();

    /**
     * @brief setProgressWidget asssigns a given ProgressWidget to be associated to the GameBoard Widget.
     * @param p is the widget to be assigned.
     */
    void setProgressWidget(ProgressWidget* p);

    /**
     * @brief buildWalls adds labels of walls to the gameboard in order to show the player their progress against the robbers.
     * @param num is the number of walls to be built. 2 for a city and 1 for a village.
     */
    void buildWalls(int num);

private:
    unsigned int robber_level; /**< sets the number of robbers necessary to lose*/
    unsigned int village_level;
    unsigned int city_level;

    QLabel* dice_roll; /**< displays the current roll of the die*/
    QLabel* dice_pic;

    QPixmap* robber_image;
    QPixmap* player_image;
    QPixmap* ore_icon;
    QPixmap* wheat_icon;
    QPixmap* wood_icon;
    QPixmap* brick_icon;
    QPixmap* dice_image;

    QPixmap* ore_image;
    QPixmap* wheat_image;
    QPixmap* wood_image;
    QPixmap* brick_image;
    QPixmap* ocean_image;
    QPixmap* desert_image;
    QPixmap* redsquare_image;
    QPixmap* background_image;
    QPixmap* wall_image;

    QLabel* brick_collected; /**< lets the player know how much brick they have*/
    QLabel* ore_collected;/**< lets the player know how much ore they have*/
    QLabel* wheat_collected;/**< lets the player know how much wheat they have*/
    QLabel* wood_collected; /**< lets the player know how much wood they have*/
    QLabel* army_collected;

    QGridLayout* grid; /**< creates a grid to organize the gameboard*/

    unsigned int ore_count; /**< keeps track of how much ore has been collected*/
    unsigned int wheat_count;/**< keeps track of how much wheat has been collected*/
    unsigned int wood_count; /**< keeps track of how much wood has been collected*/
    unsigned int brick_count; /**< keeps track of how much brick has been collected*/
    unsigned int wall_count; /**< keeps track of how many walls have been built (for villages or cities)*/

    QLabel* villages_built;
    QLabel* cities_built;
    QLabel* roads_built;
    unsigned int  village_count; /**< counts how many villages have been built*/
    unsigned int city_count; /**< counts how many cities have been built*/
    unsigned int road_count; /**< counts how many roads have been built*/

    QLabel* point_label;
    QLabel* point_info;/**< displays the number of points*/
    int point_count;/**< counts the number of points accrued*/

    QVBoxLayout* buildings;

    QWidget* top;

    QHBoxLayout* topInfo;/**< stores information for the player*/

    QWidget* board;/**< makes the main gameplay widget*/
    int board_size;
    QLabel** squares;/**< stores label information for the squares on the board widget*/
    int* pictures; /**< stores resource information for the board*/
    int* values; /**< stores the values corresponding to the die roll on the squares*/
    QLabel** values_pics; /**< stores the labels with the die roll information on them for the game board*/

    int dice_int; /**< gives the current roll of the die*/

    int army_counter;/**< keeps track of how many robbers have been generated*/
    int army_pic_counter;
    QGridLayout* army_grid; /**< stores the robber pictures at the top of the window*/
    QLabel* army_pic;

    QPoint* player_position;

    QLabel* brick_label;/**< displays the count of bricks*/
    QLabel* wood_label; /**< displays the count of wood*/
    QLabel* wheat_label; /**< displays the count of wheat*/
    QLabel* ore_label; /**< displays the count of ore*/
    QLabel* army_label;

    QGridLayout* wall_grid; /**< stores the pictures of the defenses at the top of the window*/

    ProgressWidget* progress; /**< the progress widget associated for the gameboard widget*/

    QTimer* timer; /**< the timer that rolls the die*/

    std::vector<bool> road; /**< a vector of bools that keeps track of which squares have been made into a road*/

    QuitWidget* quit; /**< the quit widget associated to the gameboard widget*/
    MainWindow* mainWindow; /**< the MainWindow associtaed to the gameboard widget*/
};

#endif // GAMEBOARD_H

