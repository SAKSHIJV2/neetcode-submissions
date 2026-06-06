class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       set<int> s;
       for (int no:nums){

        if(s.find(no)!=s.end()){
            return true;
        }
        s.insert(no);
       }
        return false;
       
    }
};