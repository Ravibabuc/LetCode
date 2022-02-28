/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;

int main()
{
   string str1, str2, sum="";
   int len1, len2, i, j, ds=0;
   cout<<"Enter the First Binary Number: ";
   cin>>str1;
   cout<<"Enter the Second Binary Number: ";
   cin>>str2;
   len1 = str1.size();
   len2 = str2.size();
   i = len1 - 1;
   j = len2 - 1;
   while(i>=0 || j>=0 || ds==1)
   {
      ds = ds + ((i >= 0) ? str1[i] - '0' : 0);
      cout<<"ds1 "<<ds<<endl;
      ds = ds + ((j >= 0) ? str2[j] - '0' : 0);
      cout<<"ds2 "<<ds<<endl;
      sum = char(ds % 2 + '0') + sum;
      cout<<"sum "<<sum<<endl;
      
      ds = ds/2;
      cout<<"ds3 "<<ds<<endl;
      i--;
      j--;
   }
   cout<<"\nSum = "<<sum;
   return 0;
}
