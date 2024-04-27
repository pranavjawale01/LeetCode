class Solution:
    def countSteps(self, ringIndex: int, i: int, n: int) -> int:
        dist = abs(i - ringIndex)
        wrapAround = n - dist
        return min(dist, wrapAround)

    def solve(self, ringIndex: int, keyIndex: int, ring: str, key: str) -> int:
        if keyIndex == len(key):
            return 0
        if self.dp[ringIndex][keyIndex] != -1:
            return self.dp[ringIndex][keyIndex]

        result = float('inf')

        for i in range(len(ring)):
            if ring[i] == key[keyIndex]:
                totalSteps = self.countSteps(ringIndex, i, len(ring)) + 1 + self.solve(i, keyIndex + 1, ring, key)
                result = min(result, totalSteps)
        self.dp[ringIndex][keyIndex] = result
        return result

    def findRotateSteps(self, ring: str, key: str) -> int:
        self.dp = [[-1] * 101 for _ in range(101)]
        return self.solve(0, 0, ring, key)