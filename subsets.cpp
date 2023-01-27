#include<iostream>
#include<vector>
using namespace std;

void f(int ind,vector<vector<int>>& ans,vector<int> &ans2,vector<int>& nums){
    for(int i=ind;i<nums.size();i++){
        ans2.push_back(nums[i]);
        f(i+1,ans,ans2,nums);
        ans2.pop_back();
    }
    ans.push_back(ans2);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ans2;
    f(0,ans,ans2,nums);
    return ans;
}

int main()
{
    
    return 0;
}