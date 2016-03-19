#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()
{
    int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x01=dwWidth/2;
    int y01=dwHeight/2;
    int i,j;
    int y3;
    int xinterf;
    float xf,ysgap,yfgap;
    float xinter;

    int x1,x2,y1,y2,temp,xs;
    float delx,dely,dx,dy,m,ys,yinter,xsgap,xfgap,yf;
    float p[500],x[500],y[500];

    printf("Enter the starting position of x co-ordinate :: ");
    scanf("%d",&x1);
    printf("Enter the ending position of x co-ordinate :: ");
    scanf("%d",&x2);
    printf("Enter the starting position of y co-ordinate :: ");
    scanf("%d",&y1);
    printf("Enter the ending position of y co-ordinate :: ");
    scanf("%d",&y2);

    if(x1>x2)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    delx = x2-x1;
    dely = y2-y1;
    m = dely/delx;

    if (m < 1)
    {
        xs = x1 + 0.5;
        ys = y1 + m * (xs - x1);
        yinter = ys + m;
        xsgap = xs + 0.5 - x1;

        int ysf = ys;
        float col = (ysf+1-ys)*xsgap;
        putpixel(xs,ysf,col);
        col = (ys - ysf) * xsgap;
        putpixel(xs,ysf+1,col);

        int xf = x2+0.5;
        yf = y2 + m * (xf - x2);
        int x2f = x2+0.5;
        xfgap = x2 + 0.5 - x2f;
        int yff = yf;
        col = (yff + 1 - yf)*xfgap;
        putpixel(xf,yff,col);
        col = (yf - yff)*xfgap;
        putpixel(xf,yff+1,col);

        int k;
        int yinterf;
        for(k=x1+1;k<=x2-1;k++)
        {
            yinterf = yinter;
            col = yinterf+1-yinter;

            putpixel(k,yinterf,col);
            col = yinter - yinterf;

            putpixel(k,yinterf+1,col);
            yinter = yinter + m;

        }


    }
    else if(m>1)
    {
        ys = y1 + 0.5;
        xs = x1 + ( (ys - y1)/m);
        xinter = xs + (1/m);
        ysgap = ys + 0.5 - y1;

        int xsf = xs;
        float col = (xsf+1-xs)*ysgap;
        putpixel(xsf,ys,col);
        col = (xs - xsf) * ysgap;
        putpixel(xs+1,ys,col);

        int yf = y2+0.5;
        xf = x2 + ( (yf - y2)/m);
        int y2f = y2+0.5;
        yfgap = y2 + 0.5 - y2f;
        int xff = xf;
        col = (xff + 1 - xf)*yfgap;
        putpixel(xf,yf,col);
        col = (xf - xff)*yfgap;
        putpixel(xf+1,yf,col);

        int k;
        int xinterf;
        for(k=y1+1;k<=y2-1;k++)
        {
            xinterf = xinter;
            col = xinterf+1-xinter;

            putpixel(xinterf,k,col);
            col = xinter - xinterf;

            putpixel(xinterf+1,k,col);
            xinter = xinter + (1/m);

        }
    }





    delay(30000);
    cleardevice();
    closegraph();
}
