#include <bits/stdc++.h>
int N;
double w[1001][1001] = {0,};
int match_x[1001];
int match_y[1001];
double l_x[1001];
double l_y[1001];
bool s[1001], t[1001];
double slack[1001];
int slack_x[1001];
int tree_x[1001];
int tree_y[1001];
double eps = 1e-9;
bool isSame(double a, double b) {
    return abs(a-b) < eps;
}
signed main() {
    ifstream myFile("Data.txt");
    myFile >> N;
    vector<double> cord[4];
    for(int i = 0; i < 4; i++) cord[i].resize(N);
    for(int i = 0; i < N; i++) {
        myFile >> cord[0][i] >> cord[1][i];
    }
    for(int i = 0; i < N; i++) {
        myFile >> cord[2][i] >> cord[3][i];
    }
    for(int i = 0; i < N: i++) {
        for(int j = 0; j < N; j++) {
            double dis = (cord[0][i]-cord[2][j])*(cord[0][i]-cord[2][j])+(cord[1][i]-cord[3][j])*(cord[1][i]-cord[3][j]);
            dis = sqrt(dis);
            w[i][j] = -dis;
        }
    }
    Hungarian();
    for(int i = 0; i < N; i++) {
        cout << match_x[i] << ' ';
    }
}
void Hungarian() {
    int i, j;
    for(i=0;i<N;i++) {
        match_x[i] = match_y[i] = -1;
    }
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) l_x[i] = max(l_x[i], w[i][j]);
    }
    for(i=0;i<N;i++) l_y[i] = 0;
    while(true) {
        for(i=0;i<N;i++) {
            tree_x[i] = tree_y[i] = -1;
            s[i] = t[i] = 0;
        }
        int s_st = -1;
        for(i=0;i<N;i++) {
            if(match_x[i]==-1) {
                s[i] = 1;
                s_st = i;
                break;
            }
        }
        if(s_st==-1) break;
        for(i=0;i<N;i++) {
            slack[i] = l_x[s_st] + l_y[i] - w[s_st][i];
            slack_x[i] = s_st;
        }
        while(true) {
            int y = -1;
            for(i=0;i<N;i++) {
                if(isSame(slack[i],0)&&!t[i]) y = i;
            }
            if(y==-1) {
                double alpha = 1e18;
                for(i=0;i<N;i++) {
                    if(!t[i]) alpha = min(alpha, slack[i]);
                }
                for(i=0;i<N;i++) {
                    if(s[i]) l_x[i] -= alpha;
                    if(t[i]) l_y[i] += alpha;
                }
                for(i=0;i<N;i++) {
                    if(!t[i]) {
                        slack[i] -= alpha;
                        if(isSame(slack[i],0)) {
                            y = i;
                        }
                    }
                }
            }
            if(match_y[i] = -1) {
                tree_y[y] = slack_x[y];
                while(y != -1) {
                    int x = tree_y[y];
                    match_y[y] = x;
                    int next_y = match_x[x];
                    match_x[x] = y;
                    y = next_y;
                }
                break;
            }
            else {
                int z = match_y[y];
                tree_x[z] = y;
                tree_y[y] = slack_x[y];
                s[z] = t[y] = true;
                for(i=0;i<N;i++) {
                    if(l_x[z] + l_y[i] - w[z][i] < slack[i]) {
                        slack[i] = l_x[z] + l_y[i] - w[z][i];
                        slack_x[i] = z;
                    }
                }
            }
        }
    }
}
