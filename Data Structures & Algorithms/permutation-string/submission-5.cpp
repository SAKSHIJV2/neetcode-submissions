class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        int k=s1.size();
        for(char c:s1){
            f1[c-'a']++;
        }
        for(int i=0;i<k;i++){
            f2[s2[i]-'a']++;
        }
        if(f1==f2){
            return true;
        }
        int left=0;
        for(int right=k;right<s2.size();right++){
            f2[s2[left]-'a']--;
            left++;
            f2[s2[right]-'a']++;
            if(f1==f2){
                return true;
            }
        }
        return false;
    }
};
