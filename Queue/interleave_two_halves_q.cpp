#include<iostream>
#include<queue>
using namespace std;

queue<int> interLeave(queue<int> q){
    
    queue<int> q2;
    queue<int> qr;
    int s = q.size();
    int hs = s/2;
    int i=1;

    /* populate an intermediate q with the first half elements*/
    while(i<=hs){
      q2.push(q.front());
      q.pop();
      i++;
    }

    while(!q2.empty() && !q.empty()){
        /* add current first half element */
        qr.push(q2.front());
        /* add current second half element */
        qr.push(q.front());
        q2.pop();
        q.pop();
    }

    return qr;

}

int main(){

    queue<int> q;

    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    queue<int> res = interLeave(q);

    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }

}