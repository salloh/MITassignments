#include<iostream>

using namespace std;

int main(){

    int n,m, result{};

    cout<<"Enter two number for multiplication:"<<endl;

    cin>>n>>m;

    while(n>1){
        n/=2;
        m*=2;
        if(n%2!=0){
            result+=m;
        }
    }

   cout<<"The result is: "<<result;
    return 0;
}