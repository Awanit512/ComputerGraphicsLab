#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

 typedef struct
{
float x;
float y;
}CIRCLE;

CIRCLE circle;

int choice = 0;
int h,k,r;
int transX, transY;
double scaleX;
double angle, angleRad;
char reflectionAxis, shearingAxis;
int shearingX, shearingY;

double round(double d)
{
  return floor(d + 0.5);
}

void drawPolygon()
{
   glBegin(GL_LINES);
   glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < 180; i++)
    {
    circle.x = r * cos(i) - h;
    circle.y = r * sin(i) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    
    circle.x = r * cos(i + 0.1) - h;
    circle.y = r * sin(i + 0.1) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    }
    glEnd();
}


void drawPolygonTrans(int x, int y)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < 180; i++)
    {
    circle.x = r * cos(i) - h;
    circle.y = r * sin(i) + k;
    glVertex3f(circle.x + k+x,circle.y - h+y,0);
    
    circle.x = r * cos(i + 0.1) - h;
    circle.y = r * sin(i + 0.1) + k;
    glVertex3f(circle.x + k+x,circle.y - h+y,0);
    }
    glEnd();
}

void drawPolygonScale(double x)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < 180; i++)
    {
    circle.x = r*x * cos(i) - h;
    circle.y = r*x * sin(i) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    
    circle.x = r *x* cos(i + 0.1) - h;
    circle.y = r *x* sin(i + 0.1) + k;
    glVertex3f(circle.x + k,circle.y - h,0);
    }
    glEnd();
}

void myInit(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}


void myDisplay(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);

  if (choice == 1)
  {
    drawPolygon();
    drawPolygonTrans(transX, transY);
  }
  else if (choice == 2)
  {
    drawPolygon();
    drawPolygonScale(scaleX);
  }

  glFlush();
}

int main(int argc, char** argv)
{
  cout << "Enter your choice:\n\n" << endl;

  cout << "1. Translation" << endl;
  cout << "2. Scaling" << endl;
  cout << "6. Exit" << endl;

  cin >> choice;

  if (choice == 6) {
    return 0;
  }

  cout << "\n\nFor Polygon:\n" << endl;

    cout << "Enter co-ordinates for vertex  " << " : "; cin >> h >> k;
     cout << "Enter the radius " << " : "; cin >> r;

  if (choice == 1)
  {
    cout << "Enter the translation factor for X and Y: "; cin >> transX >> transY;
  }
  else if (choice == 2)
  {
    cout << "Enter the scaling factor: "; cin >> scaleX;
  }


  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Extended Basic Transformations");
  glutDisplayFunc(myDisplay);
  myInit();
  glutMainLoop();
  return 0;
}