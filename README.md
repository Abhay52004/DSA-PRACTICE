# DSA Practice (Recursion & Backtracking)

Welcome to the **DSA Practice** repository! This folder contains a collection of Data Structures and Algorithms (DSA) problems solved in C++ using **recursion** and **backtracking**, along with basic study files for Python Pandas.

---

## 📚 Table of Contents

Below is a summary of the questions solved in this directory.

### 🔵 Recursion Basics
| Question No. | File Name | Topic / Problem Statement | Description |
| :---: | :--- | :--- | :--- |
| **Q1** | [first.c++](./first.c++) | **Sum of Array Elements** | Finds the sum of all elements in an array recursively. |
| **Q2** | [second.c++](./second.c++) | **Check Sorted Array** | Checks if a given array is sorted in non-decreasing order using recursion. |
| **Q3** | [third.c++](./third.c++) | **Reverse Array** | Reverses the elements of an array in-place using recursion. |
| **Q4** | [four.c++](./four.c++) | **Remove Character 'x'** | Removes all occurrences of the character `'x'` from a character array recursively. |
| **Q5** | [five.c++](./five.c++) | **Replace Character with String** | Replaces every occurrence of a specified character with a custom string recursively. |
| **Q6** | [six.c++](./six.c++) | **Remove Consecutive Duplicates** | Removes consecutive duplicate characters from a string (e.g., `abaabaabbbbc` ➔ `ababac`) recursively. |

### 🟡 Combinatorics & Subsets
| Question No. | File Name | Topic / Problem Statement | Description |
| :---: | :--- | :--- | :--- |
| **Q7** | [seven.c++](./seven.c++) | **String Subsequences** | Generates all subsequences of a string recursively (using array storage and direct printing methods). |
| **Q10** | [10.c++](./10.c++) | **String Subsequences (Enclosed)** | Generates and prints all subsequences of a string enclosed in curly braces `{}` recursively. |
| **Q11** | [11.c++](./11.c++) | **String Power Set** | Generates all subsets of a string using backtracking and groups them by length. |
| **Q12** | [12.c++](./12.c++) | **Integer Set Power Set** | Generates all subsets of an integer set using backtracking, formatted as sets and grouped by size. |

### 🔴 Advanced Backtracking & Permutations
| Question No. | File Name | Topic / Problem Statement | Description |
| :---: | :--- | :--- | :--- |
| **Q8** | [8th.c++](./8th.c++) | **Generate Valid Parentheses** | Generates all possible valid combinations of parentheses for a given pair count recursively. |
| **Q9** | [9.c++](./9.c++) | **Equal a's and b's Permutations** | Generates all possible string permutations containing an equal number of `'a'`s and `'b'`s recursively and counts the total permutations. |
| **Q13** | [13.c++](./13.c++) | **String Permutations** | Generates all permutations of a string using swap-based recursive backtracking. |
| **Q14** | [14.c++](./14.c++) | **Unique String Permutations** | Generates unique permutations of a string with duplicates by pruning redundant recursive branches. |
| **Q15** | [15.c++](./15.c++) | **Letter Combinations (Basic)** | Generates letter combinations representing keypad digits recursively using backtracking. |
| **Q16** | [16.c++](./16.c++) | **Letter Combinations (Robust)** | Generates letter combinations from phone digits, handling `0` and `1` (which map to no letters) by skipping them. |
| **Q17** | [17.c++](./17.c++) | **N-Queens Problem** | Finds all valid placements of $N$ queens on an $N \times N$ chessboard such that no two queens attack each other. |
| **Q18** | [18.c++](./18.c++) | **Rat in a Maze** | Find all unique paths a rat can take to travel from source `(0,0)` to destination `(N-1,N-1)` in a grid. |

### 🐍 Bonus: Python Pandas Practice
| File Name | Topic | Description |
| :--- | :--- | :--- |
| [pandas/main.py](./pandas/main.py) | **Pandas Series Basics** | Initializing 1D Pandas Series from lists and custom index mapping. |

---

## 💡 Recursion & Backtracking Core Concepts (Revision Cheat Sheet)

Use these key mental models to quickly review the principles of recursion and backtracking before coding:

### 1. The Core Anatomy of Recursion
Every recursive function requires two main blocks:
1. **Base Case**: The simplest, smallest input instance where the solution is known directly without recursion. Failing to write a proper base case leads to infinite recursion and **Stack Overflow**.
2. **Recursive Step**: Reducing the current complex problem into smaller subproblems of the same nature, and combining their results to solve the current instance.

