#include <unordered_map>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;


int gcdhelper(int m, int n)
{
    if(m % n == 0)
        return n;
    else
        return gcdhelper(n, m%n);
}

int gcd(vector<int> a) {
    if(a.size() == 0)
        return 0;
    if(a.size() == 1)
        return a[0];
    int res = a[0];
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] > 0 && res > 0)
            res = gcdhelper(res, a[i]);
        else
            return 0;
    }
    return res;
}


int main()
{
    int num[] = {21,42};
    int len = 2;
    vector<int> a;
    for(int i = 0; i < len; i++)
        a.push_back(num[i]);
    cout << gcd(a)<<endl;
}
