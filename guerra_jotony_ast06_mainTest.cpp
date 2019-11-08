#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>    // std::sort
#include "guerra_jotony_ast06.h"

using namespace std; 
//using brute forces from geeksforgeeks
int bruteForce(int S[], int n) 
{ 
    bool found = false; 
  
    // sort the array in 
    // ascending order 
    sort(S, S + n); 
  
    // iterating from backwards to  
    // find the required largest d 
    for (int i = n - 1; i >= 0; i--)  
    { 
        for (int j = 0; j < n; j++)  
        { 
  
            // since all four a, b, c,  
            // d should be distinct 
            if (i == j) 
                continue; 
  
            for (int k = j + 1; k < n; k++)  
            { 
                if (i == k) 
                    continue; 
  
                for (int l = k + 1; l < n; l++)  
                { 
                    if (i == l) 
                        continue; 
  
                    // if the current combination   
                    // of j, k, l in the set is  
                    // equal to S[i] return this  
                    // value as this would be the  
                    // largest d since we are 
                    //  iterating in descending order  
                    if (S[i] == S[j] + S[k] + S[l]) 
                    { 
                        found = true; 
                        return S[i]; 
                    } 
                } 
            } 
        } 
    } 
    if (found == false) 
        return 0; 
} 

int main(){
    ifstream infile;
    string fileName;
    int size;
    int input;
    
    cout<< "enter input file: ";
    cin >> fileName;
    infile.open(fileName.c_str());
    
    while(!infile.is_open()){
		cout << "file not found!" << endl;
		cout << endl;
		cout << "renter input file name: ";
		cin >> fileName;
		
		infile.open(fileName.c_str());
	}
    myHash <int, bool> * map;
    infile >> size;
    
    while(size != 0){
		map = new myHash<int, bool>();
		int * arr = NULL;
		arr = new int[size];
		for(int i = 0; i < size; i++) {
			infile >> input;
			(*map)[input] = true;
			arr[i] = input;
		}
		int d = bruteForce(arr, size);
		
		if(d==0){
			cout<<"No solution" << endl;
		}else if ((*map)[d]==true) {
			cout << d << endl;}
		delete [] arr;
		arr = NULL;
		delete map;
		map = NULL;
		infile >> size; //get new size 
	}
    
    infile.close(); //Closes file 
    
    return 0;
}

