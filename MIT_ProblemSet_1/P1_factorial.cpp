#include<iostream>

using namespace std;

int main(){
    int n,factorial=1;
    cin>>n;
    
    if(n>1){
        while(n>0){
            factorial*=n--;
        }
    }

    cout<<factorial<<endl;
    return 0;
}