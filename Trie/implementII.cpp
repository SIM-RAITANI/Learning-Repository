#include <iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    TrieNode* links[26];
    int count;
    int endsHere;
    TrieNode() {
        count=0;
        endsHere=0;
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
        endsHere++;
    }
    void increaseCount(){
        count++;
    }
    int returnCount(){
        return count;
    }
    int returnEndsHere(){
        return endsHere;
    }
    void DecreaseCount(){
        count--;
    }
    void DecreaseEndsHere(){
        endsHere--;
    }
};

class Trie{
    private:
    TrieNode* root;
    public:

    Trie(){
        root=new TrieNode();
    }

    void insert(string &word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
            node->increaseCount();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                return 0;
            }else{
                node=node->get(word[i]);
            }
        }
        return node->returnEndsHere();
    }

    int countWordsStartingWith(string &word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            if (!node->containsKey(word[i])){
                return 0;
            }else{
                node=node->get(word[i]);
            }
        }
        return node->returnCount();
    }

    void erase(string &word){
        TrieNode* node=root;
        for (int i=0;i<word.length();i++){
            TrieNode* nextNode=node->get(word[i]);
            nextNode->DecreaseCount();
            if(nextNode->returnCount() == 0){
                node->links[word[i]-'a'] = NULL;
                delete nextNode;
                return;
            }
            node=nextNode;
        }
        node->DecreaseEndsHere();
    }
};

int main(){

}