#include <iostream>
#include <vector>
using namespace std;

class hp {
private:
    vector<int> heap;
    vector<int> heap1;
    int n1;

public:
    hp() {
        heap.push_back(0);
        heap1.push_back(0);
    }

    void getdata() {
        cout << "\nEnter the number of students: ";
        cin >> n1;

        cout << "\nEnter the marks: ";
        for (int i = 0; i < n1; i++) {
            int x;
            cin >> x;
            insert1(heap, x);
            insert2(heap1, x);
        }
    }

    void insert1(vector<int>& heap, int x) {
        heap.push_back(x);
        upadjust1(heap, heap.size() - 1);
    }

    void upadjust1(vector<int>& heap, int i) {
        int temp;
        while (i > 1 && heap[i] > heap[i / 2]) {
            temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    void insert2(vector<int>& heap1, int x) {
        heap1.push_back(x);
        upadjust2(heap1, heap1.size() - 1);
    }

    void upadjust2(vector<int>& heap1, int i) {
        int temp1;
        while (i > 1 && heap1[i] < heap1[i / 2]) {
            temp1 = heap1[i];
            heap1[i] = heap1[i / 2];
            heap1[i / 2] = temp1;
            i = i / 2;
        }
    }

    void minmax() {
        cout << "\nMax marks: " << heap[1];
        cout << "\nMax Heap ";
        for (int i = 1; i <= n1; i++) {
            cout << "\n" << heap[i];
        }

        cout << "\nMin marks: " << heap1[1];
        cout << "\nMin Heap";
        for (int i = 1; i <= n1; i++) {
            cout << "\n" << heap1[i];
        }
    }
};

int main() {
    hp h;
    h.getdata();
    h.minmax();

    return 0;
}
