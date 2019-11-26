#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int x):data(x){}
};

struct AVLTree
{
    Node *root = nullptr;
    vector<int> LevelOrder();
    bool IsComplete();
    Node* LL_rotate(Node* r);
    Node* LR_rotate(Node* r);
    Node* RL_rotate(Node* r);
    Node* RR_rotate(Node* r);
    Node* Insert(int x,Node* r);
    int Height(Node* r);
};

Node* AVLTree::LL_rotate(Node* r)
{
    Node* x = r->left;
    r->left = x->right;
    x->right = r;
    return x;

}
Node* AVLTree::RR_rotate(Node* r)
{
    Node* x = r->right;
    r->right = x->left;
    x->left = r;
    return x;
}

Node* AVLTree::LR_rotate(Node* r)
{
    r->left = RR_rotate(r->left);
    return LL_rotate(r);
}

Node* AVLTree::RL_rotate(Node* r)
{
    r->right = LL_rotate(r->right);
    return RR_rotate(r);
}

int AVLTree::Height(Node* r)
{
    if(r==nullptr) return 0;
    return max(Height(r->left),Height(r->right))+1;
}

Node* AVLTree::Insert(int x,Node* r)
{
    if(r==nullptr)
        r = new Node(x);
    else if(x>r->data)
    {
        r->right = Insert(x,r->right);
        if(Height(r->right)-Height(r->left)>1)
        {
            if(x>r->right->data)
                r = RR_rotate(r);
            else
                r = RL_rotate(r);
        }
    }
    else
    {
        r->left = Insert(x,r->left);
        if(Height(r->left)-Height(r->right)>1)
        {
            if(x<r->left->data)
                r = LL_rotate(r);
            else
                r = LR_rotate(r);
        }
    }
    return r;
}

vector<int> AVLTree::LevelOrder()
{
    queue<Node*> q;
    vector<int> result;
    q.push(root);
    while (!q.empty())
    {
        Node* top = q.front();
        result.push_back(top->data);
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
        q.pop();
    }
    return result;
}
bool AVLTree::IsComplete()
{
    queue<Node*> q;
    q.push(root);
    Node* tmp;
    while((tmp=q.front())!=nullptr)
    {
        q.push(tmp->left);
        q.push(tmp->right);
        q.pop();
    }
    while (!q.empty())
    {
        if(q.front()!=nullptr)
            return false;
        q.pop();
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    AVLTree* tree = new AVLTree();
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        tree->root = tree->Insert(tmp,tree->root);
    }
    vector<int> level_result = tree->LevelOrder();
    for(int i=0;i<level_result.size();i++)
    {
        if(i==0)
            cout<<level_result[0];
        else
            cout<<" "<<level_result[i];
    }
    cout<<endl;
    if(tree->IsComplete())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}