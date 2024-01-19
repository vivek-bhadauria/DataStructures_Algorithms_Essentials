#include "graph.h"
#include<vector>
#include<queue>
#include<stack>

void setUpIndegrees(vector<int> &indegree, Graph g){

    for(int i=0; i<g.v; i++){
        for(auto x : g.l[i]){
            indegree[x]++;
        }
    }
}

void topologicalSortBfs(Graph g){
    vector<int> indegree(g.v,0);
    queue<int> q;

    setUpIndegrees(indegree, g);

    for(int i=0; i<g.v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    cout<<"Topological sort with BFS : ";
    while(!q.empty()){

        /*process node*/
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();

        for(auto x : g.l[curr]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    cout<<endl;
}

void topologicalSortDfs(Graph g){

    vector<int> indegree(g.v,0);
    stack<int> stk;

    setUpIndegrees(indegree, g);

    for(int i =0; i<g.v; i++){
        if(indegree[i] == 0){
            stk.push(i);
        }
    }

    cout<<"Topological sort with DFS : ";
    while(!stk.empty()){

        /*process node*/
        int curr = stk.top();
        cout<<curr<<" ";
        stk.pop();

        for(auto x : g.l[curr]){
            indegree[x]--;
            if(indegree[x] == 0){
                stk.push(x);
            }
        }
    }
    cout<<endl;
}

void dfsHelper(int i, vector<int> &indegree, vector<bool> &processed, Graph g){

    if(!processed[i]){
        cout<<i<<" ";
        processed[i] = true;
    }

    for(auto x : g.l[i]){
        indegree[x]--;
        if(indegree[x] == 0){
            dfsHelper(x,indegree,processed,g);
        }
    }
}

void topologicalSortDfsRecursive(Graph g){
    vector<int> indegree(g.v,0);
    vector<bool> processed(g.v,false);
    setUpIndegrees(indegree,g);

    cout<<"Topological sort with Recursive DFS : ";
    for(int i=0; i<g.v; i++){
        if(indegree[i] == 0){
            dfsHelper(i,indegree,processed,g);
        }
    }
    cout<<endl;

}

int main(){

    Graph g(6);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.print();

    topologicalSortBfs(g);
    topologicalSortDfs(g);
    topologicalSortDfsRecursive(g);
}