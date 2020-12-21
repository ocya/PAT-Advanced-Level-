#include <iostream>
#include <vector>

using namespace std;

int main( int argc, const char *argv[] ){

    int N, M;
    cin >> N >> M;
    vector<int> Value( 1001 );
    int valueIndex;

    for( int i = 0; i < N; i++ ){
        scanf( "%d", &valueIndex );
        Value[valueIndex]++;

    }
    bool isFind = false;
    int Left, Right;
    for( int i = 1; i <= 1001; i++ ){
        Left = i; Right = M - i;
        if( Right > 0 ){
            if( (Left == Right && Value[Left] > 1) || ( Left != Right && Value[Left] > 0 && Value[Right] > 0 )  ){
                isFind = true;
                cout << Left << ' ' << Right;
                break;
            }
        }
    }
    if( !isFind )
        cout << "No Solution";

    return 0;
}
