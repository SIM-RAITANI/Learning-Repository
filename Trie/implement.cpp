#include <iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    TrieNode* links[26];
    bool flag;
    
    TrieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            links[i] = NULL; 
        }
    }
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,TrieNode* node){
        links[ch-'a']=node;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isTerminal(){
        return flag;
    }
};
class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    }

    void insert(string word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    //search a particular key in the trie
    bool search(string word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                return false;
            }else{
                node=node->get(word[i]);
            }
        }
        return node->isTerminal();
    }

    //check if any word starts with a given prefix
    bool startsWith(string word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                return false;
            }else{
                node=node->get(word[i]);
            }
        }
        return true;
    }
};
int main(){

}