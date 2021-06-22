#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Street {
    int B;
    int E;
    string name;
    int L;
};

struct Car {
    int P;
    vector<string> path;
};

struct Output {
    int ID;
    int E;
    vector<pair<string, int>> street;
    // vector<string> street_name;
    // vector<int> street_time;
    Output(int ID) : ID(ID) { E = 0; }
};

unordered_map<string, int> nameToInt;
unordered_map<int, string> intToName;
unordered_map<int, int> street_cnt;
vector<vector<int>> incoming_streets;

// int get_random_time(D, n) {
//     return ceil(D/n * rand())
// }
// vector<vector<int>> outgoing_streets;

int main() {
    int cnt = 0;
    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;
    incoming_streets.resize(I);
    // outgoing_streets.resize(I);
    vector<Street> streets(S);
    vector<Car> cars(V);
    for (Street &street : streets) {
        cin >> street.B >> street.E;
        cin >> street.name;
        cin >> street.L;
        if (nameToInt.find(street.name) == nameToInt.end()) {
            nameToInt.insert({street.name, ++cnt});
            intToName.insert({cnt, street.name});
        }
        incoming_streets[street.E].push_back(nameToInt[street.name]);
        // outgoing_streets[street.E].push_back(street_hash[street.name]);
    }
    for (Car &car : cars) {
        cin >> car.P;
        car.path.resize(car.P);
        for (string &street : car.path) {
            cin >> street;
            if (street_cnt.find(nameToInt[street]) == street_cnt.end()) {
                street_cnt.insert({nameToInt[street], 1});
            } else {
                ++street_cnt[nameToInt[street]];
            }
        }
        --street_cnt[nameToInt[car.path.back()]];
    }
    int A = 0;
    vector<Output> outputs;
    for (int i = 0; i < I; ++i) {
        Output output(i);
        for (int street_int : incoming_streets[i]) {
            auto itr = street_cnt.find(street_int);
            if (itr != street_cnt.end()) {
                if (itr->second > 0) {
                    output.E++;
                    output.street.push_back({intToName[street_int], itr->second});
                }
            }
        }
        if (output.E) {
            ++A;
            outputs.push_back(output);
        }
    }
    cout << A << '\n';
    for (int i = 0; i < A; ++i) {
        cout << outputs[i].ID << '\n'
             << outputs[i].E << '\n';
        sort(outputs[i].street.begin(), outputs[i].street.end(), [](auto &a, auto &b) { return a.second > b.second; });
        for (int j = 0; j < outputs[i].E; ++j) {
            cout << outputs[i].street[j].first << ' ' << outputs[i].street[j].second << '\n';
        }
    }
    return 0;
}