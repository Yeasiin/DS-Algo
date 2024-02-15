#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *treeInput()
{
    int n;

    cin >> n;

    TreeNode *root;
    if (n == -1)
        root = NULL;
    else
        root = new TreeNode(n);

    queue<TreeNode *> q;
    if (root)
    {
        q.push(root);
    }

    while (!q.empty())
    {
        TreeNode *top = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        TreeNode *leftNode, *rightNode;

        if (l == -1)
        {
            leftNode = NULL;
        }
        else
        {
            leftNode = new TreeNode(l);
        }

        if (r == -1)
        {
            rightNode = NULL;
        }
        else
        {
            rightNode = new TreeNode(r);
        }

        top->left = leftNode;
        top->right = rightNode;

        if (top->left)
            q.push(top->left);

        if (top->right)
            q.push(top->right);
    }
    return root;
}

void printLevelWise(TreeNode *root)
{

    if (root == NULL)
        return;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *top = q.front();
        q.pop();

        cout << top->val << " ";

        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }
}

int countLeaf(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    //
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        int l = countLeaf(root->left);
        int r = countLeaf(root->right);
        return l + r;
    }
}

int main()
{
    TreeNode *root = treeInput();

    printLevelWise(root);

    cout << endl
         << endl
         << countLeaf(root);

    return 0;
}