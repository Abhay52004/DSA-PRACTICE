// Problem: Letter Combinations of a Phone Number (Keypad combinations) - Robust Version
// Given a string containing digits from 0-9, return all possible letter combinations.
// This version robustly handles digits like '0' and '1' by skipping them since they map to no letters.
// Uses recursive backtracking.

#include<iostream>
#include<vector>
using namespace std;

// Recursive function to generate letter combinations
// Parameters:
// - index: The current digit in the input string we are processing.
// - input: The input string of digits.
// - map: Array mapping digits to corresponding character strings.
// - output: The combination string built so far.
// - ans: Vector to store all the generated combinations.
void generate(int index, string input, string map[], string output, vector<string> &ans){
    // Base Case: If we have processed all digits, store the current combination.
    if(index == input.size()){
        ans.push_back(output);
        return;
    }
    
    int x = input[index] - '0';
    string var = map[x];
    
    // If the current digit has no letters mapped to it (like '0' or '1'),
    // we skip it and move directly to the next digit.
    if(var.size() == 0){
         generate(index + 1, input, map, output, ans);
         return; // End execution of current recursive path
    }
    
    // Loop through all characters corresponding to the current digit
    for(int i = 0 ; i < var.size() ; i++){
        // Recurse for the next index, appending the current character to the output string
        generate(index + 1, input, map, output + var[i], ans);
    }
}

int main(){
    // Map digits 0-9 to keypad characters (0 and 1 map to empty strings)
    string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    string input;
    cout << "Enter digits (e.g., 23 or 120): ";
    cin >> input;
    
    string output = "";
    vector<string> ans;
    
    // Generate combinations
    generate(0, input, map, output, ans);
    
    cout << "\nAll possible letter combinations:" << endl;
    for(const auto &element : ans){
        cout << element << endl;
    }
    cout << "\nTotal combinations: " << ans.size() << endl;
    
    return 0;
}