/*
Jotony Guerra
CS 302
Assignment 04
*/
#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;
mutex tLock;
void multiply(int, vector<short>, vector<short>);
//will use threads to multiply two vector numbers in parallel;
vector<vector<short>> partialResult;
vector<short> number1;
vector<short> number2;

void reverse(string str) 
{ 
   for (int i=str.length()-1; i>=0; i--) 
      cout << str[i];  
} 
//Parallel Multiplication
int main() {
    string input1, input2;
    unsigned long long  answer;
    vector<short> finalAnswer;
    //vector<short> number2;
    vector <short> r;
   // vector<vector<short>> partialResult;

    int maxThreads = thread::hardware_concurrency(); //max threads that can run on this system at the same time
    vector<thread> threadPool;

    //Get User input
    cout << "Enter number1: ";
    cin >> input1;
   // cout << "input: " << input1 << endl;

    size_t len = input1.size();

    //number1.reserve(len);

    for(int i = 0; i <= len-1; i++) {
        number1.push_back(input1[i] - '0');
    }

    // for(size_t i = 0; i < len; ++i) {
    //     cout << number1[i];
    // }

    //loop displays content of vector.
    cout<< endl;
    cout << "Enter number2: ";
    cin >> input2;

    size_t len2 = input2.size();
    for(int i =0; i <= len2-1; i++) {
        number2.push_back(input2[i] - '0');
    }
    cout<< endl;
    
    //cout <<"number 2 size: " << number2.size() << endl;
    int size = number2.size();
    for (int i=number2.size() ; i > 0; i--) //i needs to equal number of digits of number2? or maxthreads 
    {
        //spawn a thread to multiply digit to number1; 
        /*Thread does multiplication of last number of number2 to all the numbers in number1 How to store result in partialResult??? */
        //cout << "Number2[i]: " << number2[i-1] << endl;
		//threadPool.push_back(thread(multiply, number2[i ], number1));
		threadPool.push_back(thread(multiply, i-1, number1, number2));
       
		//if we spawned the max amount of threads that this system can handle
		//we wait for all of them to finish before we spawn more threads
        if (threadPool.size() == maxThreads) //|| threadPool.size() == number2.size())
        {
            for (int j=0; j < threadPool.size(); j++)
            {  threadPool[j].join();}
            threadPool.clear();
        }
        //number2.pop_back();
    }

    for (int i = 0; i < threadPool.size(); i++)
		threadPool[i].join();

	threadPool.clear();
    answer = 0;
    string s;

    for (auto i = 0; i != partialResult.size(); i++)
    {
        for (auto j = 0; j != partialResult[i].size(); ++j)
        {
            answer += partialResult[i][j];
            s = s + to_string( partialResult[i][j]);
           // cout << partialResult[i][j]; //<< " " << endl;
        }
       
    }

    // reverse(s.begin(), s.end()); 

    // int i = s.size() - 1; 
    // while (i>=0 && s[i] == '0') 
    // i--; 
    
    cout << "Product: ";
    reverse(s);
    cout << endl;
    // for (int i = 0; i <= output.size(); i++) {
    //     cout << output[i];
    // }
    //n1 = 345867
    //n2 = 000837
    //thread 3 4 5 8 6 7                                                         tLock.lock();
    //assigned 7     multiply thread by 7   -----> store in vector <short> r ---> partialResults.push_back(r);
                                                                                //tLock.unlock();
    // thread 345867
    // assigned 3           -----> store in vector <short> r---> partialResults.push_back(r);

    // thread 345867
    // assigned 8     -----> store in vector <short> r ---> partialResults.push_back(r); NEED TO KEEP TRACK OF POSITION

    return 0;
}


void multiply(int n, vector<short>v1, vector<short> v2) 
{
    //unsigned long long  carry, zeroes; //result;
    //vector <short> r;
    int len1 = v1.size();
    int len2 = v2.size();
    int carry;
    //keep result number in vector in reverse order ?
    vector<short> result(len1 + len2, 0); 
    int i_n1 = 0;  
    int i_n2 = 0; 

    for (int i=len1-1; i>=0; i--) 
    {
        carry = 0;
        short n1= v1[i];
        i_n2 = 0;
        int sum = n1 * v2[n] + result[i_n1 + i_n2] + carry;
        carry = sum/10;
        result[i_n1 + i_n2] = sum % 10;
        if (carry > 0) 
        { result[i_n1 + i_n2 + 1] += carry;}
        
        i_n1++;
    }

    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
    

    
    // for (int i=0; i < v1.size(); i++)
    // {
    //     if (v2[n] == 1)
    //     {
    //         result =
    //     }

    //     result += v1[i] * v2[n];
           
    // }
    // cout << "result: " << result << endl;
  
    //   if (v1.size() > 1) {
    //         result = result * (10 * (v1.size()-1));
    //    }
    // // if (n > 0 && result == 0) {
    // //     result = 1 * (10 * n);
    // // } else 
    // if (n > 0)
    // {
    //     result = result * (10*n);
    // }
    //r.push_back(result);
    //r.push_back(digit)
    tLock.lock();
    partialResult.push_back(result);
    tLock.unlock();
    return;
}

