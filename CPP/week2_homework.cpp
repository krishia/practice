// week2_homework.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cassert>
#include <ctime>
#include <iostream>
using namespace std;

constexpr size_t STACK_MAX_SIZE = 256;

void PushBack(int arr[STACK_MAX_SIZE], int x);
void Pop(int arr[STACK_MAX_SIZE]);
size_t Find(int arr[STACK_MAX_SIZE], int x);
void QuickSort(int arr[STACK_MAX_SIZE], int low, int high);
void partition(int arr[STACK_MAX_SIZE], int low, int high, int m, int n);
void swap(int* a, int* b);

int main()
{
    int stack[STACK_MAX_SIZE];
    stack[STACK_MAX_SIZE - 1] = 0;

    for (size_t i = 0; i < STACK_MAX_SIZE - 1; ++i) {
        PushBack(stack, i);
    }
    assert(stack[STACK_MAX_SIZE - 1] == STACK_MAX_SIZE - 1);

    for (size_t i = 0; i < (STACK_MAX_SIZE >> 1) - 1; ++i) {
        Pop(stack);
    }
    assert(stack[STACK_MAX_SIZE - 1] == (STACK_MAX_SIZE >> 1));

    for (size_t i = 0; i < STACK_MAX_SIZE - 1; ++i) {
        size_t index = Find(stack, i);
        if (i < (STACK_MAX_SIZE >> 1)) {
            assert(index == i);
            cout << "Element " << i << " is at index " << index << endl;
        }
        else {
            assert(index == -1);
            cout << "Element " << i << " is not in the stack" << endl;
        }
    }

    srand(time(NULL));
    for (size_t i = 0; i < (STACK_MAX_SIZE >> 1); ++i) {
        PushBack(stack, rand() % STACK_MAX_SIZE + STACK_MAX_SIZE);
    }
    assert(stack[STACK_MAX_SIZE - 1] == STACK_MAX_SIZE - 1);

    QuickSort(stack, 0, static_cast<int>(STACK_MAX_SIZE - 2));

    for (size_t i = 0; i < stack[STACK_MAX_SIZE - 1]; ++i) {
        for (size_t j = 0; j < stack[STACK_MAX_SIZE - 1]; ++j) {
            if (j < i) {
                assert(stack[j] <= stack[i]);
            }
            else {
                assert(stack[i] <=stack[j]);
            }
        }
    }
    cout << "program ended" << endl;
    return 0;
}

void PushBack(int arr[STACK_MAX_SIZE], int x) {
    if (arr[STACK_MAX_SIZE - 1] == 255) {
        return;
    }
    else {
        int curr_size = arr[STACK_MAX_SIZE - 1];
        arr[curr_size] = x;
        ++arr[STACK_MAX_SIZE - 1];
    }

}
void Pop(int arr[STACK_MAX_SIZE]) {
    int curr_size = arr[STACK_MAX_SIZE - 1];
    if (curr_size == 1) {
        cout << "no elem!";
        return;
    }
    arr[curr_size-1];
    arr[STACK_MAX_SIZE - 1] = curr_size - 1;
    

}

size_t Find(int arr[STACK_MAX_SIZE], int x) {
    int curr_size = arr[STACK_MAX_SIZE - 1];
    for (int i = 0; i < curr_size + 1; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void QuickSort(int arr[STACK_MAX_SIZE], int low, int high) {
    if (low >= high) {
        return;
    }

    int pivot = low;
    int i = pivot + 1;
    int j = high;

    while (i <= j) {
        while ((i <= high) && (arr[i] < arr[pivot])) {
            ++i;
        }
        while ((j > low) && arr[j] >= arr[pivot]) {
            --j;
        }
        if (i > j) {
            swap(arr + j - 1, arr + pivot - 1);
        }
        else {
            swap(arr + i - 1, arr + j - 1);
        }
    }
    int leng1 = (j - 1) - low;
    int leng2 = high - (j + 1);
    partition(arr,low, high, j-1, j+1);
}

void partition(int arr[STACK_MAX_SIZE], int low, int high, int n, int m) {
    QuickSort(arr, low, n);
    QuickSort(arr, m, high);
}

void swap(int* a, int* b) {
    int* temp = a;
    *a = *b;
    *b = *temp;
}