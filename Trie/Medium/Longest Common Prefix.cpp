string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];

        bool match  = true;
        // for comparing ch with rest of the string 
        for(int j=1;j<n;j++){
            // mot match
            if( arr[j].size() < i ||ch != arr[j][i]) {
                match = false;
                break;
            }
        }
        if(match == false) break;
        else ans.push_back(ch);
    }
    return ans;
}
class TrieNode{
    public:
    char data ;
    TrieNode* children[26];
    int childCount ;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }
    void insertUtil(TrieNode* root,string word){
            //  base case
            if(word.length() == 0){
                root->isTerminal=true;
                return;
                }
                //  assumption word will be small
            int index = word[0]-'a';
            TrieNode* child;
                // present
            if(root->children[index] != NULL)
                child=root->children[index];
                
            else{
                    // absent
                child=new TrieNode(word[0]);
                root->childCount++;
                root->children[index]=child;
                    }
        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
        void lcp(string str,string &ans){
            for(int i=0;i<str.length();i++){
                char ch = str[i];
                if(root->childCount == 1){
                    ans.push_back(ch);
                    int index = ch-'a';
                    root= root->children[index];
                }
                else break;
                if(root->isTerminal) break;
            }
        }
};

string longestCommonPrefix(vector<string> &arr, int n){
    Trie* t = new Trie('\0');
    // insert all string in trie
    for(int i=0;i<n;i++){
        t->insert(arr[i]);
    }
    string first = arr[0];
    string ans = "";
    t->lcp(first,ans);
    return ans;
}



Iterative Scanning
In this approach, we will iterate through each character of the first string and check if the same character exists in each string or not. We will maintain a variable longestPrefix to store the longest common prefix.

 

We will traverse idx from 0 to the length of ARR[0] -1.

We will iterate index from 1 to N-1 and check if ARR[index][idx] is equal to ARR[0][idx].
If the condition is true for all strings, we can add ARR[0][idx] in the common prefix string, and we will insert ARR[0][idx] in longestPrefix. Otherwise, the search is completed for the longest common prefix.
In the end, we will return the variable longestPrefix.

 

Algorithm:

We will declare a string longestPrefix to store the longest prefix string of all strings.
We will iterate through the first string of ARR and check each of its characters is present in all other strings or not.
Iterate idx from 0 to length of ARR[0] - 1 ,do the following:
Set ch as ARR[0][idx]. The variable ch stores the character to be searched.
Set matched as true. The variable stores if it is possible to insert ch into the longestPrefix.
We will iterate index from 1 to N-1, do the following:
Check if the length of ARR[index] is less than or equal to the variable idx or ARR[index][idx] is not equal to ch.
Set matched as false.
Break this loop.
If matched is true, we can insert character ch into longestPrefix. Otherwise, break this loop as the longest common prefix is already found.
Return the string longestPrefix corresponding to the longest prefix string of all the strings in the given array.
Time Complexity
O(N*M), where N is the number of strings in the array and M is the shortest length of the string present in the array.

 

We are doing M iteration, and in each iteration, we are traversing through the strings that take O(N) time. Hence, the overall time complexity is O(N*M).

Space Complexity
O(1).

 

Constant space is being used. Hence, the overall space complexity is O(1).
  /*
    Time Complexity: O(N*M)
    Space Complexity: O(1)

    where N is the number of strings in the array and M is the length of the shortest string present in the array.
*/

string longestCommonPrefix(vector<string> &arr, int n)
{
    // A String to store the longest common prefix
    string longestPrefix = "";

    for(int idx = 0; idx < arr[0].size(); ++idx)
    {
        // The variable ch is the character to be searched
        char ch = arr[0][idx];
        
        // A boolean value to check whether is it possible to insert ch in longest prefix or not.
        bool matched = true;

        for(int index = 1; index < n; ++index) 
        {   
            // Check if arr[index][idx] is equal to ch
            if (arr[index].size() < idx or arr[index][idx] != ch)
            {
                matched = false;
                break;
            }
        }

        // If matched is true,insert the character ch into longestPrefix
        if (matched)
        {
            longestPrefix += ch;
        }
        else
        {
            break;
        }
    }

    return longestPrefix;
}

