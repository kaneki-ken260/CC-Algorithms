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

void Insertion(struct Node* head, int pos, struct Node* newAdd)
{
    Node* ptr = new Node();
    ptr = head;
    if(pos>=2)
    {
        pos=pos-2;
        while(pos>0)
    {
        ptr = ptr->next;
        pos--;
    }
    newAdd->next = ptr->next;
    ptr->next = newAdd;
    }
    else{
        newAdd->next = ptr;
        head = newAdd;
    }
}

void Deletion(struct Node* head, int pos)
{
    Node* ptr = new Node();
    Node* pre = new Node();
    pre = head;
    ptr = pre->next;
    if(pos>=2)
    {
      pos = pos-2;
      while(pos>0)
      {
          pre = ptr;
          ptr = ptr->next;
          pos--;
      }
    pre->next = ptr->next;
    free(ptr);
    }
    else
    {
        head = ptr;
        free(pre);
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
    display(head);
 /* Code for Inserting a node

    cout<<"Before Insertion"<<endl;
    display(head);
    cout<<endl;

    cout<<"Enter the data of the new Node you want to add "<<endl;
    int p;cin>>p;
    Node* newAdd = new Node();
    newAdd = newNode(p);

    
    cout<<"Enter the position at which you want to add this node "<<endl;
    int pos;cin>>pos;
    Insertion(head,pos,newAdd);

    cout<<"After Insertion"<<endl;
    display(head);

 */

  /* Code for Deletion of a node
   
    cout<<"Before Deletion"<<endl;
    display(head);
    cout<<endl;

    
    cout<<"Enter the position at which you want to delete a node "<<endl;
    int pos;cin>>pos;
    
    Deletion(head,pos);
    cout<<"After Deletion"<<endl;
    display(head);

  */
    return 0;
}