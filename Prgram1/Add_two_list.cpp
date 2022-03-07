#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
   ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {};
 };



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

ListNode * Reverse(ListNode *Head)
{
    ListNode *Curr = Head;
    ListNode *next =NULL;
    ListNode *Prev =NULL;
    while(Curr != NULL)
    {
        next = Curr->next;
        Curr->next =Prev;
        Prev =Curr;
        Curr=next;
    }
    return Prev;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    
     l1 = Reverse(l1);
     l2 = Reverse(l2);
    
    ListNode *Ans = NULL;
     ListNode *Curr =l1;  
     ListNode *Curr1 =l2;
     int carry=0;
     int Value=0;
    while(Curr != NULL|| Curr1 != NULL)
    {
       
       // cout<<"Data"<<Curr->val<<endl;
       int v1= 0;
       int v2 =0;
       if(Curr != NULL)
        v1= Curr->val;
        if(Curr1 != NULL)
        v2= Curr1->val;
       
        Value =v1+v2 + carry;
        carry=0;
        int remin=0;
        
        if(Value >= 10)
        {
            carry = Value/10;
            remin = Value%10;
            Ans = Insert(Ans, remin);
        }
        else
        {   
            
            Ans = Insert(Ans, Value);
            
        }
        if(Curr != NULL)
            Curr = Curr->next;
        if(Curr1 != NULL)
            Curr1 = Curr1-> next;
        
    }
    if( carry > 0)
    {
         Ans = Insert(Ans, carry);
    }
        Ans= Reverse(Ans);
     return Ans;   
}

int main()
{
    ListNode * Head =NULL;//=GetNodeNew(1);
  //  Head->next =NULL;
   Head= Insert(Head, 7);
   Head= Insert(Head, 2);
   Head= Insert(Head, 4);
   Head= Insert(Head, 3);
  // Head= Insert(Head, 9);
 //  Head= Insert(Head, 9);
  // Head= Insert(Head, 9);
   
   ListNode * Head1 =NULL;//=GetNodeNew(1);
  //  Head->next =NULL;
   Head1= Insert(Head1, 5);
   Head1= Insert(Head1, 6);
   Head1= Insert(Head1, 4);
   //Head1= Insert(Head1, 9);
   
   
   ListNode *Ans= addTwoNumbers(Head, Head1);
   
   ListNode *Curr=Ans;
   
   
   while(Curr != NULL)
    {
       
        cout<<"Data"<<Curr->val<<endl;
        Curr = Curr->next;
        
    }
   
  
   
   return 0;
}
