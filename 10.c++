// Problem: Find and print all the subsequences of a string using recursion.
// This method stores the subsequences in a dynamically allocated array and prints them enclosed in curly braces.

#include <iostream>
using namespace std;

// Recursive function to generate subsequences
// Parameters:
// - input: The remaining string to process.
// - output: The array storing subsequences generated so far.
// Returns: The total count of subsequences generated.
int subseq(string input , string output[]){
    // Base Case: If the input is empty, the only subsequence is the empty string.
    if(input.size() == 0){
        output[0] = "";
        return 1;
    }
    
    // Recursive Step: Process the rest of the string (excluding the first character)
    int smallsize = subseq(input.substr(1), output);
    
    // For each subsequence in the small output, prepend the first character of the current string
    for(int i = 0 ; i < smallsize; i++){
        output[i + smallsize] = input[0] + output[i];
    }
    
    // The size of output doubles (one set excluding the first char, one set including it)
    return 2 * smallsize;
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    // Dynamically allocate memory for output array (max 100 entries)
    string *output = new string[100];
    int count = subseq(input, output);
    
    cout << "\nAll subsequences of the string:" << endl;
    for(int i = 0 ; i < count ; i++){
        cout << "{" << output[i] << "}" << endl;
    }
    
    delete[] output; // Clean up dynamically allocated memory
    return 0;
}
