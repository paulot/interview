// Given array of colors sort the colors
// red-green-blue

#include <iostream>
#define printColor(i) \
    if (arr[i].red)         \
        cout << "red ";     \
    else if (arr[i].green)  \
        cout << "green ";   \
    else if (arr[i].blue)   \
        cout << "blue ";

using namespace std;

struct color {
    bool red;
    bool green;
    bool blue;
};

void print (color arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i].red)
            cout << "red ";
        else if (arr[i].green)
            cout << "green ";
        else if (arr[i].blue)
            cout << "blue ";
    }
    cout << endl;
}

void swap(color arr[], int f, int s) {
    // printColor(f);
    // cout << endl;
    // printColor(s);
    // cout << endl;
    color t = arr[f];
    arr[f] = arr[s];
    arr[s] = t;
}

void cSort(color arr[], int n) {
    int firstNonRed;
    int lastNonBlue;

    for (firstNonRed = 0; firstNonRed < n and arr[firstNonRed].red; firstNonRed++);
    for (lastNonBlue = n-1; lastNonBlue >= 0 and arr[lastNonBlue].blue; lastNonBlue--);

    int i = firstNonRed + 1;
    while (i <= lastNonBlue) {
    // for (int i = firstNonRed + 1; i <= lastNonBlue; i++) {
        if (i == firstNonRed) i++;
        if (arr[i].red) {
            swap(arr, firstNonRed, i);
            // for (firstNonRed; firstNonRed < n and arr[firstNonRed].red; firstNonRed++);
            firstNonRed++;
            
        }
        if (arr[i].blue) {
            swap(arr, lastNonBlue, i);
            // for (lastNonBlue; lastNonBlue >= 0 and arr[lastNonBlue].blue; lastNonBlue--);
            lastNonBlue--;
        }
        // cout << i << endl;
        // print(arr, 20);
        // cout << firstNonRed << endl;
        // cout << i << endl;
        // cout << lastNonBlue << endl;
        if (arr[i].green) i++;
    }

    /*
    int firstNonRed;

    for (firstNonRed = 0; firstNonRed < n and arr[firstNonRed].red; firstNonRed++);

    for (int i = firstNonRed + 1; i < n; i++) {
        if (arr[i].red) {
            swap(arr, firstNonRed, i);
            for (firstNonRed; firstNonRed < n and arr[firstNonRed].red; firstNonRed++);
            continue;
        }
    }

    int lastNonBlue;

    for (lastNonBlue = n-1; lastNonBlue >= 0 and arr[lastNonBlue].blue; lastNonBlue--);


    for (int i = lastNonBlue - 1; i >= 0; i--) {
        if (arr[i].blue) {
            swap(arr, lastNonBlue, i);
            for (lastNonBlue; lastNonBlue >= 0 and arr[lastNonBlue].blue; lastNonBlue--);
            continue;
        }
    }
    */
}


int main() {
    color arr[20];

    for (int i = 0; i < 5; i++) {
        arr[i].red = true;
        arr[i].blue= false;
        arr[i].green = false;
    }
    for (int i = 5; i < 8; i++) {
        arr[i].red = false;
        arr[i].blue= true;
        arr[i].green = false;
    }
    arr[8].red = true;
    arr[8].blue = false;
    arr[8].green = false;

    arr[9].red = true;
    arr[9].blue = false;
    arr[9].green = false;

    for (int i = 10; i < 15; i++) {
        arr[i].red = false;
        arr[i].blue= false;
        arr[i].green = true;
    }
    for (int i = 15; i < 20; i++) {
        arr[i].red = true;
        arr[i].blue= false;
        arr[i].green = false;
    }

    print(arr, 20);
    cSort(arr, 20);
    print(arr, 20);

    return 0;
}
