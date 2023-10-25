
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return root;
    }
    TreeNode<int> *max=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *curr=maxDataNode(root->children[i]);
        if(max->data<curr->data){
            max=curr;
        }
    }
    return max;
}