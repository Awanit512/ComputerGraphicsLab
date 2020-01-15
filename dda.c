// DDA line generation

#include<stdio.h>
#include<graphics.h>

int abs(int n)
{
	return ((n>0)?n:(n*(-1)));
}

void DDA(int x0, int x1, int y0, int y1)
{
	int dx= x1-x0;
	int dy= y1-y0;
	int i;
	int steps = abs(dx) > abs(dy) ? abs(dx) :abs(dy);

	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;
	float x=x0, y=y0;
	for(i=0;i<=steps;i++)
	{
		putpixel (x,y,WHITE);
		x+=Xinc;
		y+=Yinc;
		delay(100);
	}

}

int main()
{
	int gd = DETECT, gm;

	initgraph (&gd, &gm, NULL);
	
	DDA(1, 270, 2, 300);

	closegraph();
	return 0;
}