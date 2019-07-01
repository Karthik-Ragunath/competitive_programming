import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class RedBlueAngularSweep
{
    static FastReader in;
    public static void main(String[] args)
    {
        int testcases;
        in = new FastReader();
        testcases = nextInt();
        System.out.println(testcases);
    }

    static String next()
    {
        return in.next();
    }

    static String nextLine()
    {
        return in.nextLine();
    }

    static int nextInt(){
        return Integer.parseInt(in.next());
    }

    static int[] ia(int N){
        int[] a = new int[N];
        for(int i = 0; i<N; i++)a[i] = ni();
        return a;
    }

    static long[] la(int N){
        long[] a = new long[N];
        for(int i = 0; i<N; i++)a[i] = nl();
        return a;
    }

    static long nextLong(){
        return Long.parseLong(in.next());
    }

    static double nextDouble(){
        return Double.parseDouble(in.next());
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while (st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException  e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
}
