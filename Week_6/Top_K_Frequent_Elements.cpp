class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        
        auto cmp = [&frequency](int left, int right) {
            return frequency[left] > frequency[right];
        };

      
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);
        
        for (auto pair : frequency) {
            minHeap.push(pair.first);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        

        reverse(result.begin(), result.end());
        return result;



      
    }
};
