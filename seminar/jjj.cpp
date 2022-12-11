#include <iostream>
#include <limits>
#include <cmath>
struct Student{
    char name[20];
    float mean_score;
};
bool operator<(const Student &s1,const Student &s2){
    return s1.mean_score < s2.mean_score;
}
bool operator>(const Student &s1, const Student &s2){
    return (s2<s1);
}
std::ostream& operator<<(std::ostream &os, Student &s){
    std::cout <<s.name << ": " << s.mean_score << '\n';
    return os;
}
void print(Student *arr, int n){
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << '\n';
    }
}
void swap(Student &a, Student &b){
    Student tmp = a;
    a = b;
    b = tmp;
}
void heapify(Student *arr, int n, int i)
{   int root = i;
    int left = i*2 + 1;
    int right = i*2 + 2;;

    if (left< n && arr[left] > arr[root]){
        root = left;
    }
    if (right < n && arr[right] > arr[root]){
        root = right;
    }

    if (root != i){
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }

}

void heapSort(Student *arr, int n){
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n-1; i >= 0; i --){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    int n;
    std::cin >> n;
    auto *arr = new Student[n];
    for (int i = 0; i<n; i++){
        std::cin >> arr[i].name;
        std::cin >> arr[i].mean_score;
    }
    heapSort(arr, n);
    print(arr, n);
}