#include "Binary_Tree.cpp"
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