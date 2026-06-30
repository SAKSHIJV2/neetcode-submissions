class TrieNode{
    public:
    TrieNode* children[26];
    
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int index=c-'a';
            if(curr->children[index]==nullptr){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    bool dfs(string word,int pos,TrieNode* curr){
        if(pos==word.size()){
            return curr->isEnd;
        }
        char c=word[pos];
        if(c!='.'){
            int index=c-'a';
            if(curr->children[index]==nullptr){
                return false;
            }
            return dfs(word,pos+1,curr->children[index]);
        }
        for(int i=0;i<26;i++){
            if(curr->children[i]!=nullptr){
                if(dfs(word,pos+1,curr->children[i])){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(word,0,root);
    }
};
