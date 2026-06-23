// #given an array, Reverse the content of the array...

#include<iostream>
using namespace std;
void reverse(int a[], int s){
    if(s == 0 || s == 1 )
   return ;
    int temp;
    temp = a[0];
    a[0] = a[s-1];
    a[s-1] = temp;
     reverse(a + 1 , s-2);
}
int main(){
    int a ;
        cin>>a;
    int b[a];
    for(int i = 0 ; i<a ; i++){
        cin>>b[i];
    }
  reverse(b,a);
  for(int i  =0 ;i  <a  ;i++){
      cout<<b[i]<<" ";
  }
}
