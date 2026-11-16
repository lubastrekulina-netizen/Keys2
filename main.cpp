#include <iostream>
#include <string>
using namespace std;

// ============================================================
// БАЗОВЫЙ КЛАСС
// ============================================================
class Animal {
protected:
    string name;   // имя животного (доступно наследникам)

public:
  
    Animal(string n) {
        name = n;
        cout << "[Animal] создан объект: " << name << endl;
    }

    
    void show() {
        cout << "Я животное по имени " << name << endl;
    }

    
    string sound() {
        return "...";
    }

    
    string kind() {
        return "Животное";
    }
};

// ============================================================
// ПРОИЗВОДНЫЙ КЛАСС 1 — Собака
// ============================================================
class Dog : public Animal {
public:
    
    Dog(string n) : Animal(n) {
        cout << "[Dog] создан объект: " << name << endl;
    }

    
    string sound() {
        return "Гав-гав";
    }

   
    string kind() {
        return "Собака";
    }

    
    string fetch() {
        return name + " приносит палку";
    }
};

// ============================================================
// ПРОИЗВОДНЫЙ КЛАСС 2 — Кошка
// ============================================================
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {
        cout << "[Cat] создан объект: " << name << endl;
    }

    string sound() {
        return "Мяу";
    }

    string kind() {
        return "Кошка";
    }

    
    string sleep() {
        return name + " спит на подоконнике";
    }
};

// ============================================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================================
int main() {
    setlocale(LC_ALL, "Russian");   // русский текст в консоли

    cout << "========== 1. Создание объектов ==========" << endl;
    Dog dog("Шарик");
    Cat cat("Мурка");

    cout << "\n========== 2. Вызов методов базового класса ==========" << endl;
    dog.show();
    cat.show();

    cout << "\n========== 3. Вызов переопределённых методов ==========" << endl;
    cout << "Собака говорит: " << dog.sound() << endl;
    cout << "Кошка говорит:  " << cat.sound() << endl;
    cout << "Вид собаки: " << dog.kind() << endl;
    cout << "Вид кошки:  " << cat.kind() << endl;

    cout << "\n========== 4. Вызов собственных методов наследников ==========" << endl;
    cout << dog.fetch() << endl;
    cout << cat.sleep() << endl;

    cout << "\n========== 5. Полиморфизм через указатель на базовый класс ==========" << endl;
    
    Animal* p1 = &dog;
    Animal* p2 = &cat;

    cout << "p1->show():  ";
    p1->show();

    cout << "p2->show():  ";
    p2->show();

    
    cout << "\n(без virtual) p1->sound() = " << p1->sound() << endl;
    cout << "(без virtual) p2->sound() = " << p2->sound() << endl;

    cout << "\n========== 6. Что будет, если вызвать напрямую ==========" << endl;
    cout << "dog.sound() = " << dog.sound() << endl;
    cout << "cat.sound() = " << cat.sound() << endl;

    cout << "\n========== 7. Проверка типа через указатель ==========" << endl;
   
    Dog* d = dynamic_cast<Dog*>(p1);
    if (d != nullptr) {
        cout << "p1 указывает на Dog, его метод fetch(): " << d->fetch() << endl;
    }

    Cat* c = dynamic_cast<Cat*>(p2);
    if (c != nullptr) {
        cout << "p2 указывает на Cat, его метод sleep(): " << c->sleep() << endl;
    }

    cout << "\nПрограмма завершена." << endl;
    return 0;
}