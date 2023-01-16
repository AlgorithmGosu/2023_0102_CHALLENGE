//
// Created by haram on 2023-01-15.
//
#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

// �ù� ������ ������ ����ü
struct citizen{
    string name;
    int age;
};

// �ù� ���� ����� ���� << operator
ostream &operator<<(ostream &os, const citizen &c){
    return (os << "[" << c.name << ", " << c.age << "]");
}

int main(){
    forward_list<citizen> citizens = {{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}};

    // ���� ����
    auto citizens_copy = citizens;

    // ��� �ù� ���
    cout << "ALL citizens: ";
    for(const auto &c: citizens)
        cout << c << " ";
    cout << endl;

    // �����Լ��� �̿��Ͽ� citizen�� age�� 19���� ���� �ùε� list���� ����
    citizens.remove_if([](const citizen &c){
        return (c.age < 19);
    });

    // ��ǥ�� �� �ִ� �ù� ���
    cout << "citizens(can vote): ";
    for(const auto &c : citizens)
        cout << c << " ";
    cout << endl;

    // 18���� �ƴ� �ù� list���� ����
    citizens_copy.remove_if([](const citizen &c){
        return (c.age != 18);
    });

    cout << "citizens(can vote next year): ";
    for(const auto &c : citizens_copy)
        cout << c << " ";
    cout << endl;


    return 0;
}
