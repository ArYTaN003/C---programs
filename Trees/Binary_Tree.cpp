template<typename t>
class BinaryTreeNode{
    public:
    t data;
    BinaryTreeNode<t>* left;
    BinaryTreeNode<t>* right;
    BinaryTreeNode(t data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};