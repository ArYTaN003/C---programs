#include <climits>
#include "Binary_Tree.cpp"
class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    private:
    int min1(BinaryTreeNode<int> *node){
      if(node==NULL){
        return INT_MAX;
      }
      int m=min(node->data,min(min1(node->left),min1(node->right)));
      return m;
    }
    void print(BinaryTreeNode<int> *node){
      if (node == NULL) {
        return;
      }
      cout << node->data << ":";
      if (node->left != NULL) {
        cout << "L:" << node->left->data<<",";
      }
      if (node->right != NULL) {
        cout << "R:" << node->right->data;
      }
      cout <<endl;
      print(node->left);
      print(node->right);
    }
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *root,int data){
      if(root==NULL){
        return root;
      }
      BinaryTreeNode<int> *temp;
      if (root->data == data) {
        temp = root;
        if(root->left!=NULL && root->right==NULL){
          root=root->left;
          delete temp;
        }
        else if(root->right!=NULL && root->left==NULL){
          root=root->right;
          delete  temp;
        }
        else if(root->left==NULL && root->right==NULL){
          root=NULL;
          delete temp;
        }
        else{
          int m=min1(root->right);
          //cout << root->data << endl;
          root->right=remove(root->right,m);
          root->data=m;
          //cout << root->data << endl;
        }
      }
      else if(root->data>data){
        root->left=remove(root->left,data);
      }
      else{
        root->right=remove(root->right,data);
      }
      return root;
    }
    public:
      void remove(int data) {
        // Implement the remove() function
        root=remove(root,data);
      }
    void print() { 
        // Implement the print() function
        print(root);
    }
    private:
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int> *node){
      BinaryTreeNode<int> *n = new BinaryTreeNode<int>(data);
      if (node == NULL) {
        node = n;
        return node;
      }
      if (node->data >= data) {
        node->left=insert(data,node->left);
      } else {
        node->right=insert(data,node->right);
      }
    }
    bool search(BinaryTreeNode<int>*node,int data){
      if(node==NULL){
        return false;
      }
      if(node->data==data){
        return true;
      }
      else if(node->data>data){
        return search(node->left,data);
      }
      else{
        return search(node->right,data);
      }
    }
    public:
    void insert(int data) { 
        // Implement the insert() function
        root=insert(data,root);
    }

    bool search(int data) {
		// Implement the search() function 
      return search(root,data);
    }
};