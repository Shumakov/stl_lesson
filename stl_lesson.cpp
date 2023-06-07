#include <iostream>
#include <memory>
#include <ctime>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

/*
Контейнер — блок для хранения данных, управления
ими и размещения . Иными словами, это объект, пред-
назначенный для хранения и использования других
элементов
*/
/*
Алгоритм — специальная функция для работы с дан-
ными, содержащимися в контейнере .
*/

/*
Итератор — специальный указатель, который позволяет
алгоритмам перемещаться по данным конкретного
контейнера
*/

/*
Функторы  — механизм для инкапсуляции функций
в конкретном объекте для использования его другими
компонентами
*/
/*
Предикат — функция нестандартного типа, используемая
в контейнере. Предикат бывает унарный и бинарный.
Может возвращать логическое значение (истину либо ложь)
*/

// итераторы
// Итератор — это своеобразный указатель общего назначения.
// Разная реализация в разных контейнерах

int main666() {
    setlocale(LC_ALL, "rus");

    vector <int> v = { 1,2,3,4,5,6,7,8,9 };
    vector<int>::iterator it = v.begin(); // Указатель на начало контейнера
    cout << *it << endl;
    

    
       
    //vector<int>::iterator it_end = v.end(); // Указатель на конец контейнера    
    
    
    //cout << *it_end << endl; - программа упадет т.к. итератор указывает за последний элемент массива

        
    cout << *(it + 5) << endl;

    //advance(it, 4); - пердвигаем итератор на заданное смещение

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        cout << *i << ", ";
    cout << endl;

    for (auto i : v)
        cout << i << ", ";
    cout << endl;

    cout << it[1] << endl;

    return 0;

    v.insert(it + 1, 44444); // вставка


    // константные итераторы
    for (vector<int>::const_iterator i = v.cbegin(); i != v.cend(); i++)
        cout << *i << " ";
    cout << endl;

    it = v.begin();
    v.erase(it); // удаление


    for (vector<int>::const_iterator i = v.cbegin(); i != v.cend(); i++)
        cout << *i << " ";
    cout << endl;


    it = v.begin();
    v.erase(it, it + 3);


    for (vector<int>::const_iterator i = v.cbegin(); i != v.cend(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;
}





//vector контейнер - динамический массив
/*
Вектор хранит элементы заданного типа в линейном расположении и обеспечивает
быстрый случайный доступ к любому элементу. Вектор является предпочтительным
контейнером для последовательности, если производительность случайного доступа
https://learn.microsoft.com/ru-ru/cpp/standard-library/vector-class?view=msvc-160#assign
*/

void print1(vector<int>& vec) {
    for (auto v = vec.begin(); v != vec.end(); ++v)
        cout << *v << " ";
    cout << endl;
}

void print(vector<int>& vec) {
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
}

void print2(vector<int>& vec) {
    // выход за границы!!! // Результат не предсказуем
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void print3(vector<int>& vec) {
    // выход за границы!!! Всегда ошибка
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
}

void print4(vector<int>& vec) {
    // выход за границы!!! Всегда ошибка (минус - скорость)
    for (int i = 0; i <= vec.size(); i++)
        try {
        cout << vec.at(i) << " ";
    }
    catch (out_of_range& oor) {
        cout << oor.what() << endl;
    }
    cout << endl;
}

void assign_test() {
    vector<int> v1, v2, v3;

    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v3.size() << endl;

    

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    cout << "v1 = ";
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;

    v2.assign(v1.begin(), v1.end());
    cout << "v2 = ";
    for (auto& v : v2) {
        cout << v << " ";
    }
    cout << endl;

    v3.assign(7, 4);
    cout << "v3 = ";
    for (auto& v : v3) {
        cout << v << " ";
    }
    cout << endl;

    v3.assign({ 5, 6, 7 });
    for (auto& v : v3) {
        cout << v << " ";
    }
    cout << endl;

    cout << "v1 = ";
    for (auto& v : v1) {
        cout << v << " ";
    }
    cout << endl;
}


bool check(string str) {

    auto s = str.begin();
    auto e = str.end();
    --e;

    for (; s < e; ++s, --e)
        if (*s != *e)
            return false;
    return true;
}

bool check1(string word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i)
        if (word[i] != word[len - i - 1])
            return false;
    return true;
}

void check2(string str) {
    string str2 = str;
    string str3 = str;
    int a = str.length();
    for (int i{}; i < a; i++) {
        str2[i] = str.back();
        str.pop_back();

    }
    if (str3 == str2) {
        cout << "TRUE" << endl;
    }
    else {
        cout << "False" << endl;
    }

};







int main6() {
    setlocale(LC_ALL, "rus");

    if (check("abxvcba"))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    

    string str = "abcdcba";
    string str_copy = str;

    reverse(str.begin(), str.end());

    if (str == str_copy)
    {
        cout << "good" << endl;
    }
    else
    {
        cout << "no good" << endl;
    }

    return 0;

    /*
        vector<vector<int>> v11(10, vector<int>(10,33));

        for (auto i: v11){
            for (auto j : i)
                cout <<j<<" ";
            cout << endl;
        }

        return 0;
    */


    //assign_test();



    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v.pop_back();

    v.push_back(5);
    v.push_back(6);

    v.insert(v.begin(), 99);

    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;

    print1(v);

    //return 0;
    //v.back() = 99;
    //cout << v.back()<< endl;    
    //Изменение размера вектора
    v.resize(10);
    
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
    
    print(v);

    
    

    v.clear();

    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;

    print(v);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;

    print(v);

    //return 0;

    //v.swap(v.front());

    //cout << v.capacity() << endl;
    //v.reserve(100);
    //cout << v.capacity() << endl;
    
    v.shrink_to_fit();
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;


    //cout << v.capacity() << endl;
    //cout << v.empty() << endl;

    v.reserve(100);

    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
       

    return 0;
}


/*
 шаблон класса контейнеров последовательностей,
 которые поддерживают их элементы в линейном расположении и
 разрешают эффективные вставки и удаления в любом расположении в последовательности.
 Последовательность хранится в виде двунаправленного связанного списка элементов,
 каждый из которых содержит элемент определенного типа Type.
 */


void printL(const list<int> li) {

    for (auto l : li)
        cout << l << " ";
    cout << endl;
}

bool pr(int a, int b) {

    return (a > b);
}

bool pr_del(int a) {

    return (a > 5);
}


int main() {
    setlocale(LC_ALL, "rus");

    list<int> li = { 1,2,3,4,5,7,6,8,9 };
    printL(li);
    li.push_back(9999);
    li.push_front(-34);
    printL(li);

    li.pop_back();
    li.pop_front();
    printL(li);

    //*(li.cbegin()) = 10000;

    //li.
    printL(li);
    

    return 0;

    li.sort();
    printL(li);

    li.sort(pr);
    printL(li);

    list<int> li2 = { 1,2,3,4,9,9,9,9,5,7,6,8,9 };
    printL(li2);

    li2.unique();
    printL(li2);


    li2.remove_if(pr_del);
    printL(li2);

    li2.assign(10, 34);
    printL(li2);

    list<int> li3(10, 44);
    printL(li3);

    li2.assign(li3.begin(), li3.end());
    printL(li2);

    auto it = li2.begin();

    it++;
    it--;
    --it;
    ++it;
    //list<int>::iterator it = li.begin();

    return 0;
}


// forward_list - односвязный список список
// для операций в начале списка.
void printLF(const forward_list<int> li) {
    for (auto l : li)
        cout << l << " ";
    cout << endl;
}

bool prLF(int a, int b) {
    return (a > b);
}

bool pr_delLF(int a) {
    return (a > 5);
}

int main7() {
    setlocale(LC_ALL, "rus");

    forward_list<int> li = { 1,2,3,4,5,7,6,8,9 };
    printLF(li);

    //только
    li.push_front(56);

    li.insert_after(li.before_begin(), 77);
    printLF(li);

    forward_list<int>::iterator it = li.begin();
    it++;
    //it--;

    return 0;
}





