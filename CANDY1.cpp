#include <bits/stdc++.h>
using namespace std;
vector <long long> t(200001);
vector <int> a(200001);
int n;
long long bsmax(int l, int r, long long k)
{
    int mid;
    long long cs;
    while (l <= r)
    {
        mid = (l+r) / 2;
        if (t[n] - t[mid] == k) return k;
        else if (t[n] - t[mid] > k)
        {
            l = mid + 1;
            cs = t[n] - t[mid];
        }
        else r = mid - 1;
    }
    return cs;
}
long long bsmin(int l, int r, long long k)
{
    int mid;
    long long cs = 0;
    while (l <= r)
    {
        mid = (l+r) / 2;
        if (t[n] - t[mid] == k) return k;
        else if (t[n] - t[mid] > k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
            cs = t[n] - t[mid];
        }
    }
    return cs;
}
int main()
{
    cin >> n;
    t[0] = 0;
    for (int i = 1; i<=n; i++)
    {
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
    long long kc1, kc2;
    kc1 = bsmax(1, n, t[n] / 2);

    kc2 = bsmin(1, n, t[n] / 2);

    cout << min(abs(t[n] - 2*kc1), abs (t[n] - 2*kc2));

    return 0;
}
