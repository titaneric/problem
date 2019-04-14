#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;

public:
    Node() : left(NULL), right(NULL), val(0) {}
    Node(int val) : left(NULL), right(NULL), val(val) {}
};

vector<int> inorder_traverse;
vector<int> postorder_traverse;

bool readList(vector<int> &traverse)
{
    string line;
    if (!getline(cin, line))
        return false;

    if (line.size() && line[line.size() - 1] == '\r')
        line.erase(line.size() - 1);

    traverse.clear();
    stringstream ss(line);
    int val;
    while (ss >> val)
    {
        traverse.push_back(val);
    }
    return traverse.size() > 0;
}
Node *buildTree(vector<int>::iterator inorder_left, vector<int>::iterator inorder_right, vector<int>::iterator postorder_left, vector<int>::iterator postorder_right)
{
    if (distance(inorder_left, inorder_right) < 0)
        return NULL;

    Node *root = new Node(*postorder_right);

    vector<int>::iterator root_it = find(inorder_left, inorder_right, root->val);

    int left_tree_cnt = distance(inorder_left, root_it);

    root->left = buildTree(inorder_left, root_it - 1, postorder_left, postorder_left + left_tree_cnt - 1);
    root->right = buildTree(root_it + 1, inorder_right, postorder_left + left_tree_cnt, postorder_right - 1);

    return root;
}

void DFS(Node *node, int cur_sum, int &min_leaf, int &min_sum)
{
    cur_sum += node->val;

    if (node->left == NULL && node->right == NULL)
    {
        if ((cur_sum < min_sum) || ((cur_sum == min_sum) && (node->val < min_leaf)))
        {
            min_sum = cur_sum;
            min_leaf = node->val;
        }
    }
    if (node->left != NULL)
        DFS(node->left, cur_sum, min_leaf, min_sum);
    if (node->right != NULL)
        DFS(node->right, cur_sum, min_leaf, min_sum);
}
int main()
{
    while (readList(inorder_traverse))
    {
        readList(postorder_traverse);
        Node *root = buildTree(inorder_traverse.begin(), inorder_traverse.end() - 1, postorder_traverse.begin(), postorder_traverse.end() - 1);
        int min_leaf = numeric_limits<int>::max();
        int min_sum = numeric_limits<int>::max();
        DFS(root, 0, min_leaf, min_sum);

        cout << min_leaf << endl;
    }

    return 0;
}
