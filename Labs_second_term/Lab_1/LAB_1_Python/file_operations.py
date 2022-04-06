def enter_file_mode():
    file_mode = input('Do you want to overwrite the file or append input to it? Enter w or a: ')
    while file_mode != 'w' and file_mode != 'a':
        print("Incorrect input. Enter 'w' or 'a'.")
        file_mode = input('Do you want to overwrite the file or append input to it? Enter w or a: ')
    return file_mode


def create_first_file(file_name, mode):
    with open(file_name, mode) as file:
        is_end = False
        while not is_end:
            try:
                text = input()
                if len(text) > 0:
                    file.write(text + '\n')
            except EOFError:
                is_end = True


def get_words_list(file_name, n):
    with open(file_name) as file:
        words_list = []
        for line in file:
            words = line.split()
            for word in words:
                words_list.append(word)
    for word in words_list:
        count = words_list.count(word)
        if count > 1:
            count = count if count >= n else count - 1
            for _ in range(count):
                words_list.remove(word)
    print(f'List of words which occur less than {n} times:\n{words_list}')
    words_list.sort(key=lambda string: len(string), reverse=True)
    return words_list


def create_second_file(file_name, words_list):
    with open(file_name, 'w') as file:
        length = len(words_list)
        for i in range(length):
            if i != length - 1:
                file.write(words_list[i] + '\n')
            else:
                file.write(words_list[i])


def output_file(file_name):
    with open(file_name) as file:
        text = file.read()
        print(text)




