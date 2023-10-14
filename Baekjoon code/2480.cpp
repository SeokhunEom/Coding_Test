#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[3], m;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    if(a[0] == a[2])
        m = 10000 + 1000 * a[2];
    else if (a[0] == a[1] || a[1] == a[2])
        m = 1000 + 100 * a[1];
    else
        m = 100 * a[2];
    cout << m;

    return 0;
}