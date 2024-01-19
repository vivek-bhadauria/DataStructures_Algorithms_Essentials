#include<iostream>
#include<list>
using namespace std;

class Graph{
    public:
        int v;
        list<int> *l;

        Graph(int v){
            this->v = v;
            l = new list<int>[v];
        }

        void addEdge(int i, int j, bool dir=true){
            l[i].push_back(j);
            if(!dir){
                l[j].push_back(i);
            }
        }

        void print(){
            for(int i=0; i<v; i++){
                cout<<i<<"-->";
                for(auto x : l[i]){
                    cout<<x<<",";
                }
                cout<<endl;
            }
        }

};