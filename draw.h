#ifndef DRAW_H_
#define DRAW_H_

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

#define ANTI 1

class Draw
{
  float weights3[9] = {1.0/16, 1.0/8, 1.0/16, 1.0/8, 1.0/4, 1.0/8, 1.0/16, 1.0/8, 1.0/16};
  float weights5[25] = {1.0/273, 4.0/273, 7.0/273, 4.0/273, 1.0/273, 4.0/273, 16.0/273, 26.0/273, 16.0/273, 4.0/273, 7.0/273, 26.0/273, 41.0/273, 26.0/273, 7.0/273, 4.0/273, 16.0/273, 26.0/273, 16.0/273, 4.0/273, 1.0/273, 4.0/273, 7.0/273, 4.0/273, 1.0/273};
 public:
  enum Color {red, green, blue, white};
 Draw(int kernel = 3, int height = 600, int width = 300, Color color =  Draw::blue): height_(height), width_(width), color_(color), scene_(Size(height, width), CV_8UC3, Scalar(0)), scene_anti_(Size(height, width), CV_8UC3, Scalar(0)), kernel_(kernel) {
    filter_weights_ = new float[kernel_ * kernel_];
    if (kernel_ == 3)
      for (int i = 0; i < 9; i++) filter_weights_[i] = weights3[i];
    else if (kernel_ == 5)
      for (int i = 0; i < 25; i++) filter_weights_[i] = weights5[i];
  }
  ~Draw() {delete[] filter_weights_;}
  void ShowImage(bool anti); // if anti == true, show anti-aliasing image
  void DrawLineBresenham(int x0, int y0, int x1, int y1);
  void DrawCurve(int x0, int y0, int r); // (x0, y0) is the center of one circle
  void AntiAliasing(int x0, int y0, int x1, int y1);
  void set_color(Color color) {color_ = color;}
  bool CheckLineInput(int x0, int y0, int x1, int y1); // check line input valid or not
  bool CheckCircleInput(int x0, int y0, int r); // check circle input valid or not

 private:
  void DrawPixel(int x, int y, float alpha = 1, bool anti = 0);
  void DrawSymmetryPixel(int x, int y, int offset_x, int offset_y);
  Vec3b Color2Scalar(float alpha);

  Color color_; //background color of this screen
  int height_;
  int width_;
  Mat scene_; // store image data without anti_aliasing
  Mat scene_anti_; // store image data with anti_aliasing
  int kernel_;
  float *filter_weights_;
};

#endif // DRAW_H_
