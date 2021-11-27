#include <bits/stdc++.h>

using namespace std;

#define modul 1000000007



long long upar(long long fir,long long sec){

    long long result=1;

    fir=fir%modul;

    while(sec>0){

        if (sec&1)result=(result*fir)%modul;

        sec=(sec>>1);

        fir=(fir*fir)%modul;

    }

    return result%modul;

}

int main(){

        int t;

        cin>>t;

        while(t--){

            long long n,k;

            cin>>n>>k;

            vector<long long> v(n);

            for(int i=0;i<n;i++){

              cin>>v[i];

            }

            sort(v.begin(),v.end() );

            long long result=1;

            long long int c[5001][5001]={0};

            for(int i=0;i<5001;i++){

                for(int j=0;j<i+1;j++){

                    if(j==0||j==i){

                                    c[i][j]=1LL;

                    }else{

                                    c[i][j]=(c[i-1][j-1]%(modul-1)+c[i-1][j]%(modul-1))%(modul-1);

                    }

                }

            }

            for(int i=1;i<n-1;i++)
            {

                long long answerr=0;

                for(int j=1;j<k-1;j++){

                                answerr+=c[i][j]*c[n-i-1][k-j-1];

                                answerr=answerr%(modul-1);

                }

                result=(result*upar(v[i],answerr))%modul;

            }

                cout<<result%modul<<endl;
        }

}
