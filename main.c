#include<stdio.h>
#include<math.h>
#define ROWS 25
#define COLS 60

char canvas[ROWS][COLS];
void initializeCanvas()
{
  for(int i=0;i<ROWS;i++)
    {
      for(int j=0;j<COLS;j++)
        {
          canvas[i][j]='_';
        }
    }
}
void display()
{
  for(int i=0;i<ROWS;i++)
    {
      for(int j=0;j<COLS;j++)
        {
          printf("%c",canvas[i][j]);
        }
      printf("\n");
    }
}
void drawRectangle(int row,int col,int height,int width,char ch)
{
  for(int i=col;i<col+width;i++)
    {
      canvas[row][i]=ch;
      canvas[row + height - 1][i]=ch;
    }
  for(int i=row;i<row+height;i++)
    {
      canvas[i][col]=ch;
      canvas[i][col + width - 1]=ch;
    }
}
void drawLine(int row,int startCol,int endCol,char ch)
{
  int i;
  if(row < 0 || row >= ROWS)
    return;
  for(i=startCol;i<=endCol && i<COLS;i++)
    {
      if(i>=0)
        canvas[row][i]=ch;
    }
}
void drawTriangle(int row,int col,int height,char ch)
{
 for(int i=0;i<height;i++)
  {
    if(row + i < ROWS && col - i >= 0)
      canvas[row+i][col-i]=ch;
    if(row + i < ROWS && col + i < COLS)
      canvas[row+i][col+i]=ch;
  }
for(int i=col-height+1;i<=col+height-1;i++)
  {
    if(row + height - 1 < ROWS && i >= 0 && i < COLS)
      canvas[row+height-1][i]=ch;
  }
}
void drawCircle(int xc,int yc,int radius,char ch)
{
  int angle;
  for(angle=0;angle<360;angle++)
    {
      int x = xc + radius*cos(angle*3.14159/180);
      int y = yc + radius*sin(angle*3.14159/180);
      if(x >= 0 && x < ROWS && y >= 0 && y < COLS)
      {
        canvas[x][y]=ch;
      } 
    }
}

int main()
{
  int choice;
  initializeCanvas();
  do
{
      printf("\n=====2D GRAPHICS EDITOR=====\n");
      printf("1.Draw Rectangle\n");
      printf("2.Draw Line\n");
      printf("3.Draw Triangle\n");
      printf("4.Draw Circle\n");
      printf("5.Delete Rectangle\n");
      printf("6.Delete Line\n");
      printf("7.Delete Triangle\n");
      printf("8.Delete Circle\n");
      printf("9.Modify Rectangle\n");
      printf("10.Display Canvas\n");
      printf("11.Clear Canvas\n");
      printf("12.Exit\n");

      printf("Enter Choice:");
      scanf("%d",&choice);
      switch(choice)
        {
          case 1:
            {
              int r,c,h,w;
              printf("Row Col Height Width:");
              scanf("%d%d%d%d",&r,&c,&h,&w);

              drawRectangle(r,c,h,w,'*');
              break;
            }
          case 2:
            {
              int row,start,end;
              printf("Row StartCol EndCol:");
              scanf("%d%d%d",&row,&start,&end);

              drawLine(row,start,end,'*');
              break;
            }
          case 3:
            {
              int row,col,height;
              printf("TopRow CenterCol Height:");
              scanf("%d%d%d",&row,&col,&height);

              drawTriangle(row,col,height,'*');
              break;
            }
          case 4:
            {
              int x,y,r;
              printf("CenterRow CenterCol Radius:");
              scanf("%d%d%d",&x,&y,&r);

              drawCircle(x,y,r,'*');
              break;
            }
          case 5:
            {
              int r,c,h,w;
              printf("Row Col Height Width:");
              scanf("%d%d%d%d",&r,&c,&h,&w);

              drawRectangle(r,c,h,w,'_');
              break;
            }
          case 6:
            {
              int row,start,end;
              printf("Row StartCol EndCol:");
              scanf("%d%d%d",&row,&start,&end);

              drawLine(row,start,end,'_');
              break;
            }
          case 7:
            {
              int row,col,height;
              printf("TopRow CenterCol Height:");
              scanf("%d%d%d",&row,&col,&height);
              drawTriangle(row,col,height,'_');
              break;
            }
          case 8:
            {
             int x,y,r;
             printf("CenterRow CenterCol Radius:");
             scanf("%d%d%d",&x,&y,&r);
             drawCircle(x,y,r,'_');
            break;
            }
          case 9:
            {
              int r,c,h,w;
              printf("Old Rectangle Row Col Height Width:");
              scanf("%d%d%d%d",&r,&c,&h,&w);

              drawRectangle(r,c,h,w,'_');

              printf("New Rectangle Row Col Height Width:");
              scanf("%d%d%d%d",&r,&c,&h,&w);
              drawRectangle(r,c,h,w,'*');
              break;
            }
          case 10:
            {
              display();
              break;
            }
          case 11:
            {
              initializeCanvas();
              printf("Canvas Cleared!\n");
              break;
            }
          case 12:
            printf("Exiting...\n");
            break;
          default:
            printf("Invalid Choice!\n");
        }
}while(choice!=12);
  return 0;
}