class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int ans=nums[0];
        int currentMin=nums[0];
        int currentMax=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempMax=currentMax;
            int tempMin=currentMin;
            currentMax=max({nums[i],nums[i]*tempMax,nums[i]*tempMin});
            currentMin=min({nums[i],nums[i]*tempMin,nums[i]*tempMax});
            ans=max(ans,currentMax);
        }
        return ans;
    }
};