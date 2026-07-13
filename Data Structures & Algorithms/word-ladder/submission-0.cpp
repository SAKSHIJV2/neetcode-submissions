class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> mp(wordList.begin(),wordList.end());
        int level=1;
        q.push(beginWord);
        mp.erase(beginWord);
        if(mp.count(endWord)==0){
            return 0;
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string word=q.front();
                q.pop();
                if(word==endWord){
                    return level;
                }
                for(int i=0;i<word.length();i++){
                    char original=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(mp.count(word)){
                            q.push(word);
                            mp.erase(word);
                        }
                    }
                    word[i]=original;
                }
            }
            level++;
        }
        return 0;
    }
};
