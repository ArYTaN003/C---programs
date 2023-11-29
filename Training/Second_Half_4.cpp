#include <iostream>
#include<queue>
using namespace std;
class BSTNode{
    public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val){
        this->val =val;
        left=NULL;
        right=NULL;
    }
};
BSTNode* insert(BSTNode* root,int val){
    if(root==NULL){
        return new BSTNode(val);
    }
    if(root->val>val){
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
BSTNode* del(BSTNode* root,int val){
    if(root==NULL) return NULL;
    if(root->val==val){
        if(root->left && root->right){
            BSTNode * m=getmin(root->right);
            swap(m->val,root->val);
            root->right=del(root->right,val);
            return root;
        }else if(root->left){
            return root->left;
        }else if(root->right){
            return root->right;
        }else{
            delete root;
            return NULL;
        }
    }
    else if(root->val>val){
        root->left = del(root->left,val);
    }else{
        root->right = del(root->right,val);
    }
    return root;
}
BSTNode *getLCAHelper(BSTNode *root, int a, int b)
{
    if (root == nullptr || root->val == a || root->val == b)
    {
        return root;
    }
    if (root->val < a && root->val < b)
    {
        return getLCAHelper(root->right, a, b);
    }
    else if (root->val > a && root->val > b)
    {
        return getLCAHelper(root->left, a, b);
    }
    BSTNode *leftLCA = getLCAHelper(root->left, a, b);
    BSTNode *rightLCA = getLCAHelper(root->right, a, b);
    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        return root;
    }
    return NULL;
     }
int getLCA(BSTNode *root, int val1, int val2)
{
    BSTNode *node = getLCAHelper(root, val1, val2);
    return (node == nullptr) ? -1 : node->val;
}
void levelOrder(BSTNode *root){
    queue<BSTNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BSTNode * f = q.front();
        q.pop();
        if(f==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << f->val << " ";
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
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
    levelOrder(root);
    root = del(root,20);
    cout << getLCAHelper(root,4,14)->val << endl;
    levelOrder(root);
}