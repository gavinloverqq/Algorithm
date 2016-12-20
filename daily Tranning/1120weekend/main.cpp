#include <iostream>
#include <vector>
using namespace std;



//vector 做法错误原因???
int main(){


    int n;
    cin >> n;
    int arr[5][5];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    int ret[100];
    int index = 0;

    int i = n,j = n;
    int x,y;
    while (i > 0) {
        i--;
        x = 0;
        y = i;
        while (x < n && y < n) {
            ret[index++] = arr[x][y];
            x++;
            y++;
        }
    }
    i = 0;
    while (i < n-1) {
        i++;
        x = i;
        y = 0;
        while (x < n && y < n) {
            ret[index++] = arr[x][y];
            x++;
            y++;
        }

    }

    for (int k = 0; k < n*n; ++k) {
        cout << ret[k] <<  " ";
    }

}
/*int main() {
    int height[110];
    int dp[110];
    int n = 1;
    while (cin >> height[n++])
        dp[n-1] = 1;
    n--;n--;
    int maxH = 1,minH = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if(height[i] <= height[j]){
                dp[i] = max(dp[i],dp[j]+1);
                maxH = max(maxH,dp[i]);
            }
        }
    }
    for (int m = 0; m <= n; ++m) {
        dp[m] = 1;
    }
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i < l; ++i) {
            if(height[l] >= height[i]){
                dp[l] = max(dp[l],dp[i] + 1);
                minH = max(minH,dp[l]);
            }
        }
    }
//    for (int k = 1; k <= n; ++k) {
//        cout << dp[k] << " ";
//    }
    cout << maxH << endl << minH << endl;
    return 0;
}*/

/*
int main(){
    int arr[10000];
    int a,n=0;
    int dp[10000];
    while (cin >> arr[n++]);
    n--;
    for (int k = 0; k < n; ++k) {
        dp[k] = 1;
    }
    int maxL = 1;
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] >= arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxL = max(maxL,dp[i]);
    }
    cout << maxL <<endl;
    for (int k = 0; k < n; ++k) {
        dp[k] = 1;
    }
    maxL = 1;
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] < arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxL = max(maxL,dp[i]);
    }
    cout << maxL <<endl;
}*/
