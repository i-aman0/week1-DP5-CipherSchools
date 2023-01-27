#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int x, int y, int n)
    {
        return !(x < 0 || x == grid[0].size() || y < 0 || y == grid.size() || grid[y][x] == -1);
    }

int uniquePaths(vector<vector<int>> &grid, int x, int y, int n)
{
    if (isSafe(grid, x, y, n))
    {
        return 0;
    }

    if (grid[y][x] == 2)
        return n == 0; //n=0 means all empty squares are visited=>one path found
    grid[y][x] = -1;
    int paths = uniquePaths(grid, x + 1, y, n - 1) + uniquePaths(grid, x - 1, y, n - 1) +
                uniquePaths(grid, x, y + 1, n - 1) + uniquePaths(grid, x, y - 1, n - 1);
    grid[y][x] = 0;
    return paths;
}
int uniquePaths(vector<vector<int>> &grid)
{
    int sx = -1, sy = -1;
    int n = 1; // track the total count of empty square need to be visited
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == 0)
                    ++n;
            else if (grid[i][j] == 1)
            {
                    sx = j;
                    sy = i;
            } // starting square
    return uniquePaths(grid, sx, sy, n);
}

int main(){

return 0;
}