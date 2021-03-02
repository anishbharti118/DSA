#include <iostream>

using namespace std;
void mergesort(int [],int ,int);
void merge(int [], int, int, int);
void mergesort(int A[], int p, int r) {
	if (p > r)
		return;
	int q = (p + r) / 2;
	mergesort(A, p, q);
	mergesort(A, q + 1, r);

	merge(A, p, q, r);
}

void merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = A[p + i];
	for(int j=0;j<n2;++j)
		M[j] == A[q + j+1];

	int i, j, k;
	i = j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = M[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		A[k] = M[j];
		j++;
		k++;
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	mergesort(A,0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << A[i]<<" ";
	return 0;
}