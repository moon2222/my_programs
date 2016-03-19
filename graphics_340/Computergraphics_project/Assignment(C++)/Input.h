
#include <iostream>
#include <graphics.h>
#include <cmath>

#define PI 3.14159265


//////................Straight lines ............./////////
class Input{
    float x1,y1;
    float x2,y2;
public:
    void setPoints(float a,float b,float c,float d){
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
    } //end function points

    //Implementaion of straight line drawing using DDA Algorithm
    void DDAAlgorithm(float a,float b,float c,float d){
        setPoints(a,b,c,d);
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");

        float dx,dy;
        float Dx,Dy;
        float x0,y0;
        float steps;

        Dx = x2-x1;
        Dy = y2-y1;

        if(abs(Dx) > abs(Dy))
        {
            steps = abs(Dx);
        }
        else
        {
            steps = abs(Dy);
        }

        dx = Dx/steps;
        dy = Dy/steps;

        for(x0 = x1,y0 = y1; x0 <= x2,y0 <= y2; x0 = x0 + dx, y0 = y0 + dy) //line drawing
        {
            putpixel(x0,y0,255);
        }

        delay(5000);
        closegraph();
    } // end of DDA Algorithm

    void BresenhamAlgorithm(float a,float b,float c,float d){
        setPoints(a,b,c,d);
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");

        int i;
        float Dx,Dy;
        float x0,y0;
        float p0;

        Dx = x2 - x1;
        Dy = y2 - y1;

        p0 = 2*Dy - Dx;

        x0 = x1;
        y0 = y1;

        for(i=0; i<Dx; i++) //line drawing
        {
            if(p0 < 0)
            {
                x0 = x0 + 1;
                p0 = p0 + 2*Dy;
                putpixel(x0,y0,255);
            }
            else
            {
                x0 = x0 + 1;
                y0 = y0 + 1;
                p0 = p0 + 2*(Dy - Dx);
                putpixel(x0,y0,255);
            }
        }

        delay(5000);
        closegraph();
    } // End of Bresenham's Algorithm

    void WuAlgorithm(float a,float b,float c,float d)
    {
        setPoints(a,b,c,d);
        int gd=DETECT,gm;
        initgraph(&gd,&gm,"");

        float dx,dy;
        float Dx,Dy;
        float x0,y0;
        float temp;
        float m;
        float yinter,x0gap;
        float xf,yf,xfgap;
        float i;

        Dx = x2-x1;
        Dy = y2-y1;
        m = Dy/Dx;

        if(abs(m) < 1)
        {
            if(x1 > x2)
            {
                temp = x1;  //swaping x1, x2
                x1 = x2;
                x2 = temp;

                temp = y1;  //swaping y1, y2
                y1 = y2;
                y2 = temp;
                Dx = x2-x1;
                Dy = y2-y1;
                m = Dy/Dx;

                x0 = floor(x1 + 0.5);
                y0 = y1 + m*(x0 - x1);
                yinter = y0 + m;
                x0gap = floor(x1 + 0.5) + 0.5 - x1;
                putpixel(x0,floor(y0),(floor(y0)+1-y0)*x0gap);
                putpixel(x0,floor(y0)+1,(y0 - floor(y0))*x0gap);

                xf = floor(x2 + 0.5);
                yf = y2 + m*(xf - x2);
                xfgap = x2 + 0.5 - floor(x2 + 0.5);
                putpixel(xf,floor(yf),(floor(yf)+1-yf)*xfgap);
                putpixel(xf,floor(yf)+1,(yf - floor(yf))*xfgap);

                for(i = x0 + 1; i <= xf - 1;i++)
                {
                    putpixel(i,floor(yinter),255);
                    putpixel(i,floor(yinter) + 1,255);
                    putpixel(i+1,floor(yinter),255);
                    putpixel(i+1,floor(yinter) + 1,255);
                    putpixel(i+2,floor(yinter),255);
                    putpixel(i+2,floor(yinter) + 1,255);
                    putpixel(i+3,floor(yinter),255);
                    putpixel(i+3,floor(yinter) + 1,255);
                    yinter = yinter + m;
                }

            }
        }
        delay(5000);
        closegraph();
    }// End of Wu Algorithm*/

};

///////////////////////// ........ Circles .............///////////

class Circle{
    float xc,yc,r;

public:
    void setPoints(float m,float n,float o){
        xc = m;
        yc = n;
        r = o;
    } //end function points

