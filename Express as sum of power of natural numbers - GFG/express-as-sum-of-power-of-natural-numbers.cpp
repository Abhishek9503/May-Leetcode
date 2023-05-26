//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
     int mod = 1e9+7;
    int help(int n,int x,int num,vector<vector<int>> &dp){
        if(n==0)return 1;
        if(num>n or n<0)return 0;
        if(dp[n][num]!=-1)return dp[n][num];
        int temp = pow(num,x);
        return dp[n][num]=(help(n-temp,x,num+1,dp)+help(n,x,num+1,dp))%mod;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(n,x,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends