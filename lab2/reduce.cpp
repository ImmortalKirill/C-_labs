//
// Created by kiril on 10.03.2022.
//
#include <iostream>
#include <cmath>
float f(float x){
    return x;
}
float g(float x){
    return 1;
}
float reduce(float *a, int size){
    int step = 1;
    while(step < size){
        int i = 0;
        while(i + step < size) {
            a[i] += a[i + step];
            i += 2*step;
        }
        step *= 2;
    }
    return a[0];
}
float mean(float const psi[], float const pdf[], float const dx, unsigned size){
    auto *arr = new float[size];
    for(int i = 0; i < size; i++){
        arr[i] = psi[i]*pdf[i];
    }
    float k = reduce(arr, size)*dx;
    delete[] arr;
    return k;
}

int main() {
    float a, b;
    int n;
    std::cin >> a >> b >> n;
    float dx = (b - a) / n;
    auto *psi = new float[n];
    auto *pdf = new float[n];
    for (int i = 0; i < n; i++) {
        psi[i] = f(a + dx * i + dx / 2);
        pdf[i] = g(a + dx * i + dx / 2);
    }
    std::cout << mean(psi, pdf, dx, n) << '\n';
}
