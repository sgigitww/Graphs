#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>
#include <chrono>

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
int lo[191];
int in[191];
int timer;
bool vis[1010];

void addedge(int x,int y){
	mp[x].pb(y);
	mp[y].pb(x);
}
//if(lo[par]<=lo(child) then bridge)
void dfs(int n,int p){

	vis[n]=1;
	in[n]=lo[n]=timer;
	timer++;
	for(auto x:mp[n]){

		if(x==p) continue;
		if(vis[x]){
			//back edge
			lo[n]=min(lo[n],in[x]);
		}
		else{
			//forward edge
			dfs(x,n);
			if(lo[x]>lo[n]){
				//its a bridge
				cout<<"("<<n+1<<","<<x+1<<") is a bridge\n";
			}
			//backtrack
			lo[n]=min(lo[n],lo[x]);
		}
	}
	return;

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
    	x--;y--;
    	addedge(x,y);
    }

	dfs(0,-1);

	auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     

    return 0;

    /*STUFF TO LOOK:	
	1. Special cases/corner cases(n==0||n==1)
	2. Variables in loops
	3. Input ranges
	*/
}
