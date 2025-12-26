#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool isUsernameTaken(const string& username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}


void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << " Username or password cannot be empty.\n";
        return;
    }

    if (isUsernameTaken(username)) {
        cout << " Username already exists. Try another.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << " Registration successful!\n";
}


void loginUser() {
    string username, password;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << " Login successful! Welcome, " << username << ".\n";
    else
        cout << " Invalid username or password.\n";
}


int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << " Exiting program.\n";
                break;
            default:
                cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
