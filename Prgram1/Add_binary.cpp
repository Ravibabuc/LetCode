/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;
string addBinary(string a, string b) 
{
        std::stack<char> Ans;
        string Ans1="";
        char cary='0';
        int n = a.size();
        int m = b.size();
        int x =0;
        int q =0;
        cout<<"m "<<m<<"  n "<<n<<endl;
        for(int i=n-1, j = m-1;i>=0 && j >=0 ;i--, j-- )
        {
            cout<<"hello1"<<endl;
            cout<<"a[i] "<<a[i]<<"  "<<b[j]<<endl;
            cout<<"i "<<i<<endl;
            if (a[i] == '1' && b[j]== '1')
            {
               if (cary == '0')
               {
              //       cout<<"hello1a"<<endl;
                    cary= '1';
                   Ans.push('0');
               }
               else 
               {
                       cary= '1';
                    Ans.push('1');
               }
            }
            else if ((a[i] == '1' && b[j]== '0' ) || (a[i] == '0' && b[j]== '1' ))
            {
                
                if (cary == '1')
               {
                    cary= '1';
                    Ans.push('0');
               }
               else 
               {
                    cary= '0';
                    Ans.push('1');
               }
            }
            else if ((a[i] == '0' && b[j]== '0' ))
            {
                       
                if (cary == '1')
               {
                    cary= '0';
                    Ans.push('1');
               }
               else 
               {
                    cary= '0';
                    Ans.push('0');
               }
               
            }
          //  x --;
            //cout<<"hello2"<<endl;
            x =i;
            q =j;
        }   
        //cout<<"x "<<x<<endl;
        
        //while (!Ans.empty())       
        //{
          //  cout<<"ans ===? "<<Ans.top()<<endl;;
        //    Ans.pop();
        //}
        
            if (n> m )
            {
                cout<<"hello3"<<endl;
                for (int i=x-1;i>=0;i--)
                {
                    cout<<"hello4"<<endl;
                   
                    if (a[i] == '1' && cary== '1')
                     {
                
                        Ans.push('0');
                     }
                     else  if (a[i] == '1' && cary== '0')
                     {
                        Ans.push('1')    ;
                     }
                     
                     else  if (a[i] == '0' && cary== '1')
                     {
                        Ans.push('1')    ;
                        cary='0';
                     }
                      else  if (a[i] == '0' && cary== '0')
                     {
                        Ans.push('0')    ;
                        cary='0';
                     }
                }       
                //Ans.push(cary);
            }
            if (m >n)
            {
              cout<<"hello5"<<endl;
                for (int i=q-1;i>=0;i--)
                {
                    cout<<"b[i]"<< b[i]<<endl;
                   cout<<"hello6"<<endl;
                   
                    if (b[i] == '1' && cary== '1')
                     {
                
                        Ans.push('0');
                     }
                     else  if (b[i] == '1' && cary== '0')
                     {
                        Ans.push('1')    ;
                     }
                     else  if (b[i] == '0' && cary== '0')
                     {
                        Ans.push('0')    ;
                     }
                     else  if (b[i] == '0' && cary== '1')
                     {
                        Ans.push('1')    ;
                        cary ='0';
                     }
                }       
                //Ans.push(cary);
            }
            
            if (cary == '1')
            Ans.push(cary);
        while (!Ans.empty())       
        {
            Ans1 += Ans.top();
            Ans.pop();
        }
        return Ans1;
}


int main()
{
  //  string A = "1010";
   //string B = "1011";
    
   string A = "11";
   string B = "1001";
//string A = "100";
//string B = "110010";


      string ans = addBinary(A, B);
    cout<<"ans "<<ans<<endl;
      
    return 0;
}
