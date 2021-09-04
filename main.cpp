#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "Header.h"
using namespace std;

template <typename T>
vector<T> mergeSort(vector<T> avector) {
    if (avector.size() > 1) {
        int mid = avector.size() / 2;
        vector<T> lefthalf(avector.begin(), avector.begin() + mid);
        vector<T> righthalf(avector.begin() + mid, avector.begin() + avector.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k] = lefthalf[i];
                i++;
            }
            else {
                avector[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i < lefthalf.size()) {
            avector[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j < righthalf.size()) {
            avector[k] = righthalf[j];
            j++;
            k++;
        }

    }

    return avector;
}


int main() {
    vector<string> avector = {"a","c","cjbsj","sd","bschjvhjcsbchjsc","hcsbc"};
    vector<int> aves = { 1,3,2,5,4,3 };
    Student A(20, "Anton");
    Student B(18, "Bobo");
    Student C(17, "Carlo");
    Student D(21, "Doni");
    vector<Student> students = { A,B,C,D };
    thread TS(mergeSort<Student>, students);
    thread TA(mergeSort<string>,avector);
    thread TB(mergeSort<int>, aves);
    TA.join();
    TS.join();
    TB.join();
    for (int i = 0; i < avector.size(); i++) {
        std::cout<< avector[i]<< std::endl;
        if (i == (avector.size() - 1)) {
            cout << '\n\n\n\n';
        }
    }
    for (int i = 0; i < aves.size(); i++) {
        std::cout << aves[i] <<std::endl;
        if (i == (aves.size() - 1)) {
            std::cout << '\n\n\n\n';
        }
    }
    for (int i = 0; i < students.size(); i++) {
        std::cout << students[i] <<std::endl;
        if (i == (students.size() - 1)) {
            std::cout << '\n\n\n\n';
        }
    }
    return 0;
}