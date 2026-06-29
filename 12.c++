// Problem: Generate all subsets (Power Set) of a given set of integers.
// Subsets are grouped by size (cardinality) and formatted inside curly braces.

#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate subsets of an integer array using backtracking (Include/Exclude)
// Parameters:
// - index: Current index of the element in the array.
// - len: Total length of the array.
// - arr: The original array representing the set.
// - curr: The current subset being constructed.
// - ans: Vector of vectors to store all generated subsets.
void power(int index, int len, int arr[], vector<int> curr, vector<vector<int>> &ans){
    // Base Case: If we have made a decision for all elements, store the subset.
    if(index == len){
        ans.push_back(curr);
        return;
    }
    
    // Choice 1: Include the current element in the subset
    curr.push_back(arr[index]);
    power(index + 1, len, arr, curr, ans);
    
    // Choice 2: Exclude the current element (Backtrack by removing it)
    curr.pop_back();
    power(index + 1, len, arr, curr, ans); 
}

int main(){
    int index = 0; 
    int len;
    cout << "Enter the size of the set/array: ";
    cin >> len;
    
    int *arr = new int[len];
    cout << "Enter the elements of the set: " << endl;
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    
    vector<int> curr;
    vector<vector<int>> ans;
    
    // Generate all subsets
    power(index, len, arr, curr, ans);
    
    // Print subsets grouped by cardinality (size 0 to len)
    cout << "\nSubsets of the set (grouped by size):" << endl;
    for(int i = 0 ; i <= len ; i++){
        for(const auto& subset : ans){
            if(subset.size() == i){
                cout << "{";
                for(size_t j = 0 ; j < subset.size() ; ++j){
                    cout << subset[j];
                    if(j < subset.size() - 1) {
                        cout << ",";
                    }
                }
                cout << "}" << endl;
            }
        }
    }
    
    delete[] arr; // Clean up dynamically allocated memory
    return 0;
}
