#include<iostream>
#include<unordered_set>

using namespace std;
int main()
{
    unordered_set<string> set;
    int n,con=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++)
    {    
        cin>>str;
        if(set.count(str))
            con++;
        else set.insert({str});
    }
}