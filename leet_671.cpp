#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    const int MAX = 987654321;
    int findSecondMinimumValue(TreeNode * root) {
        
        // root has the min val.
        
        int retValLeft = MAX, retValRight = MAX;
        
        if (root == NULL) return -1;
        
        if (root->left != NULL)
        {
            if (root->val >= root->left->val)
            {
                retValLeft = findSecondMinimumValue(root->left);
            }
            else if (root->val < root->left->val)
            {
                retValLeft = root->left->val;
            }
        }
        
        if (root->right != NULL)
        {
            if (root->val >= root->right->val)
            {
                retValRight = findSecondMinimumValue(root->right);
            } else if (root->val < root->right->val)
            {
                retValRight = root->right->val;
            }
        }
        
        retValLeft = retValLeft == -1 ? MAX : retValLeft;
        retValRight = retValRight == -1 ? MAX : retValRight;
        
        retValLeft = std::min(retValLeft, retValRight);
        
        return retValLeft == MAX ? -1 : std::max(root->val, retValLeft);
        
        
        
//        if (root->val >= root->left->val) {
//            retValLeft = findSecondMinimumValue(root->left);
//        } else if (root->val < root->left->val) {
//            secMinLeft = root->left->val; // bigger val
//        }
//        
//        if (root->val >= root->right->val) {
//            retValRight = findSecondMinimumValue(root->right);
//        } else if (root->val < root->right->val) {
//            secMinRight = root->right->val; // bigger val
//        }
        
//        secMinLeft = std::min(secMinLeft, secMinRight);
//        retValLeft = retValLeft == -1 ? MAX : retValLeft;
//        retValRight = retValRight == -1 ? MAX : retValRight;
//        
//        // so, the min val will be the root val.
//        int test = std::min(secMinLeft, std::min(retValLeft, retValRight));
//        
//        return test == root->val ? -1 : test;
        
        // need to check -1
        // if -1, then it's the smallest so
        
        
        //return std::min(std::min(secMinLeft, secMinRight), std::min(retValLeft, retValRight));
    }
};

int main()
{
    Solution obj = Solution();
    TreeNode t1(2);
    TreeNode t2(2);
    TreeNode t3(5);
    TreeNode t4(5);
    TreeNode t5(7);
    
    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;
    
    obj.findSecondMinimumValue(&t1);
    
    
    
    
    return 0;
}
