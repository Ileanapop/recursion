#include <stdio.h>
#include<stdlib.h>

#define FILE_PATH "D:\\CP\\recursion\\3.13\\labyrinth.txt"

typedef struct _coordinate{
    int x,y;
}coordinate;
coordinate start;
FILE * ptrf;

void readLabyrinth(int ** matrix, int m, int n);
void printLabyrinth(int ** matrix, int m, int n, int nrTrace);
int isOk(coordinate poz, int ** matrix, int m, int n);
void findTrace(int ** matrix, coordinate poz, int m, int n, int nrMove,int * nrTrace);
int isExitPosition(coordinate poz,int m, int n);
int ** createLabyrinth(int m, int n);

int rowMove[4]={-1,0,1,0};
int colMove[4]={0,1,0,-1};

int main()
{
    int ** matrix,n,m,nrTrace=0;
    ptrf=fopen(FILE_PATH,"r");
    if(ptrf==NULL)
    {
        perror("File could not be open");
        exit(-1);
    }
    fscanf(ptrf,"%d",&m);
    fscanf(ptrf,"%d",&n);
    matrix=createLabyrinth(m,n);
    readLabyrinth(matrix,m,n);
    printf("Labyrinth:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%3d",matrix[i][j]);
        printf("\n");
    }
    printf("Coordinates of initial position are: (%d, %d)\n",start.x, start.y);
    findTrace(matrix,start,m,n,2,&nrTrace);
    if(nrTrace==0)
        printf("There are no traces that lead to the exit of the labyrinth");
    return 0;
}
int ** createLabyrinth(int m, int n)
{
    int ** matrix=(int **)malloc(m*sizeof(int*));
    for(int i=0;i<n;i++)
        matrix[i]=(int *)malloc(n*sizeof(int));
    return matrix;
}
void readLabyrinth(int ** matrix, int m, int n)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            fscanf(ptrf,"%d",&matrix[i][j]);
            if(matrix[i][j]==-1)
            {
                start.x=i;
                start.y=j;
                matrix[i][j]=1;
            }
            /*if(matrix[i][j]==2)
            {
                finish.x=i;
                finish.y=j;
                matrix[i][j]=1;
            }*/
        }
}

void printLabyrinth(int ** matrix, int m, int n, int nrTrace)
{
    printf("Trace %d:\n",nrTrace);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%3d",matrix[i][j]);
        printf("\n");
    }
}
int isOk(coordinate poz, int ** matrix,int m, int n)
{
    if(poz.x>=0 && poz.x<m && poz.y>=0 && poz.y<n &&matrix[poz.x][poz.y]==1 && (poz.x!=start.x || poz.y!=start.y))
        return 1;
    return 0;
}
int isExitPosition(coordinate poz,int m, int n)
{
    if(poz.x==0||poz.x==m-1||poz.y==0||poz.y==n-1)
        return 1;
    return 0;
}
void findTrace(int ** matrix, coordinate poz, int m, int n, int nrMove, int * nrTrace)
{
    for(int k=0;k<4;k++)
    {
        coordinate next;
        next.x=poz.x+rowMove[k];
        next.y=poz.y+colMove[k];
        if(isOk(next,matrix,m,n))
        {
            matrix[next.x][next.y]=nrMove;
            if(isExitPosition(next,m,n))
            {
                (*nrTrace)++;
                printLabyrinth(matrix,m,n,*nrTrace);
            }
            findTrace(matrix,next,m,n,nrMove+1,nrTrace);
            matrix[next.x][next.y]=1;   //backtracking
        }
    }
}
