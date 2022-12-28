#include<iostream>
#include<bits/stdc++.h>

bool prime(int n){
    if(n==0 || n==1) return false;

    for(int i=2; i<n/2;i++){

        if(n%i==0) return false;

    }
    
    return true;

}


using namespace std;


int main(){

        int N;
        cin>>N;

        int endRow=5;
        int elementCount=0;

        for(int i=2;i<=N; i++){


            if(prime(i)) {
                cout<<i<<' ';
                elementCount++;
            }


            if(elementCount==endRow){
                cout<<endl;
                endRow+=10;
            }
            
        }

         cout<<endl;
    return 0;
}
