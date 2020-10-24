#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Node{
    string Id, Name;
    int Grade;
};

bool Compare1( Node Stu1, Node Stu2 ){
    return Stu1.Id < Stu2.Id;
}

bool Compare2( Node Stu1, Node Stu2 ){
    if( Stu1.Name ==  Stu2.Name)
        return Stu1.Id < Stu2.Id;
    return 
        Stu1.Name < Stu2.Name;
}

bool Compare3( Node Stu1, Node Stu2 ){
    if( Stu1.Grade == Stu2.Grade )
            return Stu1.Id < Stu2.Id;
    else
        return Stu1.Grade < Stu2.Grade;
}


int main( int argc, const char *argv[] ){

    int N, C;
    cin >> N >> C;
    vector<Node> StudentInfo( N );
    for( int i = 0; i < N; i++ ){
        cin >> StudentInfo[i].Id >> StudentInfo[i].Name >> StudentInfo[i].Grade;
    }
    switch( C ){
        case 1: sort( StudentInfo.begin(), StudentInfo.end(), Compare1); break;
        case 2: sort( StudentInfo.begin(), StudentInfo.end(), Compare2); break;
        case 3: sort( StudentInfo.begin(), StudentInfo.end(), Compare3); break;
    }
    for( int i = 0; i < N; i++ ){
        cout << StudentInfo[i].Id << ' ' << StudentInfo[i].Name << ' ' << StudentInfo[i].Grade << endl;
    }
    
    return 0;
}





