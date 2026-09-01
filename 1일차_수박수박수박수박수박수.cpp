#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string answer;

    for (int i = 0; i < n; i++)
        answer += (i % 2 == 0) ? "¼ö" : "¹Ú";
    
    cout << answer;
}