### 2. Backtracking: The "Undo" Pattern
Backtracking is a systematic search of a state space (tree) to find solutions. It works by making a choice, exploring that path, and then **unmaking the choice (undo/backtrack)** to reset the state before trying the next branch.
* **Why backtrack?** We share state variables (like `visited` matrices or temporary string buffers) across recursive branches to save memory. Since they are passed by reference, any modification in one branch must be restored so other branches see the clean, original state.

### 3. State Parameters: Pass-by-Value vs. Pass-by-Reference
When building paths or combinations:
* **Pass-by-Value** (e.g., `solve(..., curr + 'D', ...)`):
  * C++ creates a copy of the string for each recursive branch.
  * **Benefit**: No manual backtracking is needed because returning from a branch automatically discards that copy.
* **Pass-by-Reference** (e.g., `vector<vector<int>> &visited`):
  * All branches share a single copy in memory.
  * **Requirement**: You **must** manually reset changes after the recursive call (e.g., `visited[row][col] = 0`), otherwise subsequent paths will be incorrectly blocked by old decisions.

### 4. Pruning Branches for Optimization
"Pruning" is the process of detecting early on that a recursive branch cannot lead to a valid or unique solution, and avoiding calling recursion on it:
* **Unique Permutations (Q14)**: We prune by checking if a character value has already been swapped into the current index position at this level.
* **N-Queens (Q17)**: We prune by checking `ispossible()` before placing a queen, rather than completing the board and checking later.
* **Rat in a Maze (Q18)**: We prune by ensuring the cell is within bounds, not blocked, and not visited yet before making the recursive call.

---

## 🛠️ Detailed Problem Explanations (Q10 - Q18)

*(Refer to earlier revisions or comments inside files for Q1 to Q9)*

### Q10: String Subsequences - Enclosed (`10.c++`)
* **Problem**: Print all subsequences of a string wrapped in curly braces `{}`.
* **Approach**: Uses recursive array storage (Method 1 of Q7). When the base case returns size, the driver program iterates and wraps each output.

### Q11: String Power Set (`11.c++`)
* **Problem**: Print all subsets of a string grouped by size.
* **Approach**: Standard backtracking include/exclude. Uses `curr.push_back()` and `curr.pop_back()` to build paths, then displays them sequentially by length.

### Q12: Integer Set Power Set (`12.c++`)
* **Problem**: Print all subsets of an integer array formatted as mathematical sets `{1, 2}`.
* **Approach**: Extends string power set recursion to integer arrays. Formats output with commas and curly braces.

### Q13: String Permutations (`13.c++`)
* **Problem**: Generate all permutations of a string.
* **Approach**: Swaps element at current `index` with every element to its right, recurses, and swaps back to backtrack.

### Q14: Unique String Permutations (`14.c++`)
* **Problem**: Generate unique permutations of a string with duplicate characters (e.g., `"aab"`).
* **Approach**: Prevents duplicate swaps at the same level by checking if the character at `i` has already been placed at `index` (by searching `[index, i-1]`).

### Q15: Letter Combinations of a Phone Number - Basic (`15.c++`)
* **Problem**: Get keypad letter combinations from digit string.
* **Approach**: Recursively loops through characters corresponding to `digits[index]` and appends to `curr`.

### Q16: Letter Combinations of a Phone Number - Robust (`16.c++`)
* **Problem**: Generate letter combinations, handling digits `0` and `1` (which have no letters).
* **Approach**: If `var.size() == 0`, skips the digit entirely and recurses on `index + 1` without adding letters.

### Q17: N-Queens Problem (`17.c++`)
* **Problem**: Place $N$ non-attacking queens on a chessboard.
* **Approach**: Column-by-column placement. Checks same row, upper diagonal, and lower diagonal to the left. Backtracks by setting `board[row][col] = 0`.

### Q18: Rat in a Maze (`18.c++`)
* **Problem**: Find all paths from `(0,0)` to `(N-1,N-1)` in a grid.
* **Approach**: Recursive search in 4 directions (**D, U, L, R**). Tracks path sequence in a string `curr`. Backtracks by resetting `visited[row][col] = 0`.

---

## 🚀 How to Run Locally

To compile and run any of these files, use a C++ compiler (like `g++`):

```bash
# Compile a file (e.g., first.c++)
g++ first.c++ -o first

# Run the executable
./first
```
