#include <bits/stdc++.h>
using namespace std;
int f[26];
int n;

struct Node
{
    char data;
    int freq;
    struct Node *right, *left;
};
class Compare 
{ 
public: 
    bool operator()(Node* a, Node* b) 
    { 
        return a->freq > b->freq; 
    } 
}; 
void printCode(Node *root, string ss)
{
    //cout<<ss<<" ";
    if(root->left)
    {
        string s1=ss;
        s1+='0';
        printCode(root->left, s1);
    }
    if(root->right)
    {
        string s2=ss;
        s2+='1';
        printCode(root->right, s2);
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<ss<<" ";
    }
}
void solve()
{
    string s;
    cin>>s;
    
    n=s.length();
    priority_queue< Node* , vector<Node*> , Compare >pq;
    
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
        
        struct Node* temp = (struct Node*)malloc(
        sizeof(struct Node));
        temp->right=NULL;
        temp->left=NULL;
        temp->freq=f[i];
        temp->data=s[i];
        
        pq.push(temp);
    }
    
    while(pq.size()>1)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        
        temp->left=pq.top();
        int f1=pq.top()->freq;
        pq.pop();
        
        temp->right=pq.top();
        int f2=pq.top()->freq;
        pq.pop();
    
        temp->freq=f1+f2;
        temp->data='*';
        //cout<<f1+f2<<" ";
        pq.push(temp);
    }
    
    printCode(pq.top(),"");
    cout<<'\n';
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
