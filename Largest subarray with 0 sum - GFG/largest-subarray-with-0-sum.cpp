// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int curr = 0;
        int len = 0;
        map<int,int> m;
        for(int i=0; i<n; ++i){
            curr += a[i];
          if(curr == 0){
              len = i+1;
          }
          if(m.find(curr) != m.end()){
                len = max(len, i - m[curr]);
          }
          else{
              m[curr] = i;
          }
        }
        return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends