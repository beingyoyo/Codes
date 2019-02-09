#include<stdio.h>
#include<graphics.h>
void display(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,15);
	putpixel(xc-x,yc-y,15);
	putpixel(xc+x,yc-y,15);
	putpixel(xc-x,yc+y,15);
	putpixel(xc+y,yc+x,15);
	putpixel(xc-y,yc-x,15);
	putpixel(xc-y,yc+x,15);
	putpixel(xc+y,yc-x,15);
}
void main()
{
	int xc,yc,r,x,y,p;
	int gd=DETECT,gm;
	printf("Enter the centre co-ordinates:\n");
	scanf("%d %d",&xc,&yc);
	printf("Enter the Radius:\n");
	scanf("%d",&r);
	initgraph(&gd, &gm, "null");
	x=0;
	y=r;
	p=1-r;
	while(x<=y)
	{
		if(p<0)
		{
			x++;
			p=p+2*(x+1);
		}
		else
		{
			x++;
			y-- ;
			p=p+2*(x-y)+1;
		}
		display(xc,yc,x,y);
	}
	getch();
	delay(1000);
	closegraph();
}
