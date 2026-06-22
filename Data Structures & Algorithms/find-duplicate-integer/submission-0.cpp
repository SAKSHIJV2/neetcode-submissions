class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int c:nums){
            mp[c]++;
        }
        for(auto p:mp){
            if(p.second > 1){
                return p.first;
            }
        }
        return -1;        
    }
};
