#include <iostream>
#include <vector>
using namespace std;

// Base Class - Person
class Person {
protected:
    string name;
    int age;
    int id;
public:
    Person(string n = "", int a = 0, int i = 0) {
        name = n;
        age = a;
        id = i;
    }
    virtual void display() = 0; // Pure Virtual Function
};

// Patient Class
class Patient : public Person {
    string disease;
public:
    Patient(string n = "", int a = 0, int i = 0, string d = "") 
        : Person(n, a, i), disease(d) {}
    void display() {
        cout << "Patient ID: " << id << ", Name: " << name 
             << ", Age: " << age << ", Disease: " << disease << endl;
    }
};

// Doctor Class
class Doctor : public Person {
    string specialization;
public:
    Doctor(string n = "", int a = 0, int i = 0, string s = "") 
        : Person(n, a, i), specialization(s) {}
    void display() {
        cout << "Doctor ID: " << id << ", Name: " << name 
             << ", Age: " << age << ", Specialization: " << specialization << endl;
    }
};

// Hospital Class
class Hospital {
    vector<Patient> patients;
    vector<Doctor> doctors;
public:
    void addPatient() {
        string name, disease;
        int age, id;
        cout << "\nEnter Patient ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Disease: "; getline(cin, disease);
        patients.push_back(Patient(name, age, id, disease));
        cout << "✅ Patient added successfully!\n";
    }

    void addDoctor() {
        string name, specialization;
        int age, id;
        cout << "\nEnter Doctor ID: "; cin >> id;
        cin.ignore();
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Age: "; cin >> age;
        cin.ignore();
        cout << "Enter Specialization: "; getline(cin, specialization);
        doctors.push_back(Doctor(name, age, id, specialization));
        cout << "✅ Doctor added successfully!\n";
    }

    void showPatients() {
        cout << "\n--- Patients List ---\n";
        if (patients.empty()) {
            cout << "No patients found!\n";
            return;
        }
        for (auto &p : patients) {
            p.display();
        }
    }

    void showDoctors() {
        cout << "\n--- Doctors List ---\n";
        if (doctors.empty()) {
            cout << "No doctors found!\n";
            return;
        }
        for (auto &d : doctors) {
            d.display();
        }
    }
};

// Main Function
int main() {
    Hospital h;
    int choice;
    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. View Patients\n";
        cout << "4. View Doctors\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.addPatient(); break;
            case 2: h.addDoctor(); break;
            case 3: h.showPatients(); break;
            case 4: h.showDoctors(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "❌ Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
