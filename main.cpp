#include "iostream"
#include <stdlib.h>
#include "draw.h"

int main(int argc, char** argv)
{
  int kernel = 3;
  Draw draw(kernel);
  if (argc == 5)
    {
      int x0 = atoi(argv[1]), y0 = atoi(argv[2]), x1 = atoi(argv[3]), y1 = atoi(argv[4]);
      if (!draw.CheckLineInput(x0, y0, x1, y1))
        {
          std::cout << "Input error! Out of range!\n";
          return 0;
        }
      draw.set_color(Draw::red);
      draw.DrawLineBresenham(x0, y0, x1, y1); // without anti-aliasing
      draw.AntiAliasing(kernel * x0, kernel * y0, kernel * x1, kernel * y1); // with anti-aliasing
      draw.ShowImage(true); // need anti
    }
  else if(argc == 4)
    {
      int x0 = atoi(argv[1]), y0 = atoi(argv[2]), r = atoi(argv[3]);
      if (!draw.CheckCircleInput(x0, y0, r))
        {
          std::cout << "Input error! Out of range!\n";
          return 0;
        }
      draw.set_color(Draw::red);
      draw.DrawCurve(x0, y0, r);
      draw.ShowImage(false); // don't need anti
    }
  else
    {
      std::cout << "Input error! Line: input 4 arguments(x0, y0, x1, y1)!  Circle: input 3 arguments(x0, y0, r)\n";
      return 0;
    }
  return 0;
}
