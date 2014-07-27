def get_string(num):
    char = ''
    while num > 0:
        if num % 26 == 0:
            char = 'z' + char
            num = num / 26 - 1
        else:
            char = chr(ord('a')+(num%26)-1) + char
            num = num/26
    return char


def get_number(string):
    sum , i = 0, 0

    while len(string):
        char = string[-1]
        current = ord(char) - ord('a') + 1
        sum += current * (26 ** i)
        i += 1
        string = string[0:-1]

    print sum

if __name__ == "__main__":
    get_number(get_string(703))
    get_number(get_string(704))
    get_number(get_string(27))
    get_number(get_string(2))
    get_number(get_string(701))
    get_number(get_string(15234523452343214))

