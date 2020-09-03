#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
    public:

        /*第一种方法*/
        // int height(TreeNode *root){
        //     if(root==NULL) return 0;
        //     int leftHeight = height(root->left);
        //     int rightHeight = height(root->right);

        //     if(leftHeight>rightHeight){
        //         return leftHeight+1;
        //     }else{
        //         return rightHeight+1;   
        //     }

        // }

        int maxDepth(TreeNode* root){
            
            /*第二种方法，递归*/
            
            // if(root==NULL){
            //     return 0;
            // }
            // return 1+max(maxDepth(root->left), maxDepth(root->right) ) ;

            /*第三种方法，广度优先搜索🔍*/
            if(root==nullptr) return 0;
            queue<TreeNode*> Q;
            Q.push(root);
            int level = 0;
            while(!Q.empty()){
                int size = Q.size(); //first initial size is 1
                cout << "size is --->" << size <<endl;
                while(size>0){
                    TreeNode * node = Q.front();
                    cout << "now current node is-->" << node->val << endl;

                    Q.pop();
                    if(node->left) Q.push(node->left);
                    if(node->right) Q.push(node->right);
                    size -= 1;  
                }
                level += 1;
            }
            return level;
        }
};

int main(){
    Solution s;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int a = s.maxDepth(root);
    cout << "max depth is-->" << a<<endl;

}