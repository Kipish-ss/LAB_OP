#ifndef LAB_1_C___FILE_OPERATIONS_H
#define LAB_1_C___FILE_OPERATIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string enter_file_mode();
void create_first_file(string, string);
vector<string> get_words_list(string, int);
void create_second_file(string, vector<string>);
void output_file(string);
void output_vector(vector<string>);
#endif