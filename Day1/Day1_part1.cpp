#include <bits/stdc++.h>
using namespace std;

int main()
{
    int col1, col2;
    ifstream inputFile("input.txt"); // Missing semicolon here
    vector<int> data1;
    vector<int> data2;

    // Check if file opened successfully
    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    // Reading data from the file
    while (inputFile >> col1 >> col2)
    {
        data1.push_back(col1);
        data2.push_back(col2);
    }
    inputFile.close();
    // this can also be done by inserting both of them in a mineap
    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    long long dist = 0;
    for (int i = 0; i < data1.size(); i++)
    {
        dist = dist + abs(data1[i] - data2[i]);
    }

    cout << dist << endl;

    return 0;
}
