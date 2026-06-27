class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    //    set<int> s;
    //    for (int no:nums){

    //     if(s.find(no)!=s.end()){
    //         return true;
    //     }
    //     s.insert(no);
    //    }
    //     return false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){

                return true;
            }
        }
        return false;
    }
};