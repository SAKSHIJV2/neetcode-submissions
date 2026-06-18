class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        set<int> s(nums.begin(),nums.end());
        vector<int> arr(s.begin(),s.end());
        int longest=1,curr=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]+1){
                curr++;
            }
            else{
                longest=max(longest,curr);
                curr=1;
            }

        }
        longest=max(longest,curr);
        return longest;
    }
};
