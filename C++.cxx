#include <iostream>
#include <fstream>  // Required for File Handling
#include <string>
#include <limits>

using namespace std;

class Student {
public:
    string Name, School, Department, Faculty, Password;
    int Age;
    double Cgpa;

    void setFaculty() {
        if (Department == "Computer Science" || Department == "Microbiology") Faculty = "Science";
        else if (Department == "Medicine") Faculty = "Clinical Sciences";
        else Faculty = "General Studies";
    }

    // Default constructor
    Student() {}

    // Function to save data to a file
    void saveToFile() {
        ofstream outFile("database.txt");
        if (outFile.is_open()) {
            outFile << Name << endl;
            outFile << Password << endl;
            outFile << School << endl;
            outFile << Department << endl;
            outFile << Age << endl;
            outFile << Cgpa << endl;
            outFile.close();
            cout << "\nAccount created and saved successfully!" << endl;
        }
    }

    // Function to load data from a file
    bool loadFromFile(string attemptName, string attemptPass) {
        ifstream inFile("database.txt");
        if (inFile.is_open()) {
            getline(inFile, Name);
            getline(inFile, Password);
            
            if (Name == attemptName && Password == attemptPass) {
                getline(inFile, School);
                getline(inFile, Department);
                inFile >> Age;
                inFile >> Cgpa;
                setFaculty();
                return true;
            }
        }
        return false;
    }

    void Intro() {
        cout << "\n======================="  << endl;        
        cout << "     Welcome back,       "<< endl;
        cout << "======================== "<< endl;        
        cout << "School: " << School << endl;
        cout <<"Department: "<<Department<<endl;
        cout<<"Faculty: " << Faculty << endl;
        cout << "CGPA: " << Cgpa << endl;
          	if ( Cgpa >= 4.5){
       		cout << "---***First Class Honours***---" << endl;
       	}
       	else if(Cgpa >= 2.5 ){
       		cout<< "--**Second Class Honours**--"<< endl;}
       	else{
       	cout << "--*Third class*--"<<endl;
       	}		
       } 
   
};
// Validation for numbers
double getValidNumber(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input! Use numbers only." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Student user;
    int choice;

    cout << "1. Login\n2. Register (New User)\nSelect option: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 2) {
        // REGISTRATION
        cout << "Enter Name: "; getline(cin, user.Name);
        cout << "Create Password: "; getline(cin, user.Password);
        cout << "Enter School: "; getline(cin, user.School);
        cout << "Enter Department: "; getline(cin, user.Department);
        user.Age = (int)getValidNumber("Enter Age: ");
        user.Cgpa = getValidNumber("Enter CGPA: ");
        
        user.saveToFile();
    } 
    else if (choice == 2){
        // LOGIN
        string lName, lPass;
        cout << "Enter Name: "; getline(cin, lName);
        cout << "Enter Password: "; getline(cin, lPass);

        if (user.loadFromFile(lName, lPass)) {
            user.Intro();
        } else {
            cout << "\nLogin Failed! Incorrect name or password." << endl;
        }
    }

    return 0;
}
