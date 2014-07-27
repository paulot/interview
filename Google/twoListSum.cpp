// Google:
// Given two sorted lists of positive integers and a number N, describe an algorithm which determines if any two numbers in the list sum to N.
//
#include <iostream>
#include <vector>

using namespace std;

bool twoSum(vector<int> &fVect, vector<int> &sVect, int n) {
    if ((fVect[0] + sVect[0]) > n)
        return false;
    if ((fVect[fVect.size() - 1] + sVect[sVect.size() - 1]) < n)
        return false;
    int sum, s = sVect.size() - 1, f = 0;
    while (s >= 0 and f <= fVect.size() - 1) {
        sum = sVect[s] + fVect[f];
        if (sum == n)
            return true;
        if (sum < n) {
            f++;
        } else {
            s--;
        }
    } return false;
}

int main() {
   vector<int> f;
   vector<int> s;

   for (int i = 0; i < 10; f.push_back((i++) * 9));
   for (int i = 2; i < 10; s.push_back((i++) * 3));


   // Testing
   for (int i = 0; i < f.size(); i++)
       for (int j = 0; j < s.size(); j++) {
           if (not twoSum(f,s,f[i] + s[j]))
               cout << "test " << f[i] << " + " <<  s[j] << " is failing" << endl;
       }



   for (int i = 0; i < f.size(); i++)
       cout << f[i] << " ";
   cout << endl;

   for (int i = 0; i < s.size(); i++)
       cout << s[i] << " ";
   cout << endl;
   
   return 0;
}
