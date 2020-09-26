#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int main( int argc, const char *argv[] ){
    
    string S;
    vector<string> ValueMap{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    getline( cin, S );
    int Sum = 0;
    stack<int> Stk;
    for( int i = 0; i < S.length(); i++ )
        Sum += S[i] - '0';
    if( Sum == 0 ){
        cout << "zero";
    }else{
        while( Sum ){
            Stk.push( Sum%10 );
            Sum /= 10;
        }
        cout << ValueMap[ Stk.top() ]; Stk.pop();
        while( !Stk.empty() ){
            cout << ' ' << ValueMap[ Stk.top() ]; Stk.pop();
        }
    }


    return 0;


}



 
