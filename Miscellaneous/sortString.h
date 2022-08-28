#include <iostream>
#include <vector>
#include <cstring>

// It is given string of lowercase lattin letters.
// Sort the string in alphabet order in linear time complexity.

// Time complexity O(n)
std::string sortString(const char* str) {
    std::vector<size_t> hist(26);
    for (size_t i = 0; i < strlen(str); i++) {
        hist[str[i]-'a']++;
    }
    for(size_t i=1; i<hist.size(); i++) {
        hist[i] += hist[i-1];
    }
    std::string res(strlen(str), ' ');
    for(size_t i=0; i<strlen(str); i++) {
        size_t index = --hist[str[i]-'a'];
        res[index] = str[i];
    }
    return res;
}