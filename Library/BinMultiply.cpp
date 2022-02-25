//prevents overflows when M is large
ll binmultiply(ll a, ll b, ll mod){
	ll res = 0;
	while(b > 0){
		if(b&1){
			res = (res + a) % mod;
		}
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

//If using in tandem with binary exponentation, make sure to replace all instances of multiplication with binmultiply