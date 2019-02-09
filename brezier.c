#include<stdio.h>
#include<math.h>
#include<graphics.h>
void main()
{
    int gd=DETECT,gm;
    
    int x[5],y[5],i,xnew,ynew;
	float u;
	printf("Enter the control points");
	for(i=0;i<=3;i++)
		scanf("%d%d",&x[i],&y[i]);
	initgraph(&gd,&gm,"");
	for(i=0;i<3;i++)
		line(x[i],y[i],x[i+1],y[i+1]);
	moveto(x[0],y[0]);
	for(u=0;u<=1;u+=0.0001)
	{
		xnew=pow(1-u,3)*x[0]+3*u*pow(1-u,2)*x[1]+3*pow(u,2)*(1-u)*x[2]+pow(u,3)*x[3];
        
		ynew=pow(1-u,3)*y[0]+3*u*pow(1-u,2)*y[1]+3*pow(u,2)*(1-u)*y[2]+pow(u,3)*y[3];
		setcolor(4);
		lineto(xnew,ynew);
	}
	getch();
	closegraph();
}
