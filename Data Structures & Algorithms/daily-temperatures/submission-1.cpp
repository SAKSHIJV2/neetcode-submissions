class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> mono;
        vector<int> ans(temp.size(),0);
        for(int i=temp.size()-1;i>=0;i--){
            while(!mono.empty() && temp[i] >= temp[mono.top()] ){
                mono.pop();
            }
            if(!mono.empty()){
                ans[i]=mono.top()-i;
            }
            mono.push(i);
        } 
        return ans;
    }
};
