/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie {
    TrieNode* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    /** Inserts a word into the trie. */
    void insertUtil(TrieNode* root,string word){
        //  base case
        if(word.length() == 0){
            root->isTerminal=true;
            return;
        }
        //  assumption word will be capital
        int index = word[0]-'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            // absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0) return root->isTerminal;
        int index=word[0]-'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
        bool prefixUtil(TrieNode* root,string word){
        // base case
        if(word.length()==0) return true;

        int index=word[0]-'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL){ child=root->children[index]; } 
        else { return false; }
        return prefixUtil(child,word.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
    
};

// CN Approach Array Approach
Firstly we have defined the node class of Trie having members:

child  - storing the address of child nodes (Array of the address of Trie Nodes with size 26 initialized with NULL)
isEnd - a bool variable for marking this node as an end of some word.
Then we have defined our Trie Class having members:

root - The root node for whole Trie, every word starts from this node.
insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".
Definition of insert(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is NULL in the address of the node for the next character of the word then create a new node and store the address in child member of the previous character’s node.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, mark the isEnd member of the current node to true as it will denote the word is present or not.
Definition of search(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is NULL in the address of the node for the next character of the word then return false as the word is not present in the Trie.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, return the isEnd bool variable of the current node as it will denote the word is present or not.
Definition of startsWith(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is NULL in the address of the node for the next character of the word then return false as the no word is present in the Trie with this word as a Prefix.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, return true as some word must be present in the Trie as we are able to cover the whole prefix word.
Time Complexity
O(N*W) (insert - O(W), search - O(W), startsWith - O(W))

where N is the number of queries and W is the average length of words.

For all the operations we are iterating over the word and checking in the array for the next character of the word so Overall Time Complexity for insert, search, startsWith is O(W).

This array approach of storing child is more time-efficient than hashmap for storing child as the constant factor of O(1) in hashmaps is more costly.

Space Complexity
O(N*W) where N is the number of words inserted and W is the average length of words.

As we are making nodes of each character of a node so at max we can have all unique sequence of the words. So overall space can be at max 26*N*W, so Overall Space Complexity is O(N*W)
/*
    Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
    Where N is the number of queries and W is the average length of words.

    Space Complexity : O(N*W)
    Where N is the number of words inserted and W is the average length of words.
*/


class TrieNode {
public:
    TrieNode * child[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            child[i]=NULL;
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
        }
        tem->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child[x-'a'])
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};

// Hashmap/Dictionary Approach
Firstly we have defined the node class of Trie having members:

child  - storing the address of child nodes (hashmap of character number and address of Trie Node)
isEnd - a bool variable for marking this node as an end of some word.
Then we have defined our Trie Class having members:

root - The root node for whole Trie, every word starts from this node.
insert(word) - To insert a string "word" in Trie
search(word) - To check if string "word" is present in Trie or not.
startsWith(word) - To check if there is any string in the Trie that starts with the given prefix string "word".
Definition of insert(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is no node present for the next character of the word then create a new node and store it in child member of the previous character’s node.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, mark the isEnd member of the current node to true as it will denote the word is present or not.
Definition of search(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is no node present for the next character of the word then return false as the word is not present in the Trie.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, return the isEnd bool variable of the current node as it will denote the word is present or not.
Definition of startsWith(word):

Initialize the current node with the root node of Trie.
Iterate over the word from left to right and if there is no node present for the next character of the word then return false as the no word is present in the Trie with this word as a Prefix.
Keep updating the current node to the corresponding node for the next character of the word.
Finally, when we reached the end of the word, return true as some word must be present in the Trie as we are able to cover the whole prefix word.
Time Complexity
O(N*W) (insert - O(W), search - O(W), startsWith - O(W))

where N is the number of queries and W is the average length of words.

For all the operations we are iterating over the word and checking in hashmap for the next character of the word so that’s an O(1) operation on average so Overall Time Complexity for insert, search, startsWith is O(W).

Space Complexity
O(N*W) where N is the number of words inserted and W is the average length of words.

As we are making nodes of each character of a node so at max we can have all unique sequence of the words. This hashmap approach of storing child is more space-efficient than an array for storing child as we will only store the address for the nodes present in the Trie.
  /*
    Time Complexity : O(N*W) (insert - O(W), search - O(W), startsWith - O(W))
    Space Complexity : O(N*W)

    Where N is the number of queries and W is the average length of words.
*/

#include <unordered_map>

class TrieNode {
public:
    unordered_map<int,TrieNode *> child;
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;   
    Trie() {
        root= new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child.count(x-'a'))
                tem->child[x-'a']= new TrieNode();
            tem=tem->child[x-'a'];
        }
        tem->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *tem=root;
        for(auto x:word)
        {
            if(!tem->child.count(x-'a'))
                return false;
            tem=tem->child[x-'a'];
        }
        return  tem->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *tem=root;
        for(auto x:prefix)
        {
            if(!tem->child.count(x-'a'))
                return false;
            tem=tem->child[x-'a'];
        }
        return  true;
    }
};