Divide and Conquer
In this approach, we will divide the array of strings into halves, and we will find the common prefix for both parts separately. We will find the common prefix of these obtained strings.

 

We will define a function commonPrefix(STR1, STR2) to find the common prefix of STR1 and STR2. We will define a function commonPrefixUtil(ARR, start, end), returning the longest common prefix for the subarray from index start to end. This function will recursively divide the range into half and find the longest common prefix for that subarray of ARR.

 

Algorithm: 

Defining function commonPrefix(STR1, STR2):
Set minLength as the minimum of the length of STR1 string and length of STR2 string.
Declare a string ans to store the longest common prefix of these two strings.
For each index idx from 0 to minLength - 1 ,do the following:
If STR1[idx] is equal to STR2[idx]:
Insert STR1[idx] into ans.
Otherwise, break the loop.
Return ans string.
 

Defining function commonPrefixUtil(ARR, start, end):
If start is equal to end:
The subarray contains only one string, so the longest common prefix will be ARR[start].
Return ARR[start].
Declare variables left and right to store the longest common prefix for the left and right halves.
Set mid as (start + end)/2.
Set left as commonPrefixUtil(ARR, start, mid).
Set right as commonPrefixUtil(ARR, mid+1 , end).
Declare the variable ans to store the longest common prefix for the subarray from start to end.
Set ans as commonPrefix(left,right).
Return ans.
Declare a string answer to store the longest common prefix for all strings of the array.
Set answer as commonPrefixUtil(ARR, 0, N-1).
Return answer corresponding to longest common prefix.
Time Complexity
O(N*M), where N is the number of strings in the array and M is the shortest length of the string.

 

In the worst case, we are making the N comparison, and in each comparison, we are traversing through the length of the string that takes O(M) time. Hence, the overall time complexity is O(N*M).

Space Complexity
O(M*log(N)), where N is the number of strings in ARR and M is the shortest length of the string.

 

There is log(N) recursive calls, and in each recursive call, we need O(M) space to store the longest prefix string. Hence, the overall space complexity is O(M*log(N)).
/*
    Time Complexity: O(N*M)
    Space Complexity: O(M*log(N))

    where N is the number of strings in the array and M is the length of the stortest string present in the array.
*/

string commonPrefix(string &str1, string &str2)
{
    // Storing the minimum length
    int minLength = min(str1.size(), str2.size());

    // A string to store the longest common prefix
    string ans = "";

    for(int idx = 0; idx < minLength ; ++idx)
    {
        if (str1[idx] == str2[idx])
        {
            ans += str1[idx];
        }
        else
        {
            break;
        }
    }

    return ans;
}


string commonPrefixUtil(vector<string> &arr, int start, int end)
{
    // If range contains only one string, return that string.
    if (start == end)
    {
        return arr[start];
    }

    int mid = (start + end) / 2;

    // The string left to store the longest common prefix for the left half of the range
    string left = commonPrefixUtil(arr, start, mid);

    // The string right to store the longest common prefix for the right half of the range
    string right = commonPrefixUtil(arr, mid+1, end);

    // The variable ans to store the longest common prefix for the range from start to end
    string ans = commonPrefix(left,right);

    return ans;
}
    

string longestCommonPrefix(vector<string> &arr, int n)
{
    // A variable to store longest common prefix for the range from 0 to n-1
    string longestPrefix = commonPrefixUtil(arr, 0, n-1);

    return longestPrefix;
}  


Binary Search
In this approach, we will first find the string with the minimum length among all the strings in the array and store it as prefix because the shortest string is the longest possible common prefix. We will also define a function isCommon(ARR, prefix, length, N) to whether the string prefix is a common prefix for all the strings in the array ARR or not. We will start the search by setting start as 0 and end as the length of prefix. At each iteration, we will set mid as (start+end)/2. Each time search space is divided into two equal parts, one of them is discarded because it is sure that it doesn't contain the solution. The element prefix[0: mid] is the substring of the prefix from index 0 to mid-1. There are two possible cases:

The prefix[0: mid] is not a common string. We discard the second half of the search space. Hence, we will set end as mid-1.
prefix[0: mid] is a common string. We discard the first half of the search space because we try to find a longer common prefix. Hence, we will set start as mid-1.
At last, we will return the substring of prefix from index 0 to mid.

 

Algorithm: 

Defining function isCommon(ARR, prefix, length, N) :
We will iterate index idx from 0 to length -1, do the following steps:
We will iterate the index from 0 to N-1.
If ARR[index][idx] is not equal to prefix[idx] then we found a mismatched character, and we will return false.
If we don’t find any mismatched character, this prefix is common in all strings. Hence, return true.
 

Declare a string prefix to store the shortest string among the array.
Declare minLength to store the length of the shortest string. Initialize minLength as large integer value.
We will iterate the variable idx from 0 to N-1:
If the length of ARR[idx] is less than  minLength, do the following:
Set minLength as the length of ARR[idx].
Set prefix as ARR[idx].
Set start as 0.
Set end as minLength -1.
While start is less than or equal to end, do the following:
Set mid as (start + end) /2. 
If isCommon(arr, prefix, mid, N) is true means the first half is common in all strings, we will try to search for a longer common prefix.
Set start as mid + 1.
Otherwise, the substring of prefix from index 0 to mid is not common in all strings. We will reduce the length.
Set end as mid-1.
Set mid as (start + end) / 2 .
Now mid is the length of the longest common prefix.
Declare a string answer to store the longest common prefix for all strings of the array.
Set answer as the substring of prefix starting from index 0 to index mid-1.
Return answer corresponding to longest common prefix.
Time Complexity
O(M*N*log(M)), where N is the number of strings in ARR and M is the shortest length of the string present in the array.

 

We are doing a binary search in the range from 0 to M - 1, which takes (log(M)) time. In each iteration of binary search, we are traversing through strings present in the array ARR that takes O(N*M) time. Hence, the overall time complexity is O(M*N*log(M)).

Space Complexity
O(M), where M is the shortest length of the string present in the array.

 

We are using O(M) space to store the shortest length string. Hence, the overall space complexity is O(M).
/*
    Time Complexity: O(M*N*log(M))
    Space Complexity: O(M)

    where N is the number of strings in the array and M is the length of the shortest string present in the array.
*/

#include <climits>

// A function to check whether string prefix is common in all strings or not.
bool isCommon(vector<string> &arr, string &prefix, int length, int n)
{
    for(int idx = 0; idx < length; ++idx)
    {
        for(int index = 0; index < n; index++)
        {
            // If arr[index][idx] is not equal to prefix[idx], return false.
            if (arr[index][idx] != prefix[idx])
            {
                return false;
            }
        }
    }
    
    // The string prefix is common in all strings.
    return true; 
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // The string prefix to store the shortest string.
    string prefix = "";

    // The variable minlength to store the length of the shortest string.
    int minLength = INT_MAX;

    for(int index = 0;index < n; ++index)
    {
        if (arr[index].size() < minLength)
        {
            minLength = arr[index].size();
            prefix = arr[index];
        }
    }

    int start = 0;
    int end = minLength;
    int mid;

    while (start <= end)
    {   
        mid = (start + end) / 2;

        // The substring prefix of length mid is common in all strings 
        if (isCommon(arr, prefix, mid, n))
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    mid = (start + end) / 2;

    // The string answer will store the longest common prefix 
    string answer = prefix.substr(0, mid);

    return answer;
}





Using Trie
In this approach, we will use Trie to store all the strings, and then we will search for the longest common prefix using the Trie. Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. We need to mark the last node of every key by setting endOfWord as true. 

To search for the longest common prefix, we will start from the root node of the trie and check if it has only one child. If the node satisfies this condition, we will add it into our longest common prefix.
If we encounter a node where endOfWord is true, we cannot iterate further
Hence our search is completed. We will also define a function insertWord(root, word) to insert a string word into the Trie. 

 

Algorithm: 

Defining TrieNode class:
A variable val to store the character.
An array child of size 26 to store the child pointers corresponding to each character. Initialize all the child pointers with an empty node.
A variable childCount to count the number of child nodes. Set childCount with 0.
A variable endOfWord to store whether the character is the last character of the word or not.Set endOfWord as False.
 
Defining insert(root, word) function:
Set cur as root.
We iterate idx from 0 to length of word -1:
If the character word[idx] is not present in cur as a child, add that node and increment the childCount of cur by 1.
Set diff as a difference between word[idx] and ‘a’.
Set cur as child[diff] of cur.
Set endOfWord of cur as true.
 

Declare a TrieNode root.
Insert all strings of array ARR into the trie.
Declare a string answer to store the longest common prefix.
Declare a string prefix. Set prefix as ARR[0].
We will try to check if prefix is a common prefix or not.
Iterate  idx from 0 to length of prefix -1:
If childCount of the root is equal to 1.
Insert prefix[idx] into answer.
Set diff as a difference between prefix[idx] and ‘a’.
Set root as the child[diff] of the root.
Otherwise, if childCount of the root is not equal to 1.
We will break the loop.
If endOfWord of the root is true,
The search is completed, we will break the loop.
Return answer corresponding to longest common prefix.
Time Complexity
O(N*M), where N is the number of strings in the array and M is the maximum length of the string present in the array.

 

We will insert all the strings into the trie, and each insertion takes O(M) time. So the total time taken is O(M*N). We used O(M) time to find the longest common prefix. Hence, the overall time complexity is O(M*N).

Space Complexity
O(N*M), where N is the number of strings in the array and M is the maximum length of the string present in the array.

 

We are using O(M*N) space to store all strings into the trie. Hence, the overall space complexity is O(M*N).
  /*
    Time Complexity: O(N*M)
    Space Complexity: O(N*M)

    where N is the number of strings in the array and M is the maximum length of the string present in the array.
*/

class TrieNode
{	
    public:
    char val;
    vector<TrieNode*> child;
    int childCount;
    bool endOfWord;

    TrieNode(char val)
    {
        this->val = val;
        child.resize(26, NULL);
        childCount = 0;
        endOfWord = false;
    }

    ~TrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            if(child[i] != NULL)
            {
                delete child[i];
            }
        }
    }
};
    
void insert(TrieNode* root, string &word)
{
    TrieNode* cur = root;

    for(int idx = 0; idx < word.size(); ++idx)
    {   
        int diff = word[idx] - 'a';
        
        // If the child[diff] of cur is an empty node
        if (cur->child[diff] == NULL)
        {
            cur->child[diff] = new TrieNode(word[idx]);
            cur->childCount += 1;
        }

        cur = cur->child[diff];
    }

    // Marking the endOfWord of last character as true.
    cur->endOfWord = true;    
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Declaring the Trie's root node
    TrieNode* root = new TrieNode(' ');

    // Inserting each word into Trie
    for(int i = 0; i < arr.size(); i++)
    {
        string word = arr[i];
        insert(root, word);
    }

    // A string to store the longest common prefix
    string answer = "";

    // We will check if string prefix is common in all strings or not
    string prefix = arr[0];

    for(int idx = 0; idx < prefix.size(); idx++)
    {
        // Check if root has only one child.
        if (root->childCount == 1)
        {
            answer += prefix[idx];
            int diff = prefix[idx] - 'a';
            root = root->child[diff];
        }
        else
        {
            break;
        }
        
        //  Check if endOfWord of root is true.  
        if (root->endOfWord)
        {
            break;
        }
    }
    
    delete root;
    
    return answer;
}
