#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>



template<typename T>
class Graph{
  int v;
public:
    std::list<T> *adj;
    Graph(){}
    Graph(int n){
      this->v = n;
      this->adj = new std::list<T>[this->v];
    }
    void add_edge(T n1, T n2, bool bidir = true){
        adj[n1].push_back(n2);
        if(bidir){
            adj[n2].push_back(n1);
        }
    }
    void print(){
        for(int i=1; i<v; i++){
            std::cout << i << "-->";
            for(T el:adj[i]){
                std::cout << el << ", ";
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Graph<int> g1(5);
    g1.add_edge(1,2);
    g1.add_edge(3,2);
    g1.add_edge(4,2);
    g1.add_edge(1,4);
    g1.add_edge(1,3);
    g1.print();

    return 0;
}
