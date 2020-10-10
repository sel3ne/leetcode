/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> buffer;
        int start1 = 0;
        collect(root1, buffer);
        int start2 = buffer.size();
        collect(root2, buffer);
        vector<int> result;
        int end1 = start2;
        int end2 = buffer.size();
        int p = start1;
        int q = start2;
        while (p < end1 || q < end2)
        {
            if (p == end1)
            {
                result.push_back(buffer[q++]);
            }
            else if (q == end2)
            {
                result.push_back(buffer[p++]);
            }
            else
            {
                int bp = buffer[p];
                int bq = buffer[q];
                if (bp < bq)
                {
                    result.push_back(buffer[p++]);
                }
                else
                {
                    result.push_back(buffer[q++]);
                }
            }
        }
        return result;
    }
    
    void collect(TreeNode* n, vector<int>& buffer)
    {
        if (n != nullptr)
        {
            collect(n->left, buffer);
            buffer.push_back(n->val);
            collect(n->right, buffer);
        }
    }
};