#include<windows.h>

#include <mmsystem.h>

#pragma comment(lib, "winmm")

#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>                   

#define WIDTH 474 //宽度

#define HIGHT 120 //高度

#define PAGE_LIMIT 3000         //帧数

#define N HIGHT*WIDTH           //字符数

//初命名

char name[]="ASCII-1 0001.txt";

char str[N];

int main()

{

      system("pause");//等待用户信号；

      int i,j,n=1,p,q;

      char a[4]="000";

      //帧操作

      for(i=1;i<=PAGE_LIMIT;i++)

      {

            //时间轴定位

            for(p=10,q=0;q<4;q++)

            {

                  if(i<10&&q==1)break;

                  else if(i<100&&q==2)break;

                  else if(i<1000&&q==3)break;

                  else

                  {

                       a[q]=i%p/(p/10)+48;

                       p*=10; 

                  }

            }

            //重命名

            for(p=0;p<q;p++)

                  name[11-p]=a[p];

            FILE *fp;

            //打开文本

            if((fp=fopen(name,"r"))==NULL)  

            {

                  printf("%d",i);

                  system("pause");

                  continue;

            }

            //读取文本

            while(fgets(str,N ,fp)!=NULL)

                  printf("%s",str);

            //关闭文本

            fclose(fp);

            system("cls");//清屏

      }

      system("pause");//等待用户信号

      return 0;

}