#include "iostream"
#include "draw.h"

int main()
{
  int x0, y0, x1, y1;
  Draw draw;
  while(1)
    {
      std::cout << "Line: Please input x0, y0, x1, y1: ";
      std::cin >> x0 >> y0 >> x1 >> y1;
      if (draw.CheckInput(x0, y0, x1, y1)) break;
      else std::cout << "Input error!!!\n";
    }
  draw.set_color(Draw::blue);
  draw.DrawLineBresenham(x0, y0, x1, y1);

  while(1)
    {
      std::cout << "Line: Please input x0, y0, x1, y1: "; // TODO: fault-tolerant
      std::cin >> x0 >> y0 >> x1 >> y1;
      if (draw.CheckInput(x0, y0, x1, y1)) break;
      else std::cout << "Input error!!!\n";
    }
  draw.set_color(Draw::blue);
  draw.DrawLineBresenham(x0, y0, x1, y1);

  // int r;
  // std::cout << "Circle: Please input x0, y0, r: ";
  // std::cin >> x0 >> y0 >> r;
  // draw.set_color(Draw::red);
  // draw.DrawCurve(x0, y0, r);

  draw.ShowImage();

  return 0;
}
