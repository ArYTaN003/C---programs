#include "Binary_Tree.cpp"
BinaryTreeNode<int> *getLCAHelper(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == nullptr || root->data == a || root->data == b)
    {
        return root;
    }
    if (root->data < a && root->data < b)
    {
        return getLCAHelper(root->right, a, b);
    }
    else if (root->data > a && root->data > b)
    {
        return getLCAHelper(root->left, a, b);
    }
    BinaryTreeNode<int> *leftLCA = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int> *rightLCA = getLCAHelper(root->right, a, b);
    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        return root;
    }
    else if (leftLCA != nullptr)
    {
        return leftLCA;
    }
    return rightLCA;
}
int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
{
    BinaryTreeNode<int> *node = getLCAHelper(root, val1, val2);
    return (node == nullptr) ? -1 : node->data;
}