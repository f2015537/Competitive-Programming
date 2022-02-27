const int Z = 1e7 + 10; //change this for faster computation

vi isPrime(Z,1);
vi primes; //Stores all prime numbers from 1 to n
vi lp(Z,-1); //lp stores lowest prime factor for all numbers from 1 to n
vi hp(Z); //hp stores highest prime factor for all numbers from 1 to n

//Declare the above in global scope

void sieve(){ // O(NlglgN)
  isPrime[0] = isPrime[1] = 0;
  for(int i = 2; i < Z; ++i){
    if(isPrime[i]){
      primes.pb(i);
      lp[i] = hp[i] = i;
      for(int j = 2*i; j < Z; j += i){
        isPrime[j] = 0;
        if(lp[j] == -1) lp[j] = i;
        hp[j] = i;
      }
    }
  }
}


