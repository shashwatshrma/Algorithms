#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int freq;
    char val;
    Node *left, *right;
};

void percolate_down(vector<Node*> &chars, int i, int n)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2;
    int minimum = i;
    if (c1 < n && chars[minimum]->freq > chars[c1]->freq)
        minimum = c1;
    if (c2 < n && chars[minimum]->freq > chars[c2]->freq)
        minimum = c2;
    if (minimum != i)
    {
        swap(chars[i], chars[minimum]);
        percolate_down(chars, minimum, n);
    }
}

void percolate_up(vector<Node*> &chars, int i, int n)
{
    int p = (i-1)/2;
    if (p >= 0 && chars[i] > chars[p])
    {
        swap(chars[i], chars[p]);
        percolate_up(chars, p, n);
    }
}

void build_heap(vector<Node*> &chars, int n)
{
    for (int i = (n + 1) / 2; i >= 0; i--)
    {
        percolate_down(chars, i, n);
    }
}

void insert(vector<Node*> &chars, int &n, Node *new_node)
{
    if(n==chars.size())
    {
        chars.push_back(new_node);
    }
    else
    {
        chars[n]=new_node;
    }
    n++;
    percolate_up(chars, n-1, n);
}

Node* extract_min(vector<Node*> &chars, int &n)
{
    Node *temp = chars[0];
    swap(chars[0], chars[n - 1]);
    n--;
    percolate_down(chars, 0, n);
    return temp;
}

void pprint(Node* ch, string code)
{
    if(ch->left==NULL && ch->right==NULL)
    {
        cout<<ch->val<<" "<<code<<'\n';
        return;
    }
    pprint(ch->left, code+"0");
    pprint(ch->right, code+"1");
}

int main()
{
    vector<Node*> chars;
    Node *temp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        temp=new Node();
        cin>>temp->val;
        cin>>temp->freq;
        temp->left=NULL;
        temp->right=NULL;
        chars.push_back(temp);
    }
    build_heap(chars, n);
    Node *c1,*c2;
    while(n!=1)
    {
        c1=extract_min(chars, n);
        c2=extract_min(chars, n);
        temp=new Node();
        temp->val='$';
        temp->freq=c1->freq+c2->freq;
        temp->left=c1;
        temp->right=c2;
        insert(chars, n, temp);
    }
    pprint(chars[0], "");
}