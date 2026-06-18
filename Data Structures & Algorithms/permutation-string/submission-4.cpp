class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());
        int k=s1.size();
        for(int i=0;i<=s2.size()-k;i++){
            if(s1.size()>s2.size())
                return false;
            string temp=s2.substr(i,k);
            sort(temp.begin(),temp.end());
            if(temp==s1){
                return true;
            }
        }
        return false;
    }
};
