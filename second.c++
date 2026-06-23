// #given an array, Find weather  it is sorted or not...

#include<iostream>
using namespace std;
int issorted(int a[] , int size){
    if(size<=1)
    return 1;
    if(a[0] > a[1])
    return 0;
    else
     return issorted(a +1 , size - 1);
}
int main(){
       int a ;
     cin>>a;
    int b[a];
    for(int i = 0 ; i<a ; i++){
        cin>>b[i];
    }
    int l  = issorted(b,a);
    if(l == 0)
    cout<<"FALSE";
    else
    cout<<"True";
}
