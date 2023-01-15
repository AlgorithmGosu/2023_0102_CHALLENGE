//
// Created by haram on 2023-01-15.
//
#include <iostream>
#include <forward_list>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> vec = {
            "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg", "Sebastian Vettel", "Lewis Hamilton",
            "Sebastion Vettel", "Sebastion Vettel", "Sebastion Vettel", "Fernando Alonso"
    };

    auto it = vec.begin();
    cout << "���� �ֱ� �����: " << *it << endl;

    it += 8;
    cout << "8�� �� �����: " << *it << endl;

    advance(it, -3);
    cout << "�� �� 3�� �� �����: " << *it << endl;

    forward_list<string> fwd(vec.begin(), vec.end());

    auto it2 = fwd.begin();
    cout << "���� �ֱ� �����: " << *it2 << endl;

    advance(it2, 5); // ���� �ð�
    cout << "5�� �� �����: " << *it2 << endl;

    // forward_list�� ���������θ� �̵��� �� ����
    // advance(it1, -2);�� �ȵ�

    // it1 += 2; �� �ȵ�

    return 0;

}