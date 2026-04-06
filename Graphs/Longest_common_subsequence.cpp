#include <iostream>
#include <algorithm>

using namespace std;

int lcs(string &s1, string &s2){
    int a = s1.size();
    int b = s2.size();

    int arr[a+1][b+1];

    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            arr[i][j] = 0;
        }
    }

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    // To get LCS string
    int i=a , j=b;
    string s = "";

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            s += s1[i-1];
            i--;
            j--;
        }
        else if(arr[i-1][j] > arr[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(s.begin(), s.end());
    cout << "LCS string: " << s << endl;

    return arr[a][b];

}

int main(){
    string s1 = "prosperity";
    string s2 = "properties";
    cout << "LCS length: " << lcs(s1, s2) << endl;
    return 0;
}