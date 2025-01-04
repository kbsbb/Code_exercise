//题目：检查平衡性
//链接：https://leetcode.cn/problems/check-balance-lcci/description/
//描述：实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1
//注释：
//思路：先写出求树的高度函数，再递归判断左右子树是否平衡
//总结：



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


typedef struct TreeNode treenode;

//求二叉树的高度函数
int getTreeHeight(treenode* root){
    if(root==NULL){
        return 0;
    }
    int left = 1+getTreeHeight(root->left);
    int right = 1+getTreeHeight(root->right);
    
    return left > right ? left :right;

}


bool isBalanced(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    //如果左右子树高度差大于1返回false
    int left = getTreeHeight(root->left);
    int right = getTreeHeight(root->right);
    if(abs(left-right)>1){
        return false;
    }
    //返回值只要出现false，最后就返回false，必须全部是true才能返回true
    return isBalanced(root->left) && isBalanced(root->right);
}