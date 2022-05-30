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

vector <int> solve(struct Node* head1, struct Node* head2)
{
   vector <int> v;
   Node* ptr1 = head1;
   Node* ptr2 = head2;

   while(ptr1 && ptr2)
   {
       int a = ptr1->data;
       int b = ptr2->data;
       
       if(a==b) 
       {
           v.push_back(a);
           ptr1 = ptr1->next;
           ptr2 = ptr2->next;
       }

       else if(a<b) ptr1 = ptr1->next;
       else ptr2 = ptr2->next;
       
   }

   return v;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

  int n;cin>>n;

  Node* head1 = new Node();
  int p;cin>>p;
  head1->data=p;

  Node* ptr1 = head1;

  for(int i=1;i<n;i++)
  {
      int k;cin>>k;
      Node* current = newNode(k);
      ptr1->next = current;
      ptr1 = current;
  }

  int m;cin>>m;

   Node* head2 = new Node();
  int g;cin>>g;
  head2 = newNode(g);

  Node* ptr2 = head2;

  for(int i=1;i<m;i++)
  {
      int k;cin>>k;
      Node* current = newNode(k);
      ptr2->next = current;
      ptr2 = current;
  }

  vector <int> v;
  v = solve(head1,head2);

  //Creating the result linked list.

  Node* res = newNode(v[0]);
  Node* var = res;

  for(int i=1;i<v.size();i++)
  {
      Node* current = newNode(v[i]);
      var->next = current;
      var = current;
  }
  cout<<"The common elements are : "<<endl;
    display(res);
    return 0;
}