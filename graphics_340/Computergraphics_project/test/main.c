
#include<graphics.h>
#include<stdio.h>
#include<math.h>

int main()
{
    int gd=DETECT,gm;

    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x01=dwWidth/2;
    int y01=dwHeight/2;
    int i,j;
    for(i=0; i<dwHeight; i++)
        putpixel(x01,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y01,RED);

    int xe1,xe2,x0,y0,ye1,ye2;
    float xdelta,ydelta,steps;
    float xdel,ydel;
    printf("enter x-coordinate of starting point\n");
    scanf("%d",&xe1);
    printf("enter y-coordinate of starting point\n");
    scanf("%d",&ye1);
    printf("enter x-coordinate of ending point\n");
    scanf("%d",&xe2);
    printf("enter y-coordinate of ending point\n");
    scanf("%d",&ye2);

    if(xe1>xe2)
        xdelta=xe1-xe2;
    else
        xdelta=xe2-xe1;
    if(ye1>ye2)
        ydelta=ye1-ye2;
    else
        ydelta=ye2-ye1;
    if(xdelta>ydelta)
        steps=xdelta;
    else
        steps=ydelta;
    xe1=x01+xe1;
    xe2=x01+xe2;
    ye1=y01-ye1;
    ye2=y01-ye1;
    xdel=(xdelta/steps);
    if(ye2<ye1)
        ydel=-(ydelta/steps);
    else
        ydel=(ydelta/steps);
    putpixel(xe1,ye1,WHITE);
    x0=xe1;
    y0=ye1;
    int k;
    float x[800],y[800];
    x[0]=x0;
    y[0]=y0;
    int y3;
    for(k=1; k<steps; k++)
    {
        x[k]=x[k-1]+xdel;
        y[k]=y[k-1]+ydel;
        y3=y[k]-y[0];
        putpixel(x[k],y[k]-2*y3,WHITE);
    }



    delay(10000);
    cleardevice();
    closegraph();
}
