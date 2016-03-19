
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
    int i,j,rx,ry,xc,yc,x1,y1,x2,x3,y2,y3,x,y,xc1,yc1;

    printf("Center of the screen is :\n");
    printf("x0=%d\n",x0);
    printf("y0=%d\n",y0);
    printf("enter x-coordinate of center\n");
    scanf("%d",&xc);
    printf("enter y-coordinate of center\n");
    scanf("%d",&yc);
    printf("Enter rx(radius at x-axis)\n");
    scanf("%d",&rx);
    printf("Enter ry(radius at y-axis)\n");
    scanf("%d",&ry);
    for(i=0;i<dwHeight;i++)
            putpixel(x0,i,WHITE);

    for(j=0;j<dwWidth;j++)
            putpixel(j,y0,WHITE);


    xc=x0+xc;
    yc=y0-yc;
    x1=xc+rx+0.5;
    y1=yc+0.5;
    x2=xc-rx+0.5;
    y2=yc+ry+0.5;
    x3=xc+0.5;
    y3=yc-ry+0.5;

    putpixel(x1,y1,WHITE);
    putpixel(x2,y1,WHITE);
    putpixel(x3,y2,WHITE);
    putpixel(x3,y3,WHITE);

    if(rx>ry)
    {
        x=rx-0.5;
    }
    else if(ry>rx)
    {
        y=ry-0.5;
    }
    xc1=xc+0.5;
    yc1=yc+0.5;
    if(rx>ry)
    {
        while(x>0)
        {
            y=sqrt((ry*ry)-(ry*ry*x*x)/(rx*rx))+0.5;
            printf("%d\n",y);
            putpixel(xc1+x,yc1+y,WHITE);
            putpixel(xc1-x,yc1+y,WHITE);
            putpixel(xc1+x,yc1-y,WHITE);
            putpixel(xc1-x,yc1-y,WHITE);
            x=x-1;
            //printf("%d\n",x);
        }
    }
    else
    {
        while(y>0)
        {
            x=sqrt((rx*rx)-(rx*rx*y*y)/(ry*ry))+0.5;
            printf("%d\n",x);
            putpixel(xc1+x,yc1+y,WHITE);
            putpixel(xc1+x,yc1-y,WHITE);
            putpixel(xc1-x,yc1+y,WHITE);
            putpixel(xc1-x,yc1-y,WHITE);
            y=y-1;
        }
    }

    delay(50000);
    cleardevice();
    closegraph();
}
