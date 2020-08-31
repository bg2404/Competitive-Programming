#include<bits/stdc++.h>

using namespace std;

vector<string> grid;

int w, h;

struct developer {
    string c;
    int b;
    int s;
    vector<string> skills;

    bool operator<(struct developer &o) {
        if(c == o.c) {
            return b > o.b;
        }
        return c < o.c;
    }
};

struct pm {
    string c;
    int b;

    bool operator<(struct developer &o) {
        if(c == o.c) {
            return b > o.b;
        }
        return c < o.c;
    }
};

struct answer {
    int d_no;
    int pm_no;
};

int dev = 0, pms = 0;
pair<int, int> DIR[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

vector<vector<int>> color;
vector<vector<answer>> grid_ans;
vector<pair<developer, int > > developers;
vector<pair<pm, int > > pms_vec;
vector<pair<int,int> > dev_pos;
vector<pair<int, int> > pms_pos;

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i, j});
    while(!q.empty()) {
        pair<int,int> point = q.front();
        q.pop();
        int x = point.first, y = point.second;
        color[x][y] = 1;
        if(grid[x][y] == '_') {
            // grid_ans[x][y] = {dev++, -1};
            dev_pos[developers[dev++].second] = {x, y};
        } else if(grid[x][y] == 'M'){
            // grid_ans[x][y] = {-1, pms++};
            pms_pos[pms_vec[pms++].second] = {x, y};
        } else {
            color[x][y] = 2;
            continue;
        }
        for(int k = 0; k < 4; ++k) {
            int new_x = x + DIR[k].first;
            int new_y = y + DIR[k].second;
            if(new_x < 0 || new_y < 0 || new_x >= h || new_y >= w) {
                continue;
            }
            if(color[new_x][new_y] == 0 && grid[new_x][new_y] != '#') {
                q.push(make_pair(new_x, new_y));
            }
        }
        color[point.first][point.second] = 2;
    }    
}

bool comp_dev(pair<developer,int> a, pair<developer,int> b) {
    if(a.first.c == b.first.c) {
        if(a.first.b == b.first.b) {
            return a.second < b.second;
        }
        return a.first.b < b.first.b;
    }
    return a.first.c < b.first.c;
}

bool comp_pms(pair<pm,int> a, pair<pm,int> b) {
    if(a.first.c == b.first.c) {
        if(a.first.b == b.first.b) {
            return a.second < b.second;
        }
        return a.first.b < b.first.b;
    }
    return a.first.c < b.first.c;
}

int main() {
    cin>>w>>h;
    grid.resize(h);
    color.resize(h);
    for(int i = 0; i < h; ++i) {
        cin >> grid[i];
        for(int j = 0; j < w; ++j) {
            color[i].push_back(0);
        }
    }
    int d;
    cin >> d;
    
    grid_ans.resize(h);
    for(int k = 0; k < h; ++k) {
        grid_ans[k].resize(w);
    }
    developers.resize(d);
    for(int i = 0; i < d; ++i) {
        cin >> developers[i].first.c;
        cin >> developers[i].first.b;
        cin >> developers[i].first.s;
        developers[i].first.skills.resize(developers[i].first.s);
        for(int j = 0; j < developers[i].first.s; ++j) {
            cin >> developers[i].first.skills[j];
        }
        developers[i].second = i;
    }
    sort(developers.begin(), developers.end(), comp_dev);
    int m;
    cin >> m;
    pms_vec.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> pms_vec[i].first.c;
        cin >> pms_vec[i].first.b;
        pms_vec[i].second = i;
    }
    sort(pms_vec.begin(), pms_vec.end(), comp_pms);

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(color[i][j] == 0) {
                bfs(i,j);
            }
        }
    }

    cout << dev << ' ' << pms << '\n';
    for(int i = 0; i < dev; ++i) {
        cout << dev_pos[i].first << ' ' << dev_pos[i].second << '\n';
    }

    for(int i = 0; i < pms; ++i) {
        cout << pms_pos[i].first << ' ' << pms_pos[i].second << '\n';
    }

    return 0;
}