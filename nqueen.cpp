#include <iostream>
using namespace std;

const int N = 4; // You can change this value for different board sizes

int board[N][N];

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col)
{
    // Check column above
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(int row)
{
    if (row == N)
        return true; // All queens placed

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1; // Place queen

            if (solveNQueens(row + 1))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }
    return false; // No valid position in this row
}

// Function to print the board
void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main()
{
    if (solveNQueens(0))
        printBoard();
    else
        cout << "No solution found." << endl;
    return 0;
}
