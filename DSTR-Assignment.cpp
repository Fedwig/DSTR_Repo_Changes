// DSTR-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
using namespace std;


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;



// Structure for a car
struct car {
    int carID;
    string carTitle;
    int carPrice;
    int carRegistrationDate;
    int carMileage;
    string carFuelType;
    string carTransmission;
    string carEngineSize;
    int carDoorNum;
    string carColour;
    string carBodyType;
    string carURL;
    string carInitialSaleDate;
    string carStatus;
    car* carNext;
};


struct staff
{
    int staffID;
    string staffName;
    string staffPassword;
    string staffPosition;
    staff* staffNext;
};


struct customer
{
    string customerID;
    string customerName;
    string customerPhoneNum;
    double customerDeposit;
    customer* custNext;
};


struct salesReport
{
    //variables for sales report
};

struct billReport
{
    //variable for bill report
};


struct customerReport
{
   //variables for customer report
};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class CarList {

public:

    car* carHead = NULL;
    car* tail = NULL;

    car* createNewNode(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFuelType, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        //1. create structure in the heap location
        car* newNode = new car;

        //2. assigning the data into the node
        newNode->carID = carID;
        newNode->carTitle = carTitle;
        newNode->carPrice = carPrice;
        newNode->carRegistrationDate = carRegistrationDate;
        newNode->carMileage = carMileage;
        newNode->carFuelType = carFuelType;
        newNode->carTransmission = carTransmission;
        newNode->carEngineSize = carEngineSize;
        newNode->carDoorNum = carDoorNum;
        newNode->carColour = carColour;
        newNode->carBodyType = carBodyType;
        newNode->carURL = carURL;
        newNode->carInitialSaleDate = carInitialSaleDate;
        newNode->carStatus = carStatus;
        newNode->carNext = NULL; //always start with NULL first in newnode

        //3. return back the new created node to the other function
        return newNode;
    }


    void displayCarList()
    {
        car* current = carHead;
        while (current != NULL) // Is it the end of the list?
        {
            cout << current->carID << " - ";
            cout << current->carTitle << " - ";
            cout << current->carPrice << " - ";
            cout << current->carRegistrationDate << " - ";
            cout << current->carMileage << " - ";
            cout << current->carFuelType << " - ";
            cout << current->carTransmission << " - ";
            cout << current->carEngineSize << " - ";
            cout << current->carDoorNum << " - ";
            cout << current->carColour << " - ";
            cout << current->carBodyType << " - ";
            cout << current->carURL << " - ";
            cout << current->carInitialSaleDate << " - ";
            cout << current->carStatus << endl;
            current = current->carNext; // Move until the end
        }
        cout << "List is ended here!" << endl
            << endl;
    }

    void displayCarList2(car* carHead)
    {
        car* current = carHead;
        while (current != NULL) // Is it the end of the list?
        {
            cout << current->carID << " - ";
            cout << current->carTitle << " - ";
            cout << current->carPrice << " - ";
            cout << current->carRegistrationDate << " - ";
            cout << current->carMileage << " - ";
            cout << current->carFuelType << " - ";
            cout << current->carTransmission << " - ";
            cout << current->carEngineSize << " - ";
            cout << current->carDoorNum << " - ";
            cout << current->carColour << " - ";
            cout << current->carBodyType << " - ";
            cout << current->carURL << " - ";
            cout << current->carInitialSaleDate << " - ";
            cout << current->carStatus << endl;
            current = current->carNext; // Move until the end
        }
        cout << "List is ended here!" << endl << endl;
    }

    void insertToFrontOfList(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFueltype, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        car* newnode = createNewNode(carID, carTitle, carPrice, carRegistrationDate, carMileage,
            carFueltype, carTransmission, carEngineSize, carDoorNum, carColour,
            carBodyType, carURL, carInitialSaleDate, carStatus);

        if (carHead == NULL)
        {
            carHead = newnode;
        }
        else
        {
            newnode->carNext = carHead;
            carHead = newnode;
        }
        return;
    }

    car* insertToTheEndList(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFueltype, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        //create a newnode
        car* newnode = createNewNode(carID, carTitle, carPrice, carRegistrationDate, carMileage,
            carFueltype, carTransmission, carEngineSize, carDoorNum, carColour,
            carBodyType, carURL, carInitialSaleDate, carStatus);

        //attach your newnode to the list
        if (carHead == NULL) //list still empty
        {
            carHead = newnode;
        }
        else //list is not empty
        {
            car* current = carHead;

            while (current->carNext != NULL)
            {
                current = current->carNext;
            }
            //if found the last node? ->attach the new node into the end of the last node
            current->carNext = newnode;
        }

        return carHead;
    }

    void storeInCarLinkedList(string fileName) {
        ifstream file(fileName);
        string line;
        //car* tail = NULL;
        string header;

        // Read data from CSV file
        // Each iteration creates a new car with car objects listed below in the nested while loop

        getline(file, header);
        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            int i = 0;
            car* newNode = new car;

            // Parse CSV line
            while (getline(ss, cell, ',')) {
                switch (i) {
                case 0:
                    newNode->carID = stoi(cell);
                    break;
                case 1:
                    newNode->carTitle = cell;
                    break;
                case 2:
                    newNode->carPrice = stod(cell);
                    break;
                case 3:
                    newNode->carRegistrationDate = stoi(cell);
                    break;
                case 4:
                    newNode->carMileage = stoi(cell);
                    break;
                case 5:
                    newNode->carFuelType = cell;
                    break;
                case 6:
                    newNode->carTransmission = cell;
                    break;
                case 7:
                    newNode->carEngineSize = cell;
                    break;
                case 8:
                    newNode->carDoorNum = stoi(cell);
                    break;
                case 9:
                    newNode->carColour = cell;
                    break;
                case 10:
                    newNode->carBodyType = cell;
                    break;
                case 11:
                    newNode->carURL = cell;
                    break;
                case 12:
                    newNode->carInitialSaleDate = cell;
                    break;
                case 13:
                    newNode->carStatus = cell;
                    break;
                }
                i++;
            }
            insertToTheEndList(newNode->carID, newNode->carTitle, newNode->carPrice, newNode->carRegistrationDate, newNode->carMileage,
                newNode->carFuelType, newNode->carTransmission, newNode->carEngineSize, newNode->carDoorNum, newNode->carColour,
                newNode->carBodyType, newNode->carURL, newNode->carInitialSaleDate, newNode->carStatus);
        }

        return;
    }

    // Function to search for an ID in linked list using linear search
    car* searchID(int id) {
        car* current = carHead;

        // Traverse linked list
        while (current != NULL) {
            // Check if current node's ID matches search ID
            if (current->carID == id) {
                return current;
            }
            current = current->carNext;
        }

        return NULL;
    }



    void SearchAndUpdateBasedCarID(int CarID)
    {
        car* current = carHead;
        while (current != NULL)
        {
            if (CarID == current->carID)
            {
                cout << endl;
                current->carStatus = "Booked";

                displayUpdateCarDetails(current->carID);
                return;
            }
            current = current->carNext;

        }
        cout << "Car ID does not EXIST!! Please Try Again. " << endl;
    }


    void displayUpdateCarDetails(int carID) {

        car* car = binarySearch(carID);

        // Print search results

        if (car != NULL) {
            cout << "\n\t===========================================================================================" << endl;
            cout << "\t|| ID: " << car->carID << endl;
            cout << "\t||" << endl;
            cout << "\t|| Title: " << car->carTitle << endl;
            cout << "\t||" << endl;
            cout << "\t|| Price: " << car->carPrice << endl;
            cout << "\t||" << endl;
            cout << "\t|| Registration Date: " << car->carRegistrationDate << endl;
            cout << "\t||" << endl;
            cout << "\t|| Mileage: " << car->carMileage << endl;
            cout << "\t||" << endl;
            cout << "\t|| Fuel Type: " << car->carFuelType << endl;
            cout << "\t||" << endl;
            cout << "\t|| Transmission: " << car->carTransmission << endl;
            cout << "\t||" << endl;
            cout << "\t|| Engine Size: " << car->carEngineSize << endl;
            cout << "\t||" << endl;
            cout << "\t|| Number of Doors: " << car->carDoorNum << endl;
            cout << "\t||" << endl;
            cout << "\t|| Colour: " << car->carColour << endl;
            cout << "\t||" << endl;
            cout << "\t|| Body Type: " << car->carBodyType << endl;
            cout << "\t||" << endl;
            cout << "\t|| URL: " << car->carURL << endl;
            cout << "\t||" << endl;
            cout << "\t|| Initial Sale Date: " << car->carInitialSaleDate << endl;
            cout << "\t||" << endl;
            cout << "\t|| Status: " << car->carStatus << endl;
            cout << "\t===========================================================================================" << endl;
            cout << endl;
            cout << "\n\tCar has been booked successfully." << endl;
        }

        if (car != NULL)
        {
            // Open the CSV file in append mode
            std::ofstream csvFile("booked_car.csv", std::ios_base::app);

            csvFile << car->carID << ","
                << car->carTitle << ","
                << car->carPrice << ","
                << car->carRegistrationDate << ","
                << car->carMileage << ","
                << car->carFuelType << ","
                << car->carTransmission << ","
                << car->carEngineSize << ","
                << car->carDoorNum << ","
                << car->carColour << ","
                << car->carBodyType << ","
                << car->carURL << ","
                << car->carInitialSaleDate << ","
                << car->carStatus << std::endl;

            // Close the CSV file
            csvFile.close();
        }

        if (car != NULL)
        {
            updateCarList();
        }

        else
        {
            cout << "Car ID not Found" << endl;
        }

        return;
    }

    void updateCarList() {
        car* current = carHead;
        ofstream myfile;
        myfile.open("carlist.csv");
        myfile << "Car ID, Title, Price, RegistrationDate, Mileage, Fuel Type, Transmission, Engine Size, Doors, Colour, Body Type, URL, Sale Date, Car Status\n";
        while (current != NULL) {
            myfile << current->carID << ","
                << current->carTitle << ","
                << current->carPrice << ","
                << current->carRegistrationDate << ","
                << current->carMileage << ","
                << current->carFuelType << ","
                << current->carTransmission << ","
                << current->carEngineSize << ","
                << current->carDoorNum << ","
                << current->carColour << ","
                << current->carBodyType << ","
                << current->carURL << ","
                << current->carInitialSaleDate << ","
                << current->carStatus << "\n";
            current = current->carNext;
        }
        myfile.close();
    }


    int getCount()
    {
        int count = 0; // Initialize count
        car* current = carHead; // Initialize current
        while (current != NULL) {
            count++;
            cout << current << endl;;
            cout << current->carNext << endl;
            current = current->carNext;
        }
        return count;
    }

    //check merge bug to display for all entries within the csv file
    car* Merge(car* h1, car* h2)
    {
        car* t1 = new car;
        car* t2 = new car;
        car* temp = new car;

        // return if the first list is empty.
        if (h1 == NULL)
            return h2;

        // return if the second list is empty.
        if (h2 == NULL)
            return h1;

        t1 = h1;

        // a loop to traverse the second list, to merge the nodes to h1 in sorted way.
        while (h2 != NULL)
        {
            // taking head node of second list as t2.
            t2 = h2;

            // shifting second list head to the carNext.
            h2 = h2->carNext;
            t2->carNext = NULL;

            // if the data value is lesser than the head of first list add that node at the beginning.
            if (h1->carID > t2->carID)
            {
                t2->carNext = h1;
                h1 = t2;
                t1 = h1;
                continue;
            }

            // traverse the first list.
        flag:
            if (t1->carNext == NULL)
            {
                t1->carNext = t2;
                t1 = t1->carNext;
            }
            // traverse first list until t2->data more than node's data.
            else if ((t1->carNext)->carID <= t2->carID)
            {
                t1 = t1->carNext;
                goto flag;
            }
            else
            {
                // insert the node as t2->data is lesser than the carNext node.
                temp = t1->carNext;
                t1->carNext = t2;
                t2->carNext = temp;
            }
        }

        // return the head of new sorted list.
        return h1;
    }


    // A function implementing Merge Sort on linked list using reference.
    void MergeSort(car* carHead)
    {
        car* first = new car;
        car* second = new car;
        car* temp = new car;
        first = carHead;
        temp = carHead;

        // Return if list have less than two nodes.
        if (first == NULL || first->carNext == NULL)
        {
            return;
        }
        else
        {
            // Break the list into two half as first and second as head of list.
            while (first->carNext != NULL)
            {
                first = first->carNext;
                if (first->carNext != NULL)
                {
                    temp = temp->carNext;
                    first = first->carNext;
                }
            }
            second = temp->carNext;
            temp->carNext = NULL;
            first = carHead;
        }

        // Implementing divide and conquer approach.
        MergeSort(first);
        MergeSort(second);

        // Merge the two part of the list into a sorted one.      
        carHead = Merge(first, second);
    }

    car* middle(car* start, car* last)
    {
        if (start == NULL)
            return NULL;

        car* slow = start;
        car* fast = start->carNext;

        while (fast != last)
        {
            fast = fast->carNext;
            if (fast != last)
            {
                slow = slow->carNext;
                fast = fast->carNext;
            }
        }

        return slow;
    }


    // Function for implementing the Binary
    // Search on linked list
    car* binarySearch(int value)
    {
        struct car* start = carHead;
        struct car* last = NULL;

        do
        {
            // Find middle
            car* mid = middle(start, last);

            // If middle is empty
            if (mid == NULL)
                return NULL;

            // If value is present at middle
            if (mid->carID == value)
                return mid;

            // If value is more than mid
            else if (mid->carID < value)
                start = mid->carNext;

            // If the value is less than mid.
            else
                last = mid;

        } while (last == NULL ||
            last != start);

        // value not present
        return NULL;
    }

    void bubbleSortCarRegDate() {
        car* i = carHead;

        while (i) {
            car* j = carHead;
            car* prev = carHead;
            while (j->carNext) {
                car* temp = j->carNext;
                if (j->carRegistrationDate > temp->carRegistrationDate) {
                    if (j == carHead) {
                        j->carNext = temp->carNext;
                        temp->carNext = j;
                        prev = temp;
                        carHead = prev;
                    }
                    else {
                        j->carNext = temp->carNext;
                        temp->carNext = j;
                        prev->carNext = temp;
                        prev = temp;
                    }
                    continue;
                }
                prev = j;
                j = j->carNext;
            }
            i = i->carNext;
        }
    }


    void searchItemBasedOnKeyword(string keyword)
    {
        car* current = carHead;
        int i = 0;
        cout << "The car list contains the keyword of '" << keyword << "' as below: " << endl;

        while (current != NULL)
        {                                                           //Don't use -1 because index may not be correct and cause error as it is a string
            if (current->carTitle.find(keyword) != string::npos) //string::npos not a single row or column has the keyword 
            {
                i++;
                cout << i << ". " << current->carTitle << " " << current->carID << " - " << current->carID << endl;
                current = current->carNext;
            }
            current = current->carNext;
        }
        cout << endl;
    }
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Staff : public CarList{


public:

    staff* staffHead = NULL;
    staff* staffTail = NULL;

    customer* custHead = NULL;
    customer* custTail = NULL;

    staff* createStaff(int staffID, string staffName, string staffPassword, string staffPosition) {
        staff* newStaffNode = new staff;
        newStaffNode->staffID = staffID;
        newStaffNode->staffName = staffName;
        newStaffNode->staffPassword = staffPassword;
        newStaffNode->staffPosition = staffPosition;
        newStaffNode->staffNext = NULL;
        return newStaffNode;
    }

    void addStaff(staff** head, int staffID, string staffName, string staffPassword, string staffPosition) {
        staff* newStaffNode = createStaff(staffID, staffName, staffPassword, staffPosition);
        if (*head == NULL) {
            *head = newStaffNode;
        }
        else {
            staff* current = *head;
            while (current->staffNext != NULL) {
                current = current->staffNext;
            }
            current->staffNext = newStaffNode;
        }
    }

    void displayUsers(staff* head) {
        staff* current = head;
        while (current != NULL) {
            cout << current->staffID << " " << current->staffName << " " << current->staffPassword << " " << current->staffPosition << endl;
            current = current->staffNext;
        }
    }

    bool checkUser(staff* head, string staffName, string staffPassword) {
        staff* current = head;
        while (current != NULL) {
            if (current->staffName == staffName && current->staffPassword == staffPassword) {
                return true;
            }
            current = current->staffNext;
        }
        return false;
    }


    //------------------------------------------------------------------------------------------------------------------------------------------

    customer* createNewCustomerNode(string customerID, string customerName, string customerPhoneNum, double customerDeposit)
    {
        //1. create structure in the heap location
        customer* newCustNode = new customer;

        //2. assigning the data into the node
        newCustNode->customerID = customerID;
        newCustNode->customerName = customerName;
        newCustNode->customerPhoneNum = customerPhoneNum;
        newCustNode->customerDeposit = customerDeposit;
        
        newCustNode->custNext = NULL; //always start with NULL first in newnode

        //3. return back the new created node to the other function
        return newCustNode;
    }
    
    customer* insertToTheEndList(string customerID, string customerName, string customerPhoneNum, double customerDeposit)
    {
        //create a new customer node
        customer* newCustNode = new customer;
        newCustNode->customerID = customerID;
        newCustNode->customerName = customerName;
        newCustNode->customerPhoneNum = customerPhoneNum;
        newCustNode->customerDeposit = customerDeposit;
        newCustNode->custNext = NULL;

        //attach your new customer node to the list
        if (custHead == NULL) //list still empty
        {
            custHead = newCustNode;
        }
        else //list is not empty
        {
            customer* current = custHead;

            while (current->custNext != NULL)
            {
                current = current->custNext;
            }
            //if found the last node? ->attach the new node into the end of the last node
            current->custNext = newCustNode;
        }

        return custHead;
    }


    void storeinCustomerLinkedList(string fileName) {
        ifstream file(fileName);
        string line;
        //customer* staffTail = NULL;
        string carHeader;

        // Read data from CSV file
        // Each iteration creates a new car with car objects listed below in the nested while loop

        getline(file, carHeader);
        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            int i = 0;
            customer* newCustNode = new customer;

            // Parse CSV line
            while (getline(ss, cell, ',')) {
                switch (i) {
                case 0:
                    newCustNode->customerID = cell;
                    break;
                case 1:
                    newCustNode->customerName = cell;
                    break;
                case 2:
                    newCustNode->customerPhoneNum = cell;
                    break;
                case 3:
                    newCustNode->customerDeposit = stod(cell);
                    break;
                }
                i++;
            }
            insertToTheEndList(newCustNode->customerID, newCustNode->customerName, newCustNode->customerPhoneNum, newCustNode->customerDeposit);
        }
        return;
    }


    customer* middleOfCustomerList(customer* head, customer* staffTail)
    {
        if (head == NULL)
            return NULL;

        customer* slow = head;
        customer* fast = head->custNext;

        while (fast != staffTail)
        {
            fast = fast->custNext;
            if (fast != staffTail)
            {
                slow = slow->custNext;
                fast = fast->custNext;
            }
        }
        return slow;
    }


    //// function for implementing the binary (Not working yet for customer)
    //// search on linked list
    //customer* binarysearchcustomerlist(string custid)
    //{
    //    struct customer* head = custhead;
    //    struct customer* tail = null; 

    //    do
    //    {
    //        // find middle
    //        customer* mid = middleofcustomerlist(head, tail);

    //        // if middle is empty
    //        if (mid == null)
    //            return null;

    //        // if value is present at middle
    //        if (mid->customerid == custid)
    //            return mid;

    //        // if value is more than mid
    //        else if (mid->customerid < custid)
    //            head = mid->custnext;

    //        // if the value is less than mid.
    //        else
    //            tail = mid;

    //    } while (tail == null ||
    //        tail != head);

    //    // value not present
    //    return null;
    //}


    // function to search for customer id in linked list using linear search
    customer* searchCustomerID(string keyword) {
        customer* current = custHead;

        // traverse linked list
        while (current != NULL) {
            // check if current node's customer id matches search id
            if (current->customerID == keyword) {
                return current;
            }
            current = current->custNext;
        }
        return custHead;
    }


    void searchItemBasedOnKeyword(string keyword)
    {

        customer* current = custHead;
        int i = 0;
        cout << "Search Keyword: '" << keyword << endl;
        cout << "Items in list found below:" << endl;

        while (current != NULL)
        {                                                           //Don't use -1 because index may not be correct and cause error as it is a string
            if (current->customerName.find(keyword) != string::npos) //string::npos not a single row or column has the keyword 
            {
                i++;
                cout << i << ". " << current->customerID << " - " << current->customerName << " - " << current->customerPhoneNum << " - " << current->customerDeposit
                    << endl;
                current = current->custNext;
            }
            current = current->custNext;
        }
        cout << endl;
    }

    void login()
    {
        //login function
    }

    void searchVehicle()
    {
        //search vehicle
    }

    void createSalesInvoice()
    {
        //create Sales Invoice
    }


    void createBill()
    {
        //creating Bill
    }

};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Salesperson : public Staff{

public:

    void salespersonLogin()
    {
        //login function for staff
        // Create an empty linked list
        staff* head = NULL;
        string fileSelect;

        // Read data from CSV file and add users to the linked list
        ifstream file("Staff.csv");
        if (file.is_open()) {
            string line, header;
            getline(file, header);
            while (getline(file, line)) {
                stringstream ss(line);
                string staffIDStr, staffName, staffPassword, staffPosition;
                getline(ss, staffIDStr, ',');
                getline(ss, staffName, ',');
                getline(ss, staffPassword, ',');
                getline(ss, staffPosition, ',');

                //convert string to integer
                int staffID = stoi(staffIDStr);
                addStaff(&head, staffID, staffName, staffPassword, staffPosition);
            }
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
            return;
        }

        salespersonLogin:

        cout << "\t=====================" << endl;
        cout << "\t||SALESPERSON LOGIN||" << endl;
        cout << "\t=====================" << endl;

        // Display the linked list
        displayUsers(head);

        // Get input from user and check if it matches a user in the linked list
        string staffName, staffPassword;
        cout << "\n\tENTER USERNAME:";
        getline(cin, staffName);
        cout << endl;
        cout << "\n\tENTER PASSWORD:";
        getline(cin, staffPassword);
        if (checkUser(head, staffName, staffPassword)) {
            cout << endl << "\n\tLOGIN SUCCESSFUL!" << endl;
        }
        else {
            cout << "\n\tLOGIN FAILED!" << endl;
            system("pause");
            system("cls");
            goto salespersonLogin;
        }

        // Free memory used by the linked list
        staff* current = head;
        while (current != NULL) {
            staff* next = current->staffNext;
            delete current;
            current = next;
        }
        head = NULL;

        return;
    }

    void salespersonMainMenu()
    {
        int option = 0;
        while ((option < 1) || (option > 6)) {

            cout << "\n\t==========================================" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t||            SALESPERSON MENU          ||" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t==========================================" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t||   1. SEARCH VEHICLE INFORMATION      ||" << endl;
            cout << "\t||   2. CREATE SALE INVOICE             ||" << endl;
            cout << "\t||   3. CREATE BILL INVOICE             ||" << endl;
            cout << "\t||   4. BOOK VEHICLE                    ||" << endl;
            cout << "\t||   5. MANAGE CLIENT INFORMATION       ||" << endl;
            cout << "\t||   6. EXIT                            ||" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t==========================================\n" << endl;

            cout << endl << "\n\tENTER YOUR CHOICE HERE:";
            cin >> option;
            cout << endl;
            cin.ignore();

            switch (option) {
            case 1:
                // Search vehicle information
                break;
            case 2:
                // Create sale invoice 
                break;
            case 3:
                //Create Bill invoice
                break;
            case 4:
                // Book the vehicle
                bookCar();
                break;
            case 5:
                // Manage client information
                manageCustomer();
                break;

            case 6:
                cout << endl;
                cout << "\t==================================" << endl;
                cout << "\t||THANK YOU FOR USING OUR SYSTEM||" << endl;
                cout << "\t==================================" << endl;
                exit(0);

            default:
                cout << "\tInvalid Input! Please try again";
            }
        }
    }



    void bookCar()
    {
        int answer;

        bookCar:

        int carID = displayCarListItemsBinary();
        cout << "\n\tWould you like to confirm your booking? 1 - Yes, 0 - No: ";
        cin >> answer;
        SearchAndUpdateBasedCarID(carID);

        cout << "\n\tWould you like to book another car? 1 - Yes, 0 - No: ";
        cin >> answer;
        if (answer = 1)
        {
            goto bookCar;
        }
        else {
            salespersonMainMenu();
        }
    }


    int displayCarListItemsBinary() {
        int carIDInput;
        int choice;
        cout << "\n\tENTER CAR ID TO SEARCH: ";
        cin >> carIDInput;
        car* car = binarySearch(carIDInput);

        // Print search results

        if (car->carStatus == "Booked")
        {
            cout << "\n\tCar has already been booked successfully." << endl;
            cout << "\n\tWould you like to book another car? 1 - Yes, 0 - No: ";
            cin >> choice;

            if (choice == 1)
            {
                bookCar();
            }
            else
            {
                salespersonMainMenu();
            }

        }
        if (car->carStatus == "Available") {
            cout << "\n\t===========================================================================================" << endl;
            cout << "\t|| ID: " << car->carID << endl;
            cout << "\t||" << endl;
            cout << "\t|| Title: " << car->carTitle << endl;
            cout << "\t||" << endl;
            cout << "\t|| Price: " << car->carPrice << endl;
            cout << "\t||" << endl;
            cout << "\t|| Registration Date: " << car->carRegistrationDate << endl;
            cout << "\t||" << endl;
            cout << "\t|| Mileage: " << car->carMileage << endl;
            cout << "\t||" << endl;
            cout << "\t|| Fuel Type: " << car->carFuelType << endl;
            cout << "\t||" << endl;
            cout << "\t|| Transmission: " << car->carTransmission << endl;
            cout << "\t||" << endl;
            cout << "\t|| Engine Size: " << car->carEngineSize << endl;
            cout << "\t||" << endl;
            cout << "\t|| Number of Doors: " << car->carDoorNum << endl;
            cout << "\t||" << endl;
            cout << "\t|| Colour: " << car->carColour << endl;
            cout << "\t||" << endl;
            cout << "\t|| Body Type: " << car->carBodyType << endl;
            cout << "\t||" << endl;
            cout << "\t|| URL: " << car->carURL << endl;
            cout << "\t||" << endl;
            cout << "\t|| Initial Sale Date: " << car->carInitialSaleDate << endl;
            cout << "\t||" << endl;
            cout << "\t|| Status: " << car->carStatus << endl;
            cout << "\t===========================================================================================" << endl;

        }
        else  if (car == NULL)
        {
            cout << "\tCar ID not Found!" << endl;
        }

        return car->carID;
    }


    void manageCustomer() {

        system("cls");

        int userInput;
        cout << "\n\t============================================" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||            MANAGE CUSTOMER           ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t==========================================" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||   1. UPDATE CUSTOMER DETAILS         ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||   2. ADD NEW CUSTOMER                ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||   3. RETURN TO SALESPERSON MENU      ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t==========================================\n" << endl;

        cout << "\n\tENTER CHOICE: ";
        cin >> userInput;
        cin.ignore();

        switch(userInput) {

        case 1: 
            updateCustomerChoice();
            break;
        
        case 2:
            addNewCustomer();
            break;

        case 3:
            system("cls");
            salespersonMainMenu();

        default:
            "\tInvalid option selected.";
            break;
        }
    }


    void addNewCustomer() {

        string custID, custName, custPhoneNum;

        cout << "\n\tENTER CUSTOMER ID          : ";
        getline(cin, custID);
        cout << endl;

        cout << "\tENTER CUSTOMER NAME          :  ";
        getline(cin, custName);
        cout << endl;

        cout << "\n\tENTER CUSTOMER PHONE NUMBER:  ";
        getline(cin, custPhoneNum);
        cout << endl << endl;

        createNewCustomerNode(custID, custName, custPhoneNum, NULL);

        cout << "\tNEWLY ADDED CUSTOMER DETAILS\n" << endl;
        cout << "\t============================================================" << endl;
        cout << "\t" << endl;
        cout << "\tCUSTOMER ID            : " << custID << endl;
        cout << "\t" << endl;
        cout << "\tCUSTOMER NAME          : " << custName << endl;
        cout << "\t" << endl;
        cout << "\tCUSOTMER PHONE NUMBER  : " << custPhoneNum << endl;
        cout << "\t" << endl;
        cout << "\tCUSTOMER DEPOSIT       : RM" << NULL << endl;
        cout << "\t" << endl;
        cout << "\t============================================================" << endl;
        cout << endl;
        cout << "\n\tCustomer Details Successfully Added!" << endl;
    }

    void updateCustomerChoice() {
        string custID;

        cout << "\n\tENTER CUSTOMER ID: ";
        cin >> custID;
        cin.ignore();

        searchandUpdateCustomer(custID);
    }

    void searchandUpdateCustomer(string custID)
    {
        customer* current = custHead;
        while (current != NULL)
        {
            if (custID == current->customerID)
            {
                cout << "\n\t\n" << endl;
                cout << "\t============================================================" << endl;
                cout << "\t||" << endl;
                cout << "\t|| CUSTOMER ID            : " << current->customerID << endl;
                cout << "\t||" << endl;
                cout << "\t|| CUSTOMER NAME          : " << current->customerName << endl;
                cout << "\t||" << endl;
                cout << "\t|| CUSTOMER PHONE NUMBER  : " << current->customerPhoneNum << endl;
                cout << "\t||" << endl;
                cout << "\t|| CUSTOMER DEPOSIT       : RM " << current->customerDeposit << endl;
                cout << "\t||" << endl;
                cout << "\t============================================================" << endl;

                //Updating details of the customer
                cout << "\n\tENTER CUSTOMER NAME: ";
                getline(cin, current->customerName);
                cout << endl;


                cout << "\n\tENTER CUSTOMER PHONE NUMBER: ";
                cin >> current->customerPhoneNum;
                cout << endl;


                cout << "\n\tEnter Customer Deposit Amount: RM ";
                cin >> current->customerDeposit;

                displayUpdateCustomer(current->customerID);
                return;
                system("cls");
            }
            current = current->custNext;

        }
        int userInput;

        cout << "\n\tCustomer ID does not exist. Returning to Manager Menu Section...";
        system("pause");
        manageCustomer();
    }

    void displayUpdateCustomer(string custID) {

        system("cls");
        customer* customer = searchCustomerID(custID);

        // Print search results

        if (customer != NULL) {
            cout << "\n\tUPDATED CUSTOMER DETAILS\n" << endl;
            cout << "\t============================================================" << endl;
            cout << "\t" << endl;
            cout << "\tCUSTOMER ID            : " << customer->customerID << endl;
            cout << "\t" << endl;
            cout << "\tCUSTOMER NAME          : " << customer->customerName << endl;
            cout << "\t" << endl;
            cout << "\tCUSTOMER PHONE NUMBER  : " << customer->customerPhoneNum << endl;
            cout << "\t" << endl;
            cout << "\tCUSTOMER DEPOSIT       : RM " << customer->customerDeposit<< endl;
            cout << "\t" << endl;
            cout << "\t============================================================" << endl;
    

            cout << endl;
            cout << "\tCustomer Details Successfully Updated!" << endl;
            system("pause");
            manageCustomer();
        }

        if (customer != NULL)
        {
            // Open the CSV file in append mode
            std::ofstream csvFile("customerDetails.csv", std::ios_base::app);

            csvFile << customer->customerID << ","
                << customer->customerName<< ","
                << customer->customerPhoneNum << ","
                << customer->customerDeposit << std::endl;

            // Close the CSV file
            csvFile.close();
        }

        else
        {
            cout << "\tCustomer ID not found." << endl;
        }

        return;
    }

};


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Manager : public Staff{


public:

    void managerLogin()
    {
        //login function for staff
        // Create an empty linked list
        staff* head = NULL;

        // Read data from CSV file and add users to the linked list
        ifstream file("Manager.csv");
        if (file.is_open()) {
            string line, header;
            getline(file, header);
            while (getline(file, line)) {
                stringstream ss(line);
                string staffIDStr, staffName, staffPassword, staffPosition;
                getline(ss, staffIDStr, ',');
                getline(ss, staffName, ',');
                getline(ss, staffPassword, ',');
                getline(ss, staffPosition, ',');

                //convert string to integer
                int staffID = stoi(staffIDStr);
                addStaff(&head, staffID, staffName, staffPassword, staffPosition);
            }
            file.close();
        }
        else {
            cout << "Unable to open file" << endl;
            return;
        }

        managerLogin:

        cout << "\t=====================" << endl;
        cout << "\t||  MANAGER LOGIN  ||" << endl;
        cout << "\t=====================" << endl;

        // Display the linked list
        displayUsers(head);


        // Get input from user and check if it matches a user in the linked list
        string staffName, staffPassword;
        cout << "\n\tENTER USERNAME:";
        getline(cin, staffName);
        cout << endl;
        cout << "\n\tENTER PASSWORD:";
        getline(cin, staffPassword);
        if (checkUser(head, staffName, staffPassword)) {
            cout << endl << "\n\tLOGIN SUCCESSFUL!" << endl;
        }
        else {
            cout << "\n\tLOGIN FAILED!" << endl;
            system("pause");
            system("cls");
            goto managerLogin;
        }

        // Free memory used by the linked list
        staff* current = head;
        while (current != NULL) {
            staff* next = current->staffNext;
            delete current;
            current = next;
        }
        head = NULL;

        return;
    }

    void managerMainMenu()
    {
        int option = 0;
        while ((option < 1) || (option > 5)) {

            cout << "\n\t==========================================" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t||            MANAGER MENU              ||" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t==========================================" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t||   1. SEARCH VEHICLE INFORMATION      ||" << endl;
            cout << "\t||   2. CREATE SALE INVOICE             ||" << endl;
            cout << "\t||   3. CREATE BILL INVOICE             ||" << endl;
            cout << "\t||   4. GENERATE REPORTS                ||" << endl;
            cout << "\t||   5. EXIT                            ||" << endl;
            cout << "\t||                                      ||" << endl;
            cout << "\t==========================================\n" << endl;

            cout << endl << "\tENTER YOUR CHOICE HERE:";
            cin >> option;
            cout << endl;
            cin.ignore();

            switch (option) {
            case 1:
                // Search vehicle information
                break;
            case 2:
                // Create sale invoice 
                break;
            case 3:
                //Create Bill invoice
                break;
            case 4:
                // Report
                break;
            case 6:
                cout << endl;
                cout << "\t==================================" << endl;
                cout << "\t||THANK YOU FOR USING OUR SYSTEM||" << endl;
                cout << "\t==================================" << endl;
                exit(0);

            default:
                cout << "\tInvalid Input!";
            }
        }
    }


    void produceSaleInvoiceReport()
    {
        //Produces Sale Invoice Report
    }

};




