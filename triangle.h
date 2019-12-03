#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"
#include "shape.h"

class Triangle : public Shape{
	public:
		//Constructors/destructors
		Triangle();
		Triangle(point p1, point p2, point p3);
		~Triangle();

		//Functions
		void move(float dx, float dy);
		void zoom(float scale);
		float area();
		void setColor(colorRGB color);
		void draw();
		//TODO: void twist(float angle);
	private:
		point _p1, _p2, _p3;
		colorRGB _color = {0.5, 0.5, 0.5};
};

#endif
