#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>

void bubbleSort(vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            if (v[i] > v[j])
                swap(v[j], v[i]);
        }
    }
}

template<Sortable T>
void heapify(vector<T>& v, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// If l is larger than root
	if (l < n && v[l] > v[largest])
		largest = l;

	// If r is larger than largest so far
	if (r < n && v[r] > v[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(v[i], v[largest]);
		heapify(v, n, largest);
	}
}

template<Sortable T>
void heapSort(vector<T>& v)
{
	int n = v.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(v, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
	for (int j = 0; j<n; j++){
		reverse(v.begin(), v.end());

		}
}

}
