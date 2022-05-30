#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,pair<int,int>> ppi;


struct Node
{
    int data;
    Node* next;
    Node* pre;
};

struct Node* newNode(int data)
{
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = NULL;
    ptr->pre = NULL;

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

bool isPalindrome(struct Node* head)
{
  Node* ptr1 = head; 
  Node* ptr2 = head;

  while (ptr2->next!=NULL)
  {
      ptr2 = ptr2->next;
  }

  while(ptr1!=ptr2)
  {
    int a=ptr1->data;
    int b = ptr2->data;

    if(a!=b) return false;
    ptr1 = ptr1->next;
    ptr2 = ptr2->pre;
  } 
  return true;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

  int n;cin>>n;

  Node* head1 = new Node();
  int p;cin>>p;
  head1 = newNode(p);

  Node* ptr1 = head1;

  for(int i=1;i<n;i++)
  {
      int k;cin>>k;
      Node* current = newNode(k);
      ptr1->next = current;
      current->pre = ptr1;
      ptr1 = current;
  }

  if(isPalindrome(head1))
  cout<<"Palindrome";
  else
  cout<<"Not Palindrome";
   
    return 0;
}