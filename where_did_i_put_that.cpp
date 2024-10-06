#include <iostream>
#include <string>

using namespace std;

int find(const string &str, char ch) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}

int find(const string &str, const string &substr) {
    int strLength = str.length();
    int substrLength = substr.length();
    if (substrLength == 0) return 0;

    for (int i = 0; i <= strLength - substrLength; ++i) {
        int j;
        for (j = 0; j < substrLength; ++j) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == substrLength) {
            return i;
        }
    }
    return -1;
}

int main() {
    string testString1 = "The quick brown fox";
    char testChar1 = 'e';
    char testChar2 = 'z';

    cout << "Finding character '" << testChar1 << "' in \"" << testString1 << "\": " 
         << find(testString1, testChar1) << endl;

    cout << "Finding character '" << testChar2 << "' in \"" << testString1 << "\": " 
         << find(testString1, testChar2) << endl;

    string testString2 = "The quick brown fox";
    string testSubstring1 = "quick";
    string testSubstring2 = "cat";

    cout << "Finding substring \"" << testSubstring1 << "\" in \"" << testString2 << "\": " 
         << find(testString2, testSubstring1) << endl;

    cout << "Finding substring \"" << testSubstring2 << "\" in \"" << testString2 << "\": " 
         << find(testString2, testSubstring2) << endl;

    cout << "Finding character 'o' in \"cat's bat about yarn\": " 
         << find("cat's bat about yarn", 'o') << endl;

    cout << "Finding substring \"bat\" in \"cat's bat about yarn\": " 
         << find("cat's bat about yarn", "bat") << endl;

    cout << "Finding substring \"\" in \"cat's bat about yarn\": " 
         << find("cat's bat about yarn", "") << endl;

    return 0;
}
