#include "game.h"

void GameGui::DrawLine() // once get the gameSignal, start to design layout
{
  ui.label->setText("You should choose two points in the screen!");
  // int height = 5;
  // int width = 3;
  // int radius = 400 / std::max(height, width);

  // // move all items to center of the scene
  // // right center (200, 200)
  // // now center (height * radius, width * radius)
  // MyItem *item[height * width]; //FIXME: need release
  // for (int i = 0; i < height; ++i)
  //   for (int j = 0; j < width; ++j)
  //     {
  //       item[i * width + j] = new MyItem(j * radius - width * radius / 2 + 200, i * radius - height * radius / 2 + 200, radius);
  //       scene->addItem(item[i * width + j]);
  //     }



}

void GameGui::DrawCircle()
{
  ui.label->setText("You should choose one center in the screen!");




}

void GameGui::DrawLineWithAnti()
{
  ui.label->setText("You should choose two points in the screen!");




}

void GameGui::mousePressEvent(QMouseEvent *e)
{
  QPointF pt = e->pos(); // from (0, 75) to (460, 500)
  std::cout << pt.x() << " " << pt.y() << std::endl;
  //Point new_point(pt.x()/10.0, pt.y()/10.0);
  //_AddPoint(new_point);
  //emit newPoint(points_.size());
}
