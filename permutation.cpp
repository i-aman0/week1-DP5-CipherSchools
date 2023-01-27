#include<iostream>
#include<vector>
using namespace std;

vector<int> sliceVector(vector<int> &nums, int index){
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(i == index){
                continue;
            }

            ans.push_back(nums[i]);
        }

        return ans;
    }
    vector<vector<int> > findPermutation(vector<int> &nums){
        if(nums.size() == 1){
            return {nums};
        }

        vector<vector<int> > allPermutations;
        for(int i = 0; i < nums.size(); i++){
            vector<int> sliced = sliceVector(nums, i);
            vector<vector<int> > currPermutation = findPermutation(sliced);
        

        for(int j = 0; j < currPermutation.size(); j++){
            currPermutation[j].push_back(nums[i]);
        }

        for(int j = 0; j < currPermutation.size(); j++){
            allPermutations.push_back(currPermutation[j]);
        }
        }

        return allPermutations;
    }

vector<vector<int>> permute(vector<int>& nums) {
    return findPermutation(nums);
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int> > permutations = permute(nums);
    return 0;
}