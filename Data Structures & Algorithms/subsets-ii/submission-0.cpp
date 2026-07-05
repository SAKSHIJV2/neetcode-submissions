class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,int index){
        ans.push_back(curr);
        if(index==nums.size()){
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums,ans,curr,i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index=0;
        sort(nums.begin(),nums.end());
        solve(nums,ans,curr,index);
        return ans;
    }
};
