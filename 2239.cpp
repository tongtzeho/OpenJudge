#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > lnklst;
vector<int> l, r;
vector<bool> visited;

/* make all vectors one element bigger in case the index starts from 1 instead of 0 */
void init(int n1, int n2) {
  lnklst.clear(); lnklst.resize(n1+1);
  l.clear(); l.resize(n1+1,-1);
  r.clear(); r.resize(n2+1,-1);
  return;
}

void add_edge(int u, int v) {
  lnklst[u].push_back(v);
  return;
}

bool dfs(int u) {
  for (int i=0; i<lnklst[u].size(); i++) {
    int v = lnklst[u][i];
    if (visited[v]) continue;
    visited[v] = true;
    if (r[v] < 0 || dfs(r[v])) {
      l[u] = v;
      r[v] = u;
      return true;
    }
  }
  return false;
}

int greedy_match(int n1) {
  int match = 0;
  for (int u=0; u<n1; u++) {
    if (l[u] < 0) {
      for (int i=0; i<lnklst[u].size(); i++) {
        int v = lnklst[u][i];
        if (r[v] < 0) {
          l[u] = v;
          r[v] = u;
          match++;
          break;
        }
      }
    }
  }
  return match;
}

int hungarian(void) {
  int n1 = l.size();
  int n2 = r.size();
  int match = greedy_match(n1);
  for (int u=0; u<n1; u++) {
    if (l[u] < 0) {
      visited.clear();
      visited.resize(n2);
      if (dfs(u)) {
        match++;
      }
    }
  }
  return match;
}

int main() {
  //freopen("stall.dat", "r", stdin);
  int coursenum;
  while (cin >> coursenum)
  {
  	init(coursenum, 84);
  	int i, j;
  	for (i = 0; i < coursenum; i++)
  	{
  		int timenum;
  		cin >> timenum;
  		for (j = 0; j < timenum; j++)
  		{
  			int x, y;
  			cin >> x >> y;
  			add_edge(i+1, (x-1)*12+y);
		}
	}
	cout << hungarian() << endl;
  }
  /*int n, m;
  while (cin >> n >> m) {
    init(n, m);
    for (int u=1; u<=n; u++) {
      int cnt;
      cin >> cnt;
      while (cnt--) {
        int v;
        cin >> v;
        add_edge(u, v);
      }
    }
    cout << hungarian() << endl;
  }*/
  return 0;
}
