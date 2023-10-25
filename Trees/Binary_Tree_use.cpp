#include <iostream>
#include<queue>
#include<vector>
#include "Binary_Tree.cpp" 
using namespace std;
#include "Binary_Tree_Diamete.cpp"

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		return ;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int> *front=pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << ":";
		cout << "L:";
		if (front->left){
                cout << front->left->data;
                pendingNodes.push(front->left);
        }
        else{
          cout << -1;
        }
		cout <<",";
        cout << "R:";
		if (front->right) {
          cout << front->right->data;
          pendingNodes.push(front->right);
        }
        else{
          cout << -1;
        }
        cout << endl; 
	}
} 
void printTree(BinaryTreeNode<int> *&root){
    if(root==NULL){
        return ;
    }
    cout << root->data << ":";
    if(root->left!=NULL){ 
        cout << "L" << root->left->data;
    }
    if(root->right!=NULL){
        cout << "R" << root->right->data;
    }
    cout <<endl;
    printTree(root->left);
    printTree(root->right);
}
int count(BinaryTreeNode<int> *&root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
BinaryTreeNode<int> *buildTree1(int *preorder, int prestart,int preend ,int *inorder, int instart,int inend) {
  // Write your code here
  BinaryTreeNode<int> *root = NULL;
  if(preend-prestart+1==0){
	  return root;
}
root = new BinaryTreeNode<int>(preorder[prestart]);
  int rootIndex = -1;
  for (int i = instart; i <=inend; i++) {
    if (inorder[i] == root->data) {
      rootIndex = i;
      break;
    }
  }
  int end=rootIndex-instart+prestart;
  root->left =buildTree1(preorder,prestart+1,end,inorder,instart,rootIndex-1);
  root->right = buildTree1(preorder, end+1,preend,inorder, rootIndex+1, inend);
  return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
	if(preLength==0){
		return NULL;
	}
	return buildTree1(preorder,0,preLength-1, inorder,0,inLength-1);

}
vector<int>  preorder(BinaryTreeNode<int> *node){
	vector<int> pre;
	if(node==NULL){
		return pre;
	}
	pre.push_back(node->data);
	vector<int> l=preorder(node->left);
	for(int i=0;i<l.size();i++){
		pre.push_back(l.at(i));
	}
	vector<int> r=preorder(node->right);
	for(int i=0;i<r.size();i++){
		pre.push_back(r.at(i));
	}
	return pre;
}
int main(){
    BinaryTreeNode<int> *root=takeInput();
    /*
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3);
    root->left=node1;
    root->right=node2;
    */
   //5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
    //int preorder[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    //int inorder[]={2,4,6,5,7,8,9,3,1,10,11,12,13};
    //int l=13;
   //BinaryTreeNode<int> *root=buildTree(preorder,l,inorder,l);
    /*vector<int> p= preorder(root);
    sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++){
        cout << p.at(i) << endl;
    }
    */
    printLevelWise(root);
    delete root;
}