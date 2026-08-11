#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Longest ZigZag Path in a Binary Tree
// Approach: DFS passing steps downward, resetting to 1 when direction breaks.
// maxLen updated at every node. Two initial calls handle starting zigzag left or right from root.
// Time: O(n) — visits every node once (called twice from root, still O(n) total)
// Space: O(h) — recursion stack, h = height of tree
class Solution {
public:
   int maxLen=0;
   void solve(TreeNode*root,int steps,bool goLeft){
        if (root==nullptr) return;
    maxLen=max(steps,maxLen);
    if(goLeft==true){
        solve(root->left,steps+1,false);
        solve(root->right,1,true);
    }
    else{
        solve(root->right,steps+1,true);
        solve(root->left,1,false);

    }

   }
    int longestZigZag(TreeNode* root) {
        solve(root,0,true);
        solve(root,0,false);
        return maxLen;
    }
};