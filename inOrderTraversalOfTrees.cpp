/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;

    if(root == nullptr){
      return ans;
    }

    stack<TreeNode*> s;
    TreeNode* current = root;

    while(!s.empty() || current != nullptr){
     
     while(current != nullptr){
     s.push(current);
     current = current -> left;
     }

     current = s.top();
     s.pop();
     ans.push_back(current -> data);
     
     current = current->right;

    }

    return ans;  
}
