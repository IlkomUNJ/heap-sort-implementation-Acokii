#include <iostream>
#include <array>
using namespace std;

class MaxHeap{
    private:
    int size{};
    int maxsize{};
    int* heap;      
    
    int p(int i) {return i>>1;};
    int l(int i) {return i<<1;};
    int r(int i) {return (i<<1) + 1;};

    public:
    MaxHeap(int max);
    bool isEmpty() const {return size == 0;};
    int getMax() {return heap[1];};
    void insert(int val);
    void shiftUp(int i);
    void shiftDown(int i);
    void printheap();
};

MaxHeap::MaxHeap(int max){
    maxsize = max;
    heap = new int[maxsize];
}

void MaxHeap::shiftUp(int i) {
    if (i > size) return;
    if (i == 1) return;
    if (heap[p(i)] < heap[i]) {
        swap(heap[p(i)], heap[i]);
        shiftUp(p(i));
    }
    else return;
}

void MaxHeap::shiftDown(int i){
    if (i > size) return;

    int swapId = i;

    if (l(i) <= size && heap[i] < heap[l(i)]){
        swapId = l(i);
    }
    if (r(i) <= size && heap[swapId] < heap[r(i)]){
        swapId = r(i);
    }
    if (swapId != i){
        swap(heap[i], heap[swapId]);
        shiftDown(swapId);
    }
    return;
}

void MaxHeap::insert(int val){
    if (size <= maxsize){
        heap[++size] = val;
        // cout << heap[size] << endl;
    }else{
        cout << "insert melebihi kapasitas array yang telah ditetapkan";
        return;
    }
    shiftUp(size);
    return;
}

void MaxHeap::printheap(){
    cout << "array yang dihasilkan: ";
    for (int i = 1; i <= maxsize; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    MaxHeap* priorqueue = new MaxHeap(5);
    if (priorqueue->isEmpty()){
        cout << "array kosong" << endl;
    }else{
        cout << "array tidak kosong" << endl;
    }

    priorqueue->insert(120);
    priorqueue->insert(20);
    priorqueue->insert(200);
    priorqueue->insert(40);
    priorqueue->insert(17);
    cout << "root dari array adalah: " << priorqueue->getMax() << endl;
    priorqueue->printheap();
    if (priorqueue->isEmpty()){
        cout << "array kosong" << endl;
    }else{
        cout << "array tidak kosong" << endl;
    }
    return 0;
}