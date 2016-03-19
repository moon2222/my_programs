

#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    //setbkcolor(GREEN);
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j;
    int radius,xc,yc,x1,y1,x2,y2,y3,x,y,p,X,Y;


    printf("Center of the screen is :\n");
    printf("x0=%d\n",x0);
    printf("y0=%d\n",y0);
    printf("enter x-coordinate of center\n");
    scanf("%d",&xc);
    printf("enter y-coordinate of center\n");
    scanf("%d",&yc);
    printf("Enter the radius\n");
    scanf("%d",&radius);
    for(i=0;i<dwHeight;i++)
            putpixel(x0,i,WHITE);

    for(j=0;j<dwWidth;j++)
            putpixel(j,y0,WHITE);


    xc=x0+xc;
    yc=y0-yc;

    x=0;
    y=radius+0.5;
    X=x;
    Y=2*y;
    p=(5/4)-radius+0.5;

    putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,WHITE);
    putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,WHITE);
    putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,WHITE);
    putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,WHITE);

    while(x<y)
    {
       x+=1;
       X+=2;
       if(p<0)
       {
           p=p+X+1;
       }
       else
       {
           Y-=2;
           p=p+X+1-Y;
           y-=1;
       }
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,WHITE);

        putpixel(floor(xc+0.5)+y,floor(yc+0.5)+x,WHITE);
        putpixel(floor(xc+0.5)+y,floor(yc+0.5)-x,WHITE);
        putpixel(floor(xc+0.5)-y,floor(yc+0.5)+x,WHITE);
        putpixel(floor(xc+0.5)-y,floor(yc+0.5)-x,WHITE);
    }


    delay(10000);
    cleardevice();
    closegraph();
}

