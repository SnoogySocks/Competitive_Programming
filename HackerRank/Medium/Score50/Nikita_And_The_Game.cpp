// 05/2020
// https://www.hackerrank.com/challenges/array-splitting/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

template <typename T>
struct Tuple {
    T first;
    T second;
    T third;
    Tuple (T first, T second, T third) 
        : first { first }, second { second }, third { third } {
    }
};

int find_mid (vector<int>& arr, int left, int right) {
    if (left == right) return -1;

    long long sum_l = arr[left];
    long long sum_r = arr[right];

    while (left != right - 1) {
        if (sum_l <= sum_r) {
            sum_l += arr[++left];
        } else {
            sum_r += arr[--right];
        }
    }
    
    return sum_l == sum_r ? left : -1;
}
int arraySplitting(vector<int> arr) {
    
    int score = 0;
    std::stack<Tuple<int>> i_to_go;
    i_to_go.emplace(0, arr.size() - 1, 0);

    while (!i_to_go.empty()) {
        auto tuple = i_to_go.top();
        i_to_go.pop();

        int i_mid = find_mid(arr, tuple.first, tuple.second);
        if (i_mid != -1) {
            i_to_go.emplace(tuple.first, i_mid, tuple.third + 1);
            i_to_go.emplace(i_mid + 1, tuple.second, tuple.third + 1);
        } else {
            score = (score >= tuple.third) ? score : tuple.third;
        }
    }
    
    return score;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = arraySplitting(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
