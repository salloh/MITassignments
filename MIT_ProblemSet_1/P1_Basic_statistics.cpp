#include<iostream>
#include<limits>

using namespace std;

int main(){

    int numberElements;
    cin>>numberElements;
    int large=INT16_MIN;
    int small=INT16_MAX;
    int sum{};
    
    int* arr= new int[numberElements];

    for(int i=0; i<numberElements; ++i){
        cin>>arr[i];
    }
    

    for(int i=0; i<numberElements; ++i){

        if(arr[i]>large){
            large=arr[i];
        }
        if(arr[i]<small){
            small=arr[i];
        }    
        sum+=arr[i];
    }

    cout<<"Mean: "<<(double) sum/numberElements<<endl;
    cout<<"Max: "<<large<<endl;
    cout<<"Min: "<<small<<endl;
    cout<<"Range: "<<large-small<<endl;

    delete[] arr;

    return 0;
}