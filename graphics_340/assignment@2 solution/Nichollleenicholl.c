
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void line_draw(int sx1,int sy1,int sx2,int sy2,int xc,int yc,int color)
{
    int temp_y,i;
    if(sx1>=sx2)
    {
        int tmp1,tmp2;
        tmp1=sx1;
        sx1=sx2;
        sx2=tmp1;
        tmp2=sy1;
        sy1=sy2;
        sy2=tmp2;
    }
    float delta_x=sx2-sx1;
    float delta_y=sy2-sy1;
    sx1=xc+sx1;
    sx2=xc+sx2;
    sy1=yc-sy1;
    sy2=yc-sy2;

    int p[500],x[500],y[500];
    x[0]=sx1;
    y[0]=sy1;

    float m=(delta_y/delta_x);
    putpixel(sx1,sy1,color);

    if( m <=1 && m>0)
    {
        p[0]=(-0.5*delta_x-delta_y);
        for(i=0; i<delta_x; i++)
        {
            if(p[i]<0)
            {
                temp_y=y[i]+1-y[0];
                putpixel(x[i]+1,y[i]+1-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i]+1;
                p[i+1]=p[i]+delta_x-delta_y;
            }
            else
            {
                temp_y=y[i]-y[0];
                putpixel(x[i]+1,y[i]-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i];
                p[i+1]=p[i]-delta_y;
            }

        }
    }
	else if(m>1)
    {
        p[0]=(delta_x-(delta_y*0.5));

        for(i=0; i<delta_y; i++)
        {
            if(p[i]<0)
            {
                temp_y=y[i]+1-y[0];
                putpixel(x[i],y[i]+1-2*temp_y,color);
                x[i+1]=x[i];
                y[i+1]=y[i]+1;
                p[i+1]=p[i]+delta_x;
            }
            else
            {
                temp_y=y[i]+1-y[0];
                putpixel(x[i]+1,y[i]+1-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i]+1;
                p[i+1]=p[i]+delta_x-delta_y;
            }

        }
    }
void area1(int x1,int y1,int x2,int y2,int xc,int yc){
    float m1,m3,m5,ul,m2,m4,ur,ut,ub;

    m1=(float)(y1-yw_min)/(x1-xw_max);
    m2=(float)(y1-yw_max)/(x1-xw_max);
    m3=(float)(y1-yw_max)/(x1-xw_min);
    m4=(float)(y1-yw_min)/(x1-xw_min);
    m5=(float)(y1-y2)/(x1-x2);

    if((x2>=xw_min)&&(x2<=xw_max)&&(y2>=yw_min)&&(y2<=yw_max)){
         line_draw(x1,y1,x2,y2,xc,yc,14);
    }
    //right
    if(x2>xw_max){
        if((m5>=m1)||(m5<=m2)){
            ur=(float)(xw_max-x1)/(x2-x1);
            x2=xw_max;
            y2=floor(y1+(ur*(y2-y1))+0.5);
            line_draw(x1,y1,x2,y2,xc,yc,14);
        }
    }
    //top
    if(y2>yw_max){
        if((m5<m3)||(m5>m2)){
            ut=(float)(yw_max-y1)/(y2-y1);
            x2=x1 + floor(ut*(x2-x1)+0.5);
            y2=yw_max;
            line_draw(x1,y1,x2,y2,xc,yc,14);
        }
    }
    //left
    if(x2<xw_min){
        if((m5>=m3)||(m5<=m4)){
            ul=(float)(xw_min-x1)/(x2-x1);
            x2=xw_min;
            y2=floor(y1+(ul*(y2-y1))+0.5);
            line_draw(x1,y1,x2,y2,xc,yc,14);
        }
    }

    //bottom
    if(y2<yw_min){
        if((m5>m4)||(m5<m1)){
            ub=(float)(yw_min-y1)/(y2-y1);
            x2=x1 + floor(ub*(x2-x1)+0.5);
            y2=yw_min;
            line_draw(x1,y1,x2,y2,xc,yc,14);
        }
    }

}
//area 2
void area2(int x1,int y1,int x2,int y2,int xc,int yc,int crossed){
    float m1,m2,m3,m4,m5,ul,ur,ut,ub;

    m1=(float)(y1-yw_min)/(x1-xw_max);
    m2=(float)(y1-yw_max)/(x1-xw_max);
    m3=(float)(y1-yw_max)/(x1-xw_min);
    m4=(float)(y1-yw_min)/(x1-xw_min);
    m5=(float)(y1-y2)/(x1-x2);

    float cross=(float)(xw_min+xw_max)/2;
    //left right
    if(x2>xw_max){
        if((m5>=m1)&&(m5<=m2)){
            ul=(float)(xw_min-x1)/(x2-x1);
            x1=xw_min;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ur=(float)(xw_max-x1)/(x2-x1);
            x2=xw_max;
            y2=floor(y1+(ur*(y2-y1))+0.5);
            if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   x1=((cross*2)-x1+0.5);
                   x2=((cross*2)-x2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
        }
    }
    //left top
    if((y2>yw_max)&&(x2>xw_min)){
        if((m5<m3)&&(m5>m2)){
            ul=(float)(xw_min-x1)/(x2-x1);
            x1=xw_min;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ut=(float)(yw_max-y1)/(y2-y1);
            x2=x1 + floor(ut*(x2-x1)+0.5);
            y2=yw_max;
            if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            else{
                   x1=((cross*2)-x1+0.5);
                   x2=((cross*2)-x2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
            }
           }
    }

    //left bottom
    if((y2<yw_min)&&(x2>xw_min)){
        if((m5>m4)&&(m5<m1)){
            ul=(float)(xw_min-x1)/(x2-x1);
            x1=xw_min;
            y1=floor(y1+(ul*(y2-y1))+0.5);

            ub=(float)(yw_min-y1)/(y2-y1);
            x2=x1 + floor(ub*(x2-x1)+0.5);
            y2=yw_min;
            if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   x1=((cross*2)-x1+0.5);
                   x2=((cross*2)-x2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
        }
    }
}
//area 3
void area3(int x1,int y1,int x2,int y2,int xc,int yc,int crossed){
    float m1,m2,m3,m4,m5,ul,ur,ut,ub;
    float cross=(float)(yw_min+yw_max)/2;
    m1=(float)(y1-yw_min)/(x1-xw_max);
    m2=(float)(y1-yw_max)/(x1-xw_max);
    m3=(float)(y1-yw_max)/(x1-xw_min);
    m4=(float)(y1-yw_min)/(x1-xw_min);
    m5=(float)(y1-y2)/(x1-x2);

    if(m3<-1){
    //top right
        if((x2>xw_max)&&(y2<yw_max)){
            if((m5>=m1)&&(m5<=m2)){
                ut=(float)(yw_max-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=yw_max;

                ur=(float)(xw_max-x1)/(x2-x1);
                x2=xw_max;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }
    //top bottom
        if((y2<yw_min)&&(x2>xw_min)){
            if((m5>m3)&&(m5<m1)){
                ut=(float)(yw_max-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=yw_max;

                ub=(float)(yw_min-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=yw_min;
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }

    //left bottom
        if((y2<yw_min)&&(x2>xw_min)){
            if((m5>=m4)&&(m3>=m5)){
                ul=(float)(xw_min-x1)/(x2-x1);
                x1=xw_min;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ub=(float)(yw_min-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=yw_min;
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }
    }
    else if(m3>=-1){
        //top right
        if((x2>xw_max)&&(y2<yw_max)){
            if((m5>=m3)&&(m5<=m2)){
                ut=(float)(yw_max-y1)/(y2-y1);
                x1=x1 + floor(ut*(x2-x1)+0.5);
                y1=yw_max;

                ur=(float)(xw_max-x1)/(x2-x1);
                x2=xw_max;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }
    //left right
        if((y2<yw_max)&&(x2>xw_max)){
            if((m5<m3)&&(m5>m1)){
                ul=(float)(xw_min-x1)/(x2-x1);
                x1=xw_min;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ur=(float)(xw_max-x1)/(x2-x1);
                x2=xw_max;
                y2=floor(y1+(ur*(y2-y1))+0.5);
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }

    //left bottom
        if((y2<yw_min)&&(x2>xw_min)){
            if((m5>=m4)&&(m1>=m5)){
                ul=(float)(xw_min-x1)/(x2-x1);
                x1=xw_min;
                y1=floor(y1+(ul*(y2-y1))+0.5);

                ub=(float)(yw_min-y1)/(y2-y1);
                x2=x1 + floor(ub*(x2-x1)+0.5);
                y2=yw_min;
                if(crossed==0){
                line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==2){
                  cross=(float)(xw_min+xw_max)/2;
                  x1=floor((cross*2)-x1+0.5);
                  x2=floor((cross*2)-x2+0.5);
                  line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else if(crossed==3){
                    cross=(float)(xw_min+xw_max)/2;
                    x1=floor((cross*2)-x1+0.5);
                    x2=floor((cross*2)-x2+0.5);
                    cross=(float)(yw_min+yw_max)/2;
                    y1=floor((cross*2)-y1+0.5);
                    y2=floor((cross*2)-y2+0.5);
                    line_draw(x1,y1,x2,y2,xc,yc,14);
                }
                else{
                   y1=((cross*2)-y1+0.5);
                   y2=((cross*2)-y2+0.5);
                   line_draw(x1,y1,x2,y2,xc,yc,14);
                }
            }
        }

    }

}
//get area
int area(int x1,int y1,int x2,int y2){
     if((x1>=xw_min)&&(x1<=xw_max)&&(y1>=yw_min)&&(y1<=yw_max)){
         return 11;
     }
     else if((x2>=xw_min)&&(x2<=xw_max)&&(y2>=yw_min)&&(y2<=yw_max)){
         return 12;
     }
     else if((x1<=xw_min)&&(y1>=yw_min)&&(y1<=yw_max)){
         return 21;
     }
     else if((x2<=xw_min)&&(y2>=yw_min)&&(y2<=yw_max)){
         return 22;
     }
     else if((x1<=xw_min)&&(y1>=yw_max)){
         return 31;
     }
     else if((x2<=xw_min)&&(y2>=yw_max)){
         return 32;
     }

     //extra
     else if((x1<=xw_min)&&(y1<=yw_min)){
         return 41;
     }
     else if((x2<=xw_min)&&(y2<=yw_min)){
         return 42;
     }

    else if((x1>=xw_max)&&(y1<=yw_max)&&(y1>=yw_min)){
         return 51;
     }
     else if((x2>=xw_max)&&(y2<=yw_max)&&(y2>=yw_min)){
         return 52;
     }
     else if((x1>=xw_max)&&(y1>=yw_max)){
         return 61;
     }
     else if((x2>=xw_max)&&(y2>=yw_max)){
         return 62;
     }

     else if((x1>=xw_max)&&(y1<=yw_min)){
         return 71;
     }
     else if((x2>=xw_max)&&(y2<=yw_min)){
         return 72;
     }
     else if((x1<=xw_max)&&(x1>=xw_min)&&(y1>=yw_max)){
         return 81;
     }
     else if((x2<=xw_max)&&(x2>=xw_min)&&(y2>=yw_max)){
         return 82;
     }

}

// draw line between two vertices passed as parameter



    else if(m>=-1 && m<=0)
    {
        p[0]=(-0.5*delta_x-delta_y);
        for(i=0; i<delta_x; i++)
        {
            if(p[i]<0)
            {
                temp_y=y[i]-y[0];
                putpixel(x[i]+1,y[i]-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i];
                p[i+1]=p[i]-delta_y;
            }
            else
            {
                temp_y=y[i]-1-y[0];
                putpixel(x[i]+1,y[i]-1-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i]-1;
                p[i+1]=p[i]-delta_x-delta_y;
            }

        }
    }

    else if(m<-1)
    {
        p[0]=(-delta_x-(delta_y*0.5));

        for(i=0; i<(-1)*delta_y; i++)
        {
            if(p[i]<0)
            {
                temp_y=y[i]-1-y[0];
                putpixel(x[i]+1,y[i]-1-2*temp_y,color);
                x[i+1]=x[i]+1;
                y[i+1]=y[i]-1;
                p[i+1]=p[i]-delta_x-delta_y;
            }
            else
            {
                temp_y=y[i]-1-y[0];
                putpixel(x[i],y[i]-1-2*temp_y,color);
                x[i+1]=x[i];
                y[i+1]=y[i]-1;
                p[i+1]=p[i]-delta_x;
            }

        }
    }


}


int xw_min,yw_min,xw_max,yw_max;


int main()
{
    int gd=DETECT,gm,fill_color,boundary_color,temp,color=5;
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int xc=dwWidth/2;
    int yc=dwHeight/2;
    int i,j,p1[50],p2[50],q1[50],q2[50];

    printf("%d\t%d\n\n",xc,yc);
    for(i=0; i<dwHeight; i++)
        putpixel(xc,i,4);

    for(j=0; j<dwWidth; j++)
        putpixel(j,yc,4);

    int n,yw_min,xw_min,xw_max,yw_max;
    int h;

    printf("Enter the number of lines\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the starting coordinate %dth line\n",i+1);
        scanf("%d",&p1[i]);
        scanf("%d",&q1[i]);
        printf("Enter the ending coordinate %dth line\n",i+1);
        scanf("%d",&p2[i]);
        scanf("%d",&q2[i]);
        color=15;
        line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);

    }
    printf("Enter the coordinate of rectangle clipping window \n");
    printf("Enter the first cordinates\n ");
    scanf("%d",&xw_min);
    scanf("%d",&yw_min);
    printf("Enter the second cordinates\n ");
    scanf("%d",&xw_max);
    scanf("%d",&yw_max);


     if((xw_min>xw_max)&&(yw_min>yw_max)){
        temp=xw_min;
        xw_min=xw_max;
        xw_max=temp;
        temp=yw_min;
        yw_min=yw_max;
        yw_max=temp;
     }
     else if((xw_min>xw_max)&&(yw_min<yw_max)){
        temp=xw_min;
        xw_min=xw_max;
        xw_max=temp;
     }
     else if((xw_min<xw_max)&&(yw_min>yw_max)){
        temp=yw_min;
        yw_min=yw_max;
        yw_max=temp;
     }
     int areaFlag=0;
      //got clipping window
      //rubbing the earlier polygon
      int crossed=0;
      float cross,ut;

     for(i=0;i<n;i++){

            if((n==2)&&(i==1)){
                break;
            }
            areaFlag=area(p1[i],q1[i],p2[i],q2[i]);
            if(areaFlag==11){
                area1(p1[i],q1[i],p2[i],q2[i],xc,yc);
            }
            else if(areaFlag==12){
                area1(p2[i],q2[i],p1[i],q1[i],xc,yc);
            }
            else if(areaFlag==21){
                area2(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==22){
                area2(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==31){
                area3(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==32){
                area3(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==41){
                cross=(float)(yw_min+yw_max)/2;
                q1[i]=floor((cross*2)-q1[i]+0.5);
                q2[i]=floor((cross*2)-q2[i]+0.5);
                crossed=1;
                area3(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==42){
                cross=(float)(yw_min+yw_max)/2;
                q1[i]=floor((cross*2)-q1[i]+0.5);
                q2[i]=floor((cross*2)-q2[i]+0.5);
                crossed=1;
                area3(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==51){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                crossed=1;
                area2(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==52){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                crossed=1;
                area2(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==61){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                crossed=2;
                area3(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==62){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                crossed=2;
                area3(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==71){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                cross=(float)(yw_min+yw_max)/2;
                q1[i]=floor((cross*2)-q1[i]+0.5);
                q2[i]=floor((cross*2)-q2[i]+0.5);
                crossed=3;
                area3(p1[i],q1[i],p2[i],q2[i],xc,yc,crossed);
            }
            else if(areaFlag==72){
                cross=(float)(xw_min+xw_max)/2;
                p1[i]=floor((cross*2)-p1[i]+0.5);
                p2[i]=floor((cross*2)-p2[i]+0.5);
                cross=(float)(yw_min+yw_max)/2;
                q1[i]=floor((cross*2)-q1[i]+0.5);
                q2[i]=floor((cross*2)-q2[i]+0.5);
                crossed=3;
                area3(p2[i],q2[i],p1[i],q1[i],xc,yc,crossed);
            }
            else if(areaFlag==81){
                ut=(float)(yw_max-q1[i])/(q2[i]-q1[i]);
                if((ut>=0.0)&&(ut<=1.0)){
                   p1[i]=p1[i] + floor(ut*(p2[i]-p1[i])+0.5);
                   q1[i]=yw_max;
                   area1(p1[i],q1[i],p2[i],q2[i],xc,yc);
                }
            }
            else if(areaFlag==82){
                ut=(float)(yw_max-q1[i])/(q2[i]-q1[i]);
                if((ut>=0.0)&&(ut<=1.0)){
                   p2[i]=p1[i] + floor(ut*(p2[i]-p1[i])+0.5);
                   q2[i]=yw_max;
                   area1(p2[i],q2[i],p1[i],q1[i],xc,yc);
                }
            }


     }
     line_draw(xw_min,yw_min,xw_max,yw_min,xc,yc,12);
     line_draw(xw_max,yw_min,xw_max,yw_max,xc,yc,12);
     line_draw(xw_max,yw_max,xw_min,yw_max,xc,yc,12);
     line_draw(xw_min,yw_max,xw_min,yw_min,xc,yc,12);
    delay(90000);
    return 0;
}


