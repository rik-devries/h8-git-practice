#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include "point.h"
#include "shape.h"

class Trapezium : public Shape{
	public:
		//Constructors/destructors
		Trapezium();
		Trapezium(point p1, point p2, point p3, point p4);
		~Trapezium();

		//Functions
		void move(float dx, float dy);
		void zoom(float scale);
		float area();
		void setColor(colorRGB color);
		void draw();
		//TODO: void twist(float angle);
	private:
		point _p1, _p2, _p3, _p4;
		colorRGB _color = {0.5, 0.5, 0.5};
};

#endif
