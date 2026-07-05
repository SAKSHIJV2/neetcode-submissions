class Solution {
public:
    void solve(vector<int>& candidates,vector<int>& curr,int target,int index,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(index==candidates.size()){
            return;
        }
        if(target<0){
            return ;
        }
        
        sort(candidates.begin(),candidates.end());
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates,curr,target-candidates[i],i+1,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index=0;
        solve(candidates,curr,target,index,ans);
        return ans;
    }
};
