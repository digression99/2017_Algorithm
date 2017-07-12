//
// geeksforgeeks backtracking - N queens problem
//
// 문제정의 : n개의 퀸을 n x n 체스보드에 놓아 서로 공격하지 못하는 위치를 찾는 것.
// 아웃풋 : 퀸의 위치를 배열로 표현
// ->   (0, 1, 0, 0)
//      (0, 0, 0, 1)
//      (1, 0, 0, 0)
//      (0, 0, 1, 0)
//
// naive와 backtracking의 아이디어의 차이?
// -> naive는 모든 자리에 대해서 경우를 체크한다. 예를들어, (1, 1)의 자리에 놓고 나머지 3개를
// 그 자리를 뺀 나머지 자리에 놓고, ... 해서 아니면 다시 (1, 2)의 자리에 놓고 나머지 3개를 나머지에
// 분배하고... 한다.
// 그러나 backtracking 은 어디부터 서치할지 순서를 정하여 차례대로 검색하기 때문에
// 중복이 발생하지 않는다. 즉, 모든 곳을 철저하게 검색하되, 중복이 없이 효율적으로 검색하는 알고리즘을
// 말하는 것이다.
// 근데 살짝 dp의 느낌이 나긴 나는데, 무엇이 차이점일지 곰곰히 생각해보자.
// backtracking하면서 원래대로 돌린다... 이게 차이점일까??
//

/* C/C++ program to solve N Queen Problem using
 backtracking */
#define N 4
#include<stdio.h>

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

/* A utility function to check if a queen can
 be placed on board[row][col]. Note that this
 function is called when "col" queens are
 already placed in columns from 0 to col -1.
 So we need to check only left side for
 attacking queens */
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
    
    return true;
}

/* A recursive utility function to solve N
 Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
     then return true */
    if (col >= N)
        return true;
    
    /* Consider this column and try placing
     this queen in all rows one by one */
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
         board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;
            
            /* recur to place rest of the queens */
            if ( solveNQUtil(board, col + 1) )
                return true;
            
            /* If placing queen in board[i][col]
             doesn't lead to a solution, then
             remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
    
    /* If queen can not be place in any row in
     this colum col  then return false */
    return false;
}

/* This function solves the N Queen problem using
 Backtracking. It mainly uses solveNQUtil() to
 solve the problem. It returns false if queens
 cannot be placed, otherwise return true and
 prints placement of queens in the form of 1s.
 Please note that there may be more than one
 solutions, this function prints one  of the
 feasible solutions.*/
bool solveNQ()
{
    int board[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    
    if ( solveNQUtil(board, 0) == false )
    {
        printf("Solution does not exist");
        return false;
    }
    
    printSolution(board);
    return true;
}

// driver program to test above function
int main()
{
    solveNQ();
    return 0;
}
