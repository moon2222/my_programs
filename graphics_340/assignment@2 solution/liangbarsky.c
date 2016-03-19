
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int line_draw(int,int,int,int,int,int,int);


int main()
{
  int gd = DETECT ,gm,x1,y1,x2,y2,i,j,xwmin,xwmax,ywmin,ywmax,p,q,xs,ys,ye,xe,delx,dely,flag=0;
  float u,ui1,ui2;
  DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
  DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
  initwindow(dwWidth,dwHeight);
  int x0=dwWidth/2;
  int y0=dwHeight/2;

//Drawing axes
    for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);

  //Drawing line
  printf("Enter the value of x1,y1,x2,y2");
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
  line_draw(x1,y1,x2,y2,x0,y0,3);

  //Drawing rectangle
  printf("Enter the the two diagonal endpoints of clipping window");
  scanf("%d %d %d %d",&xwmin,&ywmin,&xwmax,&ywmax);
  line_draw(xwmin,ywmin,xwmax,ywmin,x0,y0,2);
  line_draw(xwmin,ywmin,xwmin,ywmax,x0,y0,2);
  line_draw(xwmax,ywmin,xwmax,ywmax,x0,y0,2);
  line_draw(xwmin,ywmax,xwmax,ywmax,x0,y0,2);

  xs=x1;
  ys=y1;
  xe=x2;
  ye=y2;
  ui1=0;
  ui2=1;
  delx=x2-x1;
  dely=y2-y1;

  //Left Edge
  p=-delx;
  q=x1-xwmin;
  u=(float)q/p;

  if(p<0)
  {
      if(u>ui2)
      {
          flag=1;
      }
      else if(u>ui1)
      {
          ui1=u;
      }
  }
  else if(p>0)
  {
      if(u<ui1)
      {
          flag=1;
      }
      else if(u<ui2)
      {
          ui2=u;
      }
  }
  else
  {
      if(q<0)
      {
          flag=1;
      }
  }
 //Right Edge

 p= delx;
 q=xwmax-x1;
 u=(float)q/p;

 if(p<0)
  {
      if(u>ui2)
      {
          flag=1;
      }
      else if(u>ui1)
      {
          ui1=u;
      }
  }
  else if(p>0)
  {
      if(u<ui1)
      {
          flag=1;
      }
      else if(u<ui2)
      {
          ui2=u;
      }
  }
  else
  {
      if(q<0)
      {
          flag=1;
      }
  }

  //Bottom Edge
  p=-dely;
  q=y1-ywmin;
  u=(float)q/p;

  if(p<0)
  {
      if(u>ui2)
      {
          flag=1;
      }
      else if(u>ui1)
      {
          ui1=u;
      }
  }
  else if(p>0)
  {
      if(u<ui1)
      {
          flag=1;
      }
      else if(u<ui2)
      {
          ui2=u;
      }
  }
  else
  {
      if(q<0)
      {
          flag=1;
      }
  }

  //Top Edge

  p=dely;
  q=ywmax-y1;
  u=(float)q/p;

  if(p<0)
  {
      if(u>ui2)
      {
          flag=1;
      }
      else if(u>ui1)
      {
          ui1=u;
      }
  }
  else if(p>0)
  {
      if(u<ui1)
      {
          flag=1;
      }
      else if(u<ui2)
      {
          ui2=u;
      }
  }
  else
  {
      if(q<0)
      {
          flag=1;
      }
  }


  //finding endpoints


  if(ui1>0)
  {
  xs=floor(x1+ui1*delx+0.5);
  ys=floor(y1 + ui1*dely + 0.5);
  }
  if(ui2<1)
  {
  xe=floor(x1+ui2*delx+0.5);
  ye=floor(y1 + ui2*dely + 0.5);
  }


  printf("%d %d %d %d",xs,ys,xe,ye);
  line_draw(xs,ys,xe,ye,x0,y0,7);

  delay(500000);
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
