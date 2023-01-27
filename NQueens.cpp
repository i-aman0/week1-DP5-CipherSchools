#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<bool>> &chess, int x, int y, int &N){
    // horizontally back
    for(int i = x; i >= 0; i--){
        if(chess[i][y]){
            return false;
        }

        // diagonally up
        for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){
           if(chess[i][y]){
                return false;
            } 
        }

        // diagonally down
        for(int i = x, j = y; i < N && j >= 0; i--, j--){
           if(chess[i][y]){
                return false;
            } 
        }
    }

    return true;
}

bool NQueen(vector<vector<bool>> &chess, int y, int &N){
    if(y == N){
        return true;
    }

    for(int x = 0; x < N; x++){
        if(isSafe(chess, x, y, N)){
            chess[x][y] = true;

            if(NQueen(chess, y + 1, N)){
                return true;
            }

            chess[x][y] = false;
        }
    }

    return false;
}

vector<vector<bool> > NQueen(int N){
    vector<vector<bool> > Chess(N, vector<bool>(N, false)); 

    NQueen(Chess, 0, N);

    return Chess;

}

int main()
{
    
    return 0;
}