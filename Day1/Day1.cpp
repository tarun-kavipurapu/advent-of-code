#include <bits/stdc++.h>
using namespace std;

long long part1(vector<int> &data1, vector<int> &data2)
{
    // this can also be done by inserting both of them in a mineap
    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    long long dist = 0;
    for (int i = 0; i < data1.size(); i++)
    {
        dist = dist + abs(data1[i] - data2[i]);
    }

    return dist;
}
long long part2(vector<int> &data1, vector<int> &data2)
{
    unordered_map<int, int> mp; // index of second Data
    for (auto it : data2)
    {
        mp[it]++;
    }
    long long similarity = 0;
    for (auto it : data1)
    {
        // individual Similariy
        int indiSimi = 0;
        if (mp.find(it) != mp.end())
        { // if found
            indiSimi = mp[it];
        }
        similarity = similarity + it * indiSimi;
    }

    return similarity;
}

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

    // part1(data1, data2);4

    cout << part2(data1, data2);

    return 0;
}
