
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
    initwindow(dwWidth/2,dwHeight/2);
    int x0=dwWidth/4;
    int y0=dwHeight/4;
    int i,j;
    int radius,xc,yc,x1,y1,x2,y2,y3,x;
    float y;

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

    x1=xc-radius+0.5;
    y1=yc+0.5;
    x2=xc+radius+0.5;
    y2=yc+0.5;
    putpixel(x1,y1,WHITE);
    putpixel(x2,y2,WHITE);

    for(x=x1+1;x<=x2-1;x++)
    {
        y=yc+sqrt((radius*radius)-((x-xc)*(x-xc)));
        y3=y+0.5;
        putpixel(x,y3,WHITE);
        y=yc-sqrt((radius*radius)-((x-xc)*(x-xc)));
        y3=y+0.5;
        putpixel(x,y3,WHITE);

    }



    delay(10000);
    cleardevice();
    closegraph();
}
