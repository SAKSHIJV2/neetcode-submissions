class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        for(int i=0;i<s.length();i++){
            unordered_set<char> st;
            for(int j=i;j<s.length();j++){
                if(st.count(s[j])){
                    break;
                }
                st.insert(s[j]);
                maxLength=max(maxLength,j-i+1);
            }
        }
        return maxLength;
    }
};
