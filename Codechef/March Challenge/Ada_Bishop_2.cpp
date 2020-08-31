    #include<bits/stdc++.h>

    using namespace std;

    bool board[10][10];

    vector<pair<int, int> > moves;

    void goToStart(int r, int c) {
        if(r != c) {
            moves.push_back({(r+c)/2, (r+c)/2});
            r = c = (r+c)/2;
        }

        if(r > 1) {
            moves.push_back({1,1});
        }
    }

    int main() {
        int T;
        cin >> T;
        while(T--) {
            moves.clear();
            int r0, c0;
            cin >> r0 >> c0;
            if(r0 > 1 || c0 > 1) {
                goToStart(r0, c0);
            }

            moves.push_back({8,8});
            moves.push_back({7,7});
            moves.push_back({6,8});
            moves.push_back({8,6});
            moves.push_back({7,5});
            moves.push_back({4,8});
            moves.push_back({8,4});
            moves.push_back({7,3});
            moves.push_back({2,8});
            moves.push_back({8,2});
            moves.push_back({7,1});
            moves.push_back({1,7});
            moves.push_back({2,6});
            moves.push_back({1,5});
            moves.push_back({5,1});
            moves.push_back({4,2});
            moves.push_back({3,1});
            moves.push_back({1,3});

            cout << moves.size() << '\n';
            for(int i = 0; i < moves.size(); ++i) {
                cout << moves[i].first << ' ' << moves[i].second << '\n';
            }

        }
        return 0;
    }