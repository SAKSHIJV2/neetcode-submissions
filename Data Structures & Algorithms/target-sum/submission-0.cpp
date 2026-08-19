class Solution {
public:
    vector<vector<int>> dp;
    int offset;
    int solve(int index,int sum,vector<int>& nums,int& target){
        if(index==nums.size()){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum+offset]!=-1){
            return dp[index][sum+offset];
        }
        int add=solve(index+1,sum+nums[index],nums,target);
        int subtract=solve(index+1,sum-nums[index],nums,target);
        return dp[index][sum+offset]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int num:nums){
            total+=num;
        }
        offset=total;
        dp.resize(nums.size(),vector<int>(2*total+1,-1));
        return solve(0,0,nums,target);
    }
};
