int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0){
        return 1;
    }
    int size=1;
    for(int i=0;i<root->children.size();i++){
        int curr=getHeight(root->children[i]);
        if(curr>size){
            size=curr;
        }
    }
    return  size+1;
}