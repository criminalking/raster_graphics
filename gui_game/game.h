#include <QWidget>
#include <QString>
#include "ui_game.h"
#include "my_item.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QListWidget>
#include <QDebug>
#include <QPainter>

class GameGui:public QWidget
{
  Q_OBJECT

 public:
  GameGui() {
    ui.setupUi(this);

    connect(ui.lineButton, SIGNAL(clicked()), this, SLOT(DrawLine())); // click "renew", start this level from beginning
    connect(ui.circleButton, SIGNAL(clicked()), this, SLOT(DrawCircle())); // click "answer", give user a hint
    connect(ui.antiButton, SIGNAL(clicked()), this, SLOT(DrawLineWithAnti())); // click "answer", give user a hint

    ui.label->setText(" ");
    scene = new QGraphicsScene(0, 0, 400, 400); // set the size of scene
    view = new QGraphicsView(scene);
    //QPixmap pix("/Users/lu/Documents/projects/my/raster_graphics/gui_game/background_light.png");
    //pix.scaled(400, 400,  Qt::IgnoreAspectRatio);
    //scene->addPixmap(pix);
    ui.verticalLayout->addWidget(view);
  }

 public slots:
   void DrawCircle();
   void DrawLine();
   void DrawLineWithAnti();
   void mousePressEvent(QMouseEvent* e);

 signals:
  void newPoint(int num_point);

  private:
    Ui::GameForm ui;
    QGraphicsScene* scene;
    QGraphicsView* view;
};
