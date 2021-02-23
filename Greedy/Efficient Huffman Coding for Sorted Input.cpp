#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
struct Node
{
    char data;
    int freq;
    Node *right, *left;
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
        cout<<root->data<<" "<<ss<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    char ch[n];
    for(int i=0;i<n;i++)
    {
        cin>>ch[i];
    }

    int fr[n];
    queue<Node*>q1;
    queue<Node*>q2;

    for(int i=0;i<n;i++)
    {
        cin>>fr[i];
        Node *temp= new Node[sizeof(Node)];
        temp->right=NULL;
        temp->left=NULL;
        temp->freq=fr[i];
        temp->data=ch[i];
        q1.push(temp);
    }

    if(n==1)
    {
        cout<<0<<'\n';
        return 0;
    }

    while(!(q1.size()==0 && q2.size()==1))
    {
        if(q1.size()==0)
        {
            Node *temp = new Node[sizeof(Node)];
            temp->left=q2.front();
            Node *temp1=q2.front();
            q2.pop();
            temp->right=q2.front();
            Node *temp2=q2.front();
            q2.pop();
            temp->freq=temp1->freq+temp2->freq;
            temp->data='*';

            q2.push(temp);
        }
        else if(q2.size()==0)
        {
            Node *temp = new Node[sizeof(Node)];
            temp->left=q1.front();
            Node *temp1=q1.front();
            q1.pop();
            temp->right=q1.front();
            Node *temp2=q1.front();
            q1.pop();
            temp->freq=temp1->freq+temp2->freq;
            temp->data='*';

            q2.push(temp);
        }
        else
        {
            Node *temp = new Node[sizeof(Node)];
            
            Node *temp1;
            if(q1.front()->freq<=q2.front()->freq)
            {
                temp->left=q1.front();
                temp1=q1.front();
                q1.pop();
            }
            else
            {
                temp->left=q2.front();
                temp1=q2.front();
                q2.pop();
            }

            Node *temp2;
            if(q1.size()==0)
            {
                temp->right=q2.front();
                temp2=q2.front();
                q2.pop();
            }
            else if(q2.size()==0)
            {
                temp->right=q1.front();
                temp2=q1.front();
                q1.pop();
            }
            else if(q1.front()->freq<=q2.front()->freq)
            {
                temp->right=q1.front();
                temp2=q1.front();
                q1.pop();
            }
            else
            {
                temp->right=q2.front();
                temp2=q2.front();
                q2.pop();
            }

            temp->freq=temp1->freq+temp2->freq;
            temp->data='*';
            q2.push(temp);
        }
    }

    Node *root=q2.front();
    string ss="";
    printCode(root, ss);

    return 0;
}

// char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
// int freq[] = { 5, 9, 12, 13, 16, 45 }; 

// q1 = 5, 9, 12, 13, 16, 45
// q2 = 

// q1 = 12, 13, 16, 45
// q2 = 14 //now if any other number would be added to q2 in the end, it will be greater than the last number, because we are given a sorted sequence

// q1 = 16, 45
// q2 = 14, 25

// q1 = 45
// q2 = 25, 30

// q1 = 45
// q2 = 55

// q1 = 
// q2 = 100

