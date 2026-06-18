class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int left=0;
        for(int right=k-1;right<nums.size();right++){
            left=right-k+1;
            output.push_back(*max_element(nums.begin()+left,nums.begin()+right+1));
        }
        return output;
    }
};
