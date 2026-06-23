// Given an array , Find the sum of all element?

#include<iostream>
using namespace std;
int sum(int a[] , int size){
    if(size == 0){
        return 0;

    }
    else 
    return a[0] + sum(a+1, size-1);
}
int main(){
    int a ;
    cin>>a;
    int b[a];
    for(int i = 0 ; i<a ; i++){
        cin>>b[i];
    }
    cout << sum(b,a);
    return 0;
}
