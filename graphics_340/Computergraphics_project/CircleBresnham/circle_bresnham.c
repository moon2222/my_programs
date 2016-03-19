
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
    int radius,xc,yc,x1,y1,x2,y2,y3,x,y,p;


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
    p=3-(2*radius)+0.5;

    while(x<=y)
    {
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,WHITE);
        putpixel(floor(xc+y+0.5),floor(yc+x+0.5),WHITE);
        putpixel(floor(xc+y+0.5),floor(yc-x+0.5),WHITE);
        putpixel(floor(xc-y+0.5),floor(yc+x+0.5),WHITE);
        putpixel(floor(xc-y+0.5),floor(yc-x+0.5),WHITE);

        x+=1;
        if(p<0)
        {
            p=p+(4*x)+6;
        }
        else
        {
            y-=1;
            p=p+(4*(x-y))+10;
        }
    }


    delay(10000);
    cleardevice();
    closegraph();
}

