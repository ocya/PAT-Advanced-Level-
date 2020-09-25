#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char *argv[] ){

    int A, B;
    cin >> A >> B;
    int C = A + B;
    if( C < 0 ){
        cout << '-';
        C = -C;
    } 
    string S = to_string( C );
    int len = S.length();
    for( int i = 0; i < len ; i++ ){
        cout << S[i];
        if( (i+1)%3 == len%3 && i != len - 1 ) cout << ',';
    }

    return 0;
}
