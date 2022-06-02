#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;

struct Node
{
    int data;
    Node* next;
};

struct Node* newNode(int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

void hhhh(Node** head, int k)
{
    Node* ptr1=*head;
    Node* ptr2=*head;

    while (ptr2->next!=NULL)
    {
        ptr2 = ptr2->next;
    }
    
    while (k--)
    {
      ptr2->next = ptr1;
      *head = ptr1->next;
      ptr1->next = NULL;

      ptr2 = ptr1;
      ptr1 = *head;
    }

}

void display(struct Node* head) // for displaying the linked list
{
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    Node* ptr = new Node();
    ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"Empty List";
        return 0;
    }
    Node* head = new Node();
    int k;cin>>k;
    head = newNode(k);

    Node* current = new Node();
    // head->next = current;
    Node* pre = new Node();
    pre = head;
    for(int i=1;i<n;i++)
    {
      int f;cin>>f;
      current = newNode(f);

      pre->next = current;
      pre = current;
    }

    int x;cin>>x;
    hhhh(&head,x);

    display(head);

    return 0;
}