


#include<stdio.h>
#include<graphics.h>
#include<math.h>

int polylines(int,int,int,int,int,int);
int z;
int main()
{
    int gd=DETECT,gm,color;
    int xco,yco;
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x[50],y[50];

    printf("%d\t%d\n\n",x0,y0);
    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,YELLOW);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,YELLOW);

    int n;
    int h;
    printf("Enter the number of sides or edges\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter the %dth coordinate\n",i+1);
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);


    }
    x[n]=x[0];
    y[n]=y[0];

    for(i=0; i<n; i++)
        printf("%d\t%d\n",x[i],y[i]);
    while(z!=(n))
    {
        polylines(x[z],y[z],x[z+1],y[z+1],x0,y0);
        z++;
    }

    int xone,xtwo;
    for(yco=0; yco<dwHeight; yco++)
    {
        for(xco=0; xco<dwWidth; xco++)
        {

            color=getpixel(xco,yco);

            if(color==15)//color==white
            {

                xco++;
                xone=xco;
            if(getpixel(xone,yco)!=15)
                {
                    for(i=xco; i<dwWidth; i++)
                    {
                        color=getpixel(i,yco);
                        if(color==15)
                        {
                            xtwo=i;
                            for(i=xone; i<xtwo; i++)
                                putpixel(i,yco,CYAN);
                           // xone=xtwo;
                        }
                    }

                }
            }
        }
    }



    getch();
    cleardevice();
    closegraph();

}

int polylines(int x1,int y1,int x2,int y2,int x0,int y0)
{
    int y3,k;
    if(x1>=x2)
    {
        int temp1,temp2;
        temp1=x1;
        x1=x2;
        x2=temp1;
        temp2=y1;
        y1=y2;
        y2=temp2;
    }
    float xdel=x2-x1;
    float ydel=y2-y1;
    x1=x0+x1;
    x2=x0+x2;
    y1=y0-y1;
    y2=y0-y2;

    int p[500],x[500],y[500];
    x[0]=x1;
    y[0]=y1;

    float m=(ydel/xdel);
    putpixel(x1,y1,WHITE);

    if( m <=1 && m>0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }
            else
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }

        }
    }


    else if(m>=-1 && m<=0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }

        }
    }
    else if(m>1)
    {
        p[0]=(xdel-(ydel*0.5));

        for(k=0; k<ydel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k],y[k]+1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel;
            }
            else
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }

        }
    }
    else if(m<-1)
    {
        p[0]=(-xdel-(ydel*0.5));

        for(k=0; k<(-1)*ydel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k],y[k]-1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel;
            }

        }
    }


}


