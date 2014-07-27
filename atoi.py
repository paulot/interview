# Design an atoi with a radix


def getNum(char) :
    c = char - '0'
    if c > 10 :
        e = c - '9'
        a = c - 'A'

    else :
        return c

def atoi(string) :
    result = 0
    negative = False
    for c in string :
        digit = getNum(c)
        if c == '-' :
            negative = True
            continue
        elif digit >= radix or digit < 0 :
            return result if not negative else -1 * result
        result = result * radix + digit
    return result if not negative else -1 * result

