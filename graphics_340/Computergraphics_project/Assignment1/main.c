#include<stdio.h>
#include<graphics.h>
#include<math.h>

#define PI 3.14159265

int main()
{
    int option;
    printf("1.Line Drawing(DDA algorithm)\n2.Line Drawing(Bresenham's Algo)\n"
           "3.Line Drawing(Wu's Algo)\n4.ThickLine(Bresenham's Algo)\n"
           "5.ThickLine(Wu's Algo)\n6.Circle(Cartesian approach)\n"
           "7.Circle(Parametric Algo)\n8.Ellipse(Cartesian approach)\n"
           "9.Ellipse(Parametric Algo)\n10.Ellipse(MidPoint Algo)\n");

    printf("Please enter the number of Algo which you want to use for your graphic design:\n");
    scanf("%d",&option);
    if(option==1){
        int gd=DETECT,gm;
        initgraph(&gd,&gm,NULL);
        int xe1,xe2,x0,y0,ye1,ye2,xdelta,ydelta,steps;
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
        xdel=(xdelta/steps);
        ydel=(ydelta/steps);
        putpixel(xe1,ye1,WHITE);
        x0=xe1;
        y0=ye1;
        int k;
        float x[800],y[800];
        x[0]=x0;
        y[0]=y0;
        for(k=1; k<steps; k++)
        {
            x[k]=x[k-1]+xdel;
            y[k]=y[k-1]+ydel;
            putpixel(x[k],y[k],WHITE);
        }
        delay(10000);
        cleardevice();
        closegraph();
    }
    else if(option==2){
        int gd=DETECT,gm;
        initgraph(&gd,&gm,NULL);
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
        float p[500],x[500],y[500];
        float m=(ydelta/xdelta);
        if(m>0 && m<1)
        {
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
            for(k=0; k<xdelta; k++)
            {
                if (p[k]<0)
                {
                    putpixel(x[k]+1,y[k],WHITE);
                    x[k+1]=x[k]+1;
                    y[k+1]=y[k];
                    p[k+1]=p[k]+constant1;
                }
                else
                {
                    putpixel(x[k]+1,y[k]+1,WHITE);
                    x[k+1]=x[k]+1;
                    y[k+1]=y[k]+1;
                    p[k+1]=p[k]+constant2;
                }
            }
        }
        else if(m>1)
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
            for(int k=0; k<ydelta; k++)
            {
                if(p[k]<0)
                {
                    putpixel(x[k],y[k]+1,WHITE);
                    x[k+1]=x[k];
                    y[k+1]=y[k]+1;
                    p[k+1]=p[k]+constant3;
                }
                else
                {
                    putpixel(x[k]+1,y[k]+1,WHITE);
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
    else if(option==3){
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
            for(k=x1+1; k<=x2-1; k++)
            {
                yinterf = yinter;
                col = yinterf+1-yinter;
                putpixel(k,yinterf,col);
                col = yinter - yinterf;
                putpixel(k,yinterf+1,col);
                yinter = yinter + m;

            }


        }





        delay(30000);
        cleardevice();
        closegraph();
    }
    else if(option==4){
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
    else if(option==5){
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
            for(k=x1+1; k<=x2-1; k++)
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
   else if(option==6){
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
        for(i=0; i<dwHeight; i++)
            putpixel(x0,i,WHITE);

        for(j=0; j<dwWidth; j++)
            putpixel(j,y0,WHITE);


        xc=x0+xc;
        yc=y0-yc;

        x1=xc-radius+0.5;
        y1=yc+0.5;
        x2=xc+radius+0.5;
        y2=yc+0.5;
        putpixel(x1,y1,WHITE);
        putpixel(x2,y2,WHITE);

        for(x=x1+1; x<=x2-1; x++)
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
    else if(option==7){
        int gd=DETECT,gm;
        //initgraph(&gd,&gm,NULL);
        //setbkcolor(GREEN);
        DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
        DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
        initwindow(dwWidth/2,dwHeight/2);
        int x0=dwWidth/4;
        int y0=dwHeight/4;
        int i,j;
        int radius,xc,yc,x1,y1,x2,y2,y3,x3,x4,y4;
        float theta,dtheta,x,y;
        float val=PI/180;

        printf("Center of the screen is :\n");
        printf("x0=%d\n",x0);
        printf("y0=%d\n",y0);
        printf("enter x-coordinate of center\n");
        scanf("%d",&xc);
        printf("enter y-coordinate of center\n");
        scanf("%d",&yc);
        printf("Enter the radius\n");
        scanf("%d",&radius);
        for(i=0; i<dwHeight; i++)
            putpixel(x0,i,WHITE);

        for(j=0; j<dwWidth; j++)
            putpixel(j,y0,WHITE);


        xc=x0+xc;
        yc=y0-yc;
        x1=xc+0.5;
        y1=yc+radius+0.5;
        y2=yc-radius+0.5;
        x2=xc+radius+0.5;
        y3=yc+0.5;
        x3=xc-radius+0.5;
        putpixel(x1,y1,WHITE);
        putpixel(x1,y2,WHITE);
        putpixel(x2,y3,WHITE);
        putpixel(x3,y3,WHITE);
        theta = 1;
        dtheta=1;
        while(theta<45)
        {
            x=radius*cos(theta*val);
            y=radius*sin(theta*val);
            x1=xc+x+0.5;
            y1=yc+y+0.5;
            x2=xc-x+0.5;
            y2=yc-y+0.5;
            x3=xc+y+0.5;
            y3=yc+x+0.5;
            x4=xc-y+0.5;
            y4=yc-x+0.5;
            putpixel(x1,y1,WHITE);
            putpixel(x1,y2,WHITE);
            putpixel(x2,y1,WHITE);
            putpixel(x2,y2,WHITE);
            putpixel(x3,y3,WHITE);
            putpixel(x3,y4,WHITE);
            putpixel(x4,y3,WHITE);
            putpixel(x4,y4,WHITE);
            theta=theta+dtheta;
        }
        if(theta==45)
        {
            x=radius*cos(theta*val);
            y=radius*cos(theta*val);
            x1=xc+x+0.5;
            x2=xc-x+0.5;
            y1=yc+y+0.5;
            y2=yc-y+0.5;
            putpixel(x1,y1,WHITE);
            putpixel(x1,y2,WHITE);
            putpixel(x2,y1,WHITE);
            putpixel(x2,y2,WHITE);
        }
        delay(10000);
        cleardevice();
        closegraph();
    }
    else if(option==8){
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
        for(i=0; i<dwHeight; i++)
            putpixel(x0,i,WHITE);

        for(j=0; j<dwWidth; j++)
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
    else if(option==9){
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
        for(i=0; i<dwHeight; i++)
            putpixel(x0,i,WHITE);

        for(j=0; j<dwWidth; j++)
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
    else if(option==10){
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
        for(i=0; i<dwHeight; i++)
            putpixel(x0,i,WHITE);

        for(j=0; j<dwWidth; j++)
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
    else
        printf("YOU ENTERED WRONG CHOICE!!! SORRY, WE CAN'T PROCEED\n");
    }

