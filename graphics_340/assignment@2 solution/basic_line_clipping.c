#include<stdio.h>
#include<graphics.h>
#include<math.h>

int line_draw(int,int,int,int,int,int,int);
int z;

int main()
{
    int gd=DETECT,gm,color,fill_color,boundary_color;
    int xco,yco;
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

    //drawing clipping window
    color=10;
    line_draw(xw_min,yw_min,xw_max,yw_min,xc,yc,color);
    line_draw(xw_max,yw_min,xw_max,yw_max,xc,yc,color);

    line_draw(xw_max,yw_max,xw_min,yw_max,xc,yc,color);

    line_draw(xw_min,yw_max,xw_min,yw_min,xc,yc,color);



    // start clipping algorithm
    int sFlag ,tFlag;
    int clipFlag=0;
    float ul,ur,ub,ut;
    for(i=0; i<n; i++)
    {
        if(xw_min<=p1[i]&&p1[i]<=xw_max)
        {

            if(yw_min<=q1[i]&&q1[i]<=yw_max)
                sFlag=0;
        }
        else
        {
            sFlag=1;
        }
        if(xw_min<=p2[i]&&p2[i]<=xw_max)

        {
            if(yw_min<=q2[i]&&q2[i]<=yw_max)
                tFlag=0;
        }
        else
        {
            tFlag=1;
        }

        if(sFlag==0&&tFlag==0)
        {
            color=6;
            line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);

        }
        else
        {
            if((p1[i]<xw_min)&&(p2[i]<xw_min))
            {
                clipFlag=1;
                color=15;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((xw_max<p1[i])&&(xw_max<p2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }

            if((yw_max<q1[i])&&(yw_max<q2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((q1[i]<yw_min)&&(q2[i]<yw_min))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                continue;
            }






            if(sFlag==0&&tFlag==1||sFlag==1&&tFlag==0||sFlag==1&&tFlag==1)
            {

                ul=(float)(xw_min-p1[i])/(p2[i]-p1[i]);
                if((ul<1.0)&&(ul>0.0))
                {
                    if(p1[i]<p2[i])
                    {
                        p1[i]=xw_min;
                        q1[i]=floor(q1[i]+(ul*(q2[i]-q1[i]))+0.5);
                    }
                    else
                    {
                        p2[i]=xw_min;
                        q2[i]=floor(q1[i]+(ul*(q2[i]-q1[i]))+0.5);
                    }
                }
                //***********************************************

            if((p1[i]<xw_min)&&(p2[i]<xw_min))
            {
                clipFlag=1;
                color=15;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((xw_max<p1[i])&&(xw_max<p2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }

            if((yw_max<q1[i])&&(yw_max<q2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((q1[i]<yw_min)&&(q2[i]<yw_min))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                continue;
            }
                ur=(float)(xw_max-p1[i])/(p2[i]-p1[i]);
                if((ur<1.0)&&(ur>0.0))
                {
                    if(p1[i]>p2[i])
                    {
                        p1[i]=xw_max;
                        q1[i]=floor(q1[i]+(ur*(q2[i]-q1[i]))+0.5);
                    }
                    else
                    {
                        p2[i]=xw_max;
                        q2[i]=floor(q1[i]+(ur*(q2[i]-q1[i]))+0.5);
                    }
                }
                //*****************************************************

            if((p1[i]<xw_min)&&(p2[i]<xw_min))
            {
                clipFlag=1;
                color=15;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((xw_max<p1[i])&&(xw_max<p2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }

            if((yw_max<q1[i])&&(yw_max<q2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((q1[i]<yw_min)&&(q2[i]<yw_min))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                continue;
            }
                ub=(float)(yw_min-q1[i])/(q2[i]-q1[i]);
                if((ub<1.0)&&(ub>0.0))
                {
                    if(q1[i]<q2[i])
                    {
                        p1[i]=p1[i] + floor(ub*(p2[i]-p1[i])+0.5);
                        q1[i]=yw_min;
                    }
                    else
                    {
                        p2[i]=p1[i] + floor(ub*(p2[i]-p1[i])+0.5);
                        q2[i]=yw_min;
                    }
                }
                //***********************************************

            if((p1[i]<xw_min)&&(p2[i]<xw_min))
            {
                clipFlag=1;
                color=15;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((xw_max<p1[i])&&(xw_max<p2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }

            if((yw_max<q1[i])&&(yw_max<q2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((q1[i]<yw_min)&&(q2[i]<yw_min))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                continue;
            }
                ut=(float)(yw_max-q1[i])/(q2[i]-q1[i]);
                if((ut<1.0)&&(ut>0.0))
                {
                    if(q1[i]>q2[i])
                    {
                        p1[i]=p1[i] + floor(ut*(p2[i]-p1[i])+0.5);
                        q1[i]=yw_max;
                    }
                    else
                    {
                        p2[i]=p1[i] + floor(ut*(p2[i]-p1[i])+0.5);
                        q2[i]=yw_max;
                    }
                }
                //*********************checiing*****

            if((p1[i]<xw_min)&&(p2[i]<xw_min))
            {
                clipFlag=1;
                color=15;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((xw_max<p1[i])&&(xw_max<p2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }

            if((yw_max<q1[i])&&(yw_max<q2[i]))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                 continue;
            }


            if((q1[i]<yw_min)&&(q2[i]<yw_min))
            {
                color=15;
                clipFlag=1;
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);
                continue;
            }
                line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,6);



            }
        }




    }




    getch();
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
