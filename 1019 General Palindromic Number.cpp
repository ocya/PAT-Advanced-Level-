#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main( int argc, const char *argv[] ){

    long int N, b;
    cin >> N >> b;
    vector<int> Convert;
    
    while( N != 0 ){
        Convert.push_back( N % b );
        N /= b;
    }
    vector<int> RevrseConvert( Convert );
    reverse( RevrseConvert.begin(), RevrseConvert.end() );
    if( RevrseConvert != Convert )
        cout << "No";
    else
        cout << "Yes";
    cout << endl;
    for( int i = 0; i < RevrseConvert.size(); i++ ){
        if( i != 0 ) cout << ' ';
        cout << RevrseConvert[i];
    }

    return 0;
}

