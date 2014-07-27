#include <iostream>
#include <cstring>

using namespace std;

int dp[27][27] = { 0 }, num;

int main() {
    num = 4;

    // i = allowed coins
    // j = amount
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            if (j == i) {
                dp[i][j] += 1 + dp[i-1][j];
            } else if (i < j) {
                if (j % i == 0) dp[i][j] += 1;
                if (i != 1) {
                    for (int fit = j/i; fit >= 0; fit--) {
                        if (fit != 0)
                            dp[i][j] += dp[i-1][j-fit*i];
                        else dp[i][j] += dp[i-1][j];
                    }
                }
            } else {
                dp[i][j] += dp[i-1][j];
            }
        }
    }

    
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ans " << dp[num][num] << endl;

    return 0;
}

