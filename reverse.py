# Microsoft Interview Question:
# Reverse the order of words in a phrase

def reverse(string) :
    r = string[::-1]
    end = 0
    start = 0
    i = 0
    for c in r :
        if (c == ' ' or c == '\n' or c == '\t' ) :
            end = i
            r = r[0:start] + (r[start:end])[::-1] + r[end::]
            start = end + 1
        elif (i == len(string) - 1) :
            r = r[0:start] + (r[start::])[::-1]
        i += 1
    return r

print reverse("abd   abc bla")
print reverse("abd   abc \n\nbla")
print reverse("abd   abt\t bla")
print reverse("abd")
print reverse("abdc bla")
