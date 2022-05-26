#include <bits/stdc++.h>
using namespace std;
float mvalue[1010][2] = {0,}, wvalue[1010][2] = {0,};
double s[1010][1010] = {0,};
double R[1010][1010] = {0,};
double A[1010][1010] = {0,};
double B[1010][1010] = {0,};
double H[1010][1010] = {0,};
vector<int> centers;
int exe[1010] = {0,};
int main() {
	int n = 0;
	FILE *fp = fopen("test.txt", "r");
    fscanf(fp, "%d", &n);
//	for(int i = 0; i<n; i++) {
//		fscanf(fp, "%f %f", &mvalue[i][0], &mvalue[i][1]);
//	}
//	for(int i = 0; i<n; i++) {
//		fscanf(fp, "%f %f", &wvalue[i][0], &wvalue[i][1]);
//	}
//	for(int i = 0; i<n; i++) {
//		for(int j = 0; j<n; j++) {
//			s[i][j] = -pow((mvalue[i][0]-wvalue[j][0])*(mvalue[i][0]-wvalue[j][0])+(mvalue[i][1]-wvalue[j][1])*(mvalue[i][1]-wvalue[j][1]), 0.5);
//		}
//	}
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			float f = 0;
			fscanf(fp, "%f", &f);
			s[i][j] = f;
		}
	}
	int iter = 50000;
	double lambda = 0;
	for(int r = 0; r<iter; r++) {
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				B[i][j] = s[i][j]+A[i][j];
			}
		}
		for(int i = 0; i<n; i++) {
			float max = 0, max2 = 0;
			int maxk = 0;
			if(B[i][0]>B[i][1]) {
				max = B[i][0];
				max2 = B[i][1];
				maxk = 0;
			}
			else {
				max = B[i][1];
				max2 = B[i][0];
				maxk = 1;
			}
			for(int k = 2; k<n; k++) {
				if(max<B[i][k]) {
					max2 = max;
					max = B[i][k];
					maxk = k;
				}
				else if(max2<B[i][k]) {
					max2 = B[i][k];
				}
			}
			for(int j = 0; j<n; j++) {
				if(j==maxk) {
					H[i][j] = H[i][j]*lambda + (1-lambda)*(-max2);
				}
				else {
					H[i][j] = H[i][j]*lambda + (1-lambda)*(-max);
				}
			}
		}
		for(int i = 0; i<n; i++) {
			for(int j = 0; j<n; j++) {
				R[i][j] = s[i][j]+H[i][j];
			}
		}
		for(int j = 0; j<n; j++) {
			float max = 0, max2 = 0;
			int maxk = 0;
			if(R[0][j]>R[1][j]) {
				max = R[0][j];
				max2 = R[1][j];
				maxk = 0;
			}
			else {
				max = R[1][j];
				max2 = R[0][j];
				maxk = 1;
			}
			for(int k = 2; k<n; k++) {
				if(max<R[k][j]) {
					max2 = max;
					max = R[k][j];
					maxk = k;
				}
				else if(max2<R[k][j]) {
					max2 = R[k][j];
				}
			}
			for(int i = 0; i<n; i++) {
				if(i==maxk) {
					A[i][j] = A[i][j]*lambda + (1-lambda)*(-max2);
				}
				else {
					A[i][j] = A[i][j]*lambda + (1-lambda)*(-max);
				}
			}
		}
	}
	/*for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(R[i][j]+A[i][j]>0) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(R[j][i]+A[j][i]>0) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}*/
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(R[i][j]+A[i][j]>0) {
				printf("%d ", j);
			}
		}
	}
	printf("\n");
	for(int k = 0; k<n; k++) {
		for(int a = 0; a<n; a++) {
			if(R[k][a]+A[k][a]>0) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}
