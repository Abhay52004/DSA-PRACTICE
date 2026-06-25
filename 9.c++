// Problem: Generate all strings of length (a+b) with exactly 'a' number of 'a's and 'b' number of 'b's.
// Also calculates and prints the total number of valid permutations generated.

#include<iostream>
using namespace std;

// Recursive function to generate strings
// Parameters:
// - aabtak (a-and-b till now): The string built so far.
// - n1: Remaining number of 'a's to place.
// - n2: Remaining number of 'b's to place.
// - count: Reference to an integer to track the total number of permutations.
void total_str(string aabtak, int n1, int n2, int &count){
    // Base Case: If no 'a's or 'b's are left to place, print the generated string and increment the count.
    if(n1 == 0 && n2 == 0){
        cout << aabtak << endl;
        count++;
        return;
    }
    
    // Branch 1: If we have 'a's left to place, append 'a' and recurse
    if(n1 > 0) {
        total_str(aabtak + 'a', n1 - 1, n2, count);
    }
    
    // Branch 2: If we have 'b's left to place, append 'b' and recurse
    if(n2 > 0) {
        total_str(aabtak + 'b', n1, n2 - 1, count);
    }
}

int main(){
    int a, b;
    cout << "Enter no. of a's: ";
    cin >> a;
    cout << "Enter no. of b's: ";
    cin >> b;
    
    string aab = ""; // Starts empty
    int count = 0;   // Variable to count total permutations
    
    // The program requires the number of 'a's and 'b's to be equal
    if(a == b) {
        cout << "\nAll possible strings with equal number of a's and b's:" << endl;
        total_str(aab, a, b, count);
        cout << "\nTotal no. of permutations is :: " << count << endl;
    } else {
        cout << "Error: Not a valid string (Number of a's and b's must be equal)." << endl;
    }
    return 0;
}