#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char val){
        this->data=val;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    TrieNode *root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    private:
    void insert(TrieNode *node,string word){
        if(word.length()==0){
            node->isTerminal=true;
            return ; 
        }
        if(node->children[word[0]-97]==NULL){
            node->children[word[0]-97]=new TrieNode(word[0]);
        }
        node=node->children[word[0]-97];
        insert(node,word.substr(1));
    }
    bool search(TrieNode *node,string word){
        if(word.length()==0){
            return node->isTerminal;
        }
        if(node->children[word[0]-'a']==NULL){
            return false;
        }
        return search(node->children[word[0]-'a'],word.substr(1));
    }
    void remove(TrieNode *node,string word){
        if(word.length()==0){
            node->isTerminal=false;
            return ;
        }
        if(node->children[word[0]-'a']==NULL){
            return ;
        }
        remove(node->children[word[0]-'a'],word.substr(1));
        if(node->children[word[0]-'a']->isTerminal==false){
            for(int i=0;i<26;i++){
                if(node->children[word[0]-'a']->children[i]!=NULL){
                    return ;
                }
            }
            delete node->children[word[0]-'a'];
            node->children[word[0]-'a']=NULL;
        }
    }
    public:
    void insert(string word){
        insert(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    void remove(string word){ 
        remove(root,word);
    }
};