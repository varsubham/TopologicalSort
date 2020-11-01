// Topological sort 
// This program will tell you how to dress like a man 😁

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;


class Graph{
    public:
        unordered_map<string, list<string>> um;
        
        // For Topological Sort
        // A parent hashmap to store parent and child relation
        unordered_map<string, string> parent;
        
        // linked list to inserted vertex in front
        list<string> topo;
        
        // Create a graph by adding edges
        void addEdges(string x, string y){
            
            um[x].push_back(y);
            
        }
        void addEdges(string x){
            // only one vertex is getting added
            um[x].push_back("");

        }
        
        // Recurisevly visit all the nodes rechable from 'vertex'
        void dfs_visit(list<string> adj, string vertex){
            for(string i : adj){
                if(parent.find(i) == parent.end()){
                    parent[i] = vertex;
                    dfs_visit(um[i], i);
                }
            }
            topo.push_front(vertex);
        }

        // visit all the vertices given in vector v
        void dfs(vector<string> v){
            
            for(string i : v){
                if(parent.find(i) == parent.end()){
                    parent[i] = "";
                    dfs_visit(um[i], i);
                }
            }
        }

        // print topological sort
        void topolo_sort(vector<string> v){ 
            
            // running dfs on all the vertices
            dfs(v);

            // printing vertices in topological sort order
            for(string i : topo){
                if(i == "") continue;
                cout << i << "-->";
            }
            cout << endl;
        }
        
};

int main(){
    
    Graph gp;
    
    // creating the graph
    gp.addEdges("socks", "shoes");
    gp.addEdges("pants", "belt");
    gp.addEdges("pants", "shoes");
    gp.addEdges("shirt", "belt");
    gp.addEdges("shirt", "tie");
    gp.addEdges("tie", "coat");
    gp.addEdges("belt", "coat");
    gp.addEdges("watch");
    

    // vector of all the vertices that we have added above
    // order of this doesn't matter
    vector<string> vt = {"pants", "watch", "socks", "shoes", "belt", "shirt", "tie", "coat"};
    
    // topological sort function
    gp.topolo_sort(vt);
}