int main(){

   // int listCount = 0;
   // CarList carlist;
    Salesperson salesperson;
    Manager manager;

    //Storing Content from CSV Files into Linked List
    salesperson.storeinCustomerLinkedList("customer.csv");
    salesperson.storeInCarLinkedList("carlist.csv");

    menu:
   // string titleInput;
   // int CarID;
    int loginOption = 0;

    while ((loginOption < 1) || (loginOption > 3))
    {

        cout << "\n\t==========================================" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||        VEHICLE INVOICE SYSTEM        ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t==========================================" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||           MENU OPTIONS:              ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||           1. SALESPERSON             ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||           2. MANAGER                 ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t||           3. EXIT                    ||" << endl;
        cout << "\t||                                      ||" << endl;
        cout << "\t==========================================\n" << endl;


        cout << "\n\tENTER YOUR CHOICE HERE:";
        cin >> loginOption;
        cout << endl;
        cin.ignore();

        switch (loginOption)
        {
        case 1:
            salesperson.salespersonLogin();
            salesperson.salespersonMainMenu();
            break;
        case 2:
            manager.managerLogin();
            manager.managerMainMenu();
            break;

        case 3:
            cout << endl;
            cout << "\t==================================" << endl;
            cout << "\t||THANK YOU FOR USING OUR SYSTEM||" << endl;
            cout << "\t==================================" << endl;
            exit(0);

        default:
            cout << "Invalid Choice." << endl;
            system("pause");
            system("cls");
            goto menu;
        }
    }
}



