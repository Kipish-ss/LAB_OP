#include "file_operations.h"

int main() {
    int n;
    string first_file = "/Users/kyryl/Desktop/Lab_1_C++/file_1.txt";
    string second_file = "/Users/kyryl/Desktop/Lab_1_C++/file_2.txt";
    cout << "Enter N:" << endl;
    cin >> n;
    string file_mode = enter_file_mode();
    cout << "Terminate input with Command + D. Input for the file:" << endl;
    create_first_file(first_file, file_mode);
    auto words_list = get_words_list(first_file, n);
    cout << "Sorted list by word length descending:" << endl;
    output_vector(words_list);
    create_second_file(second_file, words_list);
    cout << "First file:" << endl;
    output_file(first_file);
    cout << "Second file:" << endl;
    output_file(second_file);
    return 0;
}
