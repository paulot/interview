// Define a function to recognuze if a number is prime or not
#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n) + 1; i++) {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

int main() {
    int nums[20] = { 1,2,4,6,7,8,9,98,76,65,54,43,32,13,19,41,32,33,34,99 };
    for (int i = 0; i < 20; i++)
        cout << nums[i] << " " << is_prime(nums[i]) << endl;
    return 0;
}