// int main()
// {
//    // int listCount = 0;
//    // CarList carlist;
//    // string titleInput;
//    // int CarID;


//    // carlist.storeInCarLinkedList("carlist.csv");
//    // //listCount = carlist.getCount();
//    //// carlist.bubbleSortCarRegDate();
//    // //carlist.MergeSort(carlist.head);
//    // //carlist.displayCarList();
//    // int answer; 
//    // string word;
//    // cout << "Do you want to book a car? 1 - Yes, 0 - No: " << endl;
//    // cin >> answer;
//    // cin.ignore();

//    // while (answer == 1)
//    // {
//    //     carlist.displayCarListItemsBinary();
//    //     cout << "Do you want to edit anything? 1 - Yes, 0 - No: " << endl;
//    //     cin >> answer;

//    //     int CarID;
//    //     if (answer == 1)
//    //     {
//    //         cout << endl;
//    //         cout << "Enter your car ID: ";
//    //         cin >> CarID;
//    //         carlist.SearchAndUpdateBasedCarID(CarID);
//    //     }
//    //     cout << "Do you want to proceed with ing? 1 - Yes, 0 - No: ";
//    //     cin >> answer;
//    //     cin.ignore();
//    //     system("pause");
//    //     system("cls");
//    // }
//    // return 0;


//     Salesperson salesperson;
//     salesperson.storeinCustomerLinkedList("customer.csv");
//     salesperson.manageCustomer();
    



//     //carlist.SearchAndUpdateBasedCarID(CarID);
//     //carlist.displayCarListItemsBinary();

//     /*cout << "Enter Sale Title Search: ";
//     cin >> titleInput;
//     carlist.searchItemBasedOnKeyword(titleInput);
//     cin.ignore();*/
// }

