#include<stdio.h>
#include<graphics.h>
#include<math.h>

int line_draw(int,int,int,int,int,int,int);
int z;
int main()
{
    int gd=DETECT,gm,color,fill_color,boundary_color;

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
    int temp;

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
     unsigned int point1=1,point2=1,startP=1,endP=1,c=1;
     float m;
     int x_start,y_start,x_end,y_end;

     for(i=0;i<n;i++){

            //if((side==2)&&(i==1)){
               // break;
            //}
        if((p1[i]-xw_min)<0){
           point1=1;
        }
        if((p1[i]-xw_min)>=0){
           point1=0;
        }
        if((xw_max-p1[i])<0){
           point1=(2*1)+point1;;
        }
        if((xw_max-p1[i])>=0){
           point1=(2*0)+point1;
        }
        if((q1[i]-yw_min)<0){
           point1=(4*1)+point1;
        }
        if((q1[i]-yw_min)>=0){
           point1=(4*0)+point1;
        }
        if((yw_max-q1[i])<0){
           point1=(8*1)+point1;
        }
        if((yw_max-q1[i])>=0){
           point1=(8*0)+point1;
        }


        if((p2[i]-xw_min)<0){
           point2=1;
        }
        if((p2[i]-xw_min)>=0){
           point2=0;
        }
        if((xw_max-p2[i])<0){
           point2=(2*1)+point2;;
        }
        if((xw_max-p2[i])>=0){
           point2=(2*0)+point2;
        }
        if((q2[i]-yw_min)<0){
           point2=(4*1)+point2;
        }
        if((q2[i]-yw_min)>=0){
           point2=(4*0)+point2;
        }
        if((yw_max-q2[i])<0){
           point2=(8*1)+point2;
        }
        if((yw_max-q2[i])>=0){
           point2=(8*0)+point2;
        }
        if((point1 | point2)==0){
            line_draw(p1[i],q1[i],p2[i],q2[i],xc,yc,14);
            continue;
        }
        if((point1 & point2)!=0){
           printf("line has been cliped");
           continue;
        }

        m=(float)(q2[i]-q1[i])/(p2[i]-p1[i]);
        x_start=p1[i];
        y_start=q1[i];
        x_end=p2[i];
        y_end=q2[i];
        startP=point1;
        endP=point2;
        printf("%d\t\t%d\n",startP,endP);
        while(((startP | endP)!=0)&&((startP & endP)==0)){
           if(startP!=0){
             c=startP;
           }
           else{
             c=endP;
             temp=x_start;
             x_start=x_end;
             x_end=temp;
             temp=y_start;
             y_start=y_end;
             y_end=temp;
           }

           if((c & 1)!=0){
             x_start=xw_min;
             y_start=floor(q1[i]+(m*(xw_min-p1[i]))+0.5);
           }
           else if((c & 2)!=0){
             x_start=xw_max;
             y_start=floor(q1[i]+(m*(xw_max-p1[i]))+0.5);
           }
           else if((c & 4)!=0){
             x_start=floor(p1[i]+((1/m)*(yw_min-q1[i]))+0.5);
             y_start=yw_min;
           }
           else if((c & 8)!=0){
             x_start=floor(p1[i]+((1/m)*(yw_max-q1[i]))+0.5);
             y_start=yw_max;
           }

           if((x_start-xw_min)<0){
               startP=1;
           }
           if((x_start-xw_min)>=0){
              startP=0;
           }
           if((xw_max-x_start)<0){
             startP=(2*1)+startP;
           }
        if((xw_max-x_start)>=0){
           startP=(2*0)+startP;
        }
        if((y_start-yw_min)<0){
           startP=(4*1)+startP;
        }
        if((y_start-yw_min)>=0){
           startP=(4*0)+startP;
        }
        if((yw_max-y_start)<0){
           startP=(8*1)+startP;
        }
        if((yw_max-y_start)>=0){
           startP=(8*0)+startP;
        }


       if((x_end-xw_min)<0){
               endP=1;
           }
           if((x_end-xw_min)>=0){
              endP=0;
           }
           if((xw_max-x_end)<0){
             endP=(2*1)+endP;
           }
        if((xw_max-x_end)>=0){
           endP=(2*0)+endP;
        }
        if((y_end-yw_min)<0){
           endP=(4*1)+endP;
        }
        if((y_end-yw_min)>=0){
           endP=(4*0)+endP;
        }
        if((yw_max-y_end)<0){
           endP=(8*1)+endP;
        }
        if((yw_max-y_end)>=0){
           endP=(8*0)+endP;
        }

        }
        if((startP | endP)==0){
            line_draw(x_start,y_start,x_end,y_end,xc,yc,14);
            continue;
        }
        if((startP & endP)!=0){
           printf("cliped");
           continue;
        }

     }

    delay(90000);
    return 0;
}
//
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


