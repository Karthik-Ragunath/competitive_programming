import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RedPoints
{
    int x;
    int y;
}

class BluePoints
{
    int x;
    int y;
}

class RedBlueAngularSweepFastIO
{
    static FastReader in;
    public static void main(String[] args)
    {
        in = new FastReader();
        int testcases;
        testcases = nextInt();
        for(int i = 0; i < testcases; i++)
        {
            int redPoints;
            int bluePoints;
            redPoints = nextInt();
            bluePoints = nextInt();
            RedPoints[] redPointsCoordinates = new RedPoints[redPoints];
            BluePoints[] bluePointsCoordinates = new BluePoints[bluePoints];

            for(int j = 0; j < redPoints; j++)
            {
                redPointsCoordinates[j] = new RedPoints();
                redPointsCoordinates[j].x = nextInt();
                redPointsCoordinates[j].y = nextInt();
            }

            for(int j = 0; j < bluePoints; j++)
            {
                bluePointsCoordinates[j] = new BluePoints();
                bluePointsCoordinates[j].x = nextInt();
                bluePointsCoordinates[j].y = nextInt();
            }

            int minimumSolution = 0;
            double[][][] blueRedAngles = new double[bluePoints][redPoints][2];
            for(int j = 0; j < bluePoints; j++)
            {
                //For everyline formed by red and blue point check how many redpoints and bluePonts are in the given region (either above or below)
                //and find the min of (red + blue points above) and (red + blue points below) and print the desired answer.
                //Binary search should be used to answer the queries.
                ArrayList<Double> quadrant1Red = new ArrayList<Double>();
                ArrayList<Double> quadrant2Red = new ArrayList<Double>();
                ArrayList<Double> quadrant3Red = new ArrayList<Double>();
                ArrayList<Double> quadrant4Red = new ArrayList<Double>();

                ArrayList<Double> quadrant1 = new ArrayList<Double>();
                ArrayList<Double> quadrant2 = new ArrayList<Double>();
                ArrayList<Double> quadrant3 = new ArrayList<Double>();
                ArrayList<Double> quadrant4 = new ArrayList<Double>();

                for(int k = 0; k < redPoints; k++)
                {
                    double angle = Math.atan2((redPointsCoordinates[k].y - bluePointsCoordinates[j].y), (redPointsCoordinates[k].x - bluePointsCoordinates[j].x)) * 180 / Math.PI;
                    double interceptAngleQuadrant1;
                    double interceptAngleQuadrant2;
                    if(angle < 0)
                    {
                        interceptAngleQuadrant1 = angle + 180 % 360;
                        if(j == 0 && k == 3)
                        {
                            System.out.println(interceptAngleQuadrant1);
                        }
                        interceptAngleQuadrant2 = interceptAngleQuadrant1 + 180 % 360;
                    }
                    else
                    {
                        interceptAngleQuadrant1 = angle;
                        if(j == 0 && k == 3)
                        {
                            System.out.println(interceptAngleQuadrant1);
                        }
                        interceptAngleQuadrant2 = interceptAngleQuadrant1 + 180;
                    }
                    blueRedAngles[j][k][0] = interceptAngleQuadrant1;
                    blueRedAngles[j][k][1] = interceptAngleQuadrant2;
                    if(interceptAngleQuadrant1 > 0 && interceptAngleQuadrant1 <= 90)
                    {
                        //Quadrant 1 and the other end is in quadrant 3.
                        System.out.println("Quad 1 - k red: " + k);
                        quadrant1Red.add(interceptAngleQuadrant1);
                        quadrant3Red.add(interceptAngleQuadrant2);
                        quadrant1.add(interceptAngleQuadrant1);
                        quadrant3.add(interceptAngleQuadrant2);
                    }
                    else if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant2 <= 180)
                    {
                        //Quadrant 2 and the other end is in quadrant 4.
                        System.out.println("Quad 2 - k red: " + k);
                        quadrant2Red.add(interceptAngleQuadrant1);
                        quadrant4Red.add(interceptAngleQuadrant2);
                        quadrant2.add(interceptAngleQuadrant1);
                        quadrant4.add(interceptAngleQuadrant2);
                    }
                    else if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant2 <= 270)
                    {
                        //Quadrant 3 and the other end is in quadrant 1.
                        System.out.println("Quad 3 - k red: " + k);
                        quadrant3Red.add(interceptAngleQuadrant1);
                        quadrant1Red.add(interceptAngleQuadrant2);
                        quadrant3.add(interceptAngleQuadrant1);
                        quadrant1.add(interceptAngleQuadrant2);
                    }
                    else
                    {
                        //Quadrant 4 and the other end is in quadrant 2.
                        quadrant4Red.add(interceptAngleQuadrant1);
                        System.out.println("Quad 4 - k red: " + k);
                        quadrant2Red.add(interceptAngleQuadrant2);
                        quadrant4.add(interceptAngleQuadrant1);
                        quadrant2.add(interceptAngleQuadrant2);
                    }
                }
                Collections.sort(quadrant1Red);
                Collections.sort(quadrant2Red);
                Collections.sort(quadrant3Red);
                Collections.sort(quadrant4Red);
                int redQuad1Count = quadrant1Red.size();
                int redQuad2Count = quadrant2Red.size();
                int redQuad3Count = quadrant3Red.size();
                int redQuad4Count = quadrant4Red.size();
                for(int k = 0; k < bluePoints; k++)
                {
                    if(k != j)
                    {
                        double angle = Math.atan2((bluePointsCoordinates[k].y - bluePointsCoordinates[j].y), (bluePointsCoordinates[k].x - bluePointsCoordinates[j].x)) * 180 / Math.PI;
                        double interceptAngleQuadrant1 = angle + 180 % 360;
                        double interceptAngleQuadrant2 = interceptAngleQuadrant1 + 180 % 360;

                        if(interceptAngleQuadrant1 > 0 && interceptAngleQuadrant1 <= 90)
                        {
                            //Quadrant 1 and the other end is in quadrant 3.
                            System.out.println("Quad 1 - k blue: " + k);
                            quadrant1.add(interceptAngleQuadrant1);
                            quadrant3.add(interceptAngleQuadrant2);
                        }
                        else if(interceptAngleQuadrant1 > 90 && interceptAngleQuadrant2 <= 180)
                        {
                            //Quadrant 2 and the other end is in quadrant 4.
                            System.out.println("Quad 2 - k blue: " + k);
                            quadrant2.add(interceptAngleQuadrant1);
                            quadrant4.add(interceptAngleQuadrant2);
                        }
                        else if(interceptAngleQuadrant1 > 180 && interceptAngleQuadrant2 <= 270)
                        {
                            //Quadrant 3 and the other end is in quadrant 1.
                            System.out.println("Quad 3 - k blue: " + k);
                            quadrant3.add(interceptAngleQuadrant1);
                            quadrant1.add(interceptAngleQuadrant2);
                        }
                        else
                        {
                            //Quadrant 4 and the other end is in quadrant 2.
                            System.out.println("Quad 4 - k blue: " + k);
                            quadrant4.add(interceptAngleQuadrant1);
                            quadrant2.add(interceptAngleQuadrant2);
                        }
                    }
                }
                Collections.sort(quadrant1);
                Collections.sort(quadrant2);
                Collections.sort(quadrant3);
                Collections.sort(quadrant4);
                int quad1Count = quadrant1.size();
                int quad2Count = quadrant2.size();
                int quad3Count = quadrant3.size();
                int quad4Count = quadrant4.size();
                System.out.println("Reds in Quad 1: " + redQuad1Count);
                System.out.println("Reds in Quad 2: " + redQuad2Count);
                System.out.println("Reds in Quad 3: " + redQuad3Count);
                System.out.println("Reds in Quad 4: " + redQuad4Count);
                System.out.println("Quad 1 Count: " + quad1Count);
                System.out.println("Quad 2 Count: " + quad2Count);
                System.out.println("Quad 3 Count: " + quad3Count);
                System.out.println("Quad 4 Count: " + quad4Count);
                int minimumForParticularBluePoint = 0;
                for(int k = 0; k < redPoints; k++)
                {
                    double lineAngle = blueRedAngles[j][k][0];
                    if(lineAngle > 0 && lineAngle <= 90)
                    {
                        int indexQuad1Red = Collections.binarySearch(quadrant1Red, lineAngle);
                        int indexQuad3Red = Collections.binarySearch(quadrant3Red, lineAngle);
                        int indexQuad1 = Collections.binarySearch(quadrant1, lineAngle);
                        int indexQuad3 = Collections.binarySearch(quadrant3, lineAngle);
                        int blueQuad1 = indexQuad1 - indexQuad1Red;
                        int blueQuad3 = indexQuad3 - indexQuad3Red;
                        int remainingRedQuad1 = redQuad1Count - indexQuad1Red;
                        int remainingRedQuad3 = redQuad3Count - indexQuad3Red;
                        int remainingTotalQuad1 = quad1Count - indexQuad1;
                        int remainingTotalQuad3 = quad3Count - indexQuad3;
                        int remainingBlueQuad1 = remainingTotalQuad1 - remainingRedQuad1;
                        int remainingBlueQuad3 = remainingTotalQuad3 - remainingRedQuad3;

                        int redPointsAbove = remainingRedQuad1 + redQuad2Count + indexQuad3Red - 1;
                        int redPointsBelow = indexQuad1Red - 1 + redQuad4Count + remainingRedQuad3;
                        int bluePointsAbove = remainingBlueQuad1 + (quad2Count - redQuad2Count) + blueQuad3;
                        int bluePointsBelow = blueQuad1 + (quad4Count - redQuad4Count) + remainingBlueQuad3;

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else if(lineAngle > 90 && lineAngle <= 180)
                    {
                        int indexQuad2Red = Collections.binarySearch(quadrant2Red, lineAngle);
                        int indexQuad4Red = Collections.binarySearch(quadrant4Red, lineAngle);
                        int indexQuad2 = Collections.binarySearch(quadrant2, lineAngle);
                        int indexQuad4 = Collections.binarySearch(quadrant4, lineAngle);
                        int blueQuad2 = indexQuad2 - indexQuad2Red;
                        int blueQuad4 = indexQuad4 - indexQuad4Red;
                        int remainingRedQuad2 = redQuad2Count - indexQuad2Red;
                        int remainingRedQuad4 = redQuad4Count - indexQuad4Red;
                        int remainingTotalQuad2 = quad2Count - indexQuad2;
                        int remainingTotalQuad4 = quad4Count - indexQuad4;
                        int remainingBlueQuad2 = remainingTotalQuad2 - remainingRedQuad2;
                        int remainingBlueQuad4 = remainingTotalQuad4 - remainingRedQuad4;

                        int redPointsAbove = indexQuad2Red - 1 + redQuad1Count + remainingRedQuad4;
                        int redPointsBelow = remainingRedQuad2 + redQuad3Count + indexQuad4Red - 1;
                        int bluePointsAbove = blueQuad2 + (quad1Count - redQuad1Count) + remainingBlueQuad4;
                        int bluePointsBelow = remainingBlueQuad2 + (quad3Count - redQuad3Count) + blueQuad4;

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else if(lineAngle > 180 && lineAngle <= 270)
                    {
                        int indexQuad3Red = Collections.binarySearch(quadrant3Red, lineAngle);
                        int indexQuad1Red = Collections.binarySearch(quadrant1Red, lineAngle);
                        int indexQuad3 = Collections.binarySearch(quadrant3, lineAngle);
                        int indexQuad1 = Collections.binarySearch(quadrant1, lineAngle);
                        int blueQuad3 = indexQuad3 - indexQuad3Red;
                        int blueQuad1 = indexQuad1 - indexQuad1Red;
                        int remainingRedQuad3 = redQuad3Count - indexQuad3Red;
                        int remainingRedQuad1 = redQuad1Count - indexQuad1Red;
                        int remainingTotalQuad3 = quad3Count - indexQuad3;
                        int remainingTotalQuad1 = quad1Count - indexQuad1;
                        int remainingBlueQuad3 = remainingTotalQuad3 - remainingRedQuad3;
                        int remainingBlueQuad1 = remainingTotalQuad1 - remainingRedQuad1;

                        int redPointsAbove = indexQuad3Red - 1 + redQuad2Count + remainingRedQuad1;
                        int redPointsBelow = remainingRedQuad3 + redQuad4Count + indexQuad1Red - 1;
                        int bluePointsAbove = blueQuad3 + (quad2Count - redQuad2Count) + remainingBlueQuad1;
                        int bluePointsBelow = remainingBlueQuad3 + (quad4Count - redQuad4Count) + blueQuad1;

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                    else
                    {
                        int indexQuad4Red = Collections.binarySearch(quadrant4Red, lineAngle);
                        int indexQuad2Red = Collections.binarySearch(quadrant2Red, lineAngle);
                        int indexQuad4 = Collections.binarySearch(quadrant4, lineAngle);
                        int indexQuad2 = Collections.binarySearch(quadrant2, lineAngle);
                        int blueQuad4 = indexQuad4 - indexQuad4Red;
                        int blueQuad2 = indexQuad2 - indexQuad2Red;
                        int remainingRedQuad4 = redQuad4Count - indexQuad4Red;
                        int remainingRedQuad2 = redQuad2Count - indexQuad2Red;
                        int remainingTotalQuad4 = quad4Count - indexQuad4;
                        int remainingTotalQuad2 = quad2Count - indexQuad2;
                        int remainingBlueQuad4 = remainingTotalQuad4 - remainingRedQuad4;
                        int remainingBlueQuad2 = remainingTotalQuad2 - remainingRedQuad2;

                        int redPointsAbove = remainingRedQuad4 + redQuad1Count + indexQuad2Red - 1;
                        int redPointsBelow = indexQuad4Red - 1 + redQuad3Count + remainingRedQuad2;
                        int bluePointsAbove = remainingBlueQuad4 + (quad1Count - redQuad1Count) + blueQuad2;
                        int bluePointsBelow = blueQuad4 + (quad4Count - redQuad2Count) + remainingBlueQuad2;

                        int min = Math.min((redPointsAbove + bluePointsBelow), (redPointsBelow + bluePointsAbove));
                        if(k == 0)
                        {
                            minimumForParticularBluePoint = min;
                        }
                        else
                        {
                            if(min < minimumForParticularBluePoint)
                            {
                                minimumForParticularBluePoint = min;
                            }
                        }
                    }
                }
                if(j == 0)
                {
                    minimumSolution = minimumForParticularBluePoint;
                }
                else
                {
                    if(minimumSolution < minimumForParticularBluePoint)
                    {
                        minimumSolution = minimumForParticularBluePoint;
                    }
                }
            }
            System.out.println(minimumSolution);
        }
    }

    static String next()
    {
        return in.next();
    }

    static String nextLine()
    {
        return in.nextLine();
    }

    static int nextInt()
    {
        return Integer.parseInt(in.next());
    }

    static int[] ia(int N)
    {
        int[] a = new int[N];
        for(int i = 0; i < N; i++)a[i] = nextInt();
        return a;
    }

    static long[] la(int N)
    {
        long[] a = new long[N];
        for(int i = 0; i < N; i++)a[i] = nextLong();
        return a;
    }

    static long nextLong()
    {
        return Long.parseLong(in.next());
    }

    static double nextDouble()
    {
        return Double.parseDouble(in.next());
    }

    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
