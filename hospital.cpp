#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

struct Doctor {
    int id;
    string name;
    string specialty;
};

struct Appointment {
    int patientId;
    int doctorId;
    string date;
};

vector<Patient> patients;
vector<Doctor> doctors;
vector<Appointment> appointments;

void addPatient() {
    Patient p;
    cout << "Enter Patient ID: ";
    cin >> p.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, p.name);
    cout << "Enter Age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, p.disease);
    patients.push_back(p);
    cout << "Patient added successfully!\n";
}

void viewPatients() {
    cout << "\n--- Patient Records ---\n";
    for (const auto& p : patients) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << endl;
    }
}

void addDoctor() {
    Doctor d;
    cout << "Enter Doctor ID: ";
    cin >> d.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, d.name);
    cout << "Enter Specialty: ";
    getline(cin, d.specialty);
    doctors.push_back(d);
    cout << "Doctor added successfully!\n";
}

void viewDoctors() {
    cout << "\n--- Doctor Records ---\n";
    for (const auto& d : doctors) {
        cout << "ID: " << d.id << ", Name: " << d.name << ", Specialty: " << d.specialty << endl;
    }
}

void bookAppointment() {
    Appointment a;
    cout << "Enter Patient ID: ";
    cin >> a.patientId;
    cout << "Enter Doctor ID: ";
    cin >> a.doctorId;
    cin.ignore();
    cout << "Enter Appointment Date (dd/mm/yyyy): ";
    getline(cin, a.date);
    appointments.push_back(a);
    cout << "Appointment booked successfully!\n";
}

void viewAppointments() {
    cout << "\n--- Appointments ---\n";
    for (const auto& a : appointments) {
        cout << "Patient ID: " << a.patientId << ", Doctor ID: " << a.doctorId << ", Date: " << a.date << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== Hospital Management System ===\n";
        cout << "1. Add Patient\n2. View Patients\n3. Add Doctor\n4. View Doctors\n5. Book Appointment\n6. View Appointments\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: bookAppointment(); break;
            case 6: viewAppointments(); break;
            case 0: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
