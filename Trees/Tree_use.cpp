#include <iostream>
#include "Tree_class.h"
#include<queue>
using namespace std;
/*
TreeNode<int> *takeInput(){
    int rootdata;
    cout << "Enter data : ";
    cin >>rootdata;
    TreeNode<int> *root=new TreeNode(rootdata);
    int n;
    cout << "Enter Number of child for " << rootdata << ": ";
    cin >> n;
    for(int i=0;i<n;i++){
        TreeNode<int> *child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
*/
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
void printAtLevelK(TreeNode<int>*& root,int k){
    if(k==0){
        cout << root->data << " ";
        return ;
    }
    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}
void printLevelWise(TreeNode<int>*& root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for(int i=0;i<front->children.size();i++){
            if(i==front->children.size()-1){
              cout << front->children.at(i)->data;
            }
            else{
              cout << front->children.at(i)->data << ",";
            }
            pendingNodes.push(front->children.at(i));
        }
        cout <<endl;
    }
}
void printTree(TreeNode<int>*&root){
    if(root==NULL){
        return ;
    }
   cout << root->data  << ":";
   for(int i=0;i<root->children.size();i++){
    cout << root->children[i]->data << " ";
   }
   cout <<endl;
   for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
   }
}
int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0){
        return 1;
    }
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count+=getLeafNodeCount(root->children[i]);
    }
    return count;
}
void postorder(TreeNode<int>* const &root){
    if(root==NULL){
        return ;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}
void preorder(TreeNode<int>* const &root){
    if(root==NULL){
        return ;
    }
    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

int main() {
    //10 3 20 30 40 2 40 50 2 60 70 0 0 0 0 0
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    //preorder(root);
    //cout << endl;
    //postorder(root);
    //cout << getLeafNodeCount(root);
    delete root;
}