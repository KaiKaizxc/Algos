class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        m = 1 + int(log2(n)) #at most 16 for this problem
        self.dp = [[-1 for i in range(n)] for j in range(m)] #ith node's 2^j parent
        for i in range(m):
            for j in range(n):
                if i == 0:
                    self.dp[0][j] = parent[j]
                elif self.dp[i - 1][j] != -1:
                    self.dp[i][j] = self.dp[i-1][self.dp[i - 1][j]]




    def getKthAncestor(self, node: int, k: int) -> int:
        while k > 0 and node != -1:
            i = int(log2(k))
            node = self.dp[i][node]
            k-= (1 << i)
        return node