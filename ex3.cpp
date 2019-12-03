#include "assignment.h"

#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "trapezium.h"
#include "car.h"

#include <GL/glut.h>

void glDrawEx3();
void TimeStepEx3(int n);

void ex3(){
  int argc = 0;
  char** argv = NULL;
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutCreateWindow("Basic shapes");
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(glDrawEx3);
  glutTimerFunc(25, TimeStepEx3, 25);
  glutMainLoop();
}

void glDrawEx3() {
  static float width = 6, height = 4;
  static float move = 1;
  Car car(width, height, {-5,0});
  Circle c1;
  car.setColor({0,0,0},{1,0,0},{0,1,0});
  car.zoom(0.2);
  car.move(move/100, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  car.draw();
  //c1.draw();
	glutSwapBuffers();
	glFlush();
  move++;
}

void TimeStepEx3(int n) {
	glutTimerFunc(n, TimeStepEx3, n);
	glutPostRedisplay();
}
