class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr,int target,int index,vector<vector<int>>& ans){
        if(index==nums.size()){
            return;
        }
        if(target<0){
            return ;
        }
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[index]);
        solve(nums,curr,target-nums[index],index,ans);
        curr.pop_back();
        solve(nums,curr,target,index+1,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index=0;
        solve(nums,curr,target,index,ans);
        return ans;
    }
};
