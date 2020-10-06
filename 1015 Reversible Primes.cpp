#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int Convert( int N, int D );
bool isPrime( int N );

int main( int argc, const char *argv[] ){

    int N, D;
 
    while( 1 ){
        scanf( "%d", &N );
        if( N < 0 ) break;
        scanf( "%d", &D );
        getchar();
        if( isPrime( N ) && isPrime( Convert( N, D ) ) )
            printf( "Yes\n");
        else
            printf( "No\n");
    }
    
    return 0;
}

int Convert( int N, int D ){
    string S;
    while( N != 0 ){
        S += to_string( N % D );
        N /= D;
    }

    reverse( S.begin(), S.end() );
    int Value = 0;
    int Temp;
    for( int i = 0; i < S.length(); i++ ){
        Temp = S[i] - '0';
        Value += Temp * pow( D, i );
    }
    return Value;
}

bool isPrime( int N ){
    if( N <= 1 ) return false;
    for( int i = sqrt( N ); i > 1; i-- ){
        if( N % i == 0 ) 
            return false;
    }
    return true;
}
