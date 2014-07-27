// Given a number print all of the possible letter combinations 
// that is can have
#include <iostream>
#include <string>

using namespace::std;

void numCombo(long int num, string result) {

    switch (num%10) {
        case 0:
            cout << result << endl;
            break;
        case 1:
            break;
        case 2:
            numCombo(num/10, 'a' + result);
            numCombo(num/10, 'b' + result);
            numCombo(num/10, 'c' + result);
            break;
        case 3:
            numCombo(num/10, 'd' + result);
            numCombo(num/10, 'e' + result);
            numCombo(num/10, 'f' + result);
            break;
        case 4:
            numCombo(num/10, 'g' + result);
            numCombo(num/10, 'h' + result);
            numCombo(num/10, 'i' + result);
            break;
        case 5:
            numCombo(num/10, 'j' + result);
            numCombo(num/10, 'k' + result);
            numCombo(num/10, 'l' + result);
            break;
        case 6:
            numCombo(num/10, 'm' + result);
            numCombo(num/10, 'n' + result);
            numCombo(num/10, 'o' + result);
            break;
        case 7:
            numCombo(num/10, 'p' + result);
            numCombo(num/10, 'q' + result);
            numCombo(num/10, 'r' + result);
            numCombo(num/10, 's' + result);
            break;
        case 8:
            numCombo(num/10, 't' + result);
            numCombo(num/10, 'u' + result);
            numCombo(num/10, 'v' + result);
            break;
        case 9:
            numCombo(num/10, 'w' + result);
            numCombo(num/10, 'x' + result);
            numCombo(num/10, 'y' + result);
            numCombo(num/10, 'z' + result);
            break;
    }
}

int main() {
    numCombo(72856,"");

    return 0;
}
