// Problem: Generate and print the Power Set (all subsets) of a given string.
// Subsets are grouped and printed in order of their size (cardinality).

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to generate the power set using backtracking
// Parameters:
// - index: The current character index in the input string we are processing.
// - input: The original input string.
// - curr: The current subset being constructed.
// - ans: Vector to store all the generated subsets.
void power(int index, string input, string curr, vector<string> &ans){
    // Base Case: If we have reached the end of the string, save the current subset.
    if(index == input.size()){
        ans.push_back(curr);
        return;
    }
    
    // Choice 1: Include the current character in the subset
    curr.push_back(input[index]);
    power(index + 1, input, curr, ans);
    
    // Choice 2: Exclude the current character (Backtrack by removing it)
    curr.pop_back();
    power(index + 1, input, curr, ans);
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    int size_str = input.size();
    string curr = "";
    vector<string> ans;
    int index = 0;

    // Generate all subsets
    power(index, input, curr, ans);
    
    // Print subsets grouped sequentially by length (size 0, size 1, size 2, etc.)
    cout << "\nPower Set elements (grouped by size):" << endl;
    for(int i = 0 ; i <= size_str ; i++){
        for (const auto& subset : ans) {
            if(subset.size() == i) {
                cout << "[" << subset << "]" << "\n";
            }
        }
    }
    return 0;
}