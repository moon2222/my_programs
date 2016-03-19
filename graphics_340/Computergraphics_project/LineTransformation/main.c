

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1468

int line(int,int,int,int,int,int,int);
int z;
void translation(int,int ,int*,int*,int*,int*);
void rotation(int ,int ,int*,int*,int*,int*,float);
void scal(int,int,int ,int,int*,int*,int*,int*);
int main()
{
    int gd=DETECT,gm,color;

    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j,x[50],y[50];

    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);



        printf("Enter the 1st coordinate\n");
        scanf("%d",&x[0]);
        scanf("%d",&y[0]);
        printf("Enter the 2nd coordinate\n");
        scanf("%d",&x[1]);
        scanf("%d",&y[1]);
        printf("enter the color:\n");
        scanf("%d",&color);
    for(i=0;i<=1;i++)
        printf("%d\t%d\n",x[i],y[i]);

        line(x[0],y[0],x[1],y[1],x0,y0,color);

        int theta,p1[2][1],p2[2][1];
        p1[0][0]=x[0];
        p1[1][0]=y[0];

        p2[0][0]=x[1];
        p2[1][0]=y[1];

        int choice;
        while(choice!=4){
        printf("enter your choice\n1.translation\n2.rotation\n3.scaling\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {


        case 1:
            {
            int tx,ty;
            printf("enter tx\n");
            scanf("%d",&tx);
            printf("enter ty\n");
            scanf("%d",&ty);
            printf("enter the color\n");
            scanf("%d",&color);
            printf("\n");

            int x1=p1[0][0];
            int y1=p1[1][0];
            int x2=p2[0][0];
            int y2=p2[1][0];
            translation(tx,ty,&x1,&y1,&x2,&y2);
            line(x1,y1,x2,y2,x0,y0,color);
            p1[0][0]=x1;
            p1[1][0]=y1;
            p2[0][0]=x2;
            p2[1][0]=y2;
            break;
            }
        case 2:
           {

            int tx,ty;
            float theta;
            printf("enter the rotational point \ntx:\t");
            scanf("%d",&tx);
            printf("\nty:\t");
            scanf("%d",&ty);
            int x1=p1[0][0];
            int y1=p1[1][0];
            int x2=p2[0][0];
            int y2=p2[1][0];

            printf("enter theta value(in degree)\n");
            scanf("%f",&theta);
            printf("enter the color of transformed line\n");
            scanf("%d",&color);

            rotation(tx,ty,&x1,&y1,&x2,&y2,theta);
            line(x1,y1,x2,y2,x0,y0,color);
            p1[0][0]=x1;
            p1[1][0]=y1;
            p2[0][0]=x2;
            p2[1][0]=y2;
            break;
           }
        case 3:
            {
             int sx,sy,tx,ty;

            printf("enter the scaling point \ntx:\t");
            scanf("%d",&tx);
            printf("\nty:\t");
            scanf("%d",&ty);
            printf("\n");
            printf("enter scaling factor\n");
            printf("sx:\t");
            scanf("%d",&sx);
            printf("\nsy:\t");
            scanf("%d",&sy);
            printf("\n");
            int x1=p1[0][0];
            int y1=p1[1][0];
            int x2=p2[0][0];
            int y2=p2[1][0];

            printf("enter the color of transformed line\n");
            scanf("%d",&color);

            scal(tx,ty,sx,sy,&x1,&y1,&x2,&y2);
            line(x1,y1,x2,y2,x0,y0,color);
            p1[0][0]=x1;
            p1[1][0]=y1;
            p2[0][0]=x2;
            p2[1][0]=y2;
            break;
            }
        case 4:
            break;
        default:
            {

            printf("\nWrong choice\n");
            break;
            }
        }

        }


    getch();


    cleardevice();
    closegraph();

}
void translation(int tx,int ty,int *x1,int *y1,int *x2,int *y2)
{
            *x1=*x1+tx;
            *x2=*x2+tx;
            *y1=*y1+ty;
            *y2=*y2+ty;
            printf("Points after transformation:\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n",*x1,*y1,*x2,*y2);

}
void rotation(int tx,int ty,int *x1,int *y1,int *x2,int *y2,float theta)
{
        theta=(theta/180)*PI;
        int x11=*x1;
        int x22=*x2;
        int y11=*y1;
        int y22=*y2;
        *x1 = tx + (x11-tx)*cos(theta) - (y11-ty)*sin(theta);
        *x2 = tx + (x22-tx)*cos(theta) - (y22-ty)*sin(theta);
        *y1 = ty + (x11-tx)*sin(theta) + (y11-ty)*cos(theta);
        *y2 = ty + (x22-tx)*sin(theta) + (y22-ty)*cos(theta);
        printf("\nTransformed coordinates\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n",*x1,*y1,*x2,*y2);


}
void scal(int tx,int ty,int sx,int sy,int *x1,int *y1,int *x2,int *y2)
{
        int x11=*x1;
        int x22=*x2;
        int y11=*y1;
        int y22=*y2;
        *x1=sx*x11 + (1-sx)*tx;
        *x2=sx*x22 + (1-sx)*tx;
        *y1=sy*y11 + (1-sy)*ty;
        *y2=sy*y22 + (1-sy)*ty;
        printf("\nTransformed coordinates\nx1=%d\ty1=%d\nx2=%d\ty2=%d\n",*x1,*y1,*x2,*y2);
}
int line(int x1,int y1,int x2,int y2,int x0,int y0,int color){
    int y3,k;
    if(x1>=x2){
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
    putpixel(x1,y1,color);

    if( m <=1 && m>0)
    {
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,color);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }
            else
            {
                y3=y[k]-y[0];
                putpixel(x[k]+1,y[k]-2*y3,color);
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
                putpixel(x[k]+1,y[k]-2*y3,color);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k]+1,y[k]-1-2*y3,color);
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
                putpixel(x[k],y[k]+1-2*y3,color);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel;
            }
            else
            {
                y3=y[k]+1-y[0];
                putpixel(x[k]+1,y[k]+1-2*y3,color);
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
                putpixel(x[k]+1,y[k]-1-2*y3,color);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];
                putpixel(x[k],y[k]-1-2*y3,color);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel;
            }

        }
    }


}



