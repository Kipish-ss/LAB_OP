#include "file_operations.h"
#include "string_functions.h"


string enter_file_mode() {
    string file_mode;
    cout << "Do you want to overwrite the file or append input to it? Enter w or a:" << endl;
    cin >> file_mode;
    while (file_mode != "w" and file_mode != "a") {
        cout << "Incorrect input. Enter 'w' or 'a'." << endl;
        cout << "Do you want to overwrite the file or append input to it? Enter w or a:" << endl;
        cin >> file_mode;
    }
    return file_mode;
}


void create_first_file(const string file_name, string mode) {
    ofstream file;
    if (mode == "w") {
        file.open(file_name);
    }
    else {
        file.open(file_name, ios::app);
    }
    string text;
    while (getline(cin, text))
        if (text.length() > 0) {
            file << text << endl;
        }
    file.close();
}


vector<string> get_words_list(string file_name, int n) {
    vector<string> words_list;
    string text;
    ifstream file(file_name);
    while (!file.eof()) {
        getline(file, text);
        vector<string> words = split(text);
        for (int j = 0; j < words.size(); ++j) {
            words_list.push_back(words[j]);
        }
    }
    file.close();
    vector<string> new_words_list;
    for (int i = 0; i < words_list.size(); ++i) {
        string word = words_list[i];
        int word_count = count(words_list.begin(), words_list.end(), word);
            if (word_count < n) {
                if (!count(new_words_list.begin(), new_words_list.end(), word)) {
                    new_words_list.push_back(word);
                }
            }
        }
    cout << "List of words which occur less than " << n << " times:" << endl;
    output_vector(new_words_list);
    sort_desc(new_words_list);
    return new_words_list;
}


void create_second_file(string file_name, vector<string> words) {
    ofstream file(file_name);
    auto size = words.size();
    for (int i = 0; i < size; ++i) {
        if (i != size - 1) file << words[i] << endl;
        else file << words[i];
    }
    file.close();
}


void output_file(string file_name) {
    ifstream file(file_name);
    string text;
    while (!file.eof()) {
        getline(file, text);
        cout << text << endl;
    }
    file.close();
}


void output_vector(vector<string> vect) {
    for (string str: vect)
        cout << str << ' ';
    cout << endl;
}