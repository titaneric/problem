#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int val;
    bool have_val;

public:
    Node() : have_val(false), left(NULL), right(NULL) {}
};

class NodePool
{
private:
    queue<Node *> pool;

public:
    NodePool()
    {
        init();
    }

private:
    void init()
    {
        for (int i = 0; i < 260; i++)
        {
            pool.push(new Node());
        }
    }

public:
    Node *newNode()
    {
        Node *n = pool.front();
        n->left = n->right = NULL;
        n->have_val = false;
        pool.pop();
        return n;
    }
    void deleteNode(Node *n)
    {
        pool.push(n);
    }
};

NodePool pool;
Node *root;
bool failed = false;

void addNode(int val, string dir)
{
    Node *u = root;
    for (auto d : dir)
    {
        if (d == 'L')
        {
            if (u->left == NULL)
                u->left = pool.newNode();
            u = u->left;
        }
        else if (d == 'R')
        {
            if (u->right == NULL)
                u->right = pool.newNode();
            u = u->right;
        }
    }
    if (u->have_val)
        failed = true;

    u->val = val;
    u->have_val = true;
}

bool readInput()
{
    failed = false;
    pool.deleteNode(root);
    root = pool.newNode();
    string node_str;
    while (true)
    {
        if (cin >> node_str)
        {
            if (node_str == "()")
                break;
            int val;
            string dir;
            char buf;
            stringstream ss(node_str);
            ss >> buf >> val >> buf >> dir;
            dir.erase(dir.size() - 1);
            addNode(val, dir);
        }
        else
            return false;
    }
    return true;
}

bool BFS(vector<int> &traverse)
{
    queue<Node *> q;
    traverse.clear();
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        if (!f->have_val)
            return false;
        traverse.push_back(f->val);
        if (f->left != NULL)
            q.push(f->left);
        if (f->right != NULL)
            q.push(f->right);
    }
    return true;
}

void printVec(vector<int> &vec)
{
    int i = 0;
    for (; i < vec.size() - 1; i++)
        cout << vec[i] << " ";
    cout << vec[i] << endl;
}
int main()
{
    pool = NodePool();

    vector<int> traverse;
    while (readInput())
    {
        if (!failed)
        {
            if (BFS(traverse))
                printVec(traverse);
            else
                cout << "not complete\n";
        }
        else
        {
            cout << "not complete\n";
        }
    }
    return 0;
}