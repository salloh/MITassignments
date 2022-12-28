#include<iostream>
#include<math.h>

using namespace std;

int main(){

  double n,sum{};
  cin>>n;
  int opCount=1;
  char op='+';
  for(int i=1; i<=n;i++){
    if(opCount>2 && op=='+'){
        sum-=(1/pow(i,2));
        op='-';
        opCount=1;
    }
    else if(opCount>2 && op=='-'){
        sum+=(1/pow(i,2));
        op='+';
        opCount=1;
    } 
    else if(opCount<=2 && op=='+'){
        sum+=(1/pow(i,2));
      
        opCount++;
    }
    else if(opCount<=2 && op=='-'){
        sum-=(1/pow(i,2));
        opCount++;
    }
  }


 cout<<sum;
    return 0;
}