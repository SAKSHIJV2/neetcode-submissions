class Solution {
public:
    string palli(int left,int right,string s){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            string odd=palli(i,i,s);
            if(odd.length()>ans.length()){
                ans=odd;
            }
            string even=palli(i,i+1,s);
            if(even.length()>ans.length()){
                ans=even;
            }
        }
        return ans;
    }
};
