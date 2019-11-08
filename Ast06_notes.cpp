struct entry 
{
    Type1 key;
    Type2 iteml

};

struct tableItem
{
    size_t capacity;
    size_t amount;
    entry * list;
    /* data */
};

size_t capacity;
tableItem * table; 

//modified chaining of hash
//each cell index has: capacity,amount,list[]. capacity = 5

myHash<int, bool> * map 
//key = int, item = bool; 
map = new myHash<int, bool>(); 
(* map)[10] = true; //i want to find key 10 in the hash structure
//then return address.

//USE BINARY SEACH OF SOME SORT TO FIND KEY.