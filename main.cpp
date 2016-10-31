#include "iostream"
#include "draw.h"

int main()
{
  int x0, y0, x1, y1;
  std::cout << "Line: Please input x0, y0, x1, y1: ";
  std::cin >> x0 >> y0 >> x1 >> y1;
  Draw draw;
  draw.set_color(Draw::blue);
  draw.DrawLineBresenham(x0, y0, x1, y1);

  int r;
  std::cout << "Circle: Please input x0, y0, r: ";
  std::cin >> x0 >> y0 >> r;
  draw.set_color(Draw::red);
  draw.DrawCurve(x0, y0, r);

  draw.ShowImage();

  return 0;
}
