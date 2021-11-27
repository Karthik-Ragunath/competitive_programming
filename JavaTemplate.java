import java.util.*;
import java.io.*;
import java.math.*;
class Main{
    static final long MOD = (long)1e9+7;
    static FastReader in;
    public static void main(String[] args) throws Exception{
        in = new FastReader();
        StringBuilder out = new StringBuilder("");
        long[] dp = new long[2000001];
        for(int i = 1; i<= 2000000; i++)dp[i] = sum(i);
        long[] sum = new long[2000001];
        for(int i  = 1; i<= 2000000; i++)sum[i] = sum[i-1]+dp[i];
        long[] ans = new long[1000001];
        ans[1] = 2;
        for(int i = 2; i<= 1000000; i++){
            ans[i] = ans[i-1] + (sum[2*i-1] - sum[i])*2+dp[2*i];
        }
        int T = ni();
        while(T-->0){
            out.append(Long.toUnsignedString(ans[ni()])+"\n");
        }
        p(out.toString());
    }

    static long sum(long x){
        long odd = 0, even = 0;
        while(x>0){
            if((x&1)==0)even+=x%10;
            else odd += x%10;
            x/=10;
        }
        return Math.abs(odd-even);
    }

    static void p(Object o){
        System.out.print(o);
    }

    static void pn(Object o){
        System.out.println(o);
    }

    static String n(){
        return in.next();
    }

    static String nln(){
        return in.nextLine();
    }

    static int ni(){
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

    static long nl(){
        return Long.parseLong(in.next());
    }

    static double nd(){
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
