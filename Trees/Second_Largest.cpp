#include "Tree_class.h"
class custom{
    public:
    TreeNode<int> *max;
    TreeNode<int> *secondMax;
};

custom getSecondLargestNode1(TreeNode<int> *root){
    custom ans;
    ans.max=root;
    ans.secondMax=NULL;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp;
        custom res = getSecondLargestNode1(root->children[i]);
        if(ans.max->data<res.max->data){
            temp=ans.max;
            if(res.secondMax!=NULL){
                if( temp->data>res.secondMax->data){
                    ans.secondMax=temp;
                }
                else if(res.secondMax->data>temp->data){
                    ans.secondMax=res.secondMax;
                }
            }
            else{
                ans.secondMax=temp;
            }
            ans.max=res.max;
            }
        else if(ans.max==res.max){
                ans.secondMax=NULL;
            }
        else if(ans.secondMax!=NULL){
                if(res.max->data > ans.secondMax->data){
                    ans.secondMax=res.max;
                }   
        }
        else if(res.max->data<ans.max->data){
            ans.secondMax=res.max;
        }
            //cout << ans.max->data << " " << ans.secondMax->data << endl;
        }
        
        return ans;
}
    
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){
        return root;
    }
    custom ans=getSecondLargestNode1(root);
   return ans.secondMax;
}