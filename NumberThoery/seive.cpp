vector<bool> sieve(ll n){

    vector<bool>isPrime(n+1,1);

    isPrime[0]=isPrime[1]=0;

    for(ll i=2; i*i<=n; i++)

        if(isPrime[i])

            for(ll j=i*i; j<=n; j+=i)

            isPrime[j]=0;

    return isPrime;

}
