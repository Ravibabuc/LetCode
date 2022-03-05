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
using namespace std;



    vector<int> twoSum(vector<int>& nums, int target) 
    {
    
        vector<int> ans;
        map<int, int> Map;
        map<int, int> :: iterator  It;
        int n =nums.size();
        for(int i =0;i<n;i++)
        {
            // It = Map.find(target-nums[i]);
            
            //cout<<"ans "<< Map.find(target-nums[i])->first  <<endl;
            if(Map.find(target-nums[i]) != Map.end())
            {
                ans.push_back(i);
                ans.push_back(Map[target-nums[i]]);
                
                //cout<<"ansdd "<<Map[target-nums[i]]<<endl;
                //cout<<"ansddx "<< Map.find(target-nums[i])->second  <<endl;
                
                return ans;
            }
            else
            {
                Map[nums[i]]=  i;
            }
            
        }
        
        return ans;
        
    }


int main()
{
    vector<int> nums = {2,7,11,15};
    int target =9;
    vector<int> ans =  twoSum( nums, target) ;
    std::cout << ans[0] <<ans[1]<< std::endl;

    return 0;
}
