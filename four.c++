// #given a  particular char of a string....


#include<iostream>
using namespace std;

// Using char* allows pointer arithmetic like str + 1
void removeX(char* str) {
    // Base case: If we hit the null terminator, the string ends
    if (str[0] == '\0') {
        return;
    }
    
    if (str[0] == 'x') {
        // Shift every character to the left, INCLUDING the null terminator '\0'
        int i = 0;
        while (str[i] != '\0') {
            str[i] = str[i + 1];
            i++;
        }
        // CRITICAL: Do not do str + 1 here. 
        // The next character shifted into str[0], so we check str[0] again.
        removeX(str); 
    } 
    else {
        // Move to the next character pointer
        removeX(str + 1);
    }
}

int main() {
    // We must use a fixed character array for modification
    char s[100];
    if (!(cin >> s)) return 0;
    
    removeX(s);
    
    cout << s;
    return 0;
}