/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue <Node*> q;
        q.push(root);
        int lr = 0 ;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0 ; i<size ; i++)
            {
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(lr == 1) reverse(level.begin(), level.end());
            ans.insert(ans.end(), level.begin(), level.end());
            lr = !lr;
        }
        return ans;
    }
};