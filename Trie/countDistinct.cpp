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

    int countDistinctSubstring(string s){
        int ans=0;
        int n=s.length();
        for (int i=0;i<n;i++){
            TrieNode* node=root;
            for (int j=i;j<n;j++){
                if (!node->containsKey(s[j])){
                    ans++;
                    node->put(s[j],new TrieNode());
                }
                node=node->get(s[j]);
            }
        }
        return ans;
    }

    
};
int main(){

}