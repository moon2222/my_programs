


#include<stdio.h>
#include<graphics.h>
#include<math.h>


int line_draw(int,int,int,int,int,int,int);
void compositetransform(int theta,int sx,int sy,int tx,int ty,int xc,int yc,int x1,int y1,int x2,int y2);

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int z;
int main()
{
    int gd=DETECT,gm,min=0,maximum=0,c, location,loc, pp,  o,m,counter=0,ix,iy,BC,IC,FC;
    int p[100];
	int color=3;
    int theta,sx,sy,tx,ty,xc,yc;
    double t,m1;
    c=initwindow (600,600,"Windows Anubhav",0, 0,false,true);
    int x0=300;
    int y0=300;
    int i,j,x[50],y[50];


    for(i=0; i<600; i++)
        putpixel(x0,i,RED);

    for(j=0; j<600; j++)
        putpixel(j,y0,RED);

    int n;
    printf("Enter the number of coordinates or vertices \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %dth coordinate\n",i+1);
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }
    for(i=0;i<n;i++)
        printf("%d\t%d\n",x[i],y[i]);
    while(z!=(n-1))
    {
        line_draw(x[z],y[z],x[z+1],y[z+1],x0,y0,color);
        z++;
    }


    printf("Enter theta,sx,sy,tx,ty,xc,yc");
    scanf("%d %d %d %d %d %d %d",&theta,&sx,&sy,&tx,&ty,&xc,&yc);
    for(i=0;i<n-1;i++)
    {

    compositetransform(theta,sx,sy,tx,ty,xc,yc,x[i],y[i],x[i+1],y[i+1]);}


    delay(40000);


    cleardevice();
    closegraph();

}

int line_draw(int sx1,int sy1,int sx2,int sy2,int xc,int yc,int color)
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

void compositetransform(int theta,int sx,int sy,int tx,int ty,int xc,int yc,int x1,int y1,int x2,int y2)
{
   int ct[3][3],xy[1][3],i,j,x_1,x_2,y_1,y_2;

   ct[0][0]=ceil(sx*cos(theta));
   ct[0][1]=ceil(-sy*sin(theta));
   ct[0][2]=ceil(xc*(1-sx*cos(theta)) + yc*sy*sin(theta)+tx);
   ct[1][0]=ceil(sx*sin(theta));
   ct[1][1]=ceil(sy*cos(theta));
   ct[1][2]=ceil(yc*(1-sy*cos(theta)) - xc*sx*sin(theta)+ty);
   ct[2][0]=0;
   ct[2][1]=0;
   ct[2][2]=1;
   x_1=ct[0][0]*x1+ct[0][1]*y1+ct[0][2]*1;
   y_1=ct[1][0]*x1+ct[1][1]*y1+ct[1][2]*1;
   x1=x_1;
   y1=y_1;
   x_2=ct[0][0]*x2+ct[0][1]*y2+ct[0][2]*1;
   y_2=ct[1][0]*x2+ct[1][1]*y2+ct[1][2]*1;
   x2=x_2;
   y2=y_2;
   printf("%d %d %d %d",x1,y1,x2,y2);
  line_draw(x1,y1,x2,y2,300,300,15);

}


