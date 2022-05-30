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

int countNodes(struct Node* n)
{
    if(n==NULL)
    return 0;

    int cnt=1;
    Node* ptr = n;
    while (ptr->next!=NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

struct Node* answer(int d, struct Node* n1, struct Node* n2)
{
   Node* ptr1 = n1;
   while(d--)
   {
       ptr1 = ptr1->next;
   }
   Node* ptr2 = n2;

   while(ptr1!=ptr2)
   {
       ptr1 = ptr2->next;
       ptr2 = ptr2->next;
   }

   return ptr1;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    Node* head1 = new Node();
    head1 = newNode(10);

    Node* head2 = newNode(20);

    Node* newnode = newNode(15); // 2nd node for 1st list.
    head1->next=newnode;

    newnode = newNode(24); // 2nd node for 2nd list.
    head2->next=newnode;

    newnode = newNode(17); // 3rd node for 1st list.
    head1->next->next=newnode;

    newnode = newNode(22); // 4th node for 1st list.
    head1->next->next->next=newnode;


    head2->next->next=newnode;  //3rd node for 2nd list.

    newnode = newNode(25);
    head1->next->next->next->next=newnode; // 5th node for 1st list and 4th node for 2nd list.

    int c1 = countNodes(head1);
    int c2 = countNodes(head2);

    Node* ans = new Node();
    
    if(c1>c2)
    {
       int d = c1-c2;
       ans = answer(d,head1,head2);
    }

    else
    {
        int d = c2-c1;
        ans = answer(d,head2,head1);
    }
   cout<<ans->data;
    return 0;
}