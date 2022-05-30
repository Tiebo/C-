#include <iostream>
#include<algorithm>
using namespace std;

typedef struct complete
{
    string one, two;
    int result;
} com;

typedef struct people
{
    string name;
    int score = 0;
} peo;

int n;
peo pp[110];

void find(string one, string two, int result)
{
    int i;
    for (i = 0; pp[i].name != "" && i < n; i++)
    {
        if (pp[i].name == one)
        {
            result == 1 ? pp[i].score += 3 : pp[i].score++;
            break;
        }
    }
    if (i <= n && pp[i].name == "")
    {
        pp[i].name = one;
    }
    for (i = 0; pp[i].name != "" && i < n; i++)
    {
        if (pp[i].name == two)
        {
            if (result == 0)
                pp[i].score++;
            break;
        }
    }
    if (i <= n && pp[i].name == "")
    {
        pp[i].name = two;
    }
}
void sortst(peo pp[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pp[j - 1].score < pp[j].score)
            {
                peo temp;
                temp = pp[j];
                pp[j] = pp[j - 1];
                pp[j - 1] = temp;
            }
        }
    }
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        cin >> n;
        int k =n * (n - 1) / 2;
        com arr[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i].one >> arr[i].two >> arr[i].result;
            find(arr[i].one, arr[i].two, arr[i].result);
        }
        sortst(pp);
        for(int i = 0; i < n; i++)
        {
            cout<<i+1<<" "<<pp[i].name<<" "<<endl;
            pp[i].name="",pp[i].score=0;
        }
    }
}