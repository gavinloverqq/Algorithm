#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <exception>

using namespace std;
//int a[100005];
//using namespace std;
//int n;
//
//void quick_sort(int s,int e)
//{
//    if(s>e) return;
//
//    int key;
////    if((s+e)>>1>=0 && (s+e)>>1<n)
////        key=a[(s+e)>>1];
////    else
//    srand(time(NULL));
//    int m = rand()%(e-s+1) + s;
////    int m = (s + e) >> 1;
//    swap(a[s], a[m]);
//    key=a[s];
//    int i=s,j=e;
//    while(i!=j) {
//        while(i<j && key<=a[j]) {
//            --j;
//        }
////        if(i<j)
////            a[i]=a[j];
//        while(i<j && key>=a[i]) {
//            ++i;
//        }
////        if(i<j)
////            a[j]=a[i];
//
//        if(i < j){
//            int t = a[i];
//            a[i] = a[j];
//            a[j] = t;
//        }
//
//    }
////    a[i]=key;
//    a[s] = a[i];
//    a[i] = key;
//
//
//    quick_sort(s,i-1);
//    quick_sort(i+1,e);
//    return;
//}
//int main()
//{
//
////    freopen("testdata (2).in","r",stdin);
////    freopen("testdata (2).out","w",stdout);
//    scanf("%d",&n);
//    for(int i=0;i<n;++i) {
//        scanf("%d",&a[i]);
//    }
//    quick_sort(0,n-1);
//    printf("%d",a[0]);
//    for(int i=1;i<n;++i) {
//        printf(" %d",a[i]);
//    }
//    putchar('\n');
//    return 0;
//}


/*int partion1(int arr[],int low,int high)
{
    if(!arr||low<0||low>high)
        cout << "error array";

//left第一个元素被当做pivot
    int pivot = arr[low];
    int lessIndex = low;

    for(int i=low+1;i<=high;++i){
        if(arr[i]<pivot){
            lessIndex++;
            if(lessIndex!=i){
                int temp = arr[lessIndex];
                arr[lessIndex] = arr[i];
                arr[i] = temp;
            }
        }
    }
//这一步破坏了稳定性
    arr[low] = arr[lessIndex];
    arr[lessIndex] = pivot;

    return lessIndex;
}


int partion2(int arr[],int low,int high)
{
    if(!arr||low<0||low>high)
        cout << "error array";
    //left第一个元素被当做pivot
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    if(low<high){
        for(;;){
            while(i<=j&&arr[i]<pivot)++i;
            while(i<=j&&arr[j]>pivot)--j;
            if(i<j){
                swap(arr[i],arr[j]);
                ++i;
                --j;
            }
            else
                break;
        }
        arr[low] = arr[j];
        arr[j] = pivot;
    }

    return j;

}

int partion3(int arr[],int low,int high)
{
    if(!arr||low<0||low>high)
        cout << "error array";
    //left第一个元素被当做pivot
    int pivot = arr[low];
    int i = low;
    int j = high;


    while(i<j){
        while(i<j&&arr[j]>pivot)j--;
        if(i<j){
            arr[i] = arr[j];
            i++;
        }
        while(i<j&&arr[i]<pivot)i++;
        if(i<j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = pivot;
    return i;

}*/


/*
5
4 2 4 5 1
*/

int n;
int a[100005];
int num = 0;

int partion1(int l, int r){
    int start = l, end = r;
//    srand(time(NULL));
//    int m = rand()%(end - start+1) + start;
//    swap(a[m], a[start]);
    int key = a[start];

    while (start < end) {
        while (start < end && a[end] >= key) {// 这里的等号就是把相等的放在后面
            end--;
            num++;
        }

        a[start] = a[end];
        num++;

        while (start < end && a[start] < key) { //这里的等号就是把相等的放在前面
            start++;
            num++;
        }

        a[end] = a[start];
        num++;
    }

    a[start] = key;
    return start;
}

//上面的方法略改版本，此处必须使用2个if(start < end)，不用的话，出现错误。因为在第一个while循环中start = end 后面的a[end--] = a[start]即会出现错误
int partion2(int l, int r){
    int start = l, end = r;
//    srand(time(NULL));
//    int m = rand()%(end - start+1) + start;
//    swap(a[m], a[start]);
    int key = a[start];

    while (start < end) {
        while (start < end && a[end] >= key) {// 这里的等号就是把相等的放在后面
            end--;
            num++;
        }
        if(start < end) {
            a[start++] = a[end];
            num++;
        }
        while (start < end && a[start] < key) { //这里的等号就是把相等的放在前面
            start++;
            num++;
        }
        if(start < end) {
            a[end--] = a[start];
            num++;
        }
    }

    a[start] = key;
    return start;
}

// AC 改进了大量数据相等时的效率，不会退化为冒泡、
int partion3(int l, int r){
    int start = l, end = r;
    srand(time(NULL));
    int m = rand()%(end - start+1) + start;
    swap(a[m], a[start]);
    int key = a[start];

    while (start < end){
        while (start < end && a[end] > key)
            end--;
        if(start < end){
            a[start++] = a[end];
        }
        while (start < end && a[start] < key)
            start++;
        if(start < end){
            a[end--] = a[start];
        }
    }
    a[start] = key;
    return start;
}

//int partion2(int l, int r){
//    int start = l, end = r;
//    srand(time(NULL));
//    int m = rand()%(end - start+1) + start;
//    swap(a[m], a[start]);
//    int key = a[start++];
//
//    while (start <= end){//此处的等号，考虑只有2个元素的时候
//        while (start < end && a[end] > key)
//            end--;
//        while (start <= end && a[start] <= key)
//            start++;
//        if(start < end){
//            swap(a[start], a[end]);
//        }
//    }
//    swap(a[l], a[end]);
//    return end;
//}
//为何上面的会TLE
int partion5(int l, int r){
    int start = l, end = r;
//    srand(time(NULL));
//    int m = rand()%(end - start+1) + start;
//    swap(a[m], a[start]);
    int key = a[start++];

    while (start <= end){//此处的等号，考虑只有2个元素的时候
        while (start <= end && a[start] < key)
            start++;
        while (start <= end && a[end] >= key)
            end--;

        if(start < end){
            swap(a[start], a[end]);
        }
    }
    cout << "swap: " << end << " " << start << endl;
    swap(a[l], a[end]);
    return end;
}
int partion4(int l, int r){
    int start = l, end = r;
    srand(time(NULL));
    int m = rand()%(end - start + 1) + start;
    swap(a[m], a[start]);
    int key = a[start];

    while (start < end){//此处的等号，考虑只有2个元素的时候

        while (start < end && a[end] > key)
            end--;
        while (start < end && a[start] < key)
            start++;

        if(start < end){
            swap(a[start], a[end]);
        }
    }
    swap(a[l], a[end]);
    return end;
}

int partion(int left, int right) {
    int i = left, j = right + 1;
    int temp = a[left];
    while (true) {
        while (a[i] < temp && i < right) {
            i++;
        }
        while (a[j] >= temp && j < left) {
            j++;
        }
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[left], a[j]);
    return j;
}



void qs(int l, int r){
    if(l >= r){
        return;
    } else {
        int m = partion5(l, r);
        cout << "patition: " << m << endl;
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
        qs(l , m-1);
        qs(m + 1, r);
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    qs(0, n-1);
    for (int j = 0; j < n; ++j) {
        cout << a[j] << " ";
    }
//    cout << num << endl;

}