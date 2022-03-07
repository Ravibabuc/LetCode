#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
   ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {};
 };

ListNode* Reverse(ListNode *Node)
{
    ListNode *Curr=Node;
    ListNode * next =NULL;
    ListNode *Prev =NULL;
    
    
    while(Curr != NULL)
    {
       next = Curr->next;
       Curr->next =Prev;
       Prev=Curr;
       Curr=next;
    }
    Node =Prev;
    return Node;
}

bool compare(ListNode *head1, ListNode *head2)
{
    
    while(head2 != NULL && head1 != NULL)
    {
        if(head2->val== head1->val)
        {
            head2 =head2->next;
            head1 = head1->next;
        }
        else
        {
            return false;
        }
    }
    //if((head2 != NULL && head1 == NULL) || (head2 == NULL && head1 != NULL))
    //    return false;
    return true;
    
}

bool isPalindrome(ListNode* Head) 
{
    ListNode *Head2 ;
    
    ListNode *slow =Head;
    ListNode *Fast =Head;
    ListNode *Prev ;
    
    if (Head ->next == nullptr) 
        return true;
    
    while(Fast != nullptr && Fast ->next != nullptr)
    {
        Prev = slow;
        slow = slow->next;
        Fast = Fast->next->next;
    }
   
    Prev-> next =NULL;
    Head2 = slow;
    Head2 =Reverse(Head2);
    

    ListNode *Curr=Head;
  // cout<<"COMAPARE 1 ***********"<<endl;
   
   //while(Curr != NULL)
   // {
       
     //   cout<<"Data"<<Curr->val<<endl;
    //    Curr = Curr->next;
        
    //}
  // cout<<"COMAPARE 1 ***********"<<endl;
    
   // Curr=Head2;
   //cout<<"COMAPARE 2 ***********"<<endl;
   
   //while(Curr != NULL)
   // {
       
  //      cout<<"Data"<<Curr->val<<endl;
   //     Curr = Curr->next;
   //     
  //  }
  // cout<<"COMAPARE 2 ***********"<<endl;
    bool FLAG;
    if(compare(Head, Head2)) 
        FLAG= true;
    else
        FLAG= false ;    
        

    Head2 = Reverse(Head2);
    Prev-> next =Head2;
    
    
   //ListNode * 
   //Curr=Head;
  // cout<<"COMAPARE 3 ***********"<<endl;
   
  // while(Curr != NULL)
   // {
       
      //  cout<<"Data"<<Curr->val<<endl;
      // Curr = Curr->next;
       
   // }
  // cout<<"COMAPARE 3` ***********"<<endl;
    
    return FLAG;
}

ListNode *GetNodeNew(int Data)
{
    ListNode *NewNode = new ListNode(Data, nullptr);
    return NewNode;
    
}
ListNode *Insert(ListNode *Head, int Data)
{
    ListNode *Curr;
    ListNode *Node =  GetNodeNew(Data);
   if (Head == NULL)
    {
        Head = Node;
        
    }
    else
    {
       Curr = Head;
        while(Curr -> next!= NULL)
        {
            Curr = Curr->next;
        }
        Curr->next = Node;
    }
    
    return Head;
}




int main()
{
    ListNode * Head =NULL;//=GetNodeNew(1);
  //  Head->next =NULL;
   Head= Insert(Head, 1);
   Head= Insert(Head, 2);
   //Head= Insert(Head, 2);
   Head= Insert(Head, 1);
   ListNode *Curr=Head;
   
   
   while(Curr != NULL && Curr->next != NULL)
    {
       
        cout<<"Data"<<Curr->val<<endl;
        Curr = Curr->next;
        
    }
   
   if (isPalindrome(Head))
     cout<<" isPalindrome"<<endl;
    else
        cout<<" No Palindrome"<<endl;
   
   return 0;
}
