#include <cstdlib>
#include <iostream>
#include <fstream>
#include "guerra_jotony_ast06.cpp"

int main(){

    string fileName;
    cout << "Enter input file: ";
    getline(cin, fileName);

    ifstream inFile;
    inFile.open(file); 
    int n; 
    int x;
    int * arr;
    bool flag = true;
    myHash<int, bool> * map; 

    while (flag){
    for (int i =0; i<n; i++) {
        cin >> x;
        if (x==0) {
           
            
        } else {
            (*map)[x] = true; 
        }
        }

    }
    inFile.close();
    return 0;
}