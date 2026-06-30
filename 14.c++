// Problem: Generate all UNIQUE permutations of a given string that may contain duplicate characters.
// e.g., Input: "aab" -> Output: "aab", "aba", "baa" (no duplicate permutations printed).
// Uses swap-based backtracking with branch pruning.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursive function to generate unique permutations
// Parameters:
// - index: The current starting position in the string.
// - input: The string being permuted.
// - ans: Vector to store the unique permutations.
void permutaUnique(int index, string input, vector<string> &ans){
    int a = input.size();
    
    // Base Case: If index reaches the end, we have formed a unique permutation.
    if(index == a){
        ans.push_back(input);
        return;
    }
    
    for(int i = index; i < a; i++){
        // Pruning Step: 
        // Checking just "input[i] == input[i+1]" only works if the string is sorted and we only swap adjacent elements.
        // Because swap-based backtracking reorders elements, we must check if the character at input[i]
        // has already been swapped into the 'index' position at this level.
        // We do this by checking if input[i] matches any character in the range [index, i-1].
        bool alreadySwapped = false;
        for(int j = index; j < i; j++){
            if(input[j] == input[i]){
                alreadySwapped = true;
                break;
            }
        }
        
        // If it was already swapped, skip this branch to prevent duplicate permutations.
        if(alreadySwapped) {
            continue;
        }
        
        // Perform swap
        swap(input[index], input[i]);
        
        // Recurse for the next index
        permutaUnique(index + 1, input, ans);
        
        // Backtrack: restore original string
        swap(input[index], input[i]);
    }
}

int main(){
    string input;
    cout << "Enter a string (with duplicate characters, e.g., aab): ";
    cin >> input;
    
    vector<string> ans;
    
    // Generate unique permutations
    permutaUnique(0, input, ans);
    
    cout << "\nAll unique permutations of the string:" << endl;
    for (const auto& element : ans) {
        cout << element << endl;
    }
    cout << "\nTotal unique permutations: " << ans.size() << endl;
    return 0;
}
