class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        if (m > n) {
            return {};
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);
        vector<int> ans;

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        for (int i = 0; i < m; ++i) {
            windowFreq[s[i] - 'a']++;
        }

        for (int i = 0; i <= n - m; ++i) {
            if (windowFreq == pFreq) {
                ans.push_back(i);
            }

            if (i + m < n) {
                windowFreq[s[i] - 'a']--; 
                windowFreq[s[i + m] - 'a']++; 
            }
        }

        return ans;
    }
};
