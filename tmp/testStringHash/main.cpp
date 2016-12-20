#include <iostream>
#include <string>
using namespace std;



unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;

    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
//        hash = 65599*hash + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}


unsigned int RSHash(char *str)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash & 0x7FFFFFFF);
}


unsigned int JSHash(char *str)
{
    unsigned int hash = 1315423911;

    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }

    return (hash & 0x7FFFFFFF);
}


unsigned int ELFHash(char *str)
{
    unsigned int hash = 0;
    unsigned int x    = 0;

    while (*str)
    {
        hash = (hash << 4) + (*str++);
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}



// BKDR Hash Function
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }

//    return hash;
    cout << hash << endl;
    return (hash & 0x7FFFFFFF);
}



// DJB Hash Function
unsigned int DJBHash(char *str)
{
    unsigned int hash = 5381;

    while (*str)
    {
        hash += (hash << 5) + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}


unsigned int APHash(char *str)
{
    unsigned int hash = 0;
    int i;

    for (i=0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ (*str++) ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ (*str++) ^ (hash >> 5)));
        }
    }

    return (hash & 0x7FFFFFFF);
}

void trans16(unsigned int a){
    string n2s = "0123456789ABCDEF";
    cout << "0x";
    int tail = 0;
    int stack[100];
    while (a > 0){
//        cout << n2s[a % 16];
        stack[tail++] = a % 16;
        a /= 16;
    }
    while (--tail >= 0){
        cout << n2s[stack[tail]];
    }
}
void trans2(unsigned int a){
    int stack[100];
    int index = 0;
    while (a > 0){
        stack[index++] = a % 2;
        a /= 2;
    }
    while (--index >= 0){
        cout << stack[index];
        if(index % 8 == 0)
            cout << "  ";
    }
}
int main() {
    string str[100];
    char testStr[] = "helloworld";
//    cout << "SDBMHash:  " << SDBMHash(testStr) << endl;
//    cout << "RSHash:  " << RSHash(testStr) << endl;
//    cout << "JSHash:  " << JSHash(testStr) << endl;
    cout << "BKDRHash:    " << BKDRHash(testStr) << endl;
//    cout << 0x7FFFFFFF << endl;
//    cout << (3548576592 - 0xFFFFFFFF) << endl;
//
//    cout << (592 & 0x7FFFFFFF) << endl;
    trans2(3548576592);
    cout << endl;
    unsigned  t = (3548576592 & 0x7FFFFFFF);
    unsigned  t1 =(3548576592 - 0x80000000);
    trans2(t);
    cout << t1 << endl;

    return 0;
}