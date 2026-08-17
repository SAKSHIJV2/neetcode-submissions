class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string& text1,string& text2){
        if(i==text1.length() || j==text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            dp[i][j]=1+solve(i+1,j+1,text1,text2);
        }
        else{
            dp[i][j]=max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.length();
        int j=text2.length();
        dp.resize(i,vector<int>(j,-1));
        return solve(0,0,text1,text2);
    }
};
