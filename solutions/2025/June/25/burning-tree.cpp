*/
class Solution {
  public:
    void parents(Node* root,unordered_map<Node* ,Node*> &parent,int target,Node* &target_node)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* mynode = q.front(); q.pop();
            if(mynode->data == target) target_node = mynode;
            
            if(mynode->left)
            {
                q.push(mynode->left);
                parent[mynode->left] = mynode;
            }
            
            if(mynode->right)
            {
                q.push(mynode->right);
                parent[mynode->right] = mynode;
            }
        }
    }
    
    
    int minTime(Node* root, int target) {
        unordered_map<Node* , Node*> parent_track;
        Node* target_node;
        parents(root,parent_track,target,target_node);
        
        int mintime = 0;
        unordered_map<Node* , bool> visited;
        queue<Node*> q;
        q.push(target_node);
        visited[target_node] = true;
        
        while(!q.empty())
        {
            int size = q.size();
            bool any_burn = false;
            for(int i = 0 ; i < size ; i++)
            {
                Node* mynode = q.front(); q.pop();
                
               if(mynode->left && !visited[mynode->left])