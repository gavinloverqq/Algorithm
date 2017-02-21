#include <iostream>
#include <list>
#include <vector>
#include <sstream>
using namespace std;


/*
int main() {
    stringstream Scin;
    string s = "12 104 13 7 9 83 71 35 42 28 31";
    Scin.str(s);
    vector < list <int> > vLst(10);
    vector < list <int> > vLst2(10);
    int i;
    int Max = -1,rec = 0;
    while (Scin >> i){
        int step1 = i % 10;
        vLst[step1].push_back(i);
        Max = max(Max,i);
    }
    while (Max){
        Max /= 10;
        ++rec;
    }
    for (int j = 0; j < 10; ++j) {
        while (!vLst[j].empty()){
            int t = vLst[j].front();
            vLst[j].pop_front();
            int step2 = t % 100;
            step2 /= 10;
            vLst2[step2].push_back(t);
        }
    }
    vLst.clear();
    for (int j = 0; j < 10; ++j) {
        while (!vLst2[j].empty()){
            int t = vLst2[j].front();
            vLst2[j].pop_front();
            int step2 = t % 1000;
            step2 /= 100;
            vLst[step2].push_back(t);
        }
    }
    for (int k = 0; k < 10; ++k) {
        while (!vLst[k].empty()){
            int t = vLst[k].front();
            vLst[k].pop_front();
            cout << t << endl;
        }
    }
    return 0;
}*/


void RadixCountSort(int *npidex,int *npdate,int n) //统计基数个数并排序(桶排序)
{
    int i,npcount[10];             //基数只有十个 (十个桶）
    memset(npcount,0,sizeof(npcount));
    for(i=0;i<n;i++) npcount[npidex[i]]++;       //统计基数相同的个数。
    for(i=1;i<10;i++) npcount[i]+=npcount[i-1];  //确定不大于该位置i的个数

    int *npsort=new int[n];

    for(i=n-1;i>=0;i--) npsort[--npcount[npidex[i]]]=npdate[i];  //按桶的编号放入
    for(i=0;i<n;i++) npdate[i]=npsort[i];   //依次从小到大取出桶里的数

    delete npsort;
}

void RadixSort(int *npDate,int n) //基数排序
{
    int *npDateRadix=new int[n];
    int base=1,flag=0;
    while(flag==0){
        flag=1;
        base*=10;
        for(int i=0;i<n;i++){
            npDateRadix[i]=npDate[i]%base;
            npDateRadix[i]/=base/10;
            if(npDateRadix[i]>0) flag=0;
        }
        if(flag) break;              //如果最大的数的第一个位数为零，排序结束。
        RadixCountSort(npDateRadix,npDate,n);
    }
    delete npDateRadix;
    return;
}

int  main(){
    int n,date[1000];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>date[i];
        RadixSort(date,n);
        for(int i=0;i<n;i++)
            printf("%d ",date[i]);
        printf("\n");
    }
    return 0;
}





/*
 #define BASE 10 //基数桶[0-9]

void radixsort(int arr[], int size)
{
    if (arr == NULL)
        return ;

    //找出最大数
    int max = arr[0];
    int i;
    for (i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1; //位数
    int *temp = (int*) malloc(size * sizeof(int));
    while (max / exp > 0) {

        //重置基数桶
        int bucket[BASE] = {0};

        //统计每个基数上有多少个数据
        for (i = 0; i < size; ++i) {
            bucket[(arr[i] / exp) % BASE]++;
        }

        //求出基数桶的边界索引,bucket[i]值为第i个桶的右边界索引+1
        for (i = 1; i < BASE; ++i) {
            bucket[i] += bucket[i - 1];
        }

        //这里要从右向左扫描，保证排序稳定性
        for (i = size - 1; i >= 0; i--) {
            temp[--bucket[(arr[i] / exp) % BASE]] = arr[i];
        }

        //将基数桶排好的数据赋值到原数据，完成一趟排序
        for (i = 0; i < size; ++i) {
            arr[i] = temp[i];
        }

        exp *= BASE; //位数递增

    }
    free(temp);
}

int main()
{
    int arr[] = {27, 91, 1, 97, 17, 23, 84, 28, 72, 5, 67, 25};
    int size = sizeof(arr) / sizeof(int);

    // soer
    radixsort(arr, size);

    //print
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}


 */