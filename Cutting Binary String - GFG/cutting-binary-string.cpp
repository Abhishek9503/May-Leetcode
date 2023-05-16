//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    
    public:
     static bool hai(string s,int start, int end){
        long long num = 0,j=1;
        for(int i=end;i>=start;i--){
            if(s[i]=='1'){
                num+=j;
            }
            j*=2;
        }
        while(num>1){
            if(num%5!=0)return false;
            num/=5;
        }
        return true;
    }
    static int help(string s,int start,int end,vector<vector<int>> &dp){
        if(end<start)return 0;
        if(s[start]=='0')return -1;
        if(dp[start][end]!=-1)return dp[start][end];
        if(hai(s,start,end))return 1;
        int ans = INT_MAX;
        for(int i=start;i<=end;i++){
            if(hai(s,start,i)){
                int second = help(s,i+1,end,dp);
                if(second!=-1){
                    ans = min(ans,1+second);
                }
            }
        }
        return dp[start][end]=ans==INT_MAX?-1:ans;
    }
    
     int cuts(string s){
        //code
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(s,0,n-1,dp);
    }
};


  


//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends