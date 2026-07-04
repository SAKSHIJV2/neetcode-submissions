class Solution {
public:
    void solve(vector<int>& nums,int index,vector<int>& curr,vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[index]);
        solve(nums,index+1,curr,ans);
        curr.pop_back();
        solve(nums,index+1,curr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index=0;
        solve(nums,index,curr,ans);       
        return ans;
    }
};
