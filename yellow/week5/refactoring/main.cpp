#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    Person(const string& name) : name_(name) {}

    virtual void Walk(const string& destination) const = 0;

    virtual string Type() const = 0;

    virtual string Name() const { return name_; };

private:
    const string name_;

protected:
    string Prefix() const {
        return Type() + ": " + Name();
    }
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong) : Person(name), favouriteSong_(favouriteSong) {}

    void Learn() const {
        cout << Prefix() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << Prefix() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << Prefix() << " sings a song: " << FavouriteSong() << endl;
    }

    string Type() const override {
        return "Student";
    }

    string FavouriteSong() const {
        return favouriteSong_;
    }

private:
    const string favouriteSong_;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject) : Person(name), subject_(subject) {}

    void Teach() const {
        cout << Prefix() << " teaches: " << Subject() << endl;
    }

    void Walk(const string& destination) const override {
        cout << Prefix() << " walks to: " << destination << endl;
    }

    string Type() const override {
        return "Teacher";
    }

    string Subject() const {
        return subject_;
    }

private:
    const string subject_;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name) {}

    void Check(Person& p) const {
        cout << Prefix() << " checks " << p.Type() << ". "
             << p.Type() << "'s name is: " << p.Name() << endl;
    }

    void Walk(const string& destination) const override {
        cout << Prefix() << " walks to: " << destination << endl;
    }

    string Type() const override {
        return "Policeman";
    }
};


void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");
    Policeman p2("John");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(t);
    p.Check(s);
    p.Check(p2);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
