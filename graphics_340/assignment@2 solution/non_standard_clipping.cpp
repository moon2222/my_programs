#include<stdio.h>
#include<graphics.h>
#include<math.h>

int line_draw(int,int,int,int,int,int,int);
int z;

int main()
{
    int gd=DETECT,gm,color,fill_color,boundary_color;
    int xc,yc;
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int xc=dwWidth/2;
    int yc=dwHeight/2;
    int i,j,p1[50],p2[50],q1[50],q2[50],nw_p1[50],nw_p2[50],nw_q1[50],nw_q2[50],tmp1[50],tmp2[50],tmp3[50],tmp4[50];

    printf("%d\t%d\n\n",xc,yc);
    for(i=0; i<dwHeight; i++)
        putpixel(xc,i,4);

    for(j=0; j<dwWidth; j++)
        putpixel(j,yc,4);

    int n,yw_min,xw_min,xw_max,yw_max;
    int cx[4],cy[4],nw_x[4],nw_y[4];
    int min1,min2,flag1,flag2,index,delta_x,delta_y,save;
    float m;


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
        color=7;
        line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,color);

    }

    printf("Enter the coordinate of non standard rectangle clipping window \n");
    for(i=0; i<=3; i++)
    {
        printf("Enter the %d cordinates\n ",i);
        scanf("%d",&cx[i]);
        scanf("%d",&cy[i]);
    }
    //drawing clipping window
    color=8;
    for(i=0; i<=3; i++)
    {
        line_draw(cx[i],cy[i],cx[i+1],cy[i+1],xc,yc,color);


    }
    if(cy[0]<=cy[1])
    {
        min1=cy[0];
        flag1=0;
    }
    else
    {
        min1=cy[1];
        flag1=1;
    }
    if(cy[2]<cy[3])
    {
        flag2=0;
        min2=cy[2];
    }
    else
    {
        flag2=1;
        min2=cy[3];
    }
    if(min1<=min2)
    {
        if(flag1==0)
            index=0;
        else
            index=1;

    }
    else
    {
        if(flag2==0)
            index=2;
        else
            index=3;

    }
    delta_x=cx[index+1]-cx[index];
    printf("\n%d\n",delta_x);
    delta_y=cy[index+1]-cy[index];
    printf("\n%d\n",delta_y);
    m=delta_y/delta_x;
    printf("%d\n",m);
    float theta;
    theta=atan(m);
    for(i=0; i<4; i++)
    {

        nw_x[i]=cx[index]+floor(((cx[i]-cx[index])*cos(-theta))-((cy[i]-cy[index])*sin(-theta))+0.5);
        nw_y[i]=cy[index]+floor(((cx[i]-cx[index])*sin(-theta))+((cy[i]-cy[index])*cos(-theta))+0.5);
    }
    for(i=0; i<=3; i++)
    {
        color=9;
        line_draw(nw_x[i],nw_y[i],nw_x[i+1],nw_y[i+1],xc,yc,color);


    }
    for(i=0; i<n; i++)
    {
        nw_p1[i]=cx[index]+floor(((p1[i]-cx[index])*cos(-theta))-((q1[i]-cy[index])*sin(-theta))+0.5);
        nw_q1[i]=cy[index]+floor(((p1[i]-cx[index])*sin(-theta))+((q1[i]-cy[index])*cos(-theta))0.5);
        nw_p2[i]=cx[index]+floor(((p2[i]-cx[index])*cos(-theta))-((q2[i]-cy[index])*sin(-theta))0.5);
        nw_q2[i]=cy[index]+floor(((p2[i]-cx[index])*sin(-theta))+((q2[i]-cy[index])*cos(-theta))0.5);

        color=12;
        line_draw(nw_p1[i],nw_q1[i],nw_p2[i],nw_q2[i],xc,yc,color);

    }
    xw_min=cx[index];
    yw_min=cy[index];
    printf("%d\t%d",xw_min,yw_min);
    for(i=0;i<=3;i++)
    {
        if(nw_x[i]==cx[index]&&nw_y[i]==cy[index])
            save =i;
    }
    xw_max=nw_x[save+2];
    yw_max=nw_y[save+2];
     printf("%d\t%d",xw_max,yw_max);
    for(i=0;i<n;i++){
        p1[i]=nw_p1[i];
        q1[i]=nw_q1[i];
        p2[i]=nw_q1[i];
        q2[i]=nw_q2[i];
        p1[i]=nw_p1[i];
        q1[i]=nw_q1[i];
        p2[i]=nw_q1[i];
        q2[i]=nw_q2[i];
        nw_p1[i]=tmp1[i];
        nw_q1[i]=tmp2[i];
        nw_q1[i]=tmp3[i];
        nw_q2[i]=tmp4[i];

    }
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
