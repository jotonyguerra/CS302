#include <iostream>
#include <fstream>
#include <string>
#include "guerra_jotony_ast02.cpp"

using namespace std;
/*
Jotony Guerra
Assignment 2
CS302 1004
*/
int main()
{
    ifstream inFile;
    string file;
    int num;
    LL<int> list;
    LL<int>::iterator it, it1, it2, it3;

    cout << "Enter input file: ";
    cin >> file;
    inFile.open(file.c_str());

    //if file is not open. get new file name.
    while (!inFile.is_open())
    {
        cin.clear();
        cout << "Please enter input file: ";
        cin >> file;
        inFile.open(file.c_str());
    }

    //read in data from file.
    while (!inFile.eof())
    {
        inFile >> num;
        if (inFile.eof())
            break;
        //cout << num << endl;
        list.headInsert(num);

    }
    
    //You may need more iterators
    // Assuming you inserted nodes into the list at some point
    // this loop starts the iterator by setting it to the front of the linked list
    // the loop will keep running as long as the iterator hasn ’t reached the last node
    // it will move to the next node each time

    inFile.close();
    int max = -1;
    //int count = 0;
    //int countInner = 0;
    it1 = list.begin();
    it2= list.begin();    
    for(it3 = list.end(); it3 != it2; it3--)
    {
        countInner++;
        
        for(it1 = list.begin(); it1 != it3; it1++) 
        {
            max = -1;
            LL<int>::iterator temp;
            if (max < *it1) {
                max = *it1;
               // it2 = it1;
                temp = it1;
               
            }
            
            if (max > *it3)
            {
                list.update(temp, *it3); //put value of last node into temp
                list.update(it3, max); // put value of max into it3 node // last node
                list.update(it1, *temp); //put 
            }
            /*
                list.update(temp, *it3); //put value of last node into temp
             list.update(it3, max); // put value of max into it3 node // last node
                list.update(it1, *temp); //put 
            else {
                break;
            }
            */
            //count++;
            /*
            list.update(temp, *it3); //put value of last node into temp
            list.update(it3, max); // put value of max into it3 node // last node
            list.update(it1, *temp); //put */
            //list.update(temp, )
        }
    }
    //Code around to get the least number
    it1--;
    list.update(it1, *it2);
    
    //outputs List
    for (it = list.begin(); it != list.end(); )
    {
        //code around to get the least/1st number of list
        if (it == list.begin()) {
            cout << *it1 << endl;
        }
        it++;
        cout << *it << endl; // outputs the value in the node that it points to
    }
   
    return 0;
}
