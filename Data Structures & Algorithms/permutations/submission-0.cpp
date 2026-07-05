class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& curr,vector<bool>& visited){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(visited[i]==true){
                continue;
            }
            visited[i]=true;
            curr.push_back(nums[i]);
            solve(nums,ans,curr,visited);               
            curr.pop_back(); 
            visited[i]=false;         
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n=nums.size();
        vector<bool> visited(n,false);
        solve(nums,ans,curr,visited);
        return ans;
    }
};
