#include "progresswidget.h"

ProgressWidget::ProgressWidget(QWidget *parent) : QWidget(parent)
{

    label  = new QLabel("Hurry, they're almost here!");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("QLabel {background-color:rgb(160, 82, 45,150); font: bold georgia 22px}");

    layout = new QVBoxLayout;

    layout->addWidget(label);

    this->setLayout(layout);
    this->setMaximumSize(300,150);
    this->setMinimumSize(300,150);

    QString background_file = ":/Images/background.jpg";
    QPixmap* background_image = new QPixmap(background_file);

    QPalette palette;
    palette.setBrush((this->backgroundRole()), QBrush(*background_image));
    this->setPalette(palette);

    this->hide();
}

ProgressWidget::~ProgressWidget()
{

}

