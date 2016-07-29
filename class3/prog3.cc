#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
  int N, E;
  cin >> N >> E;
  vector<vector<int> > adj(N);
  for(int i=0; i<E; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);   
  }
  
  bool done[N];
  memset(done, 0, sizeof done);
  int C = 0;
  for(int i=0; i<N; i++) {
    queue<int> q;
    if(done[i]) continue;
    q.push(i);
    cout << "> ";
    while(!q.empty()) {
      int top = q.front();
      q.pop();
      if(done[top]) continue;
      cout << top << " ";
      for(auto it = adj[top].begin(); it != adj[top].end(); it++) {
        q.push(*it);
      }
      done[top] = true;
    }
    C++;
    cout << endl;
  }
  cout << "Number of connected components = " << C << endl;
}

