#include <bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  map<int, list<int>> adj;
public:
  Graph(){
  }
  void add_edge(int v, int u, int bidir=true){
    adj[v].push_back(u);
    if(bidir){
      adj[u].push_back(v);
    }
  }
  void print(){
    for(auto head:adj){
      cout << head.first << " --> ";
      for(auto nbr:head.second){
        cout << nbr << " -> ";
      }
      cout << '\n';
    }
  }
  void dfshelper(int src, unordered_map<int, bool> &visited){
    visited[src] = true;
    cout << src << " ";
    for(auto nbr:adj[src]){
      if(!visited[nbr])
        dfshelper(nbr, visited);
    }
  }
  void dfs(int src){
    unordered_map<int, bool> visited;
    for(auto head:adj){
      for(auto node:head.second){
      if(not visited[node]){
				dfshelper(node, visited);
				cout << '\n';
			}
      }
      cout << '\n';
    }
  }

};

int main(){

  Graph g1;
  //g1.add_edge(1,2);
  //g1.add_edge(3,2);
  g1.add_edge(4,2);
  //g1.add_edge(1,4);
  g1.add_edge(1,3);
  g1.dfs(1);
  return 0;
}