/**** Detail descriptions are provided in files "homework5.pdf".
Please read those carefully before asking your questions to TAs  ***/

#include<iostream>
#include<string>
#include<math.h>
#include <stdio.h>
using namespace std;

#include "Date.h"
#include "accidents.h"
#include "PersonalRec.h"
#include "CarInsuranceAccountRec.h"
//#include "hw5.h"� /* uncomment this line if you create a header file hw5.h */

/** Global Variable **/
Date currentDate(1,1,1900); // records the current date which may be changed during the simulation


// displays all possible options
// reads user input
// makes proper check that the choice is a valid choice
// return the valid user choice as an integer
int getChoice();

int main()
{
    int choice = -1;
    double cost = 0;
    string accidentDescription;

    cout << "Current Date ";
    /* TODO: set the current date using the member function in the class Date */
    currentDate.setDate();
    /*Take in user information*/
    string firstName, lastName;
    /* TODO : Read user information of account holder's first and last name*/
    cout << "Enter First Name ";
    cin>> firstName;

    cout << "Enter Last Name ";
    cin>> lastName;

    cout << "Date of Birth";
    Date DoB;
    /* TODO: Read user information of account holder's DoB.
     * You need to make sure the DoB was prior to  the current date */
    DoB.setDate();
    while(DoB > currentDate){
        cout<<"Date of Birth has to be prior to current date";
        DoB.setDate();
    }

    cout << "Current Date ";
    currentDate.print();
    cout << endl;
    cout << "Name: ";
    cout << firstName << " " << lastName << endl;
    cout << "Date of Birth ";
    DoB.print();
    cout << endl;


    /* TODO: Construct a CarInsuranceAccountRec object
     using user specified information holder's first and last name and DoB */
    CarInsuranceAccountRec c1(firstName,lastName,DoB);
    /* TODO: Print menu and read user choice */
    /* Hints: Use the getChoice function */
    /* TODO: Allow user to perform different operations
      on the CarInsuranceAccountRec account until the user choose to terminate the program*/
    while(choice != 0){
        choice = getChoice();
        if(choice ==1){
            c1.displayRenewCost();
        }
        else if(choice ==2){

            c1.renewInsurance();
        }
        else if(choice ==3){
            cout << "Cost of accident: ";
            cin >> cost;

            cout << "Accident Description: ";
            cin.ignore();
           getline(cin,accidentDescription);

            c1.reportAccident(accidentDescription,cost);
            c1.displayAccountInformation();
        }
        else if(choice ==4){
            c1.displayAccountInformation();
        }
        else if(choice ==5){
            Date tempDate(currentDate);
                cout << "New Date";
                currentDate.setDate();
            while(tempDate > currentDate){
                cout<<"Time moves forward! Try again!"<<endl;
                currentDate.setDate();
            }
            c1.updateAccidents();
        }
    }

    return 0;
} //end main




int getChoice()
{
    int choice = -1;
    string dummy;

    do
    {
        cout << "Use:" <<  endl;
        cout << " 1: inquire renewal cost" <<  endl;
        cout << " 2: renew account" <<  endl;
        cout << " 3: report an accident" <<  endl;
        cout << " 4: display account Information" <<  endl;
        cout << " 5: set current date" <<  endl;
        cout << " 0: terminate" <<  endl;
        cout <<  endl;

        do
        {
            cout << "Give choice:";
            cin >> choice;
            if(cin.fail())
            {
                cout << "Not a number " << endl;
                cin.clear();
                getline(cin, dummy, '\n');

            }
            if(choice < 0 || choice > 5)
            {
                cout << "Not a valid choice " << endl;
            }
        }
        while(choice < 0 || choice > 5);
    }
    while (choice < 0 || choice > 5);
    return choice;

}

