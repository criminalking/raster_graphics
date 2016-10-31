#include "draw.h"

void Draw::DrawLineBresenham(int x0, int y0, int x1, int y1)
{
  int dx = x1 - x0;
  int dy = y1 - y0;
  int ux = ((dx > 0) << 1) - 1; // set x-step is 1 or -1
  int uy = ((dy > 0) << 1) - 1; // set y_step is 1 or -1
  int x = x0, y = y0, e;

  dx = std::abs(dx); dy = std::abs(dy);
  if (dx >= dy) // |k| < 1
    {
      e = -dx;
      for (int i = 0; i <= dx; i++)
        {
          DrawPixel(x, y);
          x += ux;
          e += 2 * dy;
          if (e >= 0)
            {
              y += uy; e -= 2 * dx;
            }
        }
    }
  else // |k| >= 1
    {
      e = -dy;
      for (int i = 0; i <= dy; i++)
        {
          DrawPixel(x, y);
          y += uy;
          e += 2 * dx;
          if (e >= 0)
            {
              x += ux; e -= 2 * dy;
            }
        }
    }
}

void Draw::DrawCurve(int x0, int y0, int r)
{
  int x = 0;
  int y = r;
  int d = 5 - 4 * r; // * 4 convert float to int
  DrawSymmetryPixel(x, y, x0, y0 - r);
  while(x <= y)
    {
      if (d < 0) d += 8 * x + 12;
      else
        {
          d += 8 * (x - y) + 20;
          y--;
        }
      x++;
      DrawSymmetryPixel(x, y, x0, y0 - r);
    }
}

void Draw::FillColor()
{

}

Vec3b Draw::Color2Scalar()
{
  Vec3b color;
  switch(color_)
    {
    case red:
      {
        color.val[0] = 0; color.val[1] = 0; color.val[2] = 255;
        return color;
        break;
      }
    case blue:
      {
        color.val[0] = 255; color.val[1] = 0; color.val[2] = 0;
        return color;
        break;
      }
    case green:
      {
        color.val[0] = 0; color.val[1] = 255; color.val[2] = 0;
        return color;
        break;
      }
    case white:
      {
        color.val[0] = 255; color.val[1] = 255; color.val[2] = 255;
        return color;
        break;
      }
    }
}

void Draw::DrawPixel(int x, int y)
{
  scene.at<Vec3b>(y, x) = Color2Scalar();
}

void Draw::DrawSymmetryPixel(int x, int y, int offset_x, int offset_y)
{
  DrawPixel(x + offset_x, y + offset_y);
  DrawPixel(x + offset_x, -y + offset_y);
  DrawPixel(-x + offset_x, y + offset_y);
  DrawPixel(-x + offset_x, -y + offset_y);
  DrawPixel(y + offset_x, x + offset_y);
  DrawPixel(y + offset_x, -x + offset_y);
  DrawPixel(-y + offset_x, x + offset_y);
  DrawPixel(-y + offset_x, -x + offset_y);
}

void Draw::ShowImage()
{
  namedWindow("Display window", WINDOW_AUTOSIZE);// Create a window for display.
  imshow("Display window", scene);
  waitKey(0);
}
