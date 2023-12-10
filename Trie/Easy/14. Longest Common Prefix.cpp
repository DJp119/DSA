class TrieNode{
    public:
    TrieNode *children[26];
    bool isTerminal;

    int bodyCount;
    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;

        isTerminal = false;
        bodyCount=0;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            char index = word[i]-'a';
            if(!node->children[index]){
                node->children[index]=new TrieNode();
                node->bodyCount++;
            }
            node=node->children[index];
        }
        node->isTerminal=true;
    }
    void lcp(string word,string &ans){
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(root->bodyCount==1){
            ans.push_back(ch);
            int index=ch-'a';
            root=root->children[index];
        }
        else break;
        if(root->isTerminal) break;
    }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t=new Trie();
        for(int i=0;i<strs.size();i++){
            if(strs[i]=="") return "";
            t->insert(strs[i]);
        }
        string ans="";
        string firstword=strs[0];
        t->lcp(firstword,ans);
        return ans;
    }
};
