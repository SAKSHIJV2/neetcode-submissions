class Solution {
public:
    void solve(vector<string>& ans,int& n,int& open,int& close,string& curr){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return ;
        }
        if(open<n){
            curr.push_back('(');
            open++;
            solve(ans,n,open,close,curr);
            curr.pop_back();
            open--;
        }        
        if(close<open){
            curr.push_back(')');
            close++;
            solve(ans,n,open,close,curr);
            curr.pop_back();
            close--;
        }        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=0;
        int close=0;
        string curr="";
        solve(ans,n,open,close,curr);
        return ans;
    }
};
