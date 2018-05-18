#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "accidents.h"
#include "PersonalRec.h"

/*** Global variables ***/
extern Date currentDate;



/*** Here define all member functions under the class "PersonalRec" ****/
/* TODO: Define the constructor for "PersonalRec"                      */

PersonalRec::PersonalRec(string first, string last, Date DoB):DoB{DoB} {
    firstName = first;
    lastName = last;
    cout<<"Personal identity constructed\n";
    displayPersonalRec();
}

/* TODO: Define the member function displayPersonalRec()                */

void PersonalRec::displayPersonalRec() const {
    cout<<"Name: "<<firstName<<" "<<lastName<<endl;
    cout<<"Date of Birth: ";
    DoB.print();
}





// Implementation of the member function getAgeInYears()
int PersonalRec::getAgeInYears() const
{

    int year = currentDate.getYear();
    int month = currentDate.getMonth();
    int day = currentDate.getDay();

    int age;

    // determine the age of the aPersonalRec in years
    if((month > DoB.getMonth()) || (month == DoB.getMonth() && day > DoB.getDay()))
        age = year - DoB.getYear();
    else
        age = year - DoB.getYear() - 1;
    return age;

}

