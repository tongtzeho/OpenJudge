#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>

#define N (240)
#define M (N*N*2)
#define inf 99999999

typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

/*
 * When there are multiple test sets, you need to re-initialize before each
 */
void dinic_init(void) {
  num_of_edges = 0;
  memset(head, -1, sizeof(head));
  return;
}

int add_edge(int u, int v, int c1, int c2) {
  int& i=num_of_edges;

  assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
  e[i].v = v;
  e[i].cap = c1;
  e[i].next = head[u];
  head[u] = i++;

  e[i].v = u;
  e[i].cap = c2;
  e[i].next = head[v];
  head[v] = i++;
  return i;
}

void print_graph(int n) {
  for (int u=0; u<n; u++) {
    printf("%d: ", u);
    for (int i=head[u]; i>=0; i=e[i].next) {
      printf("%d(%d)", e[i].v, e[i].cap);
    }
    printf("\n");
  }
  return;
}

/*
 * Find all augmentation paths in the current level graph
 * This is the recursive version
 */
int dfs(int u, int t, int bn) {
  if (u == t) return bn;
  int left = bn;
  for (int i=cur[u]; i>=0; i=e[i].next) {
    int v = e[i].v;
    int c = e[i].cap;
    if (c > 0 && level[u]+1 == level[v]) {
      int flow = dfs(v, t, min(left, c));
      if (flow > 0) {
        e[i].cap -= flow;
        e[i^1].cap += flow;
        cur[u] = i;
        left -= flow;
        if (!left) break;
      }
    }
  }
  if (left > 0) level[u] = 0;
  return bn - left;
}

bool bfs(int s, int t) {
  memset(level, 0, sizeof(level));
  level[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return true;
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (!level[v] && e[i].cap > 0) {
        level[v] = level[u]+1;
        q.push(v);
      }
    }
  }
  return false;
}

LL dinic(int s, int t) {
  LL max_flow = 0;

  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    max_flow += dfs(s, t, INT_MAX);
  }
  return max_flow;
}

int upstream(int s, int n) {
  int cnt = 0;
  vector<bool> visited(n);
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i=head[u]; i>=0; i=e[i].next) {
      int v = e[i].v;
      if (e[i].cap > 0 && !visited[v]) {
        visited[v] = true;
        q.push(v);
        cnt++;
      }
    }
  }
  return cnt; // excluding s
}

int main() {
	
	int k, c, m, i, j, l;
	int dist[235][235] = {0};
	scanf("%d %d %d", &k, &c, &m);
	for (i = 0; i < k+c; i++)
		for (j = 0; j < k+c; j++)
		{
			scanf("%d", &dist[i][j]);
			if (dist[i][j] == 0 && i != j)
			{
				dist[i][j] = inf;
			}
		}
	for (l = 0; l < k+c; l++)
		for (i = 0; i < k+c; i++)
			for (j = 0; j < k+c; j++)
			{
				if (dist[i][l]+dist[l][j] < dist[i][j]) dist[i][j] = dist[i][l]+dist[l][j];
			}
	int left = 0, right = 200*(k+c+1);
	while (right > left)
	{
		int mid = (left+right)/2;
		int s = 237, t = 238;
		dinic_init();
		for (i = 0; i < k; i++)
		{
			add_edge(s, i, m, 0);
		}
		for (i = k; i < k+c; i++)
		{
			add_edge(i, t, 1, 0);
		}
		for (i = 0; i < k; i++)
			for (j = k; j < k+c; j++)
			{
				if (dist[i][j] <= mid)
				{
					add_edge(i, j, 1, 0);
				}
			}
		int flow = dinic(s, t);
		if (flow == c)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	printf("%d\n", right);
	return 0;
	
	/*
  int m, n, s, t;
  int pig[M+1], pre[M+1];
  bool con[N+1];
  FILE *fin;
  fin = stdin;

  fscanf(fin, "%d %d", &m, &n);
  dinic_init();
  s = 0, t = n+1;
  for (int i=1; i<=m; i++) {
    fscanf(fin, "%d", &pig[i]);
  }
  memset(pre, -1, sizeof(pre));
  for (int i=1; i<=n; i++) {
    int nkeys;
    fscanf(fin, "%d", &nkeys);
    memset(con, 0, sizeof(con));
    int cap = 0;
    for (int j=1; j<=nkeys; j++) {
      int ph;
      fscanf(fin, "%d", &ph);
      int cust = pre[ph];
      if (cust < 0) {
        cap += pig[ph];
      } else if (!con[cust]) {
        add_edge(cust, i, INT_MAX, 0);
      }
      pre[ph] = i;
    }
    if (cap > 0) {
      add_edge(s, i, cap, 0);
    }
    int npigs;
    fscanf(fin, "%d", &npigs);
    if (npigs > 0) {
      add_edge(i, t, npigs, 0);
    }
  }
  //print_graph(n+2);
  int flow = dinic(s, t);
  printf("%d\n", flow);

  return 0;*/
}
