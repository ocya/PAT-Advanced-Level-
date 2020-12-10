#include <iostream>

using namespace std;

int Count[10001], Index[100001];

int main() {

    int N;
    scanf( "%d", &N );

    int value;
    for( int i = 0; i < N; i++ ){
        scanf( "%d", &value );
        Count[value] += 1;
        Index[i] = value;
    }
    bool isExistWinner = false;
    for( int i = 0; i < N; i++ ){
        if( Count[ Index[i] ] == 1 ){
            cout << Index[i];
            isExistWinner = true;
            break;
        }
    }
    if( !isExistWinner )
        cout << "None";

    return 0;
}
