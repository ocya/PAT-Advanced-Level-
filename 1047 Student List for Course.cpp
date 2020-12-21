#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> studentName( 40001 );
vector<vector<int>> course( 2501 );


int main( int argc, const char *argv[] ){

    int N, K;
    cin >> N >> K;
    string name;
    char chName[5];
    int C;
    int idx;
    for( int i = 0; i < N; i++ ){
        scanf( "%s %d", chName, &C );  
        studentName[i] =  string( chName ) ;
        for( int j = 0; j < C; j++ ){
            scanf( "%d", &idx );
            course[idx].push_back( i );
        }
    }

    vector<string> selectedStudent;
    for( int i = 1; i <= K; i++ ){
        for( int j = 0; j < course[i].size(); j++ )
            selectedStudent.push_back( studentName[course[i][j]] );
        sort( selectedStudent.begin(), selectedStudent.end() );
        printf( "%d %d\n",i, course[i].size() );
        
        for( int k = 0; k < selectedStudent.size(); k++ )
            printf( "%s\n", selectedStudent[k].c_str() );           
        selectedStudent.clear();
    }

    return 0;
}
