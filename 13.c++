// Problem: Generate all possible permutations of a given string.
// Uses recursive backtracking with element swapping.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursive function to generate permutations
// Parameters:
// - index: The current starting index of the substring we are permuting.
// - input: The string being permuted (passed by value to allow easy backtracking of states).
// - ans: Vector to collect all permutations.
void permuta(int index, string input, vector<string> &ans){
    int a = input.size();
    
    // Base Case: If the index reaches the end of the string, we have formed a unique permutation.
    if(index == a){
        ans.push_back(input);
        return;
    }
    
    // Loop through all characters from 'index' to the end of the string
    for(int i = index ; i < a ; i++){
        // Swap the current character with the character at index
        swap(input[index], input[i]);
        
        // Recurse to generate permutations for the remaining substring
        permuta(index + 1, input, ans);
        
        // Swap back (Backtrack) to restore the string for the next iteration
        swap(input[index], input[i]);
    }
}

int main(){
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    vector<string> ans;
    
    // Generate all permutations
    permuta(0, input, ans);
    
    cout << "\nAll permutations of the string:" << endl;
    for (const auto& element : ans) {
        cout << element << endl;
    }
    return 0;
}