    // Implementation of circle using coordinate points
void CircleCoordinate(float m, float n, float o)
{
    setPoints(m,n,o);
    //* initialize the window

    initwindow(1300,700);

    //* Drawing coordinate axes
    int xa,ya;
    xa=650;
    for(ya=0;ya<=700;ya++)
    {
        putpixel(xa,ya,255);
    }
    ya=350;
    for(xa=0;xa<=1300;xa++)
    {
        putpixel(xa,ya,255);
    }

    // (xc,yc) is centre of circle
    //r is radius of circle

   xc=xc+650;
   yc=350-yc;

   //Drawing Circle

   int a =floor(((xc - r) + 0.5));
   int b =floor(((xc + r) + 0.5));
   putpixel( a, floor(yc + 0.5),1);
   putpixel( b, floor(yc + 0.5),1);
   int x=0;
   int y;
   for(x=a+1;x<b;x++)
   {
       y = yc + sqrt((r * r) - ((xc - x) * (xc-x)));
       putpixel(x,floor(y + 0.5),1);
       y = yc - sqrt((r * r) - ((xc - x) * (xc-x)));
       putpixel(x,floor(y + 0.5),1);
   }

   delay(10000);
   closegraph();
}

// Implementation of Parametric circle
void CircleParametric(float m, float n, float o)
{
    setPoints(m,n,o);

    //initializing the window
    initwindow(1300,700);
    int xa,ya;

    // Drawing Coordinate axes
    xa=650;
    for(ya=0;ya<=700;ya++)
    {
        putpixel(xa,ya,255);
    }
    ya=350;
    for(xa=0;xa<=1300;xa++)
    {
        putpixel(xa,ya,255);
    }

   xc=xc+650;
   yc=350-yc;
   putpixel(floor(xc + 0.5),floor(yc + r +0.5),1);
   putpixel(floor(xc + 0.5),floor((yc - r) +0.5),1);
   putpixel(floor(xc + r + 0.5),floor(yc + 0.5),1);
   putpixel(floor((xc - r) + 0.5),floor(yc + 0.5),1);
   float theta = 1;
   float delta_theta = 1;
   float radian = 3.14/180;
   float x,y;
   while(theta<45)
   {
       x = r * cos(theta * radian);
       y = r * sin(theta * radian);
       putpixel(floor(xc + x + 0.5),floor(yc + y +0.5),1);
       putpixel(floor(xc + x + 0.5),floor((yc - y) +0.5),1);
       putpixel(floor((xc - x) + 0.5),floor(yc + y +0.5),1);
       putpixel(floor((xc - x) + 0.5),floor((yc - y) +0.5),1);
       putpixel(floor(xc + y + 0.5),floor(yc + x +0.5),1);
       putpixel(floor(xc + y + 0.5),floor((yc -x) +0.5),1);
       putpixel(floor((xc -y) + 0.5),floor(yc + x +0.5),1);
       putpixel(floor((xc -y) + 0.5),floor((yc -x) +0.5),1);

       theta = theta + delta_theta;
   }

   if(theta = 45)
   {
     x = r * cos(theta * radian);
     y = r * cos(theta * radian);
     putpixel(floor(xc + x + 0.5),floor(yc + y +0.5),1);
       putpixel(floor(xc + x + 0.5),floor((yc - y) +0.5),1);
       putpixel(floor((xc - x) + 0.5),floor(yc + y +0.5),1);
       putpixel(floor((xc - x) + 0.5),floor((yc - y) +0.5),1);

   }

   delay(10000);
   closegraph();
}

};

///////////...............Ellipse.........//////////

class Ellipses{
    float xc,yc,rx,ry;

public:
    void setPoints(float m,float n,float o,float p){
        xc = m;
        yc = n;
        rx = o;
        ry = p;
    } //end function points

    // Implementation of ellipse using cartesian points
void EllipseCartesian(int m, int n, int o,int p)
{
    setPoints(m,n,o,p);

    int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    //setbkcolor(GREEN);
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x1,y1,x2,x3,y2,y3,x,y,xc1,yc1;

    //cout << "Center of the screen is :\n";
    //cout << "x0 = " << x0 << "\n";
    //cout << "y0 = " << y0 << "\n";

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
            putpixel(xc1+x,yc1+y,WHITE);
            putpixel(xc1-x,yc1+y,WHITE);
            putpixel(xc1+x,yc1-y,WHITE);
            putpixel(xc1-x,yc1-y,WHITE);
            x=x-1;
        }
    }
    else
    {
        while(y>0)
        {
            x=sqrt((rx*rx)-(rx*rx*y*y)/(ry*ry))+0.5;
            //cout << x;
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

// Implementation of ellipse using mid points
void EllipseMidPoints(int m, int n, int o,int p)
{
    setPoints(m,n,o,p);

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


    //cout << "Center of the screen is :\n";
    //cout << "x0 = " << x0 << "\n";
    //cout << "y0 = " << y0 << "\n";

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
    closegraph();
}

//Implementation of ellipse using parametric
void EllipseParametric(int m, int n, int o,int p)
{
    setPoints(m,n,o,p);

    int gd=DETECT,gm;
    //initgraph(&gd,&gm,NULL);
    //setbkcolor(GREEN);
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j;
    int x1,y1,x2,y2,y3,x3,x4,y4;
    float theta,dtheta,x,y;
    float val=PI/180;

    //cout << "Center of the screen is :\n";
    //cout << "x0 = " << x0 << "\n";
    //cout << "y0 = " << y0 << "\n";

    for(i=0;i<dwHeight;i++)
            putpixel(x0,i,WHITE);

    for(j=0;j<dwWidth;j++)
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

};
