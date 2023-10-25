#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int,int> ans;
	if(root==NULL){
		ans.first=INT_MAX;
		ans.second=INT_MIN;
		return ans;
	}
	pair<int, int> l =getMinAndMax(root->left);
	pair<int, int> r=getMinAndMax(root->right);
	ans.first=min(min(l.first,r.first),root->data);
	ans.second=max(max(l.second,r.second),root->data);
	return ans;
}