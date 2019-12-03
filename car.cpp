#include "car.h"

#include "point.h"
#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "trapezium.h"

Car::Car(float width, float height, point anchor){
  _anchor = anchor;
  _width = width;
  _height = height;
  _shapes = new Shape*[4];
  _shapes[0] = new Parallelogram({(anchor.x - _width/2), (anchor.y - _height/4)}, _width, _height/2, 90);
  _shapes[1] = new Circle({(anchor.x - _width/4), (anchor.y - _height/4)}, _height/6);
  _shapes[2] = new Circle({(anchor.x + _width/4), (anchor.y - _height/4)}, _height/6);
  _shapes[3] = new Trapezium({anchor.x - _width/2, anchor.y + _height/4}, {anchor.x + _width/4, anchor.y + _height/4},\
    {anchor.x - _width/3, anchor.y + _height/2}, {anchor.x, anchor.y + _height/2});
  setColor({0, 0, 1}, {1, 0, 0}, {0, 0, 0});
}

Car::~Car(){
  for(int i = 0; i < 4; i++){
    delete _shapes[i];
  }
  delete[] _shapes;
}

void Car::move(float dx, float dy){
  _anchor.x += dx;
  _anchor.y += dy;
  for(int i = 0; i < 4; i++){
    _shapes[i]->move(dx, dy);
  }
}

void Car::zoom(float scale){
  _width *= scale;
  _height *= scale;
  for(int i = 0; i < 4; i++){
    _shapes[i]->zoom(scale);
  }
}

float Car::area(){
  float totalarea = 0;
  for(int i = 0; i < 4; i++){
    totalarea += _shapes[i]->area();
  }
  return totalarea;
}

void Car::setColor(colorRGB bodyColor, colorRGB roofColor, colorRGB tireColor){
  _bodyColor = bodyColor;
  _roofColor = roofColor;
  _tireColor = tireColor;
  _shapes[0]->setColor(_bodyColor);
  _shapes[1]->setColor(_tireColor);
  _shapes[2]->setColor(_tireColor);
  _shapes[3]->setColor(_roofColor);
}

void Car::draw(){
  for(int i = 0; i < 4; i++){
    _shapes[i]->draw();
  }
}
