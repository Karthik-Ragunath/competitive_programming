def maximumTotalWeight(tasks, weights, runtime):
    items = [[tasks[i]*2,weights[i]] for i in range(len(tasks))]
    knapsackValues = [[0 for _ in range(runtime+1)] for _ in range(len(items)+1)]
    print(knapsackValues)
    for i in range(1, len(items)+1):
        duration, value = items[i-1]
        print(duration, value)
        for d in range(1, runtime+1):
            if duration > d:
                knapsackValues[i][d] = knapsackValues[i-1][d]
                print(">", i, d, knapsackValues[i][d])
            else:
                knapsackValues[i][d] = max(knapsackValues[i-1][d], knapsackValues[i-1][d-duration]+value)
                print("<", i, d, knapsackValues[i][d])
    return knapsackValues[-1][-1]

s = [2, 2, 3, 4]
w = [2, 4, 4, 5]
b = 15
a = maximumTotalWeight(s,w,b)
print(a)