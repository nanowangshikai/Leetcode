#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        bool isSymmetric(TreeNode* root){
            return false;
        }

        //先序
        void preOrder(TreeNode *root){
            if(root!=NULL){
                
                cout << "current root is-->" << root->val << endl;
                preOrder(root->left);
                preOrder(root->right);   
            }  
        }
        //中序
        void inOrder(TreeNode *root){
            if(root!=NULL){
                inOrder(root->left);
                cout << "current root is-->" << root->val << endl;
                inOrder(root->right);   
            }  
        }
        //后序
        void PostOrder(TreeNode *root){
            if(root!=NULL){
                PostOrder(root->left);
                PostOrder(root->right);   
                cout << "current root is-->" << root->val << endl;
            }  
        }

        int height (TreeNode *root){
            if(root == NULL){
                return 0;
                }else{
                int lheight = height(root->left);
                int rheight = height(root->right);

                if (lheight > rheight)  
                    return(lheight + 1);  
                else return(rheight + 1);  

            }

        }

        void printGivenLevel(TreeNode* root, int level){
            if(root==NULL) return;
            if(level==1){
                cout << root->val << endl;
            }else if(level>1){
                printGivenLevel(root->left, level-1);
                printGivenLevel(root->right, level-1);
            }
        }

        void DFS(TreeNode *root){
                int h = height(root);
                cout << "the highest level is -->" << h <<endl;
                for(int i=0; i<=h; ++i){
                    printGivenLevel(root, i);    
                }
        }
        


};



int main(){
    Solution s;

    TreeNode *root = new TreeNode(1);
    TreeNode *second1 = new TreeNode(2);
    TreeNode *second2 = new TreeNode(2);
    TreeNode *third1 = new TreeNode(3);
    TreeNode *third2 = new TreeNode(4);
    TreeNode *third3 = new TreeNode(4);
    TreeNode *third4 = new TreeNode(3);

    // root->left = TreeNode(2);
    // root->right = TreeNode(2);

    root->left = second1;
    root->right = second2;
    second1->left = third1;
    second1->right = third2;
    second2->left = third3;
    second2->right = third4;
    // s.preOrder(root);

    s.DFS(root);

}