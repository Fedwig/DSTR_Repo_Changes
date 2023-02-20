// DSTR-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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

class Staff {


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

class Salesperson : public Staff {

public:

    void staffLogin()
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

        // Display the linked list
        displayUsers(head);

        // Get input from user and check if it matches a user in the linked list
        string staffName, staffPassword;
        cout << "ENTER USERNAME:";
        getline(cin, staffName);
        cout << endl;
        cout << "ENTER PASSWORD:";
        getline(cin, staffPassword);
        if (checkUser(head, staffName, staffPassword)) {
            cout << endl << "LOGIN SUCCESSFUL!" << endl;
        }
        else {
            cout << "LOGIN FAILED" << endl;
            exit(0);
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
            cout << endl << "----------SALESPERSON MENU----------";
            cout << endl << "----1.SEARCH VEHICLE INFORMATION----";
            cout << endl << "-------2.CREATE SALE INVOICE-------";
            cout << endl << "-------3.CREATE BILL INVOICE-------";
            cout << endl << "-----------4.BOOK VEHICLE-----------";
            cout << endl << "----5.MANAGE CLIENT INFORMATION----";
            cout << endl << "---------------6.EXIT---------------" << endl;
            cout << endl << "ENTER YOUR CHOICE HERE:";
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

                break;
            case 5:
                // Manage client information
                manageCustomer();

                break;
            default:
                // End the program
                cout << endl << "Thank you for using our system !!" << endl;
                exit(0);
            }
        }
    }



    void bookVehicle() {
        //Booking vehilcle
    }


    void manageCustomer() {

        int userInput;
        
        cout << "--------MANAGE CUSTOMER SECTION--------" << endl;
        cout << "\n1. Update Customer Details" << endl;
        cout << "2. Add New Customer" << endl;

        cout << "\nEnter Choice: ";
        cin >> userInput;
        cin.ignore();

        switch(userInput) {

        case 1: 
            updateCustomerChoice();
            break;
        
        case 2:
            addNewCustomer();
            break;

        default:
            "Invalid option selected.";
            break;
        }
    }


    void addNewCustomer() {

        string custID, custName, custPhoneNum;

        cout << "\n ENTER CUSTOMER ID           : ";
        getline(cin, custID);
        cout << endl;

        cout << " ENTER CUSTOMER NAME         :  ";
        getline(cin, custName);
        cout << endl;

        cout << "\n ENTER CUSTOMER PHONE NUMBER :  ";
        getline(cin, custPhoneNum);
        cout << endl << endl;

        createNewCustomerNode(custID, custName, custPhoneNum, NULL);
        cout << "Newly Added Customer Details\n" << endl;
            
        cout << "Customer ID            : " << custID << endl;
        cout << "Customer Name          : " << custName << endl;
        cout << "Customer Phone Number  : " << custPhoneNum << endl;
        cout << "Customer Deposit       : RM" << NULL << endl;
        cout << endl;
        cout << "Customer Details Successfully Added!" << endl;
    }

    void updateCustomerChoice() {
        string custID;

        cout << "\n ENTER CUSTOMER ID: ";
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
                cout << "Customer ID: " << current->customerID << endl;

                //Updating details of the customer
                cout << "\nEnter Customer Name: ";
                getline(cin, current->customerName);
                cout << endl;


                cout << "\nEnter Customer Phone Number: ";
                cin >> current->customerPhoneNum;
                cout << endl;


                cout << "\nEnter Customer Deposit Amount: RM ";
                cin >> current->customerDeposit;

                displayUpdateCustomer(current->customerID);
                return;
                system("cls");
            }
            current = current->custNext;

        }
        cout << "Customer ID does not exist. Would you like to add a new customer? (1 - Yes, 0 - No)" << endl;
        //fill out atlernative if customer ID does not exist
    }

    void displayUpdateCustomer(string custID) {

        system("cls");
        customer* customer = searchCustomerID(custID);

        // Print search results

        if (customer != NULL) {
            cout << "Updated Customer Details\n" << endl;
            cout << "Customer ID            : " << customer->customerID << endl;
            cout << "Customer Name          : " << customer->customerName << endl;
            cout << "Customer Phone Number  : " << customer->customerPhoneNum << endl;
            cout << "Customer Deposit       : RM " << customer->customerDeposit<< endl;
            cout << endl;
            cout << "Customer Details Successfully Updated" << endl;
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
            cout << "Customer ID not found." << endl;
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

        // Display the linked list
        displayUsers(head);

        // Get input from user and check if it matches a user in the linked list
        string staffName, staffPassword;
        cout << "ENTER USERNAME:";
        getline(cin, staffName);
        cout << endl;
        cout << "ENTER PASSWORD:";
        getline(cin, staffPassword);
        if (checkUser(head, staffName, staffPassword)) {
            cout << "LOGIN SUCCESSFUL!" << endl;
        }
        else {
            cout << "LOGIN FAILED" << endl;
            exit(0);
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
            cout << endl << "----------MANAGER MENU----------";
            cout << endl << "--1.SEARCH VEHICLE INFORMATION--";
            cout << endl << "-----2.CREATE SALE INVOICE------";
            cout << endl << "-----3.CREATE BILL INVOICE------";
            cout << endl << "--------4.CREATE REPORT---------";
            cout << endl << "-------------5.EXIT-------------" ;
            cout << endl << "ENTER YOUR CHOICE HERE:";
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
            default:
                // End the program
                cout << endl << "Thank you for using our system !!" << endl;
                exit(0);
            }
        }
    }


    void produceSaleInvoiceReport()
    {
        //Produces Sale Invoice Report
    }

};



