/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include<bits/stdc++.h>
using namespace std;


    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        map<char, int> Map;
        int ans =0;
        int l=0, r =0;
        int tmp=0;
        char prev='\0';
        
       // cout<<"n "<<n<<endl;
        while(l<n && r< n)
        {
           cout<<"l "<<l<<endl;
           cout<<"r "<<r<<endl;
          cout<<"ans "<<ans<<endl;
            cout<<"s[r] "<<s[r]<<endl;
           cout<<"prev "<<prev<<endl;
          cout<<"Map.find(s[r])  "<<Map.find(s[r])->first <<endl;
            
            if( (Map.find(s[r]) == Map.end()) )
            {
               // cout<<"s[r]ddd "<<s[r]<<endl;
                tmp ++;
               prev = s[r];
                Map[s[r]] =r;
                r ++;
                ans = max(ans, r-l );
                
                
            }
            else
            {
                 //cout<<"s[r]dddxx "<<s[r]<<endl;
               // if (prev== s[r])
               // l = r;
               // else
                //    l ++;
                if (l <Map.find(s[r])-> second +1 )
                    l = Map.find(s[r])-> second +1;
                Map.erase(s[r]);
              //   Map[s[r]] ++;
               // prev = s[r];
                
                
              //  r--;
            }
            
               
        }
        ans = max(ans, r-l );
        return ans;
    }



int main()
{
    string s = "pwwtew";
 //"abcabc";
    int ans = lengthOfLongestSubstring(s);
    std::cout << "ans " <<ans<< std::endl;

    return 0;
}
