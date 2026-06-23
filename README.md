# DSA Practice (Recursion)

Welcome to the **DSA Practice** repository! This folder contains a collection of Data Structures and Algorithms (DSA) problems solved in C++ using **recursion**.

## 📚 Table of Contents

Below is a summary of the questions solved in this directory.

| Question No. | File Name | Topic / Problem Statement | Description |
| :---: | :--- | :--- | :--- |
| **Q1** | [first.c++](./first.c++) | **Sum of Array Elements** | Finds the sum of all elements in an array recursively. |
| **Q2** | [second.c++](./second.c++) | **Check Sorted Array** | Checks if a given array is sorted in non-decreasing order using recursion. |
| **Q3** | [third.c++](./third.c++) | **Reverse Array** | Reverses the elements of an array in-place using recursion. |
| **Q4** | [four.c++](./four.c++) | **Remove Character 'x'** | Removes all occurrences of the character `'x'` from a character array recursively. |
| **Q5** | [five.c++](./five.c++) | **Replace Character with String** | Replaces every occurrence of a specified character with a custom string recursively. |
| **Q6** | [six.c++](./six.c++) | **Remove Consecutive Duplicates** | Removes consecutive duplicate characters from a string (e.g., `abaabaabbbbc` ➔ `ababac`) recursively. |

---

## 🛠️ Detailed Problem Explanations

### Q1: Sum of Array Elements (`first.c++`)
* **Problem**: Calculate the sum of all integers in a given array.
* **Approach**: 
  * **Base Case**: If array size is `0`, return `0`.
  * **Recursive Step**: Return the first element plus the sum of the remaining array: `a[0] + sum(a + 1, size - 1)`.

### Q2: Check If Array is Sorted (`second.c++`)
* **Problem**: Determine if the elements of an array are sorted in ascending order.
* **Approach**:
  * **Base Case**: If array size is `0` or `1`, it is already sorted (return `1`).
  * **Recursive Step**: If the first element is greater than the second (`a[0] > a[1]`), return `0`. Otherwise, recursively check the rest of the array: `issorted(a + 1, size - 1)`.

### Q3: Reverse Array (`third.c++`)
* **Problem**: Reverse the order of elements in an array in-place.
* **Approach**:
  * **Base Case**: If size is `0` or `1`, no swap is needed (return).
  * **Recursive Step**: Swap the first and last element of the current array, and recursively call the function for the middle subarray: `reverse(a + 1, s - 2)`.

### Q4: Remove Character 'x' (`four.c++`)
* **Problem**: Remove all occurrences of the character `'x'` from a C-style string.
* **Approach**:
  * **Base Case**: If null terminator `\0` is reached, return.
  * **Recursive Step**: If the current character is `'x'`, shift all characters to the left to overwrite it and recursively check the current position. If it is not `'x'`, move to the next position: `removeX(str + 1)`.

### Q5: Replace Character with String (`five.c++`)
* **Problem**: Replace every occurrence of a specific character in a string with an entire custom string (e.g., replacing `'x'` with `"abc"`).
* **Approach**:
  * **Base Case**: If the string is empty, return.
  * **Recursive Step**: If the first character matches the target character, shift all elements to the right to make space for the new string, copy the string in, and recurse on the remainder.

### Q6: Remove Consecutive Duplicates (`six.c++`)
* **Problem**: Remove consecutive duplicate characters from a string so that no two adjacent characters are identical.
* **Approach**:
  * **Base Case**: If string length is `0` or `1`, return.
  * **Recursive Step**: If the first and second characters are the same (`b[0] == b[1]`), shift the rest of the string left to remove the duplicate and recurse on the same position. Otherwise, recurse on `b + 1`.

---

## 🚀 How to Run Locally

To compile and run any of these files, use a C++ compiler (like `g++`):

```bash
# Compile a file (e.g., first.c++)
g++ first.c++ -o first

# Run the executable
./first
```
