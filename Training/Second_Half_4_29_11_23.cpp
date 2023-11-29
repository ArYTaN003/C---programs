#include <iostream>
#include<map>
#include<queue>
using namespace std;
class BSTNode{
    public:
    int data;
    int hd;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val){
        this->data =val;
        left=NULL;
        right=NULL;
    }
};
BSTNode* insert(BSTNode* root,int val){
    if(root==NULL){
        return new BSTNode(val);
    }
    if(root->data>val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
BSTNode * getmin(BSTNode* root){
    if(!root->left) return root;
    return getmin(root->left);
}
void inorder(BSTNode* root,vector<int>& p){
    if(root==NULL) return ;
    inorder(root->left,p);
    p.push_back(root->data);
    inorder(root->right,p);
}
void succesor(BSTNode*root,int val){
    vector<int>p;
    inorder(root,p);
    for(int i=0;i<p.size();i++){
        cout << p[i] << " ";
    }
    cout << endl;
    for(int i=0;i<p.size();i++){
        if(p[i]==val){
            if(i-1>=0)
                cout << p[i-1] << " ";
            if(i+1<p.size())
                cout << p[i+1];
            cout << endl; 
        }
    }
}
void topview(BSTNode* root)
{
    if (root == NULL)
        return;
    queue<BSTNode*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
    cout << endl;
}
int main(){
    BSTNode *root=NULL;
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,22);
    root=insert(root,4);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,14);
    root=insert(root,25);
    topview(root);
    succesor(root,8);
}