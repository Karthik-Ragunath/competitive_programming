/*
 * Complete the function below.
 */

    static void fizzBuzz(int n) {
        for(int i=1;i<=n;i++)
        {
            if(i%15==0)
            {
                System.out.println("FizzBuzz");
                continue;
            }
            if(i%3==0)
            {
                System.out.println("Fizz");
                continue;
            }
            if(i%5==0)
            {
                System.out.println("Buzz");
                continue;
            }
            System.out.println(i);
        }

    }

