#include <iostream>
#include<vector>
using namespace std;


class TrieNode {
public:
    TrieNode* links[26];
    bool flag;
    
    TrieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            links[i] = NULL; 
        }
    }
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isTerminal() {
        return flag;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    
    void f(TrieNode* node, string temp, string &ans) {
        if (temp.length() > ans.length()) {
            ans = temp;
        } else if (temp.length() == ans.length()) {
            if (temp < ans) ans = temp;
        }

    
        for (int i = 0; i < 26; i++) {
            if (node->containsKey(i + 'a')) {
                TrieNode* child = node->get(i + 'a');
                
                
                if (child->isTerminal()) {
                    f(child, temp + (char)(i + 'a'), ans);
                }
            }
        }
    }
    
    string longestWord() {
        string ans = "";
        string temp = "";
        TrieNode* node = root;
        f(node, temp, ans);
        return ans;
    }
};

class Solution {
public:
    
    string longestValidWord(vector<string>& words) {
        Trie* root = new Trie();
        for (auto word : words) {
            root->insert(word);
        }
        return root->longestWord();
    }
};
