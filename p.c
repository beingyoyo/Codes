#include<stdio.h>
#include<graphics.h>
#include<math.h>
int l,b,u;
int top[3];//top of three stacks
int from,to;
int tower[3][10];//three towers disks as stack
int air;
void push(int to,int diskno)
{
    tower[to-1][++top[to-1]]=diskno;
    //printf("%d",top);
}
int pop(int from)
{
	return(tower[from-1][top[from-1]--]);
}

void drawStill()
{
	int i,j,disk;
	cleardevice();
	for(j=1;j<=3;j++)
    {
    	bar(j*l,u,j*l+5,b);
    	for(i=0;i<=top[j-1];i++)
    	{
    		disk=tower[j-1][i];
    		//setcolor(i+1);
    		bar(j*l-15-disk*5,b-(i+1)*10,j*l+20+disk*5,b-i*10);
    		//floodfill(j*l-20-disk*5,b-(i+2)*10,RED);
    	}
    	//setcolor(15);
    }
}
void animator()
{
	int x,y,dif,sign;
	air=pop(from);
	x=from*1;
	y=b-(top[from-1]+1)*10;
	for(;y>u-20;y-=15)
 	{
 		drawStill();
 		//setfillstyle(SOLID_FILL,1+diskInAir);
 		bar(x-15-air*5,y-10,x+5+15+air*5,y);
 		delay(100);
	}
	y=u-20;
	dif=to*l-x;
	sign=dif/abs(dif);
	//moving disk towards a target tower
	for(;abs(x-to*l)>25;x+=sign*15)
	{
 		drawStill();
 		//setfillstyle(SOLID_FILL,1+diskInAir);
 		bar(x-15-air*5,y-10,x+5+15+air*5,y);
 		delay(100);
 	}
	x=to*l;
	//placing disk on a target tower
	for(;y<b-(top[to-1]+1)*10;y+=15)
 	{
 		drawStill();
 		//setfillstyle(SOLID_FILL,1+diskInAir);
 		bar(x-15-air*5,y-10,x+5+15+air*5,y);
 		delay(100);
 	}
}
void move(int n,int a,int b,int c)
{
    if(n>=1)
    {
        move(n-1,a,c,b);
        drawStill();
        delay(1000);
        from=a;
        to=b;
        animator();
        move(n-1,b,a,c);
    }
}       
void main()
{
    int i,j,gd=DETECT,gm,n;
    printf("Enter number of discs:");
    scanf("%d",&n);
    initgraph(&gd,&gm," ");
    for(i=0;i<3;i++)
    {
        top[i]=-1;
    }
    for(i=n;i>0;i--)
    {
        push(1,i); 
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d\t",tower[i][j]);
        }
        printf("\n");
    }
    l=getmaxx()/4;
    b=getmaxy()-50;
    u=getmaxy()/3+100;
    printf("L:%d",l);
    printf("\nB:%d",b);
    printf("\nU:%d",u);
    //drawStill();
    move(n,1,2,3);
    delay(4000);
    getch();
    closegraph();
}
