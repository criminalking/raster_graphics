#ifndef DRAW_H_
#define DRAW_H_

#include <iostream>
#include <algorithm>
#include <cmath>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

#define ANTI 1

class Draw
{
 public:
  enum Color {red, green, blue, white};
 Draw(int height = 400, int width = 200, Color color =  Draw::blue): height_(height), width_(width), color_(color), scene_(Size(height, width), CV_8UC3, Scalar(0)), scene_anti_(Size(height, width), CV_8UC3, Scalar(0)) {}
  void ShowImage();
  void DrawLineBresenham(int x0, int y0, int x1, int y1);
  void DrawCurve(int x0, int y0, int r); // (x0, y0) is the center of one circle
  void AntiAliasing(int x0, int y0, int x1, int y1);
  void set_color(Color color) {color_ = color;}
  bool CheckInput(int x0, int y0, int x1, int y1); // check input valid or not

 private:
  void DrawPixel(int x, int y, float alpha = 1, bool anti = 0);
  void DrawSymmetryPixel(int x, int y, int offset_x, int offset_y);
  Vec3b Color2Scalar(float alpha);

  Color color_; //background color of this screen
  int height_;
  int width_;
  Mat scene_; // store image data without anti_aliasing
  Mat scene_anti_; // store image data with anti_aliasing
};

#endif // DRAW_H_
