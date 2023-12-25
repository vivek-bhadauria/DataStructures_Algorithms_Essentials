#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Pair
{
public:
    int pos;
    int score;
};

class PairCompare
{
public:
    bool operator()(Pair a, Pair b)
    {
        return a.score < b.score;
    }
};

string get_rank_description(int rank_num)
{

    if (rank_num == 1)
    {
        return "Gold Medal";
    }
    else if (rank_num == 2)
    {
        return "Silver Medal";
    }
    else if (rank_num == 3)
    {
        return "Bronze Medal";
    }
    return to_string(rank_num);
}

vector<string> findRelativeRanks(vector<int> &score)
{

    vector<string> ranks(score.size(), "0");
    priority_queue<Pair, vector<Pair>, PairCompare> max_heap;

    for (int i = 0; i < score.size(); i++)
    {
        Pair pair;
        pair.pos = i;
        pair.score = score[i];
        max_heap.push(pair);
    }

    int rank = 1;
    while (!max_heap.empty())
    {
        /*cout<<" Score : "<<max_heap.top().score<<", Pos : "<<max_heap.top().pos<<" Rank : "<<rank<<endl;*/
        ranks[max_heap.top().pos] = get_rank_description(rank);
        rank++;
        max_heap.pop();
    }

    return ranks;
}

void printVector(vector<string> v)
{

    cout << endl;
    for (string val : v)
    {
        cout << val << ", ";
    }
    cout << endl;
}

int main(){

    vector<int> score = {5,4,3,2,1};
    vector<string> res = findRelativeRanks(score);
    printVector(res);

}