// class Solution {
// public:
//     int K;
//     int n;
//     unordered_map<string, int> mp;
    
//     long long solve(vector<int>& nums1, vector<int>& nums2, int sum, int min_el, int i, int count) {
//         if(count == K) {
//             return sum * min_el;
//         }
//          if(i >= n) {
//             return 0;
//         }
        
//         string key = to_string(sum) + "_" + to_string(min_el) + "_" + to_string(i) + "_" + to_string(count);
//         if(mp.find(key) != mp.end())
//             return mp[key];
        
//         int min_now = min(min_el, nums2[i]);
        
//         long take_i = solve(nums1 , nums2 , sum + nums1[i] , min_now, i+1 , count+1);
        
//         long not_take_i = solve(nums1 , nums2 , sum, min_el, i+1 , count);
        
//         return mp[key] = max(take_i, not_take_i);
//     }
    
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         K = k;
//         n = nums1.size();
//         mp.clear();
        
//         return solve(nums1 , nums2 , 0 , INT_MAX , 0 , 0);
//     }
// };



class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<int> idx2(n);
        iota(idx2.begin(), idx2.end(), 0);

        sort(idx2.begin(), idx2.end(), [&nums2](int a, int b) {
            return nums2[a] > nums2[b];
        });

        sort(nums2.begin(), nums2.end(), [](int a, int b) {
            return a > b;
        });

        priority_queue<int, vector<int>, greater<int>> minh;
        long long sum = 0;
        for(int i = 0; i<k;  i++){
            sum += nums1[idx2[i]];
            minh.push(nums1[idx2[i]]);
        }

        long long mx = sum*nums2[k-1];
        for(int i = k; i<n; i++){   
            sum += nums1[idx2[i]]-minh.top();
            minh.pop();
            minh.push(nums1[idx2[i]]);
            mx = max(mx, sum*nums2[i]);
        }
        
        return mx;
    }
};