#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;

    if (n <= 1)
    {
        cout << n <<  " is NOT PRIME" << endl;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                count++;
            }
        }
        if (count > 2)
        {
            cout << n<< " is NOT PRIME" << endl;
        }
        else{
            cout<<n<<" is PRIME"<<endl;
        }
    }

    return 0;
}