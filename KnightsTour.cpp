//Solving Knight Tour problem using Backtracking
#include<bits/stdc++.h>
using namespace std;

#define N 8

//set of valid moves for a Knight
int movx[N] = {2,  1, -1, -2, -2, -1,  1,  2};
int movy[N] = {1,  2,  2,  1, -1, -2, -2, -1};

//display matrix
void dispmat(int sol[N][N])
{
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            cout<<" "<<setw(2)<<sol[row][col]<<" ";
        }
        cout<<endl;
    }
}

//finds out if given cell is within the N*N cell and is empty
bool isValid(int sol[N][N], int posx, int posy)
{
    return ( sol[posx][posy]==-1 && posx>=0 && posx<N && posy>=0 && posy<N );
}

//if it reaches certain number of moves(64) the solution is found
//loops 8 adjacent cells to find valid moves and backtracks using recursion in none of 8 moves are valid
bool solve(int sol[N][N], int posx, int posy, int movscount)
{
    if (movscount == N*N){
        cout<<"\nSolved: \n"<<endl;
        dispmat(sol);
        return true;
    }
    else {
        for(int mov=0; mov<N; mov++){
            if(isValid(sol, posx+movx[mov], posy+movy[mov])){
                sol[posx+movx[mov]][posy+movy[mov]] = movscount;
                if(solve(sol, posx+movx[mov], posy+movy[mov], movscount+1)){
                    return true;
                }
                else {
                    sol[posx+movx[mov]][posy+movy[mov]] = -1;
                }

            }
        }
        return false;
    }
}

//initialize the matrix with -1 and set the initial position (0,0) as 0 and initialize move counter
int main()
{
    int posx=0, posy=0;
    int movscount = 1;

    int sol[N][N];

    //Initializing the solution matrix with -1
    //Solution matrix counts step number for each move
    for(int row=0; row<N; row++)
        for(int col=0; col<N; col++)
            sol[row][col] = -1;

    sol[0][0] = 0;

    solve(sol, posx, posy, movscount);
}