#include <cstdlib>
#include <iostream>
using namespace std;

template <class Type1, class Type2>
class myHash
{
public:
    myHash();
    myHash(const myHash<Type1, Type2> &);
    const myHash<Type1, Type2> &operator=(const myHash<Type1, Type2> &);
    ~myHash();
    Type2 &operator[](Type1);

private:
    size_t hashFunction(int) const;

    struct entry
    {
        Type1 key;
        Type2 item;
    };

    struct tableItem
    {
        size_t amount;
        size_t capacity;
        entry *list;
    };

    //dynamic array that holds the hash
    tableItem *table;
    size_t capacity;
};

// is the default constructor that sets capacity to 10, allocates an array of length 10 to table
// field, and sets table[i].capacity to 5, table[i].amount to 0, and table[i].list to an array of
// type entry of size table[i].capacity
template <class Type1, class Type2>
myHash<Type1, Type2>::myHash()
{
    capacity = 10;
    //int table = new int[10];
    for (int i = 0; i < capacity; i++)
    {
        table[i].capacity = 5;
        table[i].amount = 0;
        table[i].list = new entry[table[i].capacity]; //list[5]; //maybe need temp array? idk mang
    }
}

// myHash(const myHash<Type1, Type2>& copy) is the copy constructor, performs a deep copy of the
// object passed into the constructor
template <class Type1, class Type2>
myHash<Type1, Type2>::myHash(const myHash<Type1, Type2> &copy)
{
    *this = copy;
}

// is the assignment
// operator, performs a deep copy of the rhs object into the left side object (i.e. the object that calls this
// operator function), make sure to avoid potential memory leaks here
template <class Type1, class Type2>
const myHash<Type1, Type2> &myHash<Type1, Type2>::operator=(const myHash<Type1, Type2> &rhs)
{
    if (this == &rhs)
        return *this;

    for (int i = 0; i < capacity; i++)
    {
        delete[] this.list;
    }

    delete[] this;
    myHash();
    *this = rhs; 
    //*this = rhs; 
    // return the existing object so we can chain this operator
    return *this;
}

template <class Type1, class Type2>
myHash<Type1, Type2>::~myHash()
{
    //delete myHash;
    for (int i = 0; i < capacity; i++)
    {
        delete[] table[i].list;
    }

    delete[] table;
}

// overloads the array bracket operator, this function calls the
// hashFunction(key) and returns an index value (let’s call it x), then you search table[x].list array
// for a matching key, if found then return that entry’s item field, if not found, then create the entry into
// table[x].list at the appropriate position and return that entry’s item field (it will contain some
// default value, try Type2(0)), table[x].list must be a sorted list with respect to the key values, so
// when you search do not use a linear search and when inserting a new entry, make sure you add the
// entry such that the sorted order is maintained. After performing an insert, if table[x].list becomes
// full, resize it to 5 more items and update table[x].capacity and table[x].amount correctly after
// an insert.
//table[].list[].key
template <class Type1, class Type2>
Type2 &myHash<Type1, Type2>::operator[](Type1 key)
{
    int x = hashFunction(key);
    int index = -1;
    int r = table[x].capacity;
    int l = 0;
    //int mid = l + (r - l) / 2;
    if (r >= 1)
    {
        int mid = l + (r - l) / 2;
        if (table[x].list[mid].key == key)
        {
            index = mid;
            return table[x].list[mid].item;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (table[x].list[mid].key < key)
        {
            for (int i = mid; i < table[x].capacity; i++)
            {
                if (table[x].list[i].key == key)
                {
                    index = i;
                    return table[x].list[i].item;
                }
            }
        }
        if (table[x].list[mid].key > key)
        {
            for (int i = mid - 1; i > 0; i--)
            {
                if (table[x].list[i].key == key)
                {
                    index = i;
                    return table[x].list[i].item;
                }
            }
        }
    }
    //
    if (index < 0)
    {
        if (table[x].amount == table[x].capacity)
        {
            entry *temp = new entry[table[x].capacity + 5];
            table[x].capacity = table[x].capacity + 5;
            for (size_t i = 0; i < table[x].capacity - 5; i++)
            {
                temp[i] = table[x].list[i];
            } //deep copies the array.
            delete[] table[x].list;
            table[x].list = temp;
        }
        int amount = table[x].amount;
        table[x].list[amount].key = key;
        table[x].list[amount].item = Type2(0);
        table[x].amount++;

        //insetion sort going on 
        int iterator = 1;
        int j;
        //int array[1]; 
        for (int i = 1; i < table[x].list[amount].key; i++)
        {
            //array = table[x].list[i];
            j = i - 1;
            /* Move elements of arr[0..i-1], that are  
            greater than key, to one position ahead  
            of their current position */
            while (j >= 0 && table[x].list[j].key > table[x].list[i].key)
            {
                table[x].list[j + 1] = table[x].list[j];
                j = j - 1;
            }
            table[x].list[j + 1] = table[x].list[i];
        }
    }
    
    //redo search.... 
    r = table[x].capacity;
    l = 0;
    //int mid = l + (r - l) / 2;
    if (r >= 1)
    {
        int mid = l + (r - l) / 2;
        if (table[x].list[mid].key == key)
        {
            index = mid;
            return table[x].list[mid].item;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (table[x].list[mid].key < key)
        {
            for (int i = mid; i < table[x].capacity; i++)
            {
                if (table[x].list[i].key == key)
                {
                    index = i;
                    return table[x].list[i].item;
                }
            }
        }
        if (table[x].list[mid].key > key)
        {
            for (int i = mid - 1; i > 0; i--)
            {
                if (table[x].list[i].key == key)
                {
                    index = i;
                    return table[x].list[i].item;
                }
            }
        }
    }
}

// • size_t hashFunction(int key) const is the hash function that takes in a key value (in the form of
// an integer) and returns an index to be used to store/find items into table[index].list[j], the hash
// function is: sumOfDigitsOfKey % capacity. Warning: the key used could be negative!
template <class Type1, class Type2>
size_t myHash<Type1, Type2>::hashFunction(int key) const
{
    int num, sum, index;
    //int tempKey = key;
    num = key;
    sum = 0;

    //loop to get sumOfDigitsOfKey
    while (num != 0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }

    index = sum % capacity;
    if (index < 0)
    {
        index = index * -1;
    }
    return index;
}