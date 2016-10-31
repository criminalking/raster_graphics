#include "draw.h"

void Draw::DrawLineBresenham(int x0, int y0, int x1, int y1)
{
  int dx = x1 - x0;
  int dy = y1 - y0;
  int ux = ((dx > 0) << 1) - 1; // set x-step is 1 or -1
  int uy = ((dy > 0) << 1) - 1; // set y_step is 1 or -1
  int x = x0, y = y0, e;

  dx = abs(dx); dy = abs(dy);
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

void Draw::AntiAliasing(int x0, int y0, int x1, int y1)
{
  float filter_weights[9] = {1.0/16, 1.0/8, 1.0/16, 1.0/8, 1.0/4, 1.0/8, 1.0/16, 1.0/8, 1.0/16};
  float k = float(y1 - y0) / (x1 - x0);
  float b = y0 - k * x0;
  float compare_number = sqrt(k * k + 1); // if ((kx - y + b) <= compare_number), add its weights_
  for (int i = x0 / 3; i < x1 / 3; i++)
    for (int j = y0 / 3; j < y1 / 3; j++)
      {
        float sum = 0;
        for (int m = 0; m < 3; m++)
          {
            float x = i * 3 + m + 0.5;
            for (int n = 0; n < 3; n++)
            {
              float y = j * 3 + n + 0.5;
              if (std::fabs(k * x - y + b) <= compare_number) sum += filter_weights[m * 3 + n];
            }
          }
        DrawPixel(i, j, sum, ANTI);

      }
}

Vec3b Draw::Color2Scalar(float alpha)
{
  Vec3b color;
  switch(color_)
    {
    case red:
      {
        color.val[0] = 0; color.val[1] = 0; color.val[2] = 255 * alpha;
        return color;
        break;
      }
    case blue:
      {
        color.val[0] = int(255 * alpha); color.val[1] = 0; color.val[2] = 0;
        return color;
        break;
      }
    case green:
      {
        color.val[0] = 0; color.val[1] = 255 * alpha; color.val[2] = 0;
        return color;
        break;
      }
    case white:
      {
        color.val[0] = 255 * alpha; color.val[1] = 255 * alpha; color.val[2] = 255 * alpha;
        return color;
        break;
      }
    }
}

void Draw::DrawPixel(int x, int y, float alpha, bool anti)
{
  if (anti) {scene_anti_.at<Vec3b>(y, x) = Color2Scalar(alpha);
    //if (alpha != 0 ) std::cout <<x << " " << y <<"     ";
  }
  else scene_.at<Vec3b>(y, x) = Color2Scalar(alpha);
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
  imshow("Display window", scene_);
  namedWindow("Display anti window", WINDOW_AUTOSIZE);// Create a window for display.
  imshow("Display anti window", scene_anti_);
  waitKey(0);
}

bool Draw::CheckInput(int x0, int y0, int x1, int y1)
{
  if (x0 < 0 || x0 >= height_) return false;
  if (x1 < 0 || x1 >= height_) return false;
  if (y0 < 0 || y0 >= width_) return false;
  if (y1 < 0 || y1 >= width_) return false;
  return true;
}
