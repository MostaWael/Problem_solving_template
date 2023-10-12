vector<pair<ll, ll>> factorize(ll n){
	vector<pair<ll, ll>> fact;
	for(ll i=2; i*i<=n; i++){
		int cnt=0;
		while(n%i==0){
		   n/=i;
		   cnt++;
		}

		if(cnt) fact.push_back({i,cnt});
	}

	if(n>1) fact.push_back({n,1});
	return fact;

}
