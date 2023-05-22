class Solution {
public:
    typedef pair<int, int> p;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        
        //count frequency of each element
        // Worst Case - n distinct elements are stored, so, space O(n)
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        
        //Push in min-heap and maintain size k
        for(auto it:mp) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        //Pick all top K elements
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};