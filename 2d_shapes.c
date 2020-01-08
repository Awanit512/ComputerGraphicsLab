// C program to demonstrate 
// drawing a triangle, pentagon, trapezium
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h>

float _angle = 30.0f;

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 0.0, 1.0); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} 

void update(int value) {
    _angle += 2.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
   
    glutPostRedisplay(); //Tell GLUT that the display has changed
   
    //Tell GLUT to call update again in 250 milliseconds
    glutTimerFunc(250, update, 0);
}


void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(-200, 175, 0);
	glRotatef(_angle, 1., 0., 0.);
	glTranslatef(200, -175, 0);
	glBegin(GL_TRIANGLES); 
	float x1, x2, x3, y1, y2, y3;
	x1=-300;
	x2=-200;
	x3=-100;
	y1=100;
	y2=250;
	y3=100;
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(225, 150, 0);
	glRotatef(_angle, 0., 1., 0.);
	glTranslatef(-225, -150, 0);
	glBegin(GL_QUADS);
	float x4, y4;
	x1=300;
	x2=250;
	x3=200;
	x4=150;
	y1=100;
	y2=200;
	y3=200;
	y4=100;
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(0, -100, 0); 
	glRotatef(_angle, 0., 0., 1.);
	glTranslatef(0, 100, 0);
	glBegin(GL_POLYGON);
	float x5, y5;
	x5=0;
	x1=-100;
	x2=-100;
	x3=100;
	x4=100;
	y5=50;
	y1=-50;
	y2=-150;
	y3=-150;
	y4=-50;
	glVertex2i(x5, y5);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);
	glEnd();

	glPopMatrix(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("shapes Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutTimerFunc(250, update, 0);
	glutMainLoop(); 
} 

