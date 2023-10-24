***************************************************************************************  Question  *****************************************************************************************************************

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Your Task:
You do not need to read input or print anything, Your task is to complete the function palindromicPartition() which takes the string str as the input parameter and returns the minimum number of partitions required.


Expected Time Complexity: O(n*n) [n is the length of the string str]
Expected Auxiliary Space: O(n*n)


Constraints:
1 ≤ length of str ≤ 500






**************************************************************************************  Solution  ******************************************************************************************************************

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
       bool palindrome(string str,int i,int j)
    {
       while(i<=j)
       {
           if(str[i]!=str[j]) return false;
           i++;
           j--;
       }
        return true;
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
      vector<int> dp(n,INT_MAX);
      //each character forms a palindrome in itself therefore length 1 
      //we require minimunm number of cuts so that all substrings form palindrome
      for(int i=n-1;i>=0;i--) //for every index to update dp
      {
          //cout<<endl<<i<<"-> \n";
          for(int j=i;j<n;j++)//to check for palindrome
          {
            if(palindrome(str,i,j))//if substring i to j is palindrome
            {
                int len=j-i+1;
                if(i+len>=n)
                   dp[i]=0;
                else
                   dp[i]=min(dp[i],dp[i+len]+1);
                //cout<<dp[i]<<",";
            }
          }
         // cout<<endl;
      }
    // cout<<endl <<"ans : ";
      return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

