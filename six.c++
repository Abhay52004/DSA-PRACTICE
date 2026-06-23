// remove the continuous duplicates in the the string in:: abaabaabbbbc    op::  abababc

#include<iostream>
#include<cstring>
using namespace std;
void dup(char b[] ){
    int a = strlen(b);
    if(a==0|| a ==1)
    return;
    if(b[0] == b[1])
    {
        for(int i = 0 ; i< a ; i++){
            b[i+1] = b[i+2];
            
        }
        dup(b);
        
    }
    dup(b+1);
}
int main(){
    char a[100];
    cin>>a;
    dup(a);
    cout<<a;
    
}