
#include<stdio.h>
#include<graphics.h>
#include<math.h>


int line_draw(int,int,int,int,int,int,int);
void floodfill4(int, int,int);

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
    double t,m1;
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x[50],y[50];
    double xc[50],yc[50];

    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
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



    //Here
    printf("Enter interior cordinates ix and iy and fill colour \n");
    scanf("%d%d%d",&ix,&iy,&IC);
    floodfill4(x0+ix,y0-iy,IC);

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

void floodfill4(int x , int y,int IC)
{
    if(getpixel(x,y)==0)
    {
        putpixel(x,y,IC);
        floodfill4( x+1,  y, IC);
        floodfill4( x-1,  y, IC);
        floodfill4( x,  y+1, IC);
        floodfill4( x, y-1, IC);
    }
}


