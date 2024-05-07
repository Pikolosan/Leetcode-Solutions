// Reverse Prefix of Word 
/* Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
*/

/* DESCRIPTION : 
This Question is to reverse the string until the first occurance of the given character.
Now , there is a simple, direct or two pointer apprroach that can be applied . 

**NOTE:** 
* If no occurance of the character ch is found in the given string then the returned index = -1.
* reverser(arg1,arg2). For reverse function , arg1 and arg2 are necessary and are *iterators* and not index positions. The arg1 = the starting iterator , while arg2 = ending iterator.
*/



// SOLUTION-1: 
// **Simple For loop approach : **
// to find 
// **CODE : **
#include <string>
#include <algorithm>

using namespace std;

string reversePrefix(string word, char ch) {
    int idx = -1; // Initialize index to -1 indicating character not found
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] == ch) {
            idx = i; // Update index if character is found
            break;   // Exit loop once character is found
        }
    }
    if (idx == -1) { // If character not found
        return word; // Return original string
    }
    // Reverse the prefix up to the target character
    for (int i = 0; i <= idx / 2; ++i) {
        swap(word[i], word[idx - i]);
    }
    return word; // Return the modified string
} 

// SOLUTION-2 : 
// 2-pointer Approach 
class Solution {
public:
    string reversePrefix(string word, char ch) {
        reverse(word.begin(),word.begin()+word.find(ch)+1); // Reverse the word from start till the inputed character.
        return word;
    }
};

// Here We simply use the reverse keyword which contains 2 pointers 
// pointing at the start and end of the given word respectively.
