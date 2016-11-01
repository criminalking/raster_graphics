# Computer graphics —— Raster graphics

## Function
Draw anti-aliased lines with or without Bresenham Algorithm and draw curves.

## Using
Draw line: `./main x0 y0 x1 y1`
> ((x0, y0), (x1, y1) are two points of a line, show with or without anti-aliasing simultaneously)


Draw Circle: `./main x0 y0 r`
> ((x0, y0) is the center of the circle, r is its radius)

## Example
* Draw line(without anti-aliasing): ./main 10 20 200 100


![line image](/result/raw.png)

* Draw line(with anti-aliasing, gaussian kernel):


![with gaussian kernel](/result/gaussian.png)

* Draw line(with anti-aliasing, uniform kernel):


![with uniform kernel](/result/uniform.png)

* Draw circle: ./main 50 50 20


![circle image](/result/circle.png)

## Summary
Without anti-aliasing result line is jagged, after anti-aliasing it becomes smooth. The effect of gaussian kernel and uniform kernel is same. The size of kernel in the example is 3.

## Outlook
GUI is not completed and also some other advanced algorithms should be tried.
