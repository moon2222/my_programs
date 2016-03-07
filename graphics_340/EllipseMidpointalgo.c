

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
    int rx,ry,xc,yc,x1,y1,x2,y2,y3,x3,x4,y4;
    int x,xcomp,y,rx2,ry2,_2rx2,_2ry2,X,Y,p1,p2,temp;


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

    x=0;
    xcomp=rx+0.5;
    y=ry+0.5;
    rx2=(rx*rx)+0.5;
    ry2=(ry*ry)+0.5;
    _2rx2=2*rx2;
    _2ry2=2*ry2;
    X=x;
    Y=_2rx2*y;
    temp=(1/4)*rx2;
    p1=ry2-rx2*y+temp;

    putpixel(floor(xc+0.5),(floor(yc+0.5))+y,WHITE);
    putpixel(floor(xc+0.5),(floor(yc+0.5))-y,WHITE);
    putpixel((floor(xc+0.5))+xcomp,floor(yc+0.5),WHITE);
    putpixel((floor(xc+0.5))-xcomp,floor(yc+0.5),WHITE);

    while((_2ry2*x) < (_2rx2*y))
    {
        x+=1;
        X=X+_2ry2;
        if(p1<0)
        {
            p1=p1+X+ry2;
        }
        else
        {
            Y=Y - _2rx2;
            p1=p1+X+ry2-Y;
            y-=1;
        }
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,WHITE);

    }

    p2=ry2*floor((x+0.5)*(x+0.5))+rx2*((y-1)*(y-1))-rx2*ry2;

    while(y>0)
    {
        y-=1;
        Y=Y- _2rx2;
        if(p2>0)
        {
            p2=p2+rx2-Y;
        }
        else
        {
            X=X+ _2ry2;
            p2=p2+rx2-Y+X;
            x+=1;
        }
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)+x,floor(yc+0.5)-y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)+y,WHITE);
        putpixel(floor(xc+0.5)-x,floor(yc+0.5)-y,WHITE);
    }

    delay(10000);
    cleardevice();
    closegraph();
}


