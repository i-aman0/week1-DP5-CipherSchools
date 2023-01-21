#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArray(vector<int> arr1, int m, vector<int> arr2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while(i >= 0 && j >= 0){
        if(arr1[i] < arr2[j]){
            arr1[k] = arr1[i];
            i--;
            k--;
        }
        else{
            arr1[k] = arr2[j];
            j--;
            k--;
        }
    }

    while(j >= 0){
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> arr1 = {5, 6, 7, 8};
    vector<int> arr2 = {1, 2, 3};

    mergeSortedArray(arr1, 4, arr2, 3);

    for(int i = 0; i < 7; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;
    return 0;
}