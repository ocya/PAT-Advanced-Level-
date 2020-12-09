#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){

    int N, K;
    scanf( "%d %d", &N, &K );
    int courseIndex, studentCount;
    map<string, vector<int>> registeredCourseIndex;
    char studentName[5];
    string strStudentName;
    for( int i = 0; i < K; i++ ){
        scanf( "%d %d", &courseIndex, &studentCount );
        for( int j = 0; j < studentCount; j++ ){
            scanf( "%s", studentName );
            strStudentName.assign( studentName ); 
            registeredCourseIndex[strStudentName].push_back( courseIndex );
        }
    }
    char queryStudentName[5];
    string strQueryStudentName;
    vector<int> courseList;
    for( int i = 0; i < N; i++ ){
        scanf( "%s", queryStudentName );
        strQueryStudentName.assign( queryStudentName );
        courseList = registeredCourseIndex[strQueryStudentName];
        sort( courseList.begin(), courseList.end() );
        printf( "%s %d", queryStudentName, courseList.size() );
        for( int j = 0; j < courseList.size(); j++ )
            printf( " %d", courseList[j] );
        printf( "\n" );
    }

    return 0;
}



