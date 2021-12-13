/* Варіант 28
У рядку символів визначити кількість повторень кожного слова та видалити дублікати слів.
Слова відокремлюються пробілами
 */

#include <iostream>
#include <string>
using namespace std;
string* get_word_list(string, int*, int&, char=' '); // функція для отримання масиву окремих слів(без дублікатів)
bool contains(string, string*, int);  // функція для визначення приналежності рядка масиву рядків
int find_index(string*, int, string); // функція для визначення індексу, на якому знаходиться заданий рядок, із заданого масиву рядків
string join_words(string*, int);  // фукнція для створення рядку із заданого масиву рядків
void display_count(string*, int*, int); // функція для виведення слова та кількості його повторень

int main() {
    int size, actual_size;
    string text;
    actual_size = 0;
    cout << "Enter a string: ";
    getline(cin, text);
    size = text.length() / 2 + 1;
    int* count_list = new int[size];
    string* words = get_word_list(text, count_list, actual_size);
    int* counts = new int[actual_size];
    for (int i = 0; i < actual_size; ++i) {
        counts[i] = count_list[i];
    }
    delete[] count_list;
    display_count(words, counts, actual_size);
    text = join_words(words, actual_size);
    cout << "Input string without duplicates:\n" << text;
    delete[] words;
    delete[] counts;
    return 0;
}

string* get_word_list(string text, int* count_list, int& actual_size, char sep) {
    int size, index;
    size = text.length() / 2 + 1;
    string* word_list = new string[size];
    string word = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != sep) {
            word += text[i];
        }
        else {
            if (!contains(word, word_list, size) && word != "") {
                word_list[actual_size] = word;
                count_list[actual_size] = 1;
                actual_size++;
            }
            else if (contains(word, word_list, size) && word != "") {
                index = find_index(word_list, size, word);
                count_list[index] += 1;
            }
            word = "";
        }
    }
    if (!contains(word, word_list, size) && word != "") {
        word_list[actual_size] = word;
        count_list[actual_size] = 1;
    }
    else if (contains(word, word_list, size) && word != "") {
        index = find_index(word_list, size, word);
        count_list[index] += 1;
    }
    actual_size ++;
    string* words = new string[actual_size];
    for (int i = 0; i < actual_size; i++) {
        words[i] = word_list[i];
    }
    delete[] word_list;
    return words;
}

bool contains(string item, string* list, int size) {
    int i = 0;
    bool found = false;
    while (i < size && !found) {
        if (list[i] == item) {
            found = true;
        }
        i++;
    }
    return found;
}

int find_index(string* list, int size, string item) {
    int index, i;
    i = 0;
    bool found = false;
    while(i < size && !found) {
        if (list[i] == item) {
            index = i;
            found = true;
        }
        i++;
    }
    return index;
}

void display_count(string* word_list, int* count_list, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Word: " << word_list[i] << ", count: " << count_list[i] << endl;
    }
}

string join_words(string* list, int size) {
    string text = "";
    for (int i = 0; i < size; i++) {
        if (i != size - 1) {
            text += list[i] + ' ';
        }
        else {
            text += list[i];
        }
    }
    return text;
}
