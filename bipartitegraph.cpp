#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> g[100001];
int vis[100001];

//also detect odd length cycle
bool dfs(int u,int col){

	vis[u]=col;
	for(auto x:g[u]){

		if(!vis[x]){
			if(!dfs(x,3-col)) return 0;
		}else if(vis[x]==col){
			return 0;
		}
	}

	return 1;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
	int n,m;
	cin>>n>>m;
	while(m--){

		int x,y;
		cin>>x>>y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}

	if(dfs(0,1)) cout<<"NO\n";
	else cout<<"YES\n";

	return 0;

	/*STUFF TO LOOK:	
		1. Input ranges
		2. corner cases(n==0||n==1)
		3. Variables in loops
	*/
}
		