class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> arr;
        for(int x:nums){
            arr[x]++;
        }
        vector<pair<int, int>> freq;
        for(auto it:arr){
            freq.push_back({it.second,it.first});
        }
        sort(freq.rbegin(),freq.rend());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
