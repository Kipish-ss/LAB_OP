from file_operations import *


def main():
    first_file = 'file_1.txt'
    second_file = 'file_2.txt'
    n = int(input('Enter N: '))
    file_mode = enter_file_mode()
    print('Terminate input with Command + D. Input for the file:')
    create_first_file(first_file, file_mode)
    words_list = get_words_list(first_file, n)
    print(f'Sorted list by word length descending: {words_list}')
    create_second_file(second_file, words_list)
    print('First file:')
    output_file(first_file)
    print('Second file:')
    output_file(second_file)


if __name__ == '__main__':
    main()

