// INput formats 
// 6 AABCCC 3 
// Here 6 is n or length of string, AABCCC is input string, And 3 is rotation value or shift value


#include <iostream>
#include <map>
using namespace std;

string caesarCipherAlgo(string str, int rotate)
{
    string result = "";

    // traverse text
    for (int i = 0; i < str.length(); i++)
    {
        // Encrypt Uppercase letters as ASCII values of uppercase starts with 65
        if (islower(str[i]))
            result += char(int(str[i] + rotate - 97) % 26 + 97);

        // Encrypt Lowercase letters as ASCII values of lowercase starts with 97
        else if (isupper(str[i]))
            result += char(int(str[i] + rotate - 65) % 26 + 65);
        // Encrypt special characters
        else
        {
            result += str[i];
        }
    }

    // Return the resulting string
    return result;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = caesarCipherAlgo(s, k);
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[result[i]]++;
    }
    // priting values of map as requires
    // MAP FORMED WILL be:
    // D->2
    // E->1
    // F->3

    for (auto x : mp)
    {
        if (x.second == 1)
        {
            cout << x.first;
        }
        else
        {
            cout << x.first << x.second;
        }
    }
    return 0;
}