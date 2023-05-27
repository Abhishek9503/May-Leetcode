class Solution {
public:

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        vector<int> t(n+1);
        //t[i] = Alice - Bob
        
        for(int i = n-1; i>=0; i--) {
            
            t[i] = stoneValue[i] - t[i+1];
            
            if(i+2 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] - t[i+2]);
        
            if(i+3 <= n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - t[i+3]);
        
        }
        
        int diff = t[0];
        if(diff < 0)
            return "Bob";
        else if(diff > 0)
            return "Alice";
        
        return "Tie";
    }
};
