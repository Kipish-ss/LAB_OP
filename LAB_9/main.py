# Варіант 28
# У рядку символів визначити кількість повторень кожного слова та видалити дублікати слів.
# Слова відокремлюються пробілами


def get_word_list(text: str, sep: str = ' '):  # функція для отримання масиву окремих слів(без дублікатів)
    word_list = []
    count_list = []
    word = ''
    for symbol in text:
        if symbol != sep:
            word += symbol
        else:
            if word not in word_list and word != '':
                word_list.append(word)
                count_list.append(1)
            elif word in word_list:
                count_list[word_list.index(word)] += 1
            word = ''
    if word not in word_list and word != '':
        word_list.append(word)
        count_list.append(1)
    elif word in word_list:
        count_list[word_list.index(word)] += 1
    return word_list, count_list


def display_count(word_list, count_list):  # функція для виведення слова та кількості його повторень
    for i in range(len(word_list)):
        word = word_list[i]
        count = count_list[i]
        if count == 1:
            print(f'The string contains "{word}" word {count} time.')
        else:
            print(f'The string contains "{word}" word {count} times.')


def join_words(word_list):  # фукнція для створення рядку із заданого масиву рядків
    text = ''
    for i in range(len(word_list)):
        if i != len(word_list) - 1:
            text += word_list[i] + ' '
        else:
            text += word_list[i]
    return text


text = input('Enter a string: ')
word_list, count_list = get_word_list(text)
display_count(word_list, count_list)
new_text = join_words(word_list)
print(f'Input string without duplicates:\n{new_text}')


