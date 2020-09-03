#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:

        void preOrder(TreeNode* root, vector<TreeNode*> &list){
            if(root!=nullptr){
                list.push_back(root);
                preOrder(root->left, list);
                preOrder(root->right, list);
            }
        } 

        void flatten(TreeNode* root){

            vector<TreeNode*> list;
            preOrder(root, list);
            int size = list.size();
            for(int i=1; i<size; ++i){
                TreeNode *pre = list.at(i-1), *curr = list.at(i);

                pre->left = nullptr;
                pre->right = curr;

            }


        }
};

int main(){
    Solution s;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);


    s.flatten(root);
}