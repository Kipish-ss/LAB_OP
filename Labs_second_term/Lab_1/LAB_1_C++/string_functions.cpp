#include "string_functions.h"

vector<string> split(string str) {
    vector<string> words;
    string temp_str;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ' || i == str.length() - 1) {
            if (str[i] == ' ') {
                words.push_back(temp_str);
                temp_str = "";
            } else {
                temp_str += str[i];
                if (!temp_str.empty()) words.push_back(temp_str);
            }
        } else {
            temp_str += str[i];
        }
    }
    return words;
}

void sort_desc(vector<string>& vect) {
    string temp;
    for (int i = 0; i < vect.size() - 1; ++i) {
        for (int j = 0; j < vect.size() - 1 - i; ++j) {
            if (vect[j].length() < vect[j+1].length()) {
                temp = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = temp;
            }
        }
    }
}