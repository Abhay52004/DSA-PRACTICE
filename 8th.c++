// Problem: Generate all possible combinations of valid parentheses.
// Input: Number of open and close brackets (which must be equal to form valid parentheses).

#include<iostream>
using namespace std;

// Recursive function to generate valid parentheses combinations
// Parameters:
// - abbtak (ab-tak / till now): The string containing the parentheses sequence generated so far.
// - open: The count of remaining '(' brackets we can add.
// - close: The count of remaining ')' brackets we can add.
void generate(string abbtak, int open, int close){
    // Base Case: If no open or close brackets are left, we have a complete valid combination.
    if(open == 0 && close == 0)
    {
        cout << abbtak << endl;
        return;
    }
    
    // Rule 1: We can always add an open bracket '(' if we have any left.
    if(open > 0) {
        generate(abbtak + '(', open - 1, close);
    }
    
    // Rule 2: We can only add a close bracket ')' if we have remaining close brackets
    // AND the number of open brackets already placed is greater than the number of close brackets placed.
    // This is equivalent to: remaining open brackets < remaining close brackets (open < close).
    if(close > 0 && open < close) {
        generate(abbtak + ')', open, close - 1);
    }
}

int main(){
    int open, close;
    cout << "Enter number of opening parentheses: ";
    cin >> open;
    cout << "Enter number of closing parentheses: ";
    cin >> close;
    
    string abbtak = ""; // Starts empty
    
    // To form valid parentheses combinations, we must start with equal numbers of open and close brackets.
    if(open == close) {
        cout << "\nAll possible valid combinations of " << open << " pairs:" << endl;
        generate(abbtak, open, close);
    } else {
        cout << "Error: Not a valid input (Opening and closing count must be equal)." << endl;
    }
    return 0;
}