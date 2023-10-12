vector <ll> getDivisors(ll n){
	vector <ll> divs;

	for(ll i=1; i*i<=n; i++){

		if(n%i==0){

		divs.push_back(i);

		if(i!=n/i) divs.push_back(n/i);

		}

	}

	return divs;

}
