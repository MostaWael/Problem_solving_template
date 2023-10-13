int gcd(int x, int y) // O(log(min(x, y))
{
    if (y == 0) return x;
    return gcd(y, x%y);
}

int expo(int a, int b, int m) // O(logB)
{
    if (b == 0) return 1;
    int res = expo(a, b/2, m);
    return 1LL*res*res%m*(b%2 ? a : 1)%m;
}

int expoIterative(int a, int b) // O(lobB)
{
    int res = 1;
    while(b) {
        if (b&1) res*=a;
        a*=a, b/=2;
    }
    return res;
}

int modInverse(int a, int m)
{
    return expo(a, m-2, m);
}

int fact[N], invfact[N]; // fact[i] = i!
const int mod = 1e9+7;
void pre()
{
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1LL*i*fact[i-1]%mod;
        invfact[i] = modInverse(fact[i], mod);
    }
}

int nPr(int n, int r)
{
    if (r > n) return 0;
    return 1LL*fact[n]*invfact[n-r]%mod;
}

int nCr(int n, int r)
{
    if (r > n) return 0;
    return 1LL*fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}
