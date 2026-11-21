#include <iostream>
#include <string>
class Person {
protected: std::string name; int id;
public: Person(std::string n, int i) : name(std::move(n)), id(i) {}
};
class Student : virtual public Person {
protected: double cgpa;
public: Student(std::string n, int i, double c) : Person(std::move(n), i), cgpa(c) {}
};
class Staff : virtual public Person {
protected: double salary;
public: Staff(std::string n, int i, double s) : Person(std::move(n), i), salary(s) {}
};
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(std::string n, int i, double c, double s)
        : Person(n, i), Student(n, i, c), Staff(n, i, s) {}
    void show() const { std::cout << name << " (ID " << id << ") CGPA: " << cgpa << ", Stipend: " << salary << "\n"; }
};
int main() {
    std::string n; int id; double c, s;
    std::cin >> n >> id >> c >> s;
    TeachingAssistant ta(n, id, c, s);
    ta.show();
    return 0;
}
