#include<bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> size, parent, rank;
public:
	DSU(int n){
		parent.resize(n+1);
		rank.resize(n+1);
		size.resize(n+1);
		// make
		for(int i = 0; i <= n; ++i){
			parent[i] = i;
			size[i] = 1;
			rank[i] = 0;
		}
	}

	int find(int v){
		if(parent[v] == v) return v;
		return parent[v] = find(parent[v]); // Path Compression
	}

	void unionBySize(int a, int b){
		a = find(a);
		b = find(b);

		if(a != b){
			if(size[a] < size[b]){
				swap(a, b);
			}
			parent[b] = a;
			size[a] += size[b];
		}
	}

	void unionByRank(int a, int b){
		a = find(a);
		b = find(b);

		if(a == b) continue;

		if(rank[a] > rank[b]){
			parent[b] = a;
		}
		else if(rank[a] < rank[b]){
			parent[a] = b;
		}
		else{
			parent[b] = a;
			rank[a]++;
		}
	}
};

int main(){
    DSU ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.find(3) == ds.find(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.find(3) == ds.find(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}