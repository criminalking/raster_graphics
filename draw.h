#include <iostream>
#include <algorithm>
#include <cmath>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

class Draw
{
 public:
  enum Color {red, green, blue, white};
 Draw(): scene(Size(400, 400), CV_8UC3, Scalar(0)) {color_ = Draw::blue;}
  void ShowImage();
  void DrawLineBresenham(int x0, int y0, int x1, int y1);
  void DrawCurve(int x0, int y0, int r); // (x0, y0) is the center of one circle
  void FillColor();
  void set_color(Color color) {color_ = color;}

 private:
  void DrawPixel(int x, int y);
  void DrawSymmetryPixel(int x, int y, int offset_x, int offset_y);
  Vec3b Color2Scalar();

  Color color_;

  Mat scene;
};
