class Solution {
public:
    int solve(int left,int right,string s){
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            count+=solve(i,i,s);
            count+=solve(i,i+1,s);
        }
        return count;
    }
};
