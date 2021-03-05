#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


//Write a program to find 2 unique numbers in an array where all numbers except two, are present twice.

/* Logic
1. Take XOR of all the elements and let that xor value be x. All the repeating
elements will get nullified and xor of only two unique elements will last. (as
a⊕a = 0).
2. There will be at least one bit set in x. Using that set bit, divide the original
set of numbers into two sets
a. First set which contains all the elements with that bit set.
b. Second set which contains all the elements with that bit unset.
3. Take xor of both the sets individually, and let those xor values be x1 and x2.
4. Voila, x1 and x2 are our unique numbers. Reason: both the above sets
contain one of the unique elements and rest elements of the sets occur
twice which will get nullified after ⊕ operation. */

int setBit(int n, int pos ){
    return ((n & (1<<pos)) != 0);
}

void unique(int arr[], int n){

    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos-1))
        {
            newxor = newxor ^ arr[i];
        }
        
    }

    cout<<newxor<<endl;
    cout<<(tempxor ^ newxor) <<endl;
    
    
    
}

int main(){
    int arr[] = {1, 2, 3, 5, 1, 2, 3, 7};

    unique(arr, 8);


    return 0;
}