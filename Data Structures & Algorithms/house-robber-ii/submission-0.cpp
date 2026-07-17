class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        vector<int> dp(nums.size());
        int prev2=0;
        int prev1=0;
        for(int i=start;i<=end;i++){
            int current=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=current;
            
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1){
            return nums[0];
        }
        
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
