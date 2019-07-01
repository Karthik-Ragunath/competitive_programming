from sys import stdin

def dynamicSolution(maximumValue):
    dp = [0] * (maximumValue + 1)
    for i in range(1, maximumValue + 1, 1):
        for j in range(1, i + 1, 1):
            if i == j:
                dp[i] = dp[i] + (2 * i)
            else:
                dp[i] = dp[i] + ((i + j) * 2)
        dp[i] = dp[i] + dp[i - 1]
    return dp




testcases = int(input())
dynamicSolutionList = dynamicSolution(100)
for i in range(0, testcases, 1):
    inputNumber = int(input())
    print(dynamicSolutionList[inputNumber])
