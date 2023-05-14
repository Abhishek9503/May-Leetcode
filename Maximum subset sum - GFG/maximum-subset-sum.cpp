//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
   
    long long help(int n,vector<int> &arr,int index,int indication,vector<vector<long long>> &dp){
        if(index==n)return 0;
        if(dp[index][indication]!=-1)return dp[index][indication];
        long long a=INT_MIN,b=INT_MIN;
        if(indication==1){
            b = help(n,arr,index+1,0,dp);
        }
        a = arr[index]+help(n,arr,index+1,1,dp);
        return dp[index][indication]=max(a,b);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(N,vector<long long>(2,-1));
        return help(N,A,0,1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends