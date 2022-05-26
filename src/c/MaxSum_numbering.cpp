#include <bits/stdc++.h>
using namespace std;
const int N = 20;
long double S[N][N] = {0};
long double R[N][N] = {0};
long double A[N][N] = {0};
int loop = 20000;
long double lambda = 0;
const char* dataFileName = "Data.txt";
void readS() {
    ifstream myFile("Data.txt");
    vector<long double> cord[4];
    cord[0].resize(N);
    cord[1].resize(N);
    cord[2].resize(N);
    cord[3].resize(N);
    mt19937 engine((unsigned int)time(NULL));
    uniform_real_distribution<long double> distribution(0,10000);
    auto gen = bind(distribution, engine);

    for(int i = 0; i < N; i++) {
        myFile >> cord[0][i] >> cord[1][i];
        //cin >> cord[0][] >> cord[i][1];
        //cord[0][i] = gen();
        //cord[1][i] = gen();
        //cord[0][i] = (i%3)*500;
        //cord[1][i] = (i%3)*500;
    }
    for(int i= 0; i < N; i++) {
        myFile >> cord[2][i] >> cord[3][i];
    }
    cout << "input :\n";
    for(int i = 0 ; i < N; i++) {
        //cout << i <<"th Point\n";
        //cout << cord[0][i] << ' ' << cord[1][i] << '\n';
    }
    myFile.close();
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            long double dis1 = (cord[0][i]-cord[2][j])*(cord[0][i]-cord[2][j])+(cord[1][i]-cord[3][j])*(cord[1][i]-cord[3][j]);
            long double dis2 = (cord[2][i]-cord[0][j])*(cord[2][i]-cord[0][j])+(cord[3][i]-cord[1][j])*(cord[3][i]-cord[1][j]);
            dis1 = sqrt(dis1);
            dis2 = sqrt(dis2);
            S[i][j] = -dis1;
            S[j][i] = -dis2;
        }
    }
}
signed main() {
    clock_t st = clock();
    readS();
    for(int loop1 = 1; loop1 <= loop; loop1++) {
        for(int i = 0; i < N; i++) {
            vector<long double> pref_ma(N);
            vector<long double> suff_ma(N);
            pref_ma[0] = S[i][0] + A[i][0];
            for(int j = 1; j < N; j++) {
                pref_ma[j] = max(pref_ma[j-1],S[i][j]+A[i][j]);
            }
            suff_ma[N-1] = S[i][N-1] + A[i][N-1];
            for(int j = N-2; j >= 0; j--) {
                suff_ma[j] = max(suff_ma[j+1],S[i][j]+A[i][j]);
            }
            for(int j = 0; j < N; j++) {
                long double ma = max((j==0?-1e100:pref_ma[j-1]),(j==N-1?-1e100:suff_ma[j+1]));
                R[i][j] = (1-lambda) * (S[i][j] - ma) + lambda * R[i][j];
            }
        }
        for(int j = 0; j < N; j++) {
            vector<long double> pref_ma(N);
            vector<long double> suff_ma(N);
            pref_ma[0] = R[0][j];
            for(int i = 1; i < N; i++) {
                pref_ma[i] = max(pref_ma[i-1],R[i][j]);
            }
            suff_ma[N-1] = R[N-1][j];
            for(int i = N-2; i >= 0; i--) {
                suff_ma[i] = max(suff_ma[i+1],R[i][j]);
            }
            for(int i = 0; i < N; i++) {
                long double ma = max((i==0?-1e100:pref_ma[i-1]),(i==N-1?-1e100:suff_ma[i+1]));
                A[i][j] = (1-lambda) * -ma + lambda * A[i][j];
            }
        }
    }
    vector<int> par(N);
    for(int i=0;i<N;i++) {
        int id = -1;
        int ma = 0;
        for(int j = 0; j < N;j++) {
            int c = j;
            if(j==0) {
                ma = R[i][c]+A[i][c];
                id = c;
            }
            if(R[i][c]+A[i][c] > ma) {
                ma = R[i][c]+A[i][c];
                id = c;
            }
        }
        par[i] = id;
    }
    for(int i = 0; i < N; i++) {
        cout << par[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(R[i][j]+A[i][j]>0) {
                cout <<"1 ";
            }
            else cout <<"_ ";
        }
        cout << '\n';
    }
    cout << clock() - st << "ms\n";
}
