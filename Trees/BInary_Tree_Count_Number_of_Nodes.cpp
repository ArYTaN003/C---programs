#include "Binary_Tree.cpp"
int count(BinaryTreeNode<int> *&root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}