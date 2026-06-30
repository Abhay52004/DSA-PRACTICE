// Problem: Letter Combinations of a Phone Number (Keypad combinations)
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// Uses recursive backtracking.

#include<iostream>
#include<vector>
using namespace std;

// Recursive function to generate letter combinations
// Parameters:
// - index: The current digit in 'digits' we are processing.
// - digits: The input string of keypad digits (e.g., "23").
// - curr: The combination string built so far.
// - ans: Vector to store all the generated combinations.
// - map: Array mapping digits to their corresponding characters.
void backtrack(int index, string digits, string curr, vector<string> &ans, string map[]){
    // Base Case: If we have processed all digits, store the current combination.
    if(index == digits.size()){
        ans.push_back(curr);
        return;
    }
    
    // Convert the current digit character to its integer value (e.g., '2' -> 2)
    int digitVal = digits[index] - '0';
    string letters = map[digitVal];
    
    // Iterate through all characters corresponding to the current digit
    for(int i = 0 ; i < letters.size() ; i++){
        // Recurse to process the next digit, adding the current letter to the combination
        backtrack(index + 1, digits, curr + letters[i], ans, map);
    }
}

int main(){
    string digits;
    cout << "Enter digits (from 2-9): ";
    cin >> digits;
    
    // Return empty result if the input digits are empty
    if(digits.empty()){
        cout << "No digits entered." << endl;
        return 0;
    }
    
    vector<string> ans;
    int index = 0; 
    string curr = "";
    
    // Mapping from index/digit to corresponding letters (0 and 1 map to empty string)
    string keypadMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // Generate combinations
    backtrack(index, digits, curr, ans, keypadMap);
    
    cout << "\nAll possible letter combinations:" << endl;
    for(const auto &combination : ans) {
        cout << combination << endl;
    }
    cout << "\nTotal combinations: " << ans.size() << endl;
    
    return 0;
}