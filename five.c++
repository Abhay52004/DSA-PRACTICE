// //Replace every occurance of char 'x'  by abc;;

// #include<iostream>
// #include<cstring>

// using namespace std;
// void replace(char input[]){
//     int a = strlen(input);
//     if( a == 0)
//     return;
//     if(input[0] == 'x'){
//         for(int i= a ; i>0 ; i--){
//             input[i+2] = input[i];
//         }
//         input[0] = 'a';
//         input[1] = 'b';
//         input[2] = 'c';
//         replace(input + 3);
//     }
//     replace(input + 1);
// }
// int main(){
//     char a[100];
//     cin>>a;
//     replace(a);
//     cout<<a;
// }



// <<=================================================================================================>>>


//Replace every occurance of char 'any character '  by your particular string;;

#include<iostream>
#include<cstring>

using namespace std;
void replace(char input[] , char b , char c[]){
    int a = strlen(input);
    int s = strlen(c);
    if( a == 0)
    return;
    if(input[0] == b){
        for(int i= a ; i>0 ; i--){
            input[i+s-1] = input[i];
        }
        for(int i = 0; i <s ; i++){
            input[i] = c[i];
        }
        replace(input + s,b,c);
    }
    replace(input + 1,b,c);
}
int main(){
    char a[100];
    cin>>a;
    char b ;
    cin>>b;
    char c[10];
    cin>>c;
    replace(a,b,c );
    cout<<a;
}