#ifndef SHAPE_H
#define SHAPE_H

typedef struct _colorRGB {
	float r;
	float g;
	float b;
} colorRGB;

class Shape {
	public:
		//Functions
		virtual void move(float dx, float dy) = 0;
		virtual void zoom(float scale) = 0;
		virtual float area() = 0;
		virtual void draw() = 0;
		virtual void setColor(colorRGB color) = 0;

		virtual ~Shape();
};

#endif
