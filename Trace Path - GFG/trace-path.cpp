//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      int isPossible(int n, int m, string s){
        // code here
        int side=0,niche=0,maxSide=0,minSide=0,maxNiche=0,minNiche=0;
        for(auto x:s){
            if(x=='R')side++;
            else if(x=='L')side--;
            else if(x=='U')niche--;
            else niche++;
            maxSide=max(maxSide,side);
            minSide=min(minSide,side);
            maxNiche=max(maxNiche,niche);
            minNiche=min(minNiche,niche);
        }
        if(maxSide+abs(minSide)+1>m)return 0;
        if(maxNiche+abs(minNiche)+1>n)return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends