#include <iostream>
#include <queue>
using namespace std;

queue<int> sortqueue(queue<int> &q)
{

    int prevMin = INT_MIN;
    int s = q.size();
    int cs = 0;
    for (int j = 1; j <= s; j++)
    {
        int min = INT_MAX;
        int i = 1;
        while (i <= s)
        {
            int curr = q.front();
            if (curr < min && curr > prevMin)
            {
                min = curr;
            }
            q.pop();
            q.push(curr);
            i++;
        }

        int k=1;
        while(k<=cs){
            q.push(q.front());
            q.pop();
            k++;
        }
        
        q.push(min);
        prevMin = min;
        cs++;
    }

    int i=1;
    while(i<=s){
        q.pop();
        i++;
    }

    return q;
}

int main(){

    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    queue<int> res = sortqueue(q);

    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }
}