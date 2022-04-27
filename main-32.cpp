/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream> 
#include <string>
#include <fstream>


using namespace std;


struct patient // sructure for the patients
{
    string name;
    string time;
    string symptoms;
    patient* next;
};


void addSymptom(patient*& head); // funciton for adding symptoms
void changeTime(patient*& head); // function for changing time
void deletepatient(patient*& head); // function for deleting patient
void saveToFile(patient*& head); // function for saving file to search 
void printFile(patient*& head); // funciton for printing file
void endProgram(patient*& head); // funciton to end program 


int main() // main function starts 
{
    patient* head = NULL; 
    int choice;
    do // do while loop starts 
    {
        cout << "Press 1 to Add Symptom/Symptoms" << endl;
        cout << "Press 2 to Change appointment time" << endl;
        cout << "Press 3 to Delete Patient" << endl;
        cout << "Press 4 to Save to file" << endl;
        cout << "Press 5 to Print out file" << endl;
        cout << "Press 6 to end program" << endl;
        cin >> choice;
        switch (choice) // switch begins 
        {
        case 1: 
            addSymptom(head);
            break;
        case 2: 
            changeTime(head);
            break;
        case 3: 
            deletepatient(head);
            break;
        case 4: 
            saveToFile(head);
            break;
        case 5: 
            printFile(head);
            break;
        case 6: 
            endProgram(head);
            break;
        default: 
            cout << "Invalid choice" << endl; // default 
            break;
        }
    } while (choice != 6); 
    return 0; // end of the main function 
}


void addSymptom(patient*& head) 
{
    patient* newpatient = new patient; 
    cout << "Enter patient name: ";
    cin >> newpatient->name;
    cout << "Enter patient time: ";
    cin >> newpatient->time;
    cout << "Enter patient symptoms: ";
    cin >> newpatient->symptoms;
    getline (cin >> ws, newpatient->symptoms); // All whitespace characters will be obtained by ws.
    newpatient->next = head; 
    head = newpatient;
}


void changeTime(patient*& head) 
{
    string name;
    string time;
    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter patient time: ";
    cin >> time;
    patient* current = head; 
    while (current != NULL) 
    {
        if (current->name == name) 
        {
            current->time = time;
            cout << "Patient time changed" << endl;
            return;
        }
        current = current->next; 
    }
    cout << "Patient not found" << endl;
}


void deletepatient(patient*& head)  
{
    string name;
    cout << "Enter patient name: ";
    cin >> name;
    patient* current = head; 
    patient* previous = NULL; 
    while (current != NULL)
    {
        if (current->name == name)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next; 
            }
            cout << "Patient has been deleted" << endl;
            delete current;
            return;
        }
        previous = current;
        current = current->next; 
    }
    cout << "Patient was not found" << endl;
}


void saveToFile(patient*& head) // file is used to be search for patient names
{
    ofstream outFile;
    outFile.open("patient.txt"); // opening file 
    patient* current = head;
    while (current != NULL)
    {
        outFile << current->name << endl;
        outFile << current->time << endl;
        outFile << current->symptoms << endl;
        current = current->next;
    }
    outFile.close(); // closing file 
}


void printFile(patient*& head) 
{
    ifstream inFile;
    inFile.open("patient.txt"); 
    string name;
    string time;
    string symptoms;
    while (inFile >> name >> time >> symptoms) // while infile is not empty while loop
    {
        cout << name << endl;
        cout << time << endl;
        cout << symptoms << endl;
    }
    inFile.close(); 
}


void endProgram(patient*& head) 
{
    patient* current = head; // creating current node
    while (current != NULL)
    {
        patient* temp = current;
        current = current->next; // moving to next node 
        delete temp;
    }
    cout << "Program ended" << endl; 
}
 void swapNodes(patient * &p1, patient * &p2) // function for swaping nodes
  {
        string name,time,symptoms;
        name = p1->name;
        p1->name = p2->name;
        p2->name = name;
        time = p1->name;
        p1->time = p2->time;
        p1->time = time; 
        symptoms = p1->symptoms;
        p1->symptoms = p2->symptoms;
        p2->symptoms = symptoms;

    }

void sortLinkedList(patient*& head) // function to sorting appointment times 
{
    patient* current = head;

    while (current != NULL)
    {
        patient* minNode = current;
        patient* second = current->next;
        while (second != NULL)
        {
            if (minNode->time > second->time) // connected to appointment time 
            {
                minNode = second;
            }
            second = second->next;
        }
        swapNodes(minNode, current);

        current = current->next;
    }
  }
    
