//键帽无一例外的向左移了一位，这样，输入Q会变成输入W，输入J会变成输入K
#include<iostream>

using namespace std;
int main()
{
    string a="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//13 12 11
    string arr;
    getline(cin,arr);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=1;j<a.size();j++){
            if(arr[i]==a[j]){
                arr[i]=a[j-1];
                break;
            }
        }
    }
    cout<<arr;
    return 0;
}