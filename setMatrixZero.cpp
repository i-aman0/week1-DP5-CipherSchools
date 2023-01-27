#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row;
        vector<int> column;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }

        for(auto r : row){
            for(int i = 0; i < n; i++){
                matrix[r][i] = 0;
            }
        }

        for(auto c : column){
            for(int i = 0; i < m; i++){
                matrix[i][c]=0;
            }
        }
    }

int main()
{
    vector<vector<int> > arr = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(arr);
    return 0;
}