
#include <stdio.h>
#include <math.h>
#include <graphics.h>


int main()
{
    int gd=DETECT,gm,i,j;
    //initgraph(&gd,&gm,NULL);
    int x1,x2,xt,yt,y1,y2,steps;
    float delx,dely,dx,dy,m,m1,m2,m3;
    float p[500],x[500],y[500];

    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    printf("width = %d\n",dwWidth);
    printf("height = %d\n",dwHeight);
    xt = dwWidth/2;
    yt = dwHeight/2;
   /* for(i=0;i<=dwHeight;i++)
        putpixel(xt,i,RED);
    for(i=0;i<=dwWidth;i++)
        putpixel(i,yt,RED);*/


    printf("Enter the starting position of x co-ordinate :: ");
    scanf("%d",&x1);
    printf("Enter the ending position of x co-ordinate :: ");
    scanf("%d",&x2);
    printf("Enter the starting position of y co-ordinate :: ");
    scanf("%d",&y1);
    printf("Enter the ending position of y co-ordinate :: ");
    scanf("%d",&y2);
    /*x1 = x1+xt;
    x2 = x2+xt;
    y1 = -(yt+y1);
    y2 = -(yt+y1);
*/
    delx = x2-x1;
    dely = y2-y1;
    m = dely/delx;

    if((m>0) && (m<1))
    {
        m1 = 2*dely;
        m2 = 2*delx;
        m3 = m1-m2;

        p[0] = 2*dely-delx;
        putpixel(x1,y1,WHITE);
        x[0] = x1;
        y[0] = y1;
        int k;

        for(k=0; k<=delx; k++)
        {
            if(p[k] < 0)
            {
                putpixel(x[k]+1,y[k],WHITE);
                putpixel(x[k]+1,y[k]+1,WHITE);
                putpixel(x[k]+1,y[k]+2,WHITE);
                putpixel(x[k]+1,y[k]+3,WHITE);
                putpixel(x[k]+1,y[k]+4,WHITE);
                x[k+1] = x[k]+1;
                y[k+1] = y[k];
                p[k+1] = p[k] + m1;
            }
            else
            {
                putpixel(x[k]+1,y[k]+1,WHITE);
                putpixel(x[k]+1,y[k]+2,WHITE);
                putpixel(x[k]+1,y[k]+3,WHITE);
                putpixel(x[k]+1,y[k]+4,WHITE);
                putpixel(x[k]+1,y[k]+5,WHITE);
                x[k+1] = x[k]+1;
                y[k+1] = y[k]+1;
                p[k+1] = p[k] + m1 - m2;
            }

        }
    }

    else if(m>1)
    {
        m1 = 2*delx;
        m2 = 2*dely;
        m3 = m1-m2;

        p[0] = 2*delx-dely;
        putpixel(x1,y1,WHITE);
        x[0] = x1;
        y[0] = y1;
        int k;

        for(k=0; k<=dely; k++)
        {
            if(p[k] < 0)
            {
                putpixel(x[k],y[k]+1,WHITE);
                putpixel(x[k],y[k]+2,WHITE);
                putpixel(x[k],y[k]+3,WHITE);
                putpixel(x[k],y[k]+4,WHITE);
                putpixel(x[k],y[k]+5,WHITE);
                x[k+1] = x[k];
                y[k+1] = y[k]+1;
                p[k+1] = p[k] + m1;
            }
            else
            {
                putpixel(x[k]+1,y[k]+1,WHITE);
                putpixel(x[k]+1,y[k]+2,WHITE);
                putpixel(x[k]+1,y[k]+3,WHITE);
                putpixel(x[k]+1,y[k]+4,WHITE);
                putpixel(x[k]+1,y[k]+5,WHITE);
                x[k+1] = x[k]+1;
                y[k+1] = y[k]+1;
                p[k+1] = p[k] + m1 - m2;
            }

        }
    }


    delay(30000);
    cleardevice();
    closegraph();

}