//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class CarList {

public:

    car* carHead = NULL;
    car* tail = NULL;

    car* createNewCarNode(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFuelType, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        //1. create structure in the heap location
        car* newCarNode = new car;

        //2. assigning the data into the node
        newCarNode->carID = carID;
        newCarNode->carTitle = carTitle;
        newCarNode->carPrice = carPrice;
        newCarNode->carRegistrationDate = carRegistrationDate;
        newCarNode->carMileage = carMileage;
        newCarNode->carFuelType = carFuelType;
        newCarNode->carTransmission = carTransmission;
        newCarNode->carEngineSize = carEngineSize;
        newCarNode->carDoorNum = carDoorNum;
        newCarNode->carColour = carColour;
        newCarNode->carBodyType = carBodyType;
        newCarNode->carURL = carURL;
        newCarNode->carInitialSaleDate = carInitialSaleDate;
        newCarNode->carStatus = carStatus;
        newCarNode->carNext = NULL; //always start with NULL first in newCarNode

        //3. return back the new created node to the other function
        return newCarNode;
    }


    void DisplayCarList()
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

    void DisplayCarList2(car* carHead)
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

    void insertFrontOfCarList(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFueltype, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        car* newCarNode = createNewCarNode(carID, carTitle, carPrice, carRegistrationDate, carMileage,
            carFueltype, carTransmission, carEngineSize, carDoorNum, carColour,
            carBodyType, carURL, carInitialSaleDate, carStatus);

        if (carHead == NULL)
        {
            carHead = newCarNode;
        }
        else
        {
            newCarNode->carNext = carHead;
            carHead = newCarNode;
        }
        return;
    }

    car* insertToEndOfCarList(int carID, string carTitle, double carPrice, int carRegistrationDate, int carMileage,
        string carFueltype, string carTransmission, string carEngineSize, int carDoorNum, string carColour,
        string carBodyType, string carURL, string carInitialSaleDate, string carStatus)
    {
        //create a newCarNode
        car* newCarNode = createNewCarNode(carID, carTitle, carPrice, carRegistrationDate, carMileage,
            carFueltype, carTransmission, carEngineSize, carDoorNum, carColour,
            carBodyType, carURL, carInitialSaleDate, carStatus);

        //attach your newCarNode to the list
        if (carHead == NULL) //list still empty
        {
            carHead = newCarNode;
        }
        else //list is not empty
        {
            car* current = carHead;

            while (current->carNext != NULL)
            {
                current = current->carNext;
            }
            //if found the last node? ->attach the new node into the end of the last node
            current->carNext = newCarNode;
        }

        return carHead;
    }

    void storeInCarLinkedList(string fileName) {
        ifstream file(fileName);
        string line;
        //car* tail = NULL;
        string carHeader;

        // Read data from CSV file
        // Each iteration creates a new car with car objects listed below in the nested while loop

        getline(file, carHeader);
        while (getline(file, line)) {
            stringstream ss(line);
            string cell;
            int i = 0;
            car* newCarNode = new car;

            // Parse CSV line
            while (getline(ss, cell, ',')) {
                switch (i) {
                case 0:
                    newCarNode->carID = stoi(cell);
                    break;
                case 1:
                    newCarNode->carTitle = cell;
                    break;
                case 2:
                    newCarNode->carPrice = stod(cell);
                    break;
                case 3:
                    newCarNode->carRegistrationDate = stoi(cell);
                    break;
                case 4:
                    newCarNode->carMileage = stoi(cell);
                    break;
                case 5:
                    newCarNode->carFuelType = cell;
                    break;
                case 6:
                    newCarNode->carTransmission = cell;
                    break;
                case 7:
                    newCarNode->carEngineSize = cell;
                    break;
                case 8:
                    newCarNode->carDoorNum = stoi(cell);
                    break;
                case 9:
                    newCarNode->carColour = cell;
                    break;
                case 10:
                    newCarNode->carBodyType = cell;
                    break;
                case 11:
                    newCarNode->carURL = cell;
                    break;
                case 12:
                    newCarNode->carInitialSaleDate = cell;
                    break;
                case 13:
                    newCarNode->carStatus = cell;
                    break;
                }
                i++;
            }
            insertToEndOfCarList(newCarNode->carID, newCarNode->carTitle, newCarNode->carPrice, newCarNode->carRegistrationDate, newCarNode->carMileage,
                newCarNode->carFuelType, newCarNode->carTransmission, newCarNode->carEngineSize, newCarNode->carDoorNum, newCarNode->carColour,
                newCarNode->carBodyType, newCarNode->carURL, newCarNode->carInitialSaleDate, newCarNode->carStatus);
        }

        return;
    }

    // Function to search for an ID in linked list using linear search
    car* searchCarID(int id) {
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
                cout << "Car Status: " << current->carStatus << endl;
                int answer;
                cout << "Do you want to edit status of the car ?  1 - Yes, 0 - No: ";
                cin >> answer;
                if (answer == 1)
                {
                    cout << endl;
                    cout << "Enter your new car status: ";
                    cin >> current->carStatus;
                }
                displayUpdate();
                return;
            }
            current = current->carNext;

        }
        cout << "Car ID does not EXIST!! Please Try Again. " << endl;
    }


    void displayUpdate() {
        int carIDInput;
        cout << "Please input ID to confirm changes : ";
        cin >> carIDInput;
        car* car = binarySearch(carIDInput);

        // Print search results

        if (car != NULL) {
            cout << "ID: " << car->carID << endl;
            cout << "Title: " << car->carTitle << endl;
            cout << "Price: " << car->carPrice << endl;
            cout << "Registration Date: " << car->carRegistrationDate << endl;
            cout << "Mileage: " << car->carMileage << endl;
            cout << "Fuel Type: " << car->carFuelType << endl;
            cout << "Transmission: " << car->carTransmission << endl;
            cout << "Engine Size: " << car->carEngineSize << endl;
            cout << "Number of Doors: " << car->carDoorNum << endl;
            cout << "Colour: " << car->carColour << endl;
            cout << "Body Type: " << car->carBodyType << endl;
            cout << "URL: " << car->carURL << endl;
            cout << "Initial Sale Date: " << car->carInitialSaleDate << endl;
            cout << "Status: " << car->carStatus << endl;
            cout << endl;
            cout << "Car has been booked successfully" << endl;
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



    void displayListItemsBinary() {
        int carIDInput;
        cout << "Enter ID to search: ";
        cin >> carIDInput;
        car* car = binarySearch(carIDInput);

        // Print search results
        if (car != NULL) {
            cout << "ID: " << car->carID << endl;
            cout << "Title: " << car->carTitle << endl;
            cout << "Price: " << car->carPrice << endl;
            cout << "Registration Date: " << car->carRegistrationDate << endl;
            cout << "Mileage: " << car->carMileage << endl;
            cout << "Fuel Type: " << car->carFuelType << endl;
            cout << "Transmission: " << car->carTransmission << endl;
            cout << "Engine Size: " << car->carEngineSize << endl;
            cout << "Number of Doors: " << car->carDoorNum << endl;
            cout << "Colour: " << car->carColour << endl;
            cout << "Body Type: " << car->carBodyType << endl;
            cout << "URL: " << car->carURL << endl;
            cout << "Initial Sale Date: " << car->carInitialSaleDate << endl;
            cout << "Status: " << car->carStatus << endl;

        }
        else {
            cout << "Car ID not Found" << endl;
        }

        return;
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
            // taking carHead node of second list as t2.
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
    void MergeSort(car* head)
    {
        car* first = new car;
        car* second = new car;
        car* temp = new car;
        first = head;
        temp = head;

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
            first = head;
        }

        // Implementing divide and conquer approach.
        MergeSort(first);
        MergeSort(second);

        // Merge the two part of the list into a sorted one.      
        head = Merge(first, second);
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


int main(){

   // int listCount = 0;
   // CarList carlist;
    Salesperson salesperson;
    Manager manager;

    //Storing Content from CSV Files into Linked List
    salesperson.storeinCustomerLinkedList("customer.csv");



   // string titleInput;
   // int CarID;
    int loginOption = 0;

    while ((loginOption < 1) || (loginOption > 3))
    {
        cout << "----------ONLINE CAR RESELLER----------" << endl;
        cout << "-----PLEASE CHOOSE AN OPTION BELOW-----" << endl;
        cout << "--------PRESS 1 FOR SALESPERSON--------" << endl;
        cout << "----------PRESS 2 FOR MANAGER----------" << endl << endl;
        cout << "ENTER YOUR CHOICE HERE:";
        cin >> loginOption;
        cout << endl;
        cin.ignore();

        switch (loginOption)
        {
        case 1:
            salesperson.staffLogin();
            salesperson.salespersonMainMenu();
            break;
        case 2:
            manager.managerLogin();
            manager.managerMainMenu();
            break;
        default:
            cout << endl << "Goodbye!" << endl;
            exit(0);
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
//    // //carlist.DisplayCarList();
//    // int answer; 
//    // string word;
//    // cout << "Do you want to book a car? 1 - Yes, 0 - No: " << endl;
//    // cin >> answer;
//    // cin.ignore();

//    // while (answer == 1)
//    // {
//    //     carlist.displayListItemsBinary();
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
//    //     cout << "Do you want to proceed with booking? 1 - Yes, 0 - No: ";
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
//     //carlist.displayListItemsBinary();

//     /*cout << "Enter Sale Title Search: ";
//     cin >> titleInput;
//     carlist.searchItemBasedOnKeyword(titleInput);
//     cin.ignore();*/
// }

