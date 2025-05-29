#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n, q, v[N];
vector<int> graph[N];

//Eular Tour part Begin
int ft[2 * N];
int in[N], out[N], timer = 1;

void dfs(int u, int p){
	in[u] = timer++;
	ft[in[u]] = v[u];
	for(auto &v : graph[u])if(v != p){
		dfs(v, u);
	}

	out[u] = timer++;
	ft[out[u]] = v[u];
}
//Eular Tour part End


#define lc  2 * node
#define rc  2 * node + 1
int t[8 * N];
void build(int node, int lo, int hi){
	if(lo == hi){
		t[node] = ft[lo];
		return;
	}

	int mid = (hi + lo) >> 1;
	build(lc, lo, mid);
	build(rc, mid + 1, hi);

	t[node] = t[lc] + t[rc];
}

int query(int node, int lo, int hi, int l, int r){
	if(hi < l or lo > r)return 0;
	if(lo >= l and hi <= r)return t[node];

	int mid = (hi + lo) >> 1;
	int q1 = query(lc, lo, mid, l, r);
	int q2 = query(rc, mid + 1, hi, l, r);

	return q1 + q2;
}

void update(int node, int lo, int hi, int p, int val){
	if(hi < p or lo > p)return;
	if(lo == hi){
		t[node] = ft[p] = val;
		return;
	}

	int mid = (hi + lo) >> 1;
	update(lc, lo, mid, p, val);
	update(rc, mid + 1, hi, p, val);

	t[node] = t[lc] + t[rc];
}


int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> q;
	for(int i = 1; i <= n; i++)cin >> v[i];
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, 0);
	int m = 2 * n;
	build(1, 1, m);

	while(q--){
		int t, x; 
		cin >> t >> x;
		if(t == 1){
			int val;
			cin >> val;
			update(1, 1, m, in[x], val);
			update(1, 1, m, out[x], val);

		}else{
			int qr = query(1, 1, m, in[x], out[x]);
			cout << qr / 2 << endl;
		}
	}
}

//https://cses.fi/problemset/task/1137