#include "weighted_graph.h"
#include<vector>
#include<set>


void dijkstraAlgo(WeightedGraph g, int i){
    vector<int> dist(g.v,INT16_MAX);
    set<pair<int,int>> s;

    dist[i]=0;
    s.insert({dist[i],i});

    while(!s.empty()){

        auto it = s.begin();
        int currDist = it->first;
        int currNode = it->second;
        s.erase(it);

        for(auto j : g.l[currNode]){
            int newDist = currDist + j.first;
            if(newDist < dist[j.second]){

                /*if the neighbour pair is present,
                 then we need updated entry for this pair in set via delete and insert operation */
                auto it = s.find({dist[j.second], j.second});
                if(it != s.end()){
                    s.erase(it);
                }
                dist[j.second] = newDist;
                s.insert({dist[j.second], j.second});
            }
        }
    }

    for(int j=0; j<dist.size(); j++){
        cout<<"Node "<<j<<" is at distance "<<dist[j]<<" from node "<<i<<endl;
    }
}

int main(){

    WeightedGraph g(5);

    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(1,2,1);
    g.addEdge(2,3,2);
    g.addEdge(3,4,3);

    g.print();

    dijkstraAlgo(g,0);

}