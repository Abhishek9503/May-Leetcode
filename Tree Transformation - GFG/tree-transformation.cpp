//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
     int solve(int N, vector<int> p){
        // code here
        vector<int> temp(N,0);
        for(int i=1;i<N;i++){
            temp[p[i]]++;
            temp[i]++;
        }
        int ans=0;
        for(auto x:temp)if(x==1)ans++;
        if(ans==N)return 0;
        return N-1-ans;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends