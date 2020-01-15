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
		delay(5);
	}

}

int main()
{
	int gd = DETECT, gm;

	initgraph (&gd, &gm, NULL);
	int i=0;
	while(i<=400)
	{
		DDA(i, i, 0, 400);
		DDA(0, 400, i, i);
		i+=50;
	}

	closegraph();
	return 0;
}