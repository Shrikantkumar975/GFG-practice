class Solution {
  public:
    
class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];

    TrieNode()
    {
        isWord = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = 0;
        }
    }
};

int countSubs(string &s)
{
    TrieNode* head = new TrieNode();

    // will hold the count of unique substrings 
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        TrieNode* temp = head;

        for (int j = i; j < s.length(); j++) {
            
            // when char not present add it to the trie
            if (temp->child[s[j] - 'a'] == NULL) {
                temp->child[s[j] - 'a'] = new TrieNode();
                temp->isWord = 1;
                count++;
            }
            // move on to the next char
            temp = temp->child[s[j] - 'a'];
        }
    }

    return count;
}
};