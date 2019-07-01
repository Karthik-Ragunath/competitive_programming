import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

class JamBoardNode
{
    int uniqueIdentifier;
    int sourcesCount;
}

class JamBoard
{
    public static int[] convertIntoWireCoordinates(String input)
    {
        int[] valueOfCoordinate = new int[4];
        int previousValue = 0;
        int currentValue = 0;
        int currentIndex = 0;
        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                continue;
            }
            else
            {
                if(i % 2 == 1)
                {
                    previousValue = (int)(input.charAt(i) - 'A');
                }
                else
                {
                    currentValue = (int)(input.charAt(i) - 'A');
                    int valueToBeStored = previousValue * 52 + currentValue;
                    valueOfCoordinate[currentIndex++] = valueToBeStored;
                }
            }
        }
        return valueOfCoordinate;
    }

    public static int[] convertIntoVoltageCoordinate(String input)
    {
        int[] valueOfCoordinate = new int[2];
        int previousValue = 0;
        int currentValue = 0;
        int currentIndex = 0;
        for(int i = 0; i < 5; i++)
        {
            if(i == 0)
            {
                continue;
            }
            else
            {
                if(i % 2 == 1)
                {
                    previousValue = (int)(input.charAt(i) - 'A');
                }
                else
                {
                    currentValue = (int)(input.charAt(i) - 'A');
                    int valueToBeStored = previousValue * 52 + currentValue;
                    valueOfCoordinate[currentIndex++] = valueToBeStored;
                }
            }
        }
        return valueOfCoordinate;
    }

    public static int[] removeVoltageCoordinates(String input)
    {
        int[] valueOfCoordinate = new int[2];
        int previousValue = 0;
        int currentValue = 0;
        int currentIndex = 0;
        for(int i = 0; i < 5; i++)
        {
            if(i == 0)
            {
                continue;
            }
            else
            {
                if(i % 2 == 1)
                {
                    previousValue = (int)(input.charAt(i) - 'A');
                }
                else
                {
                    currentValue = (int)(input.charAt(i) - 'A');
                    int valueToBeStored = previousValue * 52 + currentValue;
                    valueOfCoordinate[currentIndex++] = valueToBeStored;
                }
            }
        }
        return valueOfCoordinate;
    }

    public static int[] LCDConnections(String input)
    {
        int[] valueOfCoordinate = new int[4];
        int previousValue = 0;
        int currentValue = 0;
        int currentIndex = 0;
        for(int i = 0; i < 9; i++)
        {
            if(i == 0)
            {
                continue;
            }
            else
            {
                if(i % 2 == 1)
                {
                    previousValue = (int)(input.charAt(i) - 'A');
                }
                else
                {
                    currentValue = (int)(input.charAt(i) - 'A');
                    int valueToBeStored = previousValue * 52 + currentValue;
                    valueOfCoordinate[currentIndex++] = valueToBeStored;
                }
            }
        }
        return valueOfCoordinate;
    }

    public static int returnRootUniqueId(JamBoardNode[] jamBoards, int uniqueId)
    {
        while(jamBoards[uniqueId].uniqueIdentifier != uniqueId)
        {
            uniqueId = jamBoards[uniqueId].uniqueIdentifier;
        }
        return uniqueId;
    }

    public static void main(String[] args)
    {
        int numberOfTestcases;
        int numberOfRows;
        int numberOfColumns;
        Scanner in = new Scanner(System.in);
        numberOfTestcases = in.nextInt();
        numberOfRows = in.nextInt();
        numberOfColumns = in.nextInt();
        JamBoardNode[] jamBoards = new JamBoardNode[numberOfRows * numberOfColumns];
        for(int i = 0; i < numberOfRows; i++)
        {
            for(int j = 0; j < numberOfColumns; j++)
            {
                int uniqueIdentifier = i * numberOfColumns + j;
                jamBoards[uniqueIdentifier] = new JamBoardNode();
                jamBoards[uniqueIdentifier].uniqueIdentifier = uniqueIdentifier;
                jamBoards[uniqueIdentifier].sourcesCount = 0;
            }
        }
        in.nextLine();
        for(int i = 0; i < numberOfTestcases; i++)
        {
            String test = in.nextLine();
            if(test.charAt(0) == 'W')
            {
                int[] getTheCoordinates = convertIntoWireCoordinates(test);
                // for(int j = 0; j < 4; j++)
                // {
                //     System.out.print(getTheCoordinates[j] + " ");
                // }
                // System.out.println();
                int x1 = getTheCoordinates[0] - 1;
                int y1 = getTheCoordinates[1] - 1;
                int x2 = getTheCoordinates[2] - 1;
                int y2 = getTheCoordinates[3] - 1;

                int actualX1 = y1 / 5;
                int actualY1 = x1;
                int actualX2 = y2 / 5;
                int actualY2 = x2;

                int uniqueIdentifier1 = returnRootUniqueId(jamBoards, actualX1 * numberOfColumns + actualY1);
                int uniqueIdentifier2 = returnRootUniqueId(jamBoards, actualX2 * numberOfColumns + actualY2);
                if(uniqueIdentifier1 != uniqueIdentifier2)
                {
                    int sourcesCountUniqueId1 = jamBoards[uniqueIdentifier1].sourcesCount;
                    jamBoards[uniqueIdentifier1].uniqueIdentifier = uniqueIdentifier2;
                    jamBoards[uniqueIdentifier2].sourcesCount += sourcesCountUniqueId1;
                }
            }
            else if(test.charAt(0) == 'V')
            {
                int[] getTheCoordinates = convertIntoVoltageCoordinate(test);
                // for(int j = 0; j < 2; j++)
                // {
                //     System.out.print(getTheCoordinates[j] + " ");
                // }
                // System.out.println();
                int x1 = getTheCoordinates[0] - 1;
                int y1 = getTheCoordinates[1] - 1;
                int actualX1 = y1 / 5;
                int actualY1 = x1;
                int uniqueIdentifier1 = returnRootUniqueId(jamBoards, actualX1 * numberOfColumns + actualY1);
                jamBoards[uniqueIdentifier1].sourcesCount += 1;
            }
            else if(test.charAt(0) == 'R')
            {
                int[] getTheCoordinates = removeVoltageCoordinates(test);
                // for(int j = 0; j < 2; j++)
                // {
                //     System.out.print(getTheCoordinates[j] + " ");
                // }
                // System.out.println();
                int x1 = getTheCoordinates[0] - 1;
                int y1 = getTheCoordinates[1] - 1;
                int actualX1 = y1 / 5;
                int actualY1 = x1;
                int uniqueIdentifier1 = returnRootUniqueId(jamBoards, actualX1 * numberOfColumns + actualY1);
                if(jamBoards[uniqueIdentifier1].sourcesCount != 0)
                {
                    jamBoards[uniqueIdentifier1].sourcesCount -= 1;
                }
            }
            else if(test.charAt(0) == 'L')
            {
                int[] getTheCoordinates = LCDConnections(test);
                // for(int j = 0; j < 4; j++)
                // {
                //     System.out.print(getTheCoordinates[j] + " ");
                // }
                // System.out.println();
                int x1 = getTheCoordinates[0] - 1;
                int y1 = getTheCoordinates[1] - 1;
                int x2 = getTheCoordinates[2] - 1;
                int y2 = getTheCoordinates[3] - 1;

                int actualX1 = y1 / 5;
                int actualY1 = x1;
                int actualX2 = y2 / 5;
                int actualY2 = x2;

                int uniqueIdentifier1 = returnRootUniqueId(jamBoards, actualX1 * numberOfColumns + actualY1);
                int uniqueIdentifier2 = returnRootUniqueId(jamBoards, actualX2 * numberOfColumns + actualY2);
                if(uniqueIdentifier1 != uniqueIdentifier2)
                {
                    if(jamBoards[uniqueIdentifier1].sourcesCount > 0 && jamBoards[uniqueIdentifier2].sourcesCount > 0)
                    {
                        System.out.println("OFF");
                    }
                    else if(jamBoards[uniqueIdentifier1].sourcesCount > 0 && jamBoards[uniqueIdentifier2].sourcesCount == 0)
                    {
                        System.out.println("ON");
                    }
                    else if(jamBoards[uniqueIdentifier1].sourcesCount == 0 && jamBoards[uniqueIdentifier2].sourcesCount > 0)
                    {
                        System.out.println("ON");
                    }
                    else
                    {
                        System.out.println("OFF");
                    }
                }
                else
                {
                    System.out.println("OFF");
                }
            }
        }
    }
}
