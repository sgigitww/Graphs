#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff 					first
#define ss 					second
#define sz(x) 				(int)(x).size()
#define all(x) 				begin(x), end(x)
#define rall(x) 			(x).rbegin(), (x).rend() 
#define rsz 				resize
#define ins 				insert 
#define ft 					front() 
#define bk 					back()
#define pf 					push_front 
#define pb 					push_back
#define eb 					emplace_back 
#define lb 					lower_bound 
#define ub 					upper_bound 
#define pqmax				priority_queue<int>
#define pqmin				priority_queue<int,vector<int>,greater<int>>
#define transup(x)			transform(x.begin(),x.end(),x.begin(),::toupper)
#define translow(x)			transform(x.begin(),x.end(),x.begin(),::tolower)
#define rep(i,a,b) 			for (int i = (a); i < (b); ++i)
#define per(i,a,b) 			for (int i = (b)-1; i >= (a); --i)
#define trav(a,x) 			for (auto a: x)

#define setbits(x)  		__builtin_popcountll(x)
#define zerobits(x)			__builtin_ctzll(x)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

unordered_map<int,vector<int>> mp;

void addedge(int x,int y){
	mp[x].pb(y);
	mp[y].pb(x);
}

bool vis[100001];
int lo[100001];
int in[100001];
int timer;
bool ok;
vector<pair<int,int>> ans;

void bridge(int n,int p){

	vis[n]=1;
	in[n]=lo[n]=timer;
	timer++;
	for(auto x:mp[n]){

		if(vis[x]&&x!=p){
			//back edge
			lo[n]=min(lo[x],in[n]);
			if(in[n]>in[x]){
				ans.pb(make_pair(n,x));
			}

		}else{ bridge(x,n); if(lo[x]>lo[x]){ ok=1; return;	 }

			lo[n]=min(lo[x],lo[n]);
			//forward edge
			ans.pb(make_pair(n,x));
		}	
	}

}	

int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    auto start = std::chrono::high_resolution_clock::now();
    /*start from here*/
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		addedge(x,y);
	}
	
	bridge(0,-1);
	if(ok){
		cout<<0<<'\n';
	}else{
		for(auto x:ans){
			cout<<x.ff<<" "<<x.ss<<'\n';
		}
	}
	
	auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     

    /*STUFF TO LOOK:	
	1. Special cases/corner cases(n==0||n==1)
	2. Variables in loops
	3. Input ranges
	*/
    return 0;

}
