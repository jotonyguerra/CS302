#include <iostream>
#include <cstdlib>

using namespace std;


//Recursive Function 
void printStarsUtil(int num) {
    if (num < 1)
    {
        return;
    }
    cout << "* ";
    printStarsUtil(num-1);
}


void printStarsIncreasing(int num) {
    if (num < 1)
    {
        return;
    }
    printStarsIncreasing(num - 1);
    cout << endl;
    printStarsUtil(num);
}

void printStarsDecreasing(int number) {
    
    if (number < 1)
    {
        return;
    }
    
    printStarsUtil(number);
    cout << endl;
    printStarsDecreasing(number-1);
}

bool isPalindrome(string str) {
    if (str == ""){
        return true;
    }

    if (str.length() == 1 ) {
        return true;
    }

    if (str[0] != str[str.length() - 1]) {
        return false;
    }
    str = str.substr(1, str.length()-2);
    isPalindrome(str);
}

//Recursive Function that checks if the digits of a number is increasing from left to right;
//Paramaters: unsigned long long num;
//Returns boolean true or false;
bool increasingDigits(unsigned long long num) {
    //. but should be recursive

    //base case
    if (num < 10) {
        return true;
    }

    int rem = num % 10; //remainder
    int temp = num / 10;
    int second = temp % 10; // second to last digit.

    if (second <= rem) {
      return increasingDigits(num/10);
    } else if (second > rem){
        return false;
    }

    
}
//Main function to test recursive functions
int main() 
{
    //variable declarations
    int width;
    bool loop = false;
    int number; 
    string palindrome;
    //Gather user input for width
    cout << "Enter the width: "; 
    cin >> width;

    //set bool flag for while loop
    //checking user input
    if (!cin or width <= 0)
    {
        loop = false;
    } else {
        loop = true;
    }

    //loop to error check input
    while (!loop)
    { 
        cin.clear();
        cin.ignore(1000,'\n');
        //clear input stream
        cout << "Seriously?, Wow!" << endl;
        cout << "Enter the width: " << endl;
        cin >> width;

        if(width <= 0){
            loop = false;
        } else if (width > 0){
            loop = true;
        }
    }

    //Call recursive functions to print out stars
    printStarsIncreasing(width);
    cout<<endl;
    printStarsDecreasing(width);

    //Palindrome checker
    cout << endl;
    cout << "Ok hopefully that worked" << endl;
    cout << "Enter a string: ";
    cin >> palindrome;

    //Call bool function to check if string is a palindrome and 
    //upon the return bool return a string.
    if (isPalindrome(palindrome) == true) {
        cout << palindrome << " is a palindrome, nicely done" << endl;
    } else {
        cout << palindrome << " is not a palindrome" << endl;
    }

    cout << "Hopefully we are still doing alright, last part" << endl;
    cout << "Enter a number: ";
    cin >> number;
    cout << endl;


    if (increasingDigits(number) == true) {
         cout << "looks the digits are increasing from left to right" << endl;
    } else if (increasingDigits(number) == false)  {
        cout << "Digits do not increase from left to right, oh well";
    }

    return 0;
}


