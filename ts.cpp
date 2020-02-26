#include <iostream>
using namespace std;

int main(){
    cout << "Stay with me" << endl;

    int total[2][3] = {
        {3,4,6},
        {1,2,3}
    };

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cout << "some " << total[i][j] << endl;
        }
    }


}
