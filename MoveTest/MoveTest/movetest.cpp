#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class MyString 
{
    char* string_content;  // 문자열 데이터를 가리키는 포인터
    int string_length;     // 문자열 길이

    int memory_capacity;  // 현재 할당된 용량

public:
    MyString()
    {
        std::cout << "생성자 호출 ! " << std::endl;
        string_length = 0;
        memory_capacity = 0;
        string_content = NULL;
    }

    // 문자열로 부터 생성
    MyString(const char* str)
    {
        std::cout << "생성자 호출 ! " << std::endl;
        string_length = strlen(str);
        memory_capacity = string_length;
        string_content = new char[string_length];

        for (int i = 0; i != string_length; i++) string_content[i] = str[i];
    }

    // 복사 생성자
    MyString(const MyString& str)
    {
        std::cout << "복사 생성자 호출 ! " << std::endl;
        string_length = str.string_length;
        memory_capacity = str.string_length;
        string_content = new char[string_length];

        for (int i = 0; i != string_length; i++)
            string_content[i] = str.string_content[i];
    }

    // 이동 생성자
    MyString(MyString&& str) noexcept
    {
        std::cout << "이동 생성자 호출 !" << std::endl;
        string_length = str.string_length;
        string_content = str.string_content;
        memory_capacity = str.memory_capacity;

        // 임시 객체 소멸 시에 메모리를 해제하지
        // 못하게 한다.
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
    cout << "첫 번째 추가 ---" << endl;
    vec.push_back(s);
    cout << "두 번째 추가 ---" << endl;
    vec.push_back(s);
    cout << "세 번째 추가 ---" << endl;
    vec.push_back(s);
    

    cout << "첫 번째 추가 ---" << endl;
    vec.emplace_back(s);
    cout << "두 번째 추가 ---" << endl;
    vec.emplace_back(s);
    cout << "세 번째 추가 ---" << endl;
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