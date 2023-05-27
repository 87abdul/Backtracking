//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends

class Solution {
public:

    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N]) { 
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 0) {
                    for(char c=1; c<=9; c++) {
                        if(isValid(grid, i, j, c)) {
                            grid[i][j] = c;
                            if(SolveSudoku(grid) == true) return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int grid[N][N], int row, int col, char c) {
        for(int i=0; i<9; i++) {
            if(grid[i][col] == c) return false;
            if(grid[row][i] == c) return false;
            if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == c) return false;
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                std::cout<< grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends



// Leetcode Solution

// class Solution {
// public:
    
//     // function to solve Sudoku puzzle
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }

//     // function to check if the given value is valid for a cell in the Sudoku puzzle
//     bool isValid(vector<vector<char>>& board, int row, int col, char c) {
//         // check if the value is already present in the same row or column
//         for (int i = 0; i < 9; i++) {
//             if (board[i][col] == c) return false;
//             if (board[row][i] == c) return false;
//         }
//         // check if the value is already present in the same 3x3 sub-grid
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 if (board[3 * (row / 3) + i][3 * (col / 3) + j] == c) return false;
//             }
//         }
//         // if the value is not already present in the same row, column, or sub-grid, then it is a valid value for the cell
//         return true;
//     }

//     // function to solve the Sudoku puzzle using backtracking
//     bool solve(vector<vector<char>>& board) {
//         // loop through each cell in the board
//         for (int i = 0; i < board.size(); i++) {
//             for (int j = 0; j < board[0].size(); j++) {
//                 // if the cell is empty, try filling it with each possible value from 1 to 9
//                 if (board[i][j] == '.') {
//                     for (char c = '1'; c <= '9'; c++) {
//                         // check if the value is valid for the cell
//                         if (isValid(board, i, j, c)) {
//                             // if the value is valid, fill the cell with the value
//                             board[i][j] = c;
//                             // recursively try to solve the puzzle with the new value filled in
//                             if (solve(board) == true) {
//                                 // if a solution is found, return true to stop further backtracking
//                                 return true;
//                             } else {
//                                 // if a solution is not found, backtrack by resetting the cell to its previous empty state
//                                 board[i][j] = '.';
//                             }
//                         }
//                     }
//                     // if none of the possible values lead to a solution, backtrack by returning false
//                     return false;
//                 }
//             }
//         }
//         // if all cells are filled, the puzzle is solved, so return true
//         return true;
//     }
// };
