#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>



template<typename T>
class Graph{
public:
    std::unordered_map<T, std::list<T>> adj;
    Graph(){}
    void add_edge(T n1, T n2, bool bidir = true){
        adj[n1].push_back(n2);
        if(bidir){
            adj[n2].push_back(n1);
        }
    }
    void print(){
        for(auto row:this->adj){
            std::cout << row.first << "-->";
            for(T el:row.second){
                std::cout << el << ", ";
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Graph<int> g1;
    Graph<std::string> g2;
    g1.add_edge(1,2);
    g1.add_edge(3,2);
    g1.add_edge(4,2);
    g1.add_edge(1,4);
    g1.add_edge(1,3);
    g1.print();

    return 0;
}
