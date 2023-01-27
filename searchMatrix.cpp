#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        if(row < 0){
            return false;
        }

        int c = matrix[0].size() - 1;

        int r = 0;
        while(c >= 0 && r <= row){
            if(target == matrix[r][c]){
                return true;
            }

            else if(target < matrix[r][c]){
                c--;
            }

            else if(target > matrix[r][c]){
                r++;
            }
        }

        return false;
    }

int main()
{
    vector<vector<int> > matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout << searchMatrix(matrix, 5);
    return 0;
}