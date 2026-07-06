class Solution {
public:
    bool pallindrome(string curr){
        int left=0;
        int right=curr.size()-1;
        while(left<right){
            if(curr[left]!=curr[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>& ans,vector<string>& curr,int index){
        if(index==s.size()){
            ans.push_back(curr);
            return ;
        }
        for(int i=index;i<s.size();i++){
            string part=s.substr(index,i-index+1);
            if(pallindrome(part)){
                curr.push_back(part);
                solve(s,ans,curr,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int index=0;
        vector<string> curr;
        solve(s,ans,curr,index);
        return ans;
    }
};
