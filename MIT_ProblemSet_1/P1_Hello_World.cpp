#include<iostream>

using namespace std;

int main(){

    
    //2.1 simple print
    cout<<"Hello World"<<endl;

    //2.2 using for loop
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<"Hello World"<<endl;
    }
    
    //2.3 using while loop
    int m;
    cin>>m;
    while(m>0){
        cout<<"Hello World"<<endl;
        m--;
    }

    //2.4 using do while loop
    int l;
    cin>>l;
    do{
        cout<<"Hello World"<<endl;
        l--;
    }while(l>0);

    return 0;
}