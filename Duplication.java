import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

class Duplication
{
	public static void main(String[] args)
	{
		int numberOfQueries;
		Scanner in = new Scanner(System.in);
		numberOfQueries = in.nextInt();
		int valuesToBeSubtracted = 2;
		ArrayList<Integer> valuesToBeSubtractedList = new ArrayList<Integer>();
		valuesToBeSubtractedList.add(valuesToBeSubtracted);
		while(true)
		{
			valuesToBeSubtracted = valuesToBeSubtracted * 2;
			if (valuesToBeSubtracted < 2000)
			{
				valuesToBeSubtractedList.add(valuesToBeSubtracted);
			}
			else
			{
				break;
			}
		}
		for(int i = 0; i < numberOfQueries; i ++)
		{
			int input = in.nextInt();
            //System.out.println(input);
			input = input + 1;
			int inputCopy = input;
			int counterOfNumberOfTwoPowersPresent = 0;
			int arrayListElementsCounter = 0;

            if (input == 1)
            {
                System.out.println("0");
            }
            else if (input == 2)
            {
                System.out.println("1");
            }
            else
            {
                if (valuesToBeSubtractedList.contains(input))
                {
                    int outputValue = 0;
                    while (input / 2 > 0)
                    {
                        if (outputValue == 0)
                        {
                            outputValue = 1;
                        }
                        else
                        {
                            outputValue = 0;
                        }
                        input = input / 2;
                    }
                    System.out.println(outputValue);
                }
                else
                {
                    while (input / 2 > 0)
                    {
                        input = input / 2;
                        arrayListElementsCounter = arrayListElementsCounter + 1;
                        counterOfNumberOfTwoPowersPresent = counterOfNumberOfTwoPowersPresent + 1;
                    }
                    input = inputCopy;
                    int answerAssociatingCounter = 0;
                    int answer = 0;
                    while( input > 2)
                    {
                        for (int j = 0; j <= 9; j++)
                        {
                            if( input <= valuesToBeSubtractedList.get(j))
                            {
                                //System.out.println(valuesToBeSubtractedList.get(j));
                                int k = j - 1;
                                answer = (valuesToBeSubtractedList.get(k));
                                //System.out.println("answer is " + answer);
                                answerAssociatingCounter = answerAssociatingCounter + 1;
                                input = input - answer;
                                //System.out.println("Input is " + input);
                                break;
                            }
                        }
                    }
                    //System.out.println(answerAssociatingCounter);
                    if (input == 1)
                    {
                        if (answerAssociatingCounter % 2 == 0)
                        {
                            System.out.println("0");
                        }
                        else
                        {
                            System.out.println("1");
                        }
                    }
                    else
                    {
                        if (answerAssociatingCounter % 2 == 0)
                        {
                            System.out.println("1");
                        }
                        else
                        {
                            System.out.println("0");
                        }
                    }
                }
            }
		}
	}
}
