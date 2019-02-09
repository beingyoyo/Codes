#include<stdio.h>
#include<graphics.h>

void main()
{
int gd=DETECT,gm,x[5],y[5],n,i,ch,tx,ty,X[5],Y[5],r,pi=3.14,sx,sy;
double ra;
printf("enter no.of vertices");
scanf("%d",&n);

for(i=0;i<n;i++)
{
  printf("enter the %d coordinate of x and y",i+1); 
  scanf("%d %d",&x[i],&y[i]);
}



printf("enter the choice\n1.translation\n2.rotation\n3.scaling\n");
scanf("%d",&ch);
switch (ch)
{
   case 1:
        printf("\nEnter the translation factors: ");
        scanf("%d %d",&tx, &ty);
        initgraph(&gd,&gm,NULL);
        //setbkcolor(WHITE);
        //setcolor(BLACK);
        for(i=0;i<n-1;i++)
        {
            line(x[i],y[i],x[i+1],y[i+1]);
        }
        line(x[0],y[0],x[n-1],y[n-1]);   
   
        for(i=0;i<n;i++)
        {
         X[i]=tx+x[i];
         Y[i]=ty+y[i];
        }
        for(i=0;i<n-1;i++)
        {
          line(X[i],Y[i],X[i+1],Y[i+1]);
        }
        line(X[0],Y[0],X[n-1],Y[n-1]);   
        break;
   case 2:
    printf("ENTER THE ROTATE ANGLE ");
    scanf("%d",&r);
    ra=(r*pi)/180;
    initgraph(&gd,&gm,NULL);
                      
   for(i=0;i<n;i++)
   {
     if(i<n-1)       
     line(x[i],y[i],x[i+1],y[i+1]);
     else
     line(x[i],y[i],x[0],y[0]);
   }   
   for(i=0;i<n;i++)
   {
     X[i]=abs((int)x[i]*cos(ra)-(int)y[i]*sin(ra));
     Y[i]=abs((int)x[i]*sin(ra)+(int)y[i]*cos(ra));
   }   
   for(i=0;i<n;i++)
   {
     if(i<n-1)       
     line(X[i],Y[i],X[i+1],Y[i+1]);
     else
     line(X[i],Y[i],X[0],Y[0]);
   }
   break;
   case 3:
          printf("ENTER THE SCALING TERM FOR X and Y ");
          scanf("%d %d",&sx,&sy);
          initgraph(&gd,&gm,NULL);
                      
          for(i=0;i<n;i++)
          {
            if(i<n-1)       
            line(x[i],y[i],x[i+1],y[i+1]);
            else
            line(x[i],y[i],x[0],y[0]);
          }   
          for(i=0;i<n;i++)
          {
             X[i]=x[i]*sx;
             Y[i]=y[i]*sy;
          }   
          for(i=0;i<n;i++)
          {
             if(i<n-1)       
             line(X[i],Y[i],X[i+1],Y[i+1]);
             else
             line(X[i],Y[i],X[0],Y[0]);
          }   
          break;
               
}

getch();
closegraph();
}
