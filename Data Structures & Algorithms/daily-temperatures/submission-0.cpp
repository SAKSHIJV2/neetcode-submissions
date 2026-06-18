class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(temp[j]>temp[i]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
