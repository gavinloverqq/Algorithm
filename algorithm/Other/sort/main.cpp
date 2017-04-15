#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>

int a[100005];
using namespace std;
int n;

void quick_sort(int s,int e)
{
    if(s>e) return;

    int key;
//    if((s+e)>>1>=0 && (s+e)>>1<n)
//        key=a[(s+e)>>1];
//    else
    srand(time(NULL));
    int m = rand()%(e-s+1) + s;
//    int m = (s + e) >> 1;
    swap(a[s], a[m]);
    key=a[s];
    int i=s,j=e;
    while(i!=j) {
        while(i<j && key<=a[j]) {
            --j;
        }
//        if(i<j)
//            a[i]=a[j];
        while(i<j && key>=a[i]) {
            ++i;
        }
//        if(i<j)
//            a[j]=a[i];

        if(i < j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }

    }
//    a[i]=key;
    a[s] = a[i];
    a[i] = key;


    quick_sort(s,i-1);
    quick_sort(i+1,e);
    return;
}
int main()
{

//    freopen("testdata (2).in","r",stdin);
//    freopen("testdata (2).out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a[i]);
    }
    quick_sort(0,n-1);
    printf("%d",a[0]);
    for(int i=1;i<n;++i) {
        printf(" %d",a[i]);
    }
    putchar('\n');
    return 0;
}