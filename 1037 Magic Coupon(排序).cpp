#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ComparePositive( int A, int B );
bool CompareNegative( int A, int B );
int main( int argc, const char *argv[] ){

    int N1, N2;
    cin >> N1;
    vector<int> CouponsPositive, CouponsNegative;
    int tempDate;
    for( int i = 0; i < N1; i++ ){
        cin >> tempDate;
        if( tempDate > 0 ) CouponsPositive.push_back( tempDate );
        else if( tempDate < 0 ) CouponsNegative.push_back( tempDate );
    }
    cin >> N2;
    vector<int> ProductsPositive, ProductsNegative;
    for( int i = 0; i < N2; i++ ){
        cin >> tempDate;
        if( tempDate > 0 ) ProductsPositive.push_back( tempDate );
        else if( tempDate < 0 ) ProductsNegative.push_back( tempDate );
    }
    
    sort( CouponsPositive.begin(), CouponsPositive.end(), ComparePositive );
    sort( ProductsPositive.begin(), ProductsPositive.end(), ComparePositive );
    sort( CouponsNegative.begin(), CouponsNegative.end(), CompareNegative );
    sort( ProductsNegative.begin(), ProductsNegative.end(), CompareNegative );

    int Positive = min( CouponsPositive.size(), ProductsPositive.size() );
    int Negative = min( CouponsNegative.size(), ProductsNegative.size() );

    int MaxValue = 0;
    if( Positive != 0 || Negative != 0 ){
        for( int i = 0; i < Positive; i++ ){
            MaxValue += CouponsPositive[i] * ProductsPositive[i];
        }
        for( int i = 0; i < Negative; i++ ){
            MaxValue += CouponsNegative[i] * ProductsNegative[i];
        }
    }
    cout << MaxValue;

    return 0;
}

bool ComparePositive( int A, int B ){
    return A > B;
}
bool CompareNegative( int A, int B ){
    return A < B;
}
