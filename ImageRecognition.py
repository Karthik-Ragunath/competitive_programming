from PIL import Image
import numpy as np
import matplotlib.pyplot as plt
import time
from collections import Counter

def createExamples():
    numberArrayExamples = open('numberArray.txt','a')
    numbersWeHave = range(0,10) #Creats zero through 9
    versionsWeHave = range(1,10) #Creates one through nine

    for eachNum in numbersWeHave:
        for eachVersion in versionsWeHave:
            print str(eachNum) + '.' + str(eachVersion)
            imgFilePath = 'images/numbers/' + str(eachNum) + '.' + str(eachVersion) + '.png'
            exampleImage = Image.open(imgFilePath)
            exampleImageArray = np.array(exampleImage)
            exampleImageArrayList = str(exampleImageArray.tolist())
            lineToWrite = str(eachNum) + '::' + exampleImageArrayList + '\n'
            numberArrayExamples.write(lineToWrite)



def whatNumIsThis(filePath):
    matchedArray = []
    loadExamples = open('numberArray.txt','r').read()
    loadExamples = loadExamples.split('\n')

    image = Image.open(filePath)
    imageArray = np.array(image)
    imageArrayList = imageArray.tolist()

    inQuestion = str(imageArrayList)

    for eachExample in loadExamples:
        if len(eachExample) > 3: #To not worry about last example
            splitExample = eachExample.split('::')
            currentNum = splitExample[0]
            print currentNum
            currentArray = splitExample[1]
            eachPixelExample = currentArray.split('],')
            eachPixelInQuestion = inQuestion.split('],')

            x = 0

            while x < len(eachPixelExample): #Or eachPixelInQuestion as it doesnt really matter

                if eachPixelExample[x] == eachPixelInQuestion[x]:
                    matchedArray.append(int(currentNum))

                x = x + 1

    print matchedArray
    x = Counter(matchedArray) #Returns in dictionary format the count of number of specific values found with that value as key
                              #Example ex= [1,1,2,4,6,6,6,4,1]; c = Counter(ex); c = {1: 3, 2: 1, 4: 2, 6: 3}
    print x

    graphX = []
    graphY = []

    for eachThing in x:       #x is in Dictionary format and hence eachThing refers to the key of the Dictionary
        print eachThing
        graphX.append(eachThing)
        print x[eachThing]
        graphY.append(x[eachThing])

    fig = plt.figure()
    ax1 = plt.subplot2grid((4,4), (0,0), rowspan = 1, colspan = 4)
    ax2 = plt.subplot2grid((4,4), (1,0), rowspan = 3, colspan = 4)

    ax1.imshow(imageArray)
    ax2.bar(graphX, graphY, align = 'center')

    #plt.ylim(400)

    xloc = plt.MaxNLocator(12) #Max number of x values in graph should be greater than (0-9) 10 values since we have specified center alignment
    ax2.xaxis.set_major_locator(xloc)
    plt.show()

whatNumIsThis('images/three.png')
'''
#i = Image.open('images/dotndot.png')    #File placed in the same path as the python script and hence no need to specify the path

i = Image.open('images/numbers/y0.5.png')
imageArray = np.asarray(i)          #images will be in the form of 3 Dimensional Array
                                    #The column elements indicatee Red, Green, Blue and Alpha(Opacity)
                                    #Why RGB and not RYB?
                                    #dotndot contains black and green
print imageArray

plt.imshow(imageArray)
plt.show()                          #Converts the imageArray into image
'''


def threshold(imageArray): #Converts the image into pure black and white form (thresholding) for image detection capabilities
    balanceArray = []
    newArray = imageArray #for manipulating the array

    for eachRow in imageArray:
        for eachPix in eachRow:
            avgNum = reduce(lambda x, y: x + y, eachPix[:3])/len(eachPix[:3]) #[:3] indicates 4 elements in the column; Continually add two numbers in a Sequence(List/Array) and then apply the result to next element in the sequence and repeat the process
            balanceArray.append(avgNum)

    balance = reduce(lambda x, y: x + y, balanceArray)/len(balanceArray)

    for eachRow in newArray:
        for eachPix in eachRow:
            if reduce(lambda x, y: x + y, eachPix[:3])/len(eachPix[:3])>balance:
                eachPix[0] = 255
                eachPix[1] = 255
                eachPix[2] = 255
                eachPix[3] = 255

            else:
                eachPix[0] = 0
                eachPix[1] = 0
                eachPix[2] = 0
                eachPix[3] = 255

    return newArray


'''
reduce perform func similar to
let a[6] = [1,2,3,4,5,6]
let sum = 0
let num = 0

while(num<6)
{
    sum = sum + a[num]
}

This process is performed by reduce in one line

reduce(lambda x,y: x + y, a)

'''

i1 = Image.open('images/numbers/0.1.png')
imageArray1 = np.array(i1)


i2 = Image.open('images/numbers/y0.4.png')
imageArray2 = np.array(i2)

i3 = Image.open('images/numbers/y0.5.png')
imageArray3 = np.array(i3)

i4 = Image.open('images/sentdex.png')
imageArray4 = np.array(i4)

'''
threshold(imageArray2)
threshold(imageArray3)
threshold(imageArray4)

fig = plt.figure() #If the figure needed to be edited
ax1 = plt.subplot2grid((8,6), (0,0), rowspan = 4, colspan = 3) #The parameters are size, startingPoint, rowSpan, colSpan

ax2 = plt.subplot2grid((8,6), (4,0), rowspan = 4, colspan = 3)

ax3 = plt.subplot2grid((8,6), (0,3), rowspan = 4, colspan = 3)

ax4 = plt.subplot2grid((8,6), (4,3), rowspan = 4, colspan = 3)

ax1.imshow(imageArray1)
ax2.imshow(imageArray2)
ax3.imshow(imageArray3)
ax4.imshow(imageArray4)
plt.show()
’’’
