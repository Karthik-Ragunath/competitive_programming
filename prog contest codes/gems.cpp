#include <iostream>
using namespace std;
int main() {
    int charactercounter[100][26]={0},flagship[26]={0},testcases,i,length,j,counter,charcounter[26]={0},output=0;
    char ch;
    string s1;
    cin>>testcases;
    for(i=0;i<testcases;i++)
        {
        cin>>s1;
        length=s1.length();
        for(j=0;j<length;j++)
            {
            ch=s1[j];
            counter=ch-'a';
           // cout<<counter;
     
            charactercounter[i][counter]=charactercounter[i][counter]+1;
            //cout<<charactercounter[i][counter];
            if(charactercounter[i][counter]==1)
                {
                charcounter[counter]=charcounter[counter]+1;
               // cout<<charcounter[counter];
                //cout<<counter;
                
                }
            }
        }
        /*for(i=0;i<26;i++)
            {
            if(charcounter[counter]==testcases)
                {
                output=output+1;
                }
            }*/
        //cout<<output;
    for(i=0;i<26;i++)
        {
        if(charcounter[i]==testcases)
            {
            output=output+1;
            }
        }
    cout<<output;
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}