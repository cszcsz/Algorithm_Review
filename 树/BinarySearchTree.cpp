#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lch, *rch;
    Node(int x) : data(x), lch(nullptr), rch(nullptr) {}
};

class BinarySearchTree
{
public:
    Node *root;
public:
    BinarySearchTree() = default;
    ~BinarySearchTree();
    void Insert(int x, Node *&r);
    bool Find(int x,Node* r);
    bool Delete(int x);
    int GetMaxElement();
    int GetMinElement();
    int GetHeight(Node *r);
    void InOrder(Node *r);
    void PreOrder(Node *r);
    void PostOrder(Node *r);
    void LevelOrder();
};

BinarySearchTree::~BinarySearchTree()
{

}
void BinarySearchTree::InOrder(Node *r)
{
    if (r == nullptr)
        return;
    InOrder(r->lch);
    cout << r->data << " ";
    InOrder(r->rch);
}
void BinarySearchTree::PreOrder(Node *r)
{
    if(r==nullptr)
        return;
    cout<<r->data<<" ";
    PreOrder(r->lch);
    PreOrder(r->rch);
}

void BinarySearchTree::PostOrder(Node *r)
{
    if(r==nullptr)
        return;
    PostOrder(r->lch);
    PostOrder(r->rch);
    cout<<r->data<<" ";
}

void BinarySearchTree::LevelOrder()
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* top = q.front();
        cout<<top->data<<" ";
        if(top->lch!=nullptr)
            q.push(top->lch);
        if(top->rch!=nullptr)
            q.push(top->rch);
        q.pop();
    }
}

int BinarySearchTree::GetHeight(Node* r)
{
    if(r==nullptr)
        return 0;
    else
        return max(GetHeight(r->lch),GetHeight(r->rch))+1;
}

void BinarySearchTree::Insert(int x, Node *&r)
{
    if (r == nullptr)
        r = new Node(x);
    else if (x < r->data)
        Insert(x, r->lch);
    else
        Insert(x, r->rch);
}

bool BinarySearchTree::Find(int x,Node* r)
{
    if(r==nullptr)
        return false;
    if(r->data==x)
        return true;
    else if(r->data<x)
        Find(x,r->rch);
    else
        Find(x,r->lch);
}

bool BinarySearchTree::Delete(int x)
{
    Node *p=root,*pp=nullptr;
    //先找到待删除的节点并记录其父节点
    while(p!=nullptr&&p->data!=x)
    {
        pp=p;
        if(p->data>x)
            p=p->lch;
        else
            p=p->rch;
    }
    if(p==nullptr)
        return false;
    //情况1：待删除节点有两个子节点
    if(p->lch!=nullptr&&p->rch!=nullptr)
    {
        Node *tmpMinp=p->rch,*tmpMinpp=p;
        while(tmpMinp->lch!=nullptr)
        {
            tmpMinpp=tmpMinp;
            tmpMinp=tmpMinp->lch;
        }
        p->data=tmpMinp->data; // 令待删除节点的值为其右子树上的最小值
        p=tmpMinp;          // 再删除该右子树最小值节点，巧妙的转化为情况2
        pp=tmpMinpp;     
    }
    //情况2：待删除节点是叶子节点或只有一个子节点
    Node* child;
    if(p->lch!=nullptr)
        child=p->lch;
    else if(p->rch!=nullptr)
        child=p->rch;
    else
        child=nullptr;
    if(pp==nullptr)   //如果删除的是根节点
        root=child;
    else
    {
        if(pp->lch==p)
            pp->lch=child;
        else if(pp->rch==p)
            pp->rch=child;
        delete p;
    }
    return true;
}

int main()
{
    int data[10] = {1, 3, 4, 2, 9, 10, 8, 5, 7, 6};
    BinarySearchTree *tree = new BinarySearchTree();
    for (int i = 0; i < 10; i++)
        tree->Insert(data[i], tree->root);
    cout<<"The tree height is: "<<tree->GetHeight(tree->root)<<endl;
    tree->InOrder(tree->root);
    cout<<endl;
    tree->Delete(3);
    tree->InOrder(tree->root);
    cout<<endl;
    tree->LevelOrder();
    cout<<endl;
    cout<<tree->Find(11,tree->root)<<endl;
    return 0;
}