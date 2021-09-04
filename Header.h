#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <thread>
using namespace std;
class Student {
private:
    int Age;
    string Name;
public:
    Student(int m_age, string m_name) {
        Name = m_name;
        Age = m_age;
    }

    friend bool operator<(const Student& c1, const Student& c2);
    friend bool operator>(const Student& c1, const Student& c2);
    friend ostream& operator << (std::ostream& out, const Student& student);
};

bool operator<(const Student& c1, const Student& c2) {
    return c1.Age < c2.Age;
}

bool operator>(const Student& c1, const Student& c2) {
    return c1.Age > c2.Age;
}

std::ostream& operator << (std::ostream& out, const Student& student) {
std::cout <<"Name: "<< student.Name << endl;
std::cout <<"Age:" << student.Age<< endl;
return out;
}