class TreeAncestor {
public:
    vector<vector<int> > dp; // P[i][node] :::: [node] 's [2^i]th parent
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        // initialize
        LOG = 32;
        dp = vector<vector<int>>(n, vector<int>(LOG, -1));
        // 2^0

        for(int i = 0; i < parent.size(); i++){
            dp[i][0] = parent[i];
        }

        // 2^i
        for(int i = 1; i < 20; i++){
            for(int node = 0; node < n; node ++){
                int nodep = dp[node][i - 1];
                if(nodep != -1) dp[node][i] = dp[nodep][i - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 32; i++){
            if(k & (1 << i)){
                node = dp[node][i];
                if(node == -1) return -1;
            }
        }

        return node;
    }
};