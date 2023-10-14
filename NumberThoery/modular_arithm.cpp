ll arthim_mod(ll a,ll b,ll c){
    return ((a%c)+(b%c))%c;
}

ll arithm_multip(ll a,ll b,ll c){
    return ((a%c)*(b%c))%c;
}

ll arithm_subtr(ll a,ll b,ll c){
    return ((a%c)-(b%c)+c)%c;
}
