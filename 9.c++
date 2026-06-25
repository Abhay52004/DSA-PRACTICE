// All the string with equal no. of the a's and b's .....
#include<iostream>
using namespace std;
void total_str(string aabtak , int n1, int n2,int &count){
    if(n1 == 0 && n2 ==0 ){
        cout << aabtak <<endl;
        count++;
        return;
    }
    if(n1>0)
    total_str(aabtak  + 'a', n1-1 , n2,count);
    if(n2>0)
    
    total_str(aabtak  + 'b', n1 , n2-1,count);
    
}
int main(){
    int a;
    int b;
    string aab;
    aab = "";
    cout<<"Enter  no. of a's" ;
    cin>>a;
    cout<<"Enter  no. of b's" ;
    cin>>b;
    int count = 0;
    if(a==b)
    total_str(aab,a,b, count);
    else
    cout<<"not a valid string";
    
    cout<<"Total no. of permutaion is :: "<<count;
}