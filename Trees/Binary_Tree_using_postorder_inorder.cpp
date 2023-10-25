#include "Binary_Tree.cpp"
BinaryTreeNode<int>* buildTree1(int *postorder,int poststart,int postend,int* inorder,int instart,int inend){
	if(poststart>postend){
		return NULL;
	}
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postend]);
    int rootIndex=-1;
	for(int i=instart;i<=inend;i++){
		if(inorder[i]==root->data){
			rootIndex=i;
			break;
		}
	}
	root->left=buildTree1(postorder, poststart,rootIndex-1-instart+poststart, inorder, instart,rootIndex-1);
    root->right =buildTree1(postorder, rootIndex - instart + poststart, postend - 1, inorder, rootIndex + 1, inend);
	return root;
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
	if(postLength==0){
		return NULL;
	}
	return buildTree1(postorder,0, postLength-1, inorder,0, inLength-1);
}