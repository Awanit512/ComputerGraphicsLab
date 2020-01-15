// Bresenham's line generation

#include<stdio.h>
#include<graphics.h>

void bresenham(int x0, int x1, int y0, int y1)
{
	int dx= x1-x0;
	int dy= y1-y0;
	int slope_error= 2*dy - dx;
	int x,y;
	for(x=x0, y=y0 ; x<=x1; x++)
	{
		putpixel(x,y,WHITE);
		if(slope_error >=0)
		{
			y++;
			slope_error = 2* (dy-dx);
		}
		else
			slope_error+=2*dy;
		delay(100);
	}
}

int main()
{
	int gd = DETECT, gm;

	initgraph (&gd, &gm, NULL);
	
	bresenham(1, 270, 2, 300);

	closegraph();
	return 0;
}