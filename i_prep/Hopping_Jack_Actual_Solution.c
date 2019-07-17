//Enter your code here. Read input from STDIN. Print output to STDOU
int main(int argc, const char * argv[]) {
@autoreleasepool {

    int N;
    long K;

    scanf ("%d", &N);

    if (N >= 1 && N <= 2000) {
        scanf ("%li", &K);

        if (K >= 1 && K <= 4000000) {

            long maxSteps = (N * (N + 1)) / 2;
            int n = ceil((-1 + sqrt(-1 * (1 - (8 * K))))/2);

            long k = (n * (n + 1)) / 2;

            if (k == K) {
                maxSteps -= n;
            }
            printf ("%li", maxSteps);
        }
    }
}
return 0;
}