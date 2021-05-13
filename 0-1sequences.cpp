#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
ll p = 1e9 + 7;
ll inv2 = 500000004;

/*ll pow(ll base, ll exponent)
{
    ll ans = 1;
    int digits = 0;
    while (exponent>>digits)
    {
        digits++;
    }
    while (digits>=0)
    {
        ans = (ans * ans) % p;
        if (exponent & ((ll)1 << digits)) 
            ans = ans * base % p;
        digits--;
    }
    return ans;
}*/

ll binpow(ll a, ll b, ll m) {
    if (b < 0)
    {
        b = -b;
        a = inv2;
    }
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string in; cin >> in;
    ll Q = 0;
    ll sQ = 0;
    ll O = 0;
    ll sO = 0;
    char x;
    size_t len = in.size();
    size_t val = len - 1;
    for(int i = 0; i<len; i++)
    {
        x = in[i];
        if (x == '?')
        {
            sQ = (sQ+val)%p;
            Q++;
        }
        else if (x == '1')
        {
            O++;
            sO = (sO + val) % p;
        }
        val--;
    }
    ll basic = sO * 8 + sQ * 4 - Q * (Q + 1) - Q * (2 * O - 1) * 2 - (O * O - O) * 4 ;
    basic = ((basic%p)+p)%p;
    ll ans = (basic) * binpow((ll)2,Q-3,p) % p;
    cout << ans << endl;
    return 0;
}