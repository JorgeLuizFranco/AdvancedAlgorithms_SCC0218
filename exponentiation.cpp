#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7; 

long long fastexp(long long a, long long b){
    long long ans=1;

    while(b>0){
        if(b&1){
            ans= ((ans%MOD)*(a%MOD))%MOD;
        }

        a= ((a%MOD)*(a%MOD))%MOD;

        b>>=1;

    }

    return ans%MOD;
}   

int main(){
    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        long long a,b;

        cin>>a>>b;

        cout<< fastexp(a,b)<<'\n';
    }

    return 0;
}