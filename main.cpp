#include "iostream"
#include <stdlib.h>
#include "draw.h"

int main(int argc, char** argv)
{
  if (argc != 5)
    {
      std::cout << "Input error! Please input 4 arguments(x0, y0, x1, y1)!\n";
      return 0;
    }
  int x0 = atoi(argv[1]), y0 = atoi(argv[2]), x1 = atoi(argv[3]), y1 = atoi(argv[4]);
  Draw draw;
  if (!draw.CheckInput(x0, y0, x1, y1))
    {
      std::cout << "Input error! Out of range!\n";
      return 0;
    }
  draw.set_color(Draw::blue);
  draw.DrawLineBresenham(x0, y0, x1, y1);
  draw.AntiAliasing(3*x0, 3*y0, 3*x1, 3*y1);

  // int r;
  // std::cout << "Circle: Please input x0, y0, r: ";
  // std::cin >> x0 >> y0 >> r;
  // draw.set_color(Draw::red);
  // draw.DrawCurve(x0, y0, r);

  draw.ShowImage();

  return 0;
}
