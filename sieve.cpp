vector<int> factors(int n) {
    std::vector<bool> dp(n + 1, true);

    for (int p = 2; p * p <= n; ++p) {
        if (dp[p]) {
            for (int i = p * p; i <= n; i += p) {
                dp[i] = false;
            }
        }
    }
    vector<int> f;
    for (int p = 2; p <= n; ++p) {
        if (dp[p]) {
            f.push_back(p);
        }
    }
    return f;
}