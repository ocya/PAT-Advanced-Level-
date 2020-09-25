#include <iostream>
#include <vector>

#define MaxSize 1001

using namespace std;


int main( int argc, const char *argv[] ){

    int K1, K2;
    vector<double> APolynomial( MaxSize, 0 );
    int Exponent;
    double Coefficient;
    cin >> K1;
    for( int i = 0; i < K1; i++ ){
        scanf( "%d %lf", &Exponent, &Coefficient );
        APolynomial[Exponent] = Coefficient;
    }
    

    cin >> K2;
    for( int i = 0; i < K2; i++ ){
        scanf( "%d %lf", &Exponent, &Coefficient );
        APolynomial[Exponent] += Coefficient ;
    }    
    int Count = 0;
    vector<int> Ans;
    for( int i = MaxSize-1; i >= 0; i-- ){
        if( APolynomial[i] != 0 ){
            Ans.push_back( i );
            Count++;
        }
    }
    cout << Count;
    for( int i = 0; i < Ans.size(); i++ )
        printf( " %d %.1lf", Ans[i], APolynomial[ Ans[i] ]);

    return 0;
}
