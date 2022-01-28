#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef pair<int, int>      pi;
typedef pair<ll, ll>        pl;
typedef pair<ull, ull>     pul;
typedef pair<ld, ld>       pld;
typedef pair<double,double> pd;

typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<ull>   vul;
typedef vector<bool>   vb;
typedef vector<double> vd;
typedef vector<ld>    vld;
typedef vector<str>    vs;

typedef vector<pi>    vpi;
typedef vector<pl>    vpl;
typedef vector<pul>  vpul;
typedef vector<pld>  vpld;
typedef vector<pd>    vpd;

typedef vector<vi>    vvi;
typedef vector<vl>    vvl;  

#define mp  make_pair
#define pb  push_back
#define F   first
#define S   second
#define lb  lower_bound
#define ub  upper_bound
#define ins insert
#define rsz resize

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
#define tr(it, x) for(auto it = beg(x); it != en(x); ++it)

#define clr(x,i) memset(x, i, sizeof(x))

// ************************DEBUG START********************************
#ifdef chemecocs
// #define cerr cout  // if you want to print to stdout, uncomment this
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  tr(it,c)
    os << &", "[2 * (it == beg(c))] << *it;
  return os << ']';
}
//support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
//Change output format here
#define out(x) #x " = " << x << "; "
#define dbg(...)                                                              \
  cerr << __func__ << ":" << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#define dnl(x) cerr <<"----------- Test Case # " << x << " -----------\n";
#else
#define dbg(...)
#define dnl(x)
#endif
// ************************DEBUG END**********************************

// ************************MATH START*********************************
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, vector<ll>& fact, vector<ll>& ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
// ************************MATH END**********************************
 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int MOD = 1'000'000'007;
const int INF = 2e9;
const int N = 3e5, M = N;
//=======================

vvi g(N);
vi v(N);

void solve() {
  int n,x;
  cin>>n>>x;
  v.rsz(n+1);
  vi pf(n+1);
  bool ok = true;
  int l = n+1, r = 0;
  FOR(i,1,n+1){
    cin>>v[i];
    pf[i] = v[i] + pf[i-1];
    ok &= v[i]%x == 0;
    if(v[i]%x!=0){
      l = min(l,i);
      r = max(r,i);
    }
  }

  if(ok){
    cout<<-1<<"\n";
    return;
  }

  if(pf[n]%x != 0){
    cout<<n<<"\n";
    return;
  }

  cout<<max(n-l,r-1)<<"\n";
}

inline namespace FileIO {
  void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
  void setOut(str s) { freopen(s.c_str(),"w",stdout); }
  void setErr()      { freopen("Error.out","w",stderr); }
  void setIO(str s = "") {
    cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
    #ifdef chemecocs
      setErr();
    #endif
  }
}

int main() {
    setIO();
    int t = 1;
    cin >> t;
    F0R(i,t) {
      dnl(i+1);
      solve();
    }
    return 0;
}

void ipgraph(int n, int m){
  int i, u, v;
  while(m--){
    cin>>u>>v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par){
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}