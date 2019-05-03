#include <iostream>

using namespace std;

template<typename T>
void insertSorting(int a[],size_t N);

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a[] = {1, 2, 3, 12, 3, 12, 3, 123, 12, 3, 123, 12, 3, 123, 123, 12312, 312, 3};
    insertSorting<int>(a,sizeof(a)/sizeof(int));
    for (auto i: a) {
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}

template<typename T>
void insertSorting(int a[],size_t N) {
    cout<<"数组长度为"<<N<<endl;
    size_t i, j, low, high, mid;
    T temp;
    for (i = 1; i < N; i++) {
        if (a[i] < a[i - 1]) {
            temp = a[i];
            low = 0;
            high = i - 1;
            while (low <= high) {
                mid = (low + high) >> 1;
                if (temp < a[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

            }
            for (j = i - 1; j >= high + 1; j--) {
                a[j + 1] = a[j];
            }
            a[high + 1] = temp;
        }
    }
}