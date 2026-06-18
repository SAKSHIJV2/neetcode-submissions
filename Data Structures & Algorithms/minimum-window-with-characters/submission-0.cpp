class Solution {
public:
    bool valid(vector<int> &scount, vector<int> &tcount){
        for(int i=0;i<128;i++){
            if(scount[i] < tcount[i]){
                return false;
            }
        }       
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        int minLength=INT_MAX;
        int start=0;
        vector<int> scount(128,0);
        vector<int> tcount(128,0);
        int left=0;
        for(char c:t){
            tcount[c]++;
        }
        for(int right=0;right<s.size();right++){
            scount[s[right]]++;
            while(valid(scount,tcount)){
                if(right-left+1 < minLength){
                    minLength=right-left+1;
                    start=left;
                }
                scount[s[left]]--;
                left++;
            }            
        }
        if(minLength==INT_MAX){
            return "";
        }
        return s.substr(start,minLength);
    }
};
