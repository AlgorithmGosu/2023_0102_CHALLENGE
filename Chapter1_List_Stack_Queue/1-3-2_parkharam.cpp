//
// Created by haram on 2023-01-15.
//

#include <array>
#include <iostream>
#include <type_traits> // Ÿ�� ���� ������ ���� ���ø� ��Ÿ �Լ� ����


// ���� �Լ�(builder function) - �Է� ������ Ÿ���� ��ȣ�� �� ����� �� �ִ�.
// ���� ��ȯ ����(trailing return type)
// auto Ű����� ���ǵ� �Լ��� ��ȯ���� ��������� �˷���
template<typename ... Args> // ... template parameter pack
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof... (args)>
{
    // common_type�� �̿��ؼ� array�� ������ Ÿ�� ����
    using commonType = typename std::common_type<Args...>::type;
    // lvalue�� rvalue
    // lvalue: ���� ǥ���� ���Ŀ��� �������� �ʰ� ���ӵǴ� ��ü
        // lvalue�� ref -> &x
    // rvalue: ǥ���� ���Ŀ��� ���̻� �������� �ʴ� �ӽ� ��
        // rvalue�� ref -> &&x

    // ���ø��� ����ϴ� ��쿡�� �����Ϸ��� l-value���� r-value���� �������� ���Ѵ�.
    // std::forward�� ���� �� l-value�� r-value Ÿ���� ��Ȯ�ϰ� ������ �� �ִ�.
    return {std::forward<commonType>((Args&&)args)...};
}

int main(){
    auto data = build_array(1, 0u, 'a', 3.2f, false);
    for(auto i: data)
        std::cout << i << " ";
    std::cout << std::endl;

    // ��� ������ Ÿ���� �ϳ��� ���� Ÿ������ ��ȯ�� �� ����
    // -> ���� �߻� (template argument deduction/substitution failed)"
//    auto data2 = build_array(1, "Packt", 2.0);
}