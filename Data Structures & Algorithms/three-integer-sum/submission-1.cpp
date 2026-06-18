class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        set<vector<int>> st;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right] < 0){
                    left++;
                }
                else if(nums[i]+nums[left]+nums[right] > 0){
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right] == 0){
                    vector<int> temp={nums[i],nums[left],nums[right]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    left++;
                    right--;
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
