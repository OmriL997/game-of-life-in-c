#include <stdio.h>
#include <unistd.h>
#define WIDTH 30
#define HEIGHT 20
void print_screen (int *board)
{
  for (int i=0;i<HEIGHT;i++)
    {
      for (int j=0;j<WIDTH;j++)
	{
	  printf("%d",board[i*WIDTH+j]);
	}
      printf("\n");
    }
  printf("\n");
}

int count_neighbours(int *board, int i, int j){
  int neighbours=0;
  int i_arr[3] = { ((i-1+HEIGHT)%HEIGHT)*WIDTH , i*WIDTH , ((i+1)%HEIGHT)*WIDTH };
  int j_arr[3] = { ((j-1+WIDTH)%WIDTH) , j , (j+1)%WIDTH };
  for (int m=0;m<3;m++)
    {
      for (int n=0;n<3;n++)
	{
	  if (m==1 && n==1)
	    {
	      continue;
	    }
	  if (board[i_arr[m]+j_arr[n]]==1)
	    {
	      neighbours++;
	    }
	}
    }
  return neighbours;
}

int main (void)
{
  int boardA[HEIGHT][WIDTH];
  int boardB[HEIGHT][WIDTH];
  int *front;
  int *back;
  int iter;
  unsigned int delay;
  scanf("%d",&iter);
  scanf("%d",&delay);
  for (int i=0;i<HEIGHT;i++)
    {
      for (int j=0;j<WIDTH;j++)
	{
	  scanf("%d",&boardA[i][j]);
	}
    }
  front=&boardA[0][0];
  back=&boardB[0][0];
  while (0<(iter--))
    {
      print_screen(front);
      for (int i=0;i<HEIGHT;i++)
	{
	  for (int j=0;j<WIDTH;j++)
	    {
	      int neighbs=count_neighbours(front,i,j);
	      if (neighbs==3)
		{
		  back[i*WIDTH+j]=1;
		}
	      if (neighbs<2||neighbs>3)
		{
		  back[i*WIDTH+j]=0;
		}
	      else
		{
		  back[i*WIDTH+j]=front[i*WIDTH+j];
		}
	    }
	}
      int* temp;
      temp=front;
      front=back;
      back=temp;
      usleep(500000*delay);
    }
  return 0;
}
