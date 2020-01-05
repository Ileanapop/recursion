#include<stdio.h>
#include<stdlib.h>


int xNext[8] = {-2,-2,-1,1,2,2,1,-1};
int yNext[8] = {-1,1,2,2,1,-1,-2,-2};

int isOk(int x, int y, int ** board, int n);
void printBoard(int ** board, int n, int nrSol);
void initializeBoard(int ** board, int n);
int ** createBoard(int n);
void findPath(int ** board,int n, int nrMove, int x, int y, int * nrSol);

int main()
{
    int n,nrSol=0;
    printf("Input the size of the chess board n= ");
    scanf("%d",&n);
    int ** board=createBoard(n);
    initializeBoard(board,n);
    board[0][0]=0;
    findPath(board,n,1,0,0,&nrSol);
    if(nrSol==0)
        printf("There is no path");
    else
        printf("Total number of paths: %d\n",nrSol);
    return 0;
}


int isOk(int x, int y, int ** board, int n)
{
    if(x>=0 && x<n && y>=0 && y<n && board[x][y]==-1)
        return 1;
    return 0;
}
void printBoard(int ** board, int n, int nrSol)
{
    printf("Path %d:\n", nrSol);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf(" %3d ",board[i][j]);
        printf("\n");
    }
    printf("\n");
}
void initializeBoard(int ** board, int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=-1;
}
int ** createBoard(int n)
{
    int ** board=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        board[i]=(int *)malloc(n*sizeof(int));
    return board;
}
void findPath(int ** board,int n, int nrMove, int x, int y, int * nrSol)
{
    int nextX, nextY;
    for(int k=0;k<8;k++)
    {
        nextX=x+xNext[k];
        nextY=y+yNext[k];
        if(isOk(nextX, nextY,board,n))
        {
            board[nextX][nextY]=nrMove;
            if(nrMove==n*n-1)
            {
                (*nrSol)++;
                printBoard(board,n,*nrSol);
            }
            findPath(board,n,nrMove+1,nextX,nextY,nrSol);
            board[nextX][nextY]=-1;
        }
    }
}
