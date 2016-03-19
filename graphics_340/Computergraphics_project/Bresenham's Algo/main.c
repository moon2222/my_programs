

#include<graphics.h>
#include<stdio.h>
#include<math.h>

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
     for(i=0; i<dwHeight; i++)
        putpixel(x01,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y01,RED);

    int xe1,xe2,x0,y0,ye1,ye2,steps;
    float xdelta,ydelta;
    printf("enter x-coordinate of starting point\n");
    scanf("%d",&xe1);
    printf("enter y-coordinate of starting point\n");
    scanf("%d",&ye1);
    printf("enter x-coordinate of ending point\n");
    scanf("%d",&xe2);
    printf("enter y-coordinate of ending point\n");
    scanf("%d",&ye2);
    xdelta=xe2-xe1;
    ydelta=ye2-ye1;
    xe1=x01+xe1;
    xe2=x01+xe2;
    ye1=y01-ye1;
    ye2=y01-ye2;
    float p[500],x[500],y[500];
    float m=(ydelta/xdelta);
    if(m>0 && m<1){
        int constant1=2*ydelta;
        int constant2=(2*ydelta-(2*xdelta));
        int p0=2*ydelta-xdelta;
        putpixel(xe1,ye1,WHITE);
        x0=xe1;
        y0=ye1;

        p[0]=p0;
        x[0]=x0;
        y[0]=y0;
        int k;
        for(k=0;k<xdelta;k++)
        {
            if (p[k]<0){
                y3=y[k]-ye1;
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]+constant1;
            }
            else{
                y3=y[k]+1-ye1;
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+constant2;
            }
        }
    }
    else if(m<=0 && m>-1)
    {
        int constant1=2*ydelta;
        int constant2=(2*ydelta+(2*xdelta));
        int p0=2*ydelta-xdelta;
        putpixel(xe1,ye1,WHITE);
        x0=xe1;
        y0=ye1;

        p[0]=p0;
        x[0]=x0;
        y[0]=y0;
        int k;
        for(k=0;k<xdelta;k++)
        {
            if (p[k]<0){
                y3=y[k]-1-ye1;
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]+constant2;
            }
            else{
                y3=y[k]-ye1;
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]+constant1;
            }
        }
    }
    else if(m<-1)
    {
        int constant1=2*xdelta;
        int constant2=(2*ydelta+(2*xdelta));
        int p0=-2*xdelta-ydelta;
        putpixel(xe1,ye1,WHITE);
        x0=xe1;
        y0=ye1;
        //printf("asdfasf");
        p[0]=p0;
        x[0]=x0;
        y[0]=y0;
        int k;
        int sd=-ydelta;
        for(k=0;k<sd;k++)
        {
            if (p[k]<0){
                y3=y[k]-1-ye1;
                putpixel(x[k],y[k]-1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]+constant1;
            }
            else{
                y3=y[k]-1-ye1;
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]+constant2;
            }
        }
    }
    else if(m>=1)
    {
        int constant3=2*xdelta;
        int constant4=(2*xdelta-(2*ydelta));
        int p0=2*xdelta-ydelta;
        putpixel(xe1,ye1,WHITE);
        x0=xe1;
        y0=ye1;
        p[0]=p0;
        x[0]=x0;
        y[0]=y0;
        for(int k=0;k<ydelta;k++)
        {
            if(p[k]<0)
            {
                 y3=y[k]+1-ye1;
                putpixel(x[k],y[k]+1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+constant3;
            }
            else
            {
                 y3=y[k]+1-ye1;
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+constant4;
            }
        }

    }
    delay(10000);
    cleardevice();
    closegraph();
}
