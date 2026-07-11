#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 70000 + 5;

const ll MOD = 1e9 + 7;
ll dp[N][2][2];
ll mex[N][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            dp[0][a][b] = 1;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                vector<ll> add;
               for (int j = 1; j <= i; j++) {
                   bool can = true;

                   if (j == 1) {
                       if (a == 0) {
                           can = false;
                       }
                   }

                   if (j == i) {
                       if (b == 0) {
                           can = false;
                       }
                   }

                   if (can) {
                       add.push_back(mex[j - 1][a][0] ^ mex[i - j][0][b]);
                   }
               }

                for (int j = 1; j <= i; j++) {
                    bool can = true;

                    if (j == 1) {
                        if (a == 1) {
                            can = false;
                        }
                    }

                    if (j == i) {
                        if (b == 1) {
                            can = false;
                        }
                    }

                    if (can) {
                        add.push_back(mex[j - 1][a][1] ^ mex[i - j][1][b]);
                    }
                }

                sort(add.begin(), add.end());

                int mx = 0;

                for (auto j : add) {
                    if (j == mx) {
                        mx++;
                    }
                }

                mex[i][a][b] = mx;

                if (mx == 0) {
                    for (int j = 1; j <= i; j++) {
                        bool can = true;

                        if (j == 1) {
                            if (a == 0) {
                                can = false;
                            }
                        }

                        if (j == i) {
                            if (b == 0) {
                                can = false;
                            }
                        }

                        if (can) {
                            dp[i][a][b] = (dp[i][a][b] + (dp[j - 1][a][0] * dp[i - j][0][b]) % MOD) % MOD;
                        }
                    }

                    for (int j = 1; j <= i; j++) {
                        bool can = true;

                        if (j == 1) {
                            if (a == 1) {
                                can = false;
                            }
                        }

                        if (j == i) {
                            if (b == 1) {
                                can = false;
                            }
                        }

                        if (can) {
                            dp[i][a][b] = (dp[i][a][b] + (dp[j - 1][a][1] * dp[i - j][1][b]) % MOD) % MOD;
                        }
                    }
                } else {
                    for (int j = 1; j <= i; j++) {
                        bool can = true;

                        if (j == 1) {
                            if (a == 0) {
                                can = false;
                            }
                        }

                        if (j == i) {
                            if (b == 0) {
                                can = false;
                            }
                        }

                        if (can && (mex[j - 1][a][0] ^ mex[i - j][0][b]) == 0) {
                            dp[i][a][b] = (dp[i][a][b] + (dp[j - 1][a][0] * dp[i - j][0][b]) % MOD) % MOD;
                        }
                    }

                    for (int j = 1; j <= i; j++) {
                        bool can = true;

                        if (j == 1) {
                            if (a == 1) {
                                can = false;
                            }
                        }

                        if (j == i) {
                            if (b == 1) {
                                can = false;
                            }
                        }

                        if (can && (mex[j - 1][a][1] ^ mex[i - j][1][b]) == 0) {
                            dp[i][a][b] = (dp[i][a][b] + (dp[j - 1][a][1] * dp[i - j][1][b]) % MOD) % MOD;
                        }
                    }
                }
            }
        }
    }

    // for (int i = 0; i < 1000; i++) {
    //     cout << mex[i][1][1] << ' ';
    // }

    cout << (dp[n - 1][0][0] * (ll)(n) + dp[n - 1][1][1] * (ll)(n)) % MOD;


    return 0;
}
