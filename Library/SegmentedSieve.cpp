//Constraints: R-L+1 <= 1e7 and R <= 1e12
//returns prime numbers in the range [L,R]
//Usage: vector<char> a = segmentedSieve(5,100) ---> This gives us primes in the range [5,100]
//a[x-L] tells us if x is prime
vector<char> segmentedSieve(long long L, long long R) {//O(R-L+1)lglgR + sqrt(R)lglg(sqrt(R))
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
