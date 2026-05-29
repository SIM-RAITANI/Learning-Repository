#include<iostream>
#include<vector>
using namespace std;
class TrieNode {
public:
    TrieNode* next[2];
    TrieNode() {
        next[0] = NULL;
        next[1] = NULL;
    }
};
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->next[bit] == NULL) {
                node->next[bit] = new TrieNode();
            }
            node = node->next[bit];
        }
    }
    int getMax(int num) {
        TrieNode* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            int oppositeBit = 1 - bit;

            if (node->next[oppositeBit] != NULL) {

                maxi = maxi | (1 << i);
                node = node->next[oppositeBit];
            } else {

                node = node->next[bit];
            }
        }
        return maxi;
    }
};
int main(){

}