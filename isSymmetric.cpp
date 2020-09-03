#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
    public:
        
        bool check(TreeNode* p, TreeNode* q){
            if(p==NULL && q==NULL){return true;} //if they both empty 
            if(q==NULL || p==NULL){return false;}   //if one of Tree is empty
            return (p->val==q->val) && check(p->left,q->right) && check(p->right, q->left);
        }
        
        bool isSymmetric(TreeNode* root){
            return check(root, root);
        }
};

int main(){

    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool yesOrno = s.isSymmetric(root);
    cout << "This is symmetric root ? " << yesOrno <<endl;

}