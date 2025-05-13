#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MyString 
{
    char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
    int string_length;     // ���ڿ� ����

    int memory_capacity;  // ���� �Ҵ�� �뷮

public:
    MyString()
    {
        std::cout << "������ ȣ�� ! " << std::endl;
        string_length = 0;
        memory_capacity = 0;
        string_content = NULL;
    }

    // ���ڿ��� ���� ����
    MyString(const char* str)
    {
        std::cout << "������ ȣ�� ! " << std::endl;
        string_length = strlen(str);
        memory_capacity = string_length;
        string_content = new char[string_length];

        for (int i = 0; i != string_length; i++) string_content[i] = str[i];
    }

    // ���� ������
    MyString(const MyString& str)
    {
        std::cout << "���� ������ ȣ�� ! " << std::endl;
        string_length = str.string_length;
        memory_capacity = str.string_length;
        string_content = new char[string_length];

        for (int i = 0; i != string_length; i++)
            string_content[i] = str.string_content[i];
    }

    // �̵� ������
    MyString(MyString&& str) noexcept
    {
        std::cout << "�̵� ������ ȣ�� !" << std::endl;
        string_length = str.string_length;
        string_content = str.string_content;
        memory_capacity = str.memory_capacity;

        // �ӽ� ��ü �Ҹ� �ÿ� �޸𸮸� ��������
        // ���ϰ� �Ѵ�.
        str.string_content = nullptr;
    }

    virtual ~MyString()
    {
        if (string_content) delete[] string_content;
    }
};

int main() {
    MyString s("abc");
    vector<MyString> vec;
    vec.resize(0);

    /*
    cout << "ù ��° �߰� ---" << endl;
    vec.push_back(s);
    cout << "�� ��° �߰� ---" << endl;
    vec.push_back(s);
    cout << "�� ��° �߰� ---" << endl;
    vec.push_back(s);
    

    cout << "ù ��° �߰� ---" << endl;
    vec.emplace_back(s);
    cout << "�� ��° �߰� ---" << endl;
    vec.emplace_back(s);
    cout << "�� ��° �߰� ---" << endl;
    vec.emplace_back(s);
    */

    cout << "push_back ---" << endl;
    vec.push_back("abc");
    cout << "emplace_back ---" << endl;
    vec.emplace_back("abc");
    cout << "push_back ---" << endl;
    vec.push_back(s);
    cout << "emplace_back ---" << endl;
    vec.emplace_back(s);
}