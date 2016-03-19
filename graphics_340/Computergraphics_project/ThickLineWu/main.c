#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()
{
    int gd=DETECT,gm,i,j;
    initgraph(&gd,&gm,NULL);
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
            col = yinterf-yinter;
            putpixel(k+1,yinterf+1,col);
col = yinterf-1-yinter;
            putpixel(k+2,yinterf+2,col);
col = yinterf-2-yinter;
            putpixel(k+3,yinterf+3,col);
col = yinterf-3-yinter;
            putpixel(k+4,yinterf+4,col);

            col = yinter - yinterf;
            putpixel(k,yinterf+1,col);
col = yinterf-yinter;
            putpixel(k+1,yinterf+2,col);
col = yinterf-1-yinter;
            putpixel(k+2,yinterf+3,col);
col = yinterf-2-yinter;
            putpixel(k+3,yinterf+4,col);
col = yinterf-3-yinter;
            putpixel(k+4,yinterf+5,col);

            yinter = yinter + m;

        }


    }





    delay(30000);
    cleardevice();
    closegraph();
}
