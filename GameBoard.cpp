#include "gameboard.h"

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator (seed);

GameBoard::GameBoard(QWidget *parent, int _robber, int _city, int villages) : QWidget(parent), board_size(10)
{

    robber_level = _robber;
    city_level = _city;
    village_level = villages;

    wall_count = 0;

    point_count = 0;

    road.resize(board_size*board_size);

    road_count = 0;

    for(auto x: road) x = false;

    setFocusPolicy(Qt::FocusPolicy(Qt::StrongFocus));

    top = new QWidget;
    topInfo = new QHBoxLayout;

    QString brick_file = ":/Images/brick_icon.jpg";
    brick_icon = new QPixmap(brick_file);
    brick_count=0;
    brick_label = new QLabel(QString::number(brick_count));
    brick_collected = new QLabel;
    brick_collected->setPixmap(*brick_icon);
    brick_collected->setMaximumSize(50,50);
    brick_collected->setMinimumSize(50,50);
    brick_collected->setScaledContents(true);
    brick_collected->setStyleSheet("QLabel {border: 2px inset black}");
    brick_label->setMaximumSize(15,15);
    brick_label->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    brick_label->setAlignment(Qt::AlignCenter);
    topInfo->addWidget(brick_collected);
    topInfo->addWidget(brick_label);

    QString ore_file = ":/Images/ore_icon.jpg";
    ore_icon = new QPixmap(ore_file);
    ore_collected = new QLabel;
    ore_count=0;
    ore_label = new QLabel(QString::number (ore_count));
    ore_collected->setPixmap(*ore_icon);
    ore_collected->setStyleSheet("QLabel {border: 2px inset black}");
    ore_collected->setMaximumSize(50,50);
    ore_collected->setMinimumSize(50,50);
    ore_collected->setScaledContents(true);
    ore_label->setMaximumSize(15,15);
    ore_label->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    ore_label->setAlignment(Qt::AlignCenter);
    topInfo->addWidget(ore_collected);
    topInfo->addWidget(ore_label);

    QString wood_file = ":/Images/wood_icon.jpg";
    wood_icon = new QPixmap(wood_file);
    wood_collected = new QLabel;
    wood_count=0;
    wood_label = new QLabel(QString::number(wood_count));
    wood_collected->setPixmap(*wood_icon);
    wood_collected->setStyleSheet("QLabel {border: 2px inset black}");
    wood_collected->setMaximumSize(50,50);
    wood_collected->setMinimumSize(50,50);
    wood_collected->setScaledContents(true);
    wood_label->setMaximumSize(15,15);
    wood_label->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    wood_label->setAlignment(Qt::AlignCenter);
    topInfo->addWidget(wood_collected);
    topInfo->addWidget(wood_label);


    QString wheat_file = ":/Images/wheat_icon.jpg";
    wheat_icon = new QPixmap(wheat_file);
    wheat_count=0;
    wheat_label = new QLabel(QString::number(wheat_count));
    wheat_collected = new QLabel;
    wheat_collected->setPixmap(*wheat_icon);
    wheat_collected->setStyleSheet("QLabel {border: 2px inset black}");
    wheat_collected->setMaximumSize(50,50);
    wheat_collected->setMinimumSize(50,50);
    wheat_collected->setScaledContents(true);
    wheat_label->setMaximumSize(15,15);
    wheat_label->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    wheat_label->setAlignment(Qt::AlignCenter);
    topInfo->addWidget(wheat_collected);
    topInfo->addWidget(wheat_label);

    QString robber_file = ":/Images/robber.jpg";
    robber_image = new QPixmap(robber_file);
    army_counter=0;
    army_pic_counter = 0;
    army_label = new QLabel(QString::number(army_counter));
    army_collected = new QLabel;
    army_collected->setPixmap(*robber_image);
    army_collected->setMaximumSize(40,40);
    army_collected->setMinimumSize(40,40);
    army_collected->setScaledContents(true);
    army_label->setMaximumSize(30,30);
    army_label->setMinimumSize(30,30);
    army_label->setAlignment(Qt::AlignCenter);
    army_collected->setHidden(true);
    army_label->setHidden(true);
    topInfo->addWidget(army_collected);
    topInfo->addWidget(army_label);

    village_count = 0;
    city_count = 0;
    road_count = 0;
    villages_built = new QLabel("Villages: "+QString::number(village_count));
    cities_built = new QLabel("Cities: "+QString::number(city_count));
    roads_built = new QLabel("Roads: "+QString::number(city_count));
    villages_built->setMaximumHeight(25);
    cities_built->setMaximumHeight(25);
    roads_built->setMaximumHeight(25);
    villages_built->setMinimumHeight(25);
    cities_built->setMinimumHeight(25);
    roads_built->setMinimumHeight(25);
    villages_built->setMaximumWidth(100);
    cities_built->setMaximumWidth(100);
    roads_built->setMaximumWidth(100);
    villages_built->setMinimumWidth(100);
    cities_built->setMinimumWidth(100);
    roads_built->setMinimumWidth(100);
    villages_built->setAlignment(Qt::AlignCenter);
    cities_built->setAlignment(Qt::AlignCenter);
    roads_built->setAlignment(Qt::AlignCenter);
    villages_built->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    cities_built->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    roads_built->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");

    buildings = new QVBoxLayout;
    buildings->addWidget(villages_built);
    buildings->addWidget(cities_built);
    buildings->addWidget(roads_built);
    buildings->setSpacing(0);

    topInfo->addLayout(buildings);

    point_label = new QLabel("Points: ");
    point_label->setMaximumHeight(25);
    point_label->setMinimumHeight(25);
    point_label->setMaximumWidth(50);
    point_label->setMinimumWidth(50);
    point_label->setAlignment(Qt::AlignCenter);
    point_label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); color:black}");

    point_info = new QLabel(QString::number(point_count));
    point_info->setMaximumSize(15,15);
    point_info->setStyleSheet("QLabel {background-color:rgb(245, 222, 179, 150); color:black}");
    point_info->setAlignment(Qt::AlignCenter);
    topInfo->addWidget(point_label);
    topInfo->addWidget(point_info);

    std::uniform_int_distribution<int> unif(1,12);

    QString dice_file = ":/Images/dice.jpg";
    dice_image = new QPixmap(dice_file);
    dice_int = unif(generator);
    dice_roll = new QLabel(QString::number(dice_int));
    dice_roll->setAlignment(Qt::AlignCenter);
    dice_roll->setMaximumSize(30,30);
    dice_roll->setMinimumSize(30,30);
    dice_roll->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); color:black}");
    dice_pic = new QLabel;
    dice_pic->setPixmap(*dice_image);
    dice_pic->setMaximumSize(40,40);
    dice_pic->setMinimumSize(40,40);
    dice_pic->setScaledContents(true);
    topInfo->addWidget(dice_pic);
    topInfo->addWidget(dice_roll);

    top->setLayout(topInfo);

    board = new QWidget;
    squares = new QLabel*[board_size*board_size];
    values_pics = new QLabel*[board_size*board_size];

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateDice()));
    timer->start(3000);

    board->setFocusPolicy(Qt::StrongFocus);

    grid = new QGridLayout(board);
    grid->setGeometry(QRect());
    grid->setSpacing(0);

    army_grid = new QGridLayout;
    army_grid->setGeometry(QRect());
    army_pic_counter = 0;

    pictures = new int[board_size*board_size];
    values = new int[board_size*board_size];

    QString brick_file2 = ":/Images/brick.jpg";
    brick_image = new QPixmap(brick_file2);
    QString ore_file2 = ":/Images/ore.jpg";
    ore_image = new QPixmap(ore_file2);
    QString wood_file2 = ":/Images/wood.jpg";
    wood_image = new QPixmap(wood_file2);
    QString wheat_file2 = ":/Images/wheat.jpg";
    wheat_image = new QPixmap(wheat_file2);
    QString ocean_file = ":/Images/ocean.jpg";
    ocean_image = new QPixmap(ocean_file);
    QString redsquare_file = ":/Images/redsquare.jpg";
    redsquare_image = new QPixmap(redsquare_file);
    QString wall_file = ":/Images/walls.jpg";
    wall_image = new QPixmap(wall_file);
    QString desert_file = ":/Images/desert.jpg";
    desert_image = new QPixmap(desert_file);

    wall_grid = new QGridLayout;
    wall_grid->setGeometry(QRect());
    wall_grid->setSpacing(0);
    wall_grid->setSizeConstraint(QLayout::SetMinAndMaxSize);

    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {
            int rand_value_pic = qrand() % 5;
            int rand_value_dice = unif(generator);
            squares[i*board_size+j] = new QLabel;
            squares[i*board_size+j]->setMinimumSize(55,55);
            squares[i*board_size+j]->setMaximumSize(55,55);
            squares[i*board_size+j]->setFrameStyle(0);
            squares[i*board_size+j]->setScaledContents(true);
            squares[i*board_size+j]->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

            values_pics[i*board_size+j] = new QLabel;

            if(i==0 && (j==0 || j==1 || j==8 || j==9)){
                if(j==1){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-bottom: 2px solid black;"
                                                           "border-right: 2px solid black}");

                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else if(j==8){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-bottom: 2px solid black;"
                                                           "border-left: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else{
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center}");
                }
                squares[i*board_size+j]->setScaledContents(true);
                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else if(i==1 && (j==0 || j==9)){
                if(j==0){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-right: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else if(j==9){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-left: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                squares[i*board_size+j]->setScaledContents(true);
                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else if(i==8 && (j==0 || j==9)){
                if(j==0){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-right: 2px solid black}");
                }
                else if(j==9){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-left: 2px solid black}");
                }
                squares[i*board_size+j]->setMaximumSize(53,53);
                squares[i*board_size+j]->setMinimumSize(53,53);
                squares[i*board_size+j]->setScaledContents(true);
                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else if(i==9 && (j==0 || j==1 || j==8 || j==9)){
                if(j==1){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-top: 2px solid black;"
                                                           "border-right: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else if(j==8){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-top: 2px solid black;"
                                                           "border-left: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else{
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center}");
                }

                squares[i*board_size+j]->setScaledContents(true);
                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else if(i==2 && (j==0 || j==9)){
                if(j==0){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-right: 2px solid black;"
                                                           "border-bottom: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,52);
                    squares[i*board_size+j]->setMinimumSize(53,52);
                }
                else if(j==9){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-left: 2px solid black;"
                                                           "border-bottom: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,52);
                    squares[i*board_size+j]->setMinimumSize(53,52);
                }

                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else if(i==7 && (j==0 || j==9)){
                if(j==0){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-right: 2px solid black;"
                                                           "border-top: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }
                else if(j==9){
                    squares[i*board_size+j]->setStyleSheet("QLabel {color: black;"
                                                           "background-image:url(:/Images/ocean.jpg); "
                                                           "background-repeat: no-repeat;"
                                                           "background-position: center;"
                                                           "border-left: 2px solid black;"
                                                           "border-top: 2px solid black}");
                    squares[i*board_size+j]->setMaximumSize(53,53);
                    squares[i*board_size+j]->setMinimumSize(53,53);
                }

                grid->addWidget(squares[i*board_size+j],i,j);
                pictures[i*board_size+j]=6;
            }

            else{
                if(rand_value_pic==0){
                    squares[i*board_size+j]->setPixmap(*brick_image);
                    values_pics[i*board_size+j]->setText(QString::number(rand_value_dice));
                    values_pics[i*board_size+j]->setAlignment(Qt::AlignCenter);
                    values_pics[i*board_size+j]->setMaximumSize(15,15);
                    values_pics[i*board_size+j]->setMinimumSize(15,15);
                    values_pics[i*board_size+j]->setStyleSheet("QLabel {background-color:rgb(112, 128, 144); color:black}");
                    grid->addWidget(squares[i*board_size+j], i, j);
                    grid->addWidget(values_pics[i*board_size+j], i, j, Qt::AlignBottom|Qt::AlignHCenter);
                }

                else if(rand_value_pic==1){
                    squares[i*board_size+j]->setPixmap(*ore_image);
                    values_pics[i*board_size+j]->setText(QString::number(rand_value_dice));
                    values_pics[i*board_size+j]->setAlignment(Qt::AlignCenter);
                    values_pics[i*board_size+j]->setMaximumSize(15,15);
                    values_pics[i*board_size+j]->setMinimumSize(15,15);
                    values_pics[i*board_size+j]->setStyleSheet("QLabel {background-color:rgb(112, 128, 144); color:black}");
                    grid->addWidget(squares[i*board_size+j], i, j);
                    grid->addWidget(values_pics[i*board_size+j], i, j, Qt::AlignBottom|Qt::AlignHCenter);
                }

                else if(rand_value_pic==2){
                    squares[i*board_size+j]->setPixmap(*wood_image);
                    values_pics[i*board_size+j]->setText(QString::number(rand_value_dice));
                    values_pics[i*board_size+j]->setAlignment(Qt::AlignCenter);
                    values_pics[i*board_size+j]->setMaximumSize(15,15);
                    values_pics[i*board_size+j]->setMinimumSize(15,15);
                    values_pics[i*board_size+j]->setStyleSheet("QLabel {background-color:rgb(112, 128, 144); color:black}");
                    grid->addWidget(squares[i*board_size+j], i, j);
                    grid->addWidget(values_pics[i*board_size+j], i, j, Qt::AlignBottom|Qt::AlignHCenter);
                }

                else if(rand_value_pic==3){
                    squares[i*board_size+j]->setPixmap(*wheat_image);
                    values_pics[i*board_size+j]->setText(QString::number(rand_value_dice));
                    values_pics[i*board_size+j]->setAlignment(Qt::AlignCenter);
                    values_pics[i*board_size+j]->setMaximumSize(15,15);
                    values_pics[i*board_size+j]->setMinimumSize(15,15);
                    values_pics[i*board_size+j]->setStyleSheet("QLabel {background-color:rgb(112, 128, 144); color:black}");
                    grid->addWidget(squares[i*board_size+j], i, j);
                    grid->addWidget(values_pics[i*board_size+j], i, j, Qt::AlignBottom|Qt::AlignHCenter);
                }

                else if(rand_value_pic==4){
                    squares[i*board_size+j]->setPixmap(*desert_image);
                    values_pics[i*board_size+j]->setText(QString::number(0));
                    values_pics[i*board_size+j]->setAlignment(Qt::AlignCenter);
                    values_pics[i*board_size+j]->setMaximumSize(15,15);
                    values_pics[i*board_size+j]->setMinimumSize(15,15);
                    values_pics[i*board_size+j]->setStyleSheet("QLabel {background-color:rgb(112, 128, 144); color:black}");
                    grid->addWidget(squares[i*board_size+j], i, j);
                    grid->addWidget(values_pics[i*board_size+j], i, j, Qt::AlignBottom|Qt::AlignHCenter);}

                pictures[i*board_size+j]=rand_value_pic;
                values[i*board_size+j]=rand_value_dice;
                values_pics[i*board_size+j]->setParent(squares[i*board_size+j]);
            }

        }
    }

    QString player_file = ":/Images/player.jpg";
    player_image = new QPixmap(player_file);
    player_position = new QPoint(2,0);
    squares[2]->setPixmap(*player_image);
    squares[0]->setScaledContents(true);

    board->setFixedSize(558,558);

    setFixedSize(600,750);

    QVBoxLayout* piece_together = new QVBoxLayout;

    piece_together->addLayout(army_grid);
    piece_together->addWidget(top);
    piece_together->addLayout(wall_grid);
    piece_together->addWidget(board);
    piece_together->setSpacing(5);

    this->setLayout(piece_together);
    this->setStyleSheet("QLabel {background-color: black; color: white}");

    QString background_file = ":/Images/background.jpg";
    background_image = new QPixmap(background_file);

    QPalette palette;
    palette.setBrush((this->backgroundRole()), QBrush(*background_image));
    this->setPalette(palette);

    this->setWindowTitle("SETTLERS");
}


GameBoard::~GameBoard()
{
    delete [] pictures;
    delete [] player_position;
    delete [] values;
}

void GameBoard::setMainWindow(MainWindow* mw)
{
    mainWindow = mw;
}

void GameBoard::setQuitWidget(QuitWidget *quit_widget)
{
    quit = quit_widget;
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    int x = player_position->rx();
    int y = player_position->ry();

    switch (event->key()) {
    case Qt::Key_Left:
        if(x != 0)
            movePlayer(x,y,x-1,y);

        break;
    case Qt::Key_Right:
        if(x != board_size-1)
            movePlayer(x,y,x+1,y);

        break;
    case Qt::Key_Up:
        if(y != 0)
            movePlayer(x,y,x,y-1);

        break;
    case Qt::Key_Down:
        if(y != board_size-1)
            movePlayer(x,y,x,y+1);

        break;

    case Qt::Key_Space:
        collectResource(x,y);
        break;

    case Qt::Key_V:
        buildVillage();
        break;

    case Qt::Key_C:
        buildCity();
        break;

    case Qt::Key_B:
        buildRoad();
        break;

    default:
        QWidget::keyPressEvent(event);
    }

    QCoreApplication::processEvents();
    repaint();

    return;
}

bool GameBoard::collectResource(int x, int y)
{
    if(dice_int==values[y*board_size+x]){
        if(pictures[y*board_size+x]==0) ++brick_count;
        else if(pictures[y*board_size+x]==1) ++ore_count;
        else if(pictures[y*board_size+x]==2) ++wood_count;
        else if(pictures[y*board_size+x]==3) ++wheat_count;
        else;
        afterCollection(true);
        return true;
    }
    else{
        afterCollection(false);
        return false;
    }

    repaint();
    QCoreApplication::processEvents();

}

void GameBoard::afterCollection(bool flag){
    int x = player_position->rx();
    int y = player_position->ry();

    int current_pic = pictures[y*board_size+x];

    if(flag){
        squares[y*board_size+x]->clear();
        pictures[y*board_size+x]=5;
    }

    else{
        squares[y*board_size+x]->clear();
        if(current_pic == 0) squares[y*board_size+x]->setPixmap(*brick_image);
        else if(current_pic == 1) squares[y*board_size+x]->setPixmap(*ore_image);
        else if(current_pic == 2) squares[y*board_size+x]->setPixmap(*wood_image);
        else if(current_pic == 3) squares[y*board_size+x]->setPixmap(*wheat_image);
        else if(current_pic == 4) squares[y*board_size+x]->setPixmap(*desert_image);
    }

    QCoreApplication::processEvents();
    update();

    return;

}

void GameBoard::movePlayer(int px, int py, int nx, int ny)
{
    int current_pic = pictures[py*board_size+px];
    squares[py*board_size+px]->clear();

    if(current_pic==0)
        squares[py*board_size+px]->setPixmap(*brick_image);
    else if(current_pic==1)
        squares[py*board_size+px]->setPixmap(*ore_image);
    else if(current_pic==2)
        squares[py*board_size+px]->setPixmap(*wood_image);
    else if(current_pic==3)
        squares[py*board_size+px]->setPixmap(*wheat_image);
    else if(current_pic==4)
        squares[py*board_size+px]->setPixmap(*desert_image);
    else if(current_pic==5)
        squares[py*board_size+px]->setPixmap(*redsquare_image);
    else if(current_pic==6)
        squares[py*board_size+px]->setPixmap(*ocean_image);

    if(px==2 && (py==0 ||py==9)){
        if(nx<px) nx=px;
    }
    else if(px==1 && py==1){
        if(nx<px) nx=px;
        if(ny<py) ny=py;
    }
    else if(px==1 && (py==2 || py==7)){
        if(nx<px) nx=px;
    }
    else if(px==1 && py==8){
        if(nx<px) nx=px;
        if(ny>py) ny=py;
    }
    else if(px==7 && (py==0 || py==9)){
        if(nx>px) nx=px;
    }
    else if(px==8 && (py==2 || py==7)){
        if(nx>px) nx=px;
    }
    else if(px==8 && py==1){
        if(nx>px) nx=px;
        if(ny<py) ny=py;
    }
    else if(px==8 && py==8){
        if(nx>px) nx=px;
        if(ny>py) ny=py;
    }
    else if(py==6 && (px==0 || px==9)){
        if(ny>py) ny=py;
    }
    else if(py==3 && (px==0 || px==9)){
        if(ny<py) ny=py;
    }

    player_position->setX(nx);
    player_position->setY(ny);

    return;

}

void GameBoard::closeEvent(QCloseEvent *event){
    if(army_counter==350){
        QWidget* sorry = new QWidget;
        QLabel* text = new QLabel("The robbers overpowered you and your village. They will plunder all and "
                                  "save none. Thus is the life of a settler. Better luck next time.");
        text->setWordWrap(true);
        text->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
        QLabel* pic = new QLabel;
        pic->setPixmap(QPixmap(":/Images/sorry.png"));

        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(pic);
        layout->addWidget(text);

        QPalette palette1;
        palette1.setBrush((sorry->backgroundRole()), QBrush(*background_image));
        sorry->setPalette(palette1);

        sorry->setLayout(layout);
        sorry->show();
    }
    else if (point_count>=5){
        QWidget* congrats = new QWidget;
        QLabel* text2 = new QLabel("You have successfully defended your clan and your village. The robbers will have to "
                                  "steal from someone else today. Good Job. "
                                  "But they'll be back, count on that.");
        text2->setWordWrap(true);
        text2->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");
        QVBoxLayout* layout2 = new QVBoxLayout;
        QLabel* pic = new QLabel;
        pic->setPixmap(QPixmap(":/Images/winner.jpg"));

        layout2->addWidget(pic);
        layout2->addWidget(text2);
        congrats->setLayout(layout2);

        QPalette palette2;
        palette2.setBrush((congrats->backgroundRole()), QBrush(*background_image));
        congrats->setPalette(palette2);

        congrats->show();
    }

}

void GameBoard::paintEvent(QPaintEvent *event) {

    int x = player_position->rx();
    int y = player_position->ry();

    squares[y*board_size+x]->setPixmap(*player_image);

    brick_label->clear();
    brick_label->setText(QString::number(brick_count));
    ore_label->clear();
    ore_label->setText(QString::number(ore_count));
    wood_label->clear();
    wood_label->setText(QString::number(wood_count));
    wheat_label->clear();
    wheat_label->setText(QString::number(wheat_count));
    roads_built->clear();
    roads_built->setText(("Roads:"+QString::number(road_count)));

    int rand_num = qrand()%50;
    if(rand_num%13==0 && rand_num%17 == 0 && rand_num%23==0 && rand_num%2==0){
        ++army_counter;
    }

    dice_roll->clear();
    dice_roll->setText(QString::number(dice_int));

    for(int i=0;i<board_size;++i) {
        for(int j=0;j<board_size;++j) {
            if(dice_int!=values[i*board_size+j] || pictures[i*board_size+j]==4) values_pics[i*board_size+j]->setHidden(true);
            else{
                if(values_pics[i*board_size+j])
                    values_pics[i*board_size+j]->setVisible(true);
            }
        }
    }

    if(army_counter%20==0 && army_counter>0){
        army_pic = new QLabel;
        army_pic->setPixmap(*robber_image);
        army_pic->setMaximumSize(30,30);
        army_pic->setMinimumSize(30,30);
        army_pic->setScaledContents(true);
        army_grid->addWidget(army_pic, 1, army_counter/20);
        ++army_pic_counter;
    }

    if(army_counter%50==0 && army_counter>0){
        timer->stop();
        progress->label->setText("Hurry! They're "+QString::number((double)army_counter/(double)robber_level *100)+"% here!");
        progress->setAttribute(Qt::WA_ShowWithoutActivating);
        QTimer* timer1 = new QTimer;
        connect(timer1, SIGNAL(timeout()), progress, SLOT(close()));
        timer1->start(5000);
        progress->setGeometry(600, 250, 200, 150);
        progress->show();
        runTimer();
    }

    point_info->clear();
    point_info->setText(QString::number(point_count));

    army_label->clear();
    army_label->setText(QString::number(army_counter));

    if(army_counter==350 || point_count==5) this->close();
}

void GameBoard::buildVillage()
{
    if(brick_count>=1 && ore_count >= 1 && wheat_count>=1 && wood_count>=1){
        ++village_count;
        villages_built->setText("Villages:"+QString::number(village_count));
        --brick_count;
        --wood_count;
        --wheat_count;
        --ore_count;
        buildWalls(1);
        ++point_count;
    }

    else;

    repaint();
    QCoreApplication::processEvents();

    return;
}

void GameBoard::buildCity(){
    if(wheat_count>=3 && ore_count>=2){
        ++city_count;
        ++village_count;
        cities_built->setText("Cities: "+QString::number(city_count));
        wheat_count-=3;
        ore_count-=2;
        buildWalls(2);
        point_count+=2;
    }

    else;

    repaint();
    QCoreApplication::processEvents();

    return;
}

void GameBoard::updateDice(){

    std::uniform_int_distribution<int> unif(1,12);

    dice_int = unif(generator);

    repaint();
    QCoreApplication::processEvents();

    return;
}

void GameBoard::setProgressWidget(ProgressWidget *progress_widget){
    progress = progress_widget;
}

void GameBoard::runTimer(){
    timer->start();
}

void GameBoard::buildWalls(int num){

    int c=0;
    while(c<num){
        QLabel* new_label = new QLabel;
        new_label->setPixmap(*wall_image);
        new_label->setMinimumSize(40,40);
        new_label->setMaximumSize(40,40);
        new_label->setFrameStyle(3);
        new_label->setScaledContents(true);
        wall_grid->addWidget(new_label, 0, wall_count);
        ++wall_count;
        ++c;
    }

    repaint();
    QCoreApplication::processEvents();

    return;

}

void GameBoard::buildRoad(){
    int x = player_position->rx();
    int y = player_position->ry();

    if(brick_count>=1 && wood_count>= 1){
        road[y*board_size+x] = true;
        squares[y*board_size+x]->setFrameStyle(QFrame::Box | QFrame::Raised);
        squares[y*board_size+x]->setLineWidth(6);
        --wood_count;
        --brick_count;
    }

    if(y>0 && x>0){
        if(road.at((y-1)*board_size+x)&&road.at(y*board_size+x)) ++road_count;
        else if(road.at(y*board_size+(x-1))&&road.at(y*board_size+x)) ++road_count;
    }
    else if(y<board_size && x<board_size){
        if(road.at(y*board_size+x)&&road.at((y+1)*board_size+x)) ++road_count;
        else if(road.at(y*board_size+x)&&road.at(y*board_size+(x+1))) ++road_count;
    }

    if(road_count%5==0 && road_count>0){
        ++point_count;
        road_count=0;
    }

    repaint();
    QCoreApplication::processEvents();
}
