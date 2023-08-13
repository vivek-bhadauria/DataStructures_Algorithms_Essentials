#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool duplicateParenthesis(string str)
{
    /*
    Intuition based on the observation was that
    if top of stack is '(' when current element is ')' ==> duplicate bracket exists
    Pushing and popping from stack is performed as below
    we use a stack and we keep on pushing each element until ')' is received
    at which point we keep popping elements from stack until the first ')' is received 
    */

    stack<char> stk;

    for (int i = 0; i < str.length(); i++)
    {

        if (!stk.empty() && stk.top() == '(' && str.at(i) == ')')
        {
            return true;
        }
        else if (str.at(i) == ')')
        {
            while (stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            stk.push(str.at(i));
        }
    }

    return false;
}

int main(){

    string str1 = "((a+b)+((c+d)))";
    bool res1 = duplicateParenthesis(str1);
    cout<<"duplicate parenthesis exist for "<<str1<<" : "<<res1<<endl;

    string str2 = "(((a+(b)))+(c+d))";
    bool res2 = duplicateParenthesis(str2);
    cout<<"duplicate parenthesis exist for "<<str2<<" : "<<res2<<endl;

}