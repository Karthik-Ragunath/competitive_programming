def getTheCountOfCombinations(number, maximumValue):
    if (number == 0):
        return 1
    elif number < 0:
        return 0
    else:
        counter = 0
        for i in range(2, maximumValue + 1, 2):
            counter = counter + getTheCountOfCombinations(number - i, maximumValue)
        return counter

def getTheCombinations(number, maximumValue, combinations, tempCombinations):
    if (number == 0):
        tempList = list(tempCombinations)
        combinations.append(tempList)
        # We make a copy of list and append in solution list because python lists are pass by reference and hence when elements are modified in tempCombinations, they get modified in combinations as well.
        return
    elif number < 0:
        return
    else:
        counter = 0
        for i in range(2, maximumValue + 1, 2):
            tempCombinations.append(i)
            getTheCombinations(number - i, maximumValue, combinations, tempCombinations)
            tempCombinations.pop()
        return


testcases = int(input())
for i in range(0, testcases):
    #print(i)
    value = int(input());
    maxValue = int(input());
    maximumCount = getTheCountOfCombinations(value, maxValue)
    print(maximumCount)
    combinations = []
    tempCombinations = []
    getTheCombinations(value, maxValue, combinations, tempCombinations)
    for item in combinations:
        for element in item:
            print("%d " %(element), end = '')
        print()

    
