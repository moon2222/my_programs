
#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define PI 3.14159265

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
    int rx,ry,xc,yc,x1,y1,x2,y2,y3,x3,x4,y4;
    float theta,dtheta,x,y;
    float val=PI/180;

    printf("Center of the screen is :\n");
    printf("x0=%d\n",x0);
    printf("y0=%d\n",y0);
    printf("enter x-coordinate of center\n");
    scanf("%d",&xc);
    printf("enter y-coordinate of center\n");
    scanf("%d",&yc);
    printf("Enter rx\n");
    scanf("%d",&rx);
    printf("Enter ry\n");
    scanf("%d",&ry);
    for(i=0;i<dwHeight;i++)
            putpixel(x0,i,WHITE);

    for(j=0;j<dwWidth;j++)
            putpixel(j,y0,WHITE);


    xc=x0+xc;
    yc=y0-yc;

    x1=xc+rx+0.5;
    y1=yc+0.5;
    y2=yc+ry+0.5;
    x2=xc-rx+0.5;
    y3=yc-ry+0.5;
    x3=xc+0.5;
    putpixel(x1,y1,WHITE);
    putpixel(x2,y1,WHITE);
    putpixel(x3,y2,WHITE);
    putpixel(x3,y3,WHITE);
    theta = 1;
    dtheta=1;
    while(theta<=90)
    {
        x=rx*cos(theta*val);
        y=ry*sin(theta*val);
        x1=xc+x+0.5;
        y1=yc+y+0.5;
        x2=xc-x+0.5;
        y2=yc-y+0.5;

        putpixel(x1,y1,WHITE);
        putpixel(x2,y1,WHITE);
        putpixel(x1,y2,WHITE);
        putpixel(x2,y2,WHITE);

        theta=theta+dtheta;
    }

    delay(10000);
    cleardevice();
    closegraph();
}


