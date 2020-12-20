#include <iostream>

using  namespace std;
int main( int argc, const char *argv[] ){

    int N, now, left, right, a = 1, sum = 0;
    cin >> N;
    while( N / a ){
        left = N / ( a * 10 ); now = N / a % 10; right = N % a;
        if( now == 0 ) sum += left * a;
        else if( now  == 1 ) sum += left * a +  right + 1;
        else sum += ( left + 1) * a;
        a *= 10;
    }
    cout << sum;

}
