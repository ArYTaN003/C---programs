
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
pair<int,int> heightDiameter(BinaryTreeNode<int> *root){
    pair<int,int> ans;
    if(root==NULL){
        ans.first=0;
        ans.second=0;
        return ans;
    }
    pair<int,int> left=heightDiameter(root->left);
    pair<int,int> right=heightDiameter(root->right);
    ans.first=1+max(left.first,right.first);
    ans.second=max(left.first+right.first,max(left.second,right.second));
    return ans;

}
int diameter(BinaryTreeNode<int> *root){
   return heightDiameter(root).second;
    
}