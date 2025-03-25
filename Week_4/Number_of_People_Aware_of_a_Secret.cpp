class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int m = 1000000007;
        int d = delay, g = forget;
        vector<long long> p(n + 1, 0);
        p[1] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = i + d; j <= min(n, i + g - 1); j++)
                p[j] = (p[j] + p[i]) % m;
        long long r = 0;
        for (int i = max(1, n - g + 1); i <= n; i++)
            r = (r + p[i]) % m;
        return r;
    }
};
