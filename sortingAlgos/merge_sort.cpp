#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid+1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx + st] = temp[idx];
    }
}

void merge_sort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = (st + end) / 2;
        merge_sort(arr, st, mid); // left half
        merge_sort(arr, mid+1, end); // right half

        merge(arr, st, mid, end);
    }
}

int main(){
    vector<int> arr = {12, 31, 35, 8, 32, 37};
    merge_sort(arr, 0, arr.size()-1);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
