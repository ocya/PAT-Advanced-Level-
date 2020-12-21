#include <iostream>
#include <string>
#include <vector>

using  namespace std;
int main( int argc, const char *argv[] ){

    string S1, S2;
    getline( cin, S1 );
    getline( cin, S2 );
    vector<bool> isExist( 100, false );
    for( int i = 0; i < S2.length(); i++ ){
        isExist[ S2[i] ] = true;
    }
    string S;
    for( int i = 0; i < S1.length(); i++ ){
        if( !isExist[ S1[i] ] )
            S += S1[i];
    }

    cout << S;
}
