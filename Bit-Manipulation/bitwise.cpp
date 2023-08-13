#include<iostream>
using namespace std;

int getBinary(int n){

    /* Suppose we want to convert
       n = 9 i.e. 1001 to binary

    */

    int i=0; //This specifies current bit position
    int res=0;
    int power = 1;
    while(n!=0){

        int currentBit = n & 1;
        res = res + currentBit * power;
        n = n>>1;
        power = power * 10;
    } 

    return res;
    
}

void checkOddEven(int n){
     /*
      5 - 101
      1 - 001
      5&1 = 1 i.e. n&1==0 -> even else odd
     */

    if(n&1){
        cout<<n<<" is Odd"<<endl;
    }else{
        cout<<n<<" is Even"<<endl;
    }
}

int getIthBit(int n, int i){
    /*
     n = 9 -> 1001 ; here i can take values from 0 to 3

     Case 1 : suppose we want to do a get of 3rd bit answer should be 1
              if we do 1001
                     & 1000 we get 1000 i.e. not zero
     Case 2 : suppose we want to do a get of 2nd bit, answer should be 0
              if we do 1001
                     &  100 we get zero
    so we can say n & mask where mask is 1<<i is not zero then 1 else zero
    */

    int mask = 1<<i;
    int res = (n & mask) != 0 ? 1 : 0;
    return res;
}

void setIthBit(int &n, int i){

    /*
     suppose n is 9 i.e. 1001 so i an take values from 0 to 3
     suppose we want to set the 2nd bit to 1 then we shuld do the following
     if we do 1001
            | 0100 then result is 1101 which means we have effectively set the bit
     To create a mask of 0100 we can create it by doing 1<<2 i.e. 1<<i
    */
    
    int mask = 1<<i;
    n = n|mask;
}

void clearIthBit(int &n, int i){

    /*
    Suppose the numer is n = 13 i.e 1101, so  can take values from 0 to 3
    if we want to clear th 2nd bit we shall do the following
      1101
    & 1011 -> 1001
    here the mask is ~(1<<i) as 1011 can be got from 0100
    */
    int mask = ~(1<<i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int val){
    /*
      This is a combination of set and clear ith bits field
      There are below cases which come up
      1. Ith bit is 0 and update value is 0 - clearIthBit can work
      2. Ith bit is 0 and update value is 1 - setIthBit can work
      3. Ith bit is 1 and update value is 0 - clearIthBit can work
      4. Ith bit is 1 and update value is 1 - setIthBit can work

      or it can also be done in below manner
      suppose n = 12 i.e. 1100, so i can take value 0 to 3
      now suppose, you are asked to update 2nd bit
        1100
      | 0100

    */
    /*if(val&1){
        setIthBit(n,i);
    }else{
        clearIthBit(n,i);
    }*/
    
    clearIthBit(n,i);
    int mask = val<<i;
    n = n|mask;
}

void clearLastIbits(int &n, int i){
    /*
     suppose n = 15 i.e. 1111 so i can take value 1 to 4
     suppose we want to clear last 2 bits, so we can do something like
      1111
    & 1100
     the mask can be obtained as 1111<<2 i.e. 1111<<i
     1111 is ~(0)
     so mask is (~0)<<i;
    */
    int mask = (~0)<<i;
    n = n & mask;
}

void clearRangeOfBits(int &n, int i, int j){
    /*
    suppose n is 1101101 and we want to clear range of bits from
    i=2 to j=4
    we would need to do something like
      1101101
    & 1100011 -> 1100001    
    the mask 1100011 can be obtained as
             1100000 -> can be obtained by left shifting ~0<<(j+1)
            |0000011 -> can be obtained by left shifting i times ~0and then negating the result
    */
   int mask = (~0)<<(j+1) | ~((~0)<<i);
   n = n & mask;
}

void replaceBitsInRange(int &n, int i, int j, int val){

    /*
    suppose n = 127 i.e. 1111111, i and j can take values between 0 and 6 such that i<j
    suppose we are asked to place val 5 in index range
    i=2 and j=4
    clear the range first in the input n i.e. n becomes 1100011
    Now we need to do something like
     1100011
    |0010100 -> 1110111
    now we need to create mask 0010100
    which val left shifted i times

    */
   clearRangeOfBits(n,i,j);
   int mask = val<<i;
   n = n | mask;
}

void isPowerOfTwo(int n){

    if(n & (n-1)){
        cout<<n<<" is NOT a power of two"<<endl;
    }else{
        cout<<n<<" is a power of two"<<endl;
    }
}

int countOfBits(int n){
    /*
    suppose we want to count bits in n=9 i.e. 10101
    We can do below
    1. n & 1 -> if it is not zero then count ++
    2. n = n>>1;
    Repeat above till n!=0
    */
   int c=0;
   while(n!=0){
      if(n & 1){
        c++;
      }
      n = n>>1;
   }
   return c;
}

int countOfBitsImproved(int n){

    int c=0;
    while(n!=0){
        n = n & (n-1);
        c++;
    }
    return c;
}

int fastPower(int a, int b){

    int res = 1;
    int power = a;

    while(b!=0){
        if(b&1){
           res = res * power;
        }
        power = power * power;
        b = b>>1;
    }

    return res;

}

int power(int x, int y, int mod){

    int p = x;
    int res = 1;
    while(y!=0){
        if(y&1){
            res = (res * p) % mod;
        }
        p = (p * p) % mod;
        y = y>>1;
    }

    return res % mod;
}

int main() {

    int n;

    checkOddEven(9);
    cout<<"0th bit in 9 : "<<getIthBit(9,0)<<endl;
    cout<<"1st bit in 9 : "<<getIthBit(9,1)<<endl;
    cout<<"2nd bit in 9 : "<<getIthBit(9,2)<<endl;
    cout<<"3rd bit in 9 : "<<getIthBit(9,3)<<endl;
    cout<<"10 in binary : "<<getBinary(10)<<endl;

    char c;
    int i;
    int j;
    do{
        cout<<"Enter n : "<<endl;
        cin>>n;
        /*cin>>i;
        cin>>j;
        cout<<n<<" before clearing last "<<i<<" bits : "<<getBinary(n)<<endl;
        replaceBitsInRange(n,i,j,5);
        cout<<n<<" after clearing last "<<14<<" bits : "<<getBinary(n)<<endl;*/
        //isPowerOfTwo(n);
        cout<<"count of bits in "<<n<<" : "<<getBinary(n)<<" -> "<<countOfBitsImproved(n)<<endl;
        /*cout<<"Power 3^5 : "<<fastPower(3,5)<<endl;
        cout<<"Power 5^3 : "<<fastPower(5,3)<<endl;
        cout<<"Power 2^9 : "<<fastPower(2,9)<<endl;*/
        cout<<"Mod power : "<<power(12, 25, 10007)<<endl;
        cout<<"Power 12^25 : "<<fastPower(12,25)<<endl;

    }while(true);
}