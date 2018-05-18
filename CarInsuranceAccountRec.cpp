#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "accidents.h"
#include "PersonalRec.h"
#include "CarInsuranceAccountRec.h"

/*** Global variables ***/
 extern Date currentDate;


/* Define the constructor and the following member functions under the class "CarInsuranceAccountRec" */
/* TODO: class constructor */
CarInsuranceAccountRec::CarInsuranceAccountRec(string first, string last, Date DoB):PersonalRec(first,last,DoB), accDateOfOpening{currentDate},accDateOfExpiry{currentDate} {
    accDateOfExpiry.addYears(1);
    accRenewalCost = FLAT_RATE;
    displayAccountInformation();
}

/* TODO: checkValidityRenewal() - Check validity of a Renewal */
int CarInsuranceAccountRec::checkValidityRenewal()
{

    //Temp date to check if the current date is within a year
    Date withinYear(currentDate);
    withinYear.addYears(1);

    //Compare expiration date to the current date. Case 2 and 3 should pass
    if(accDateOfExpiry>currentDate){
        //Compare current date +1 year to expirary date
        if(accDateOfExpiry>withinYear){
            //Case 2
            cout << " Renewal for another year is not allowed" << endl;
            return 0;

        }
        else
            //Case 3
            cout << " !!!!!!!!!!!!!!" << endl;
            return 1;

     }
        //Case 1
     else
        cout << "The account is renewable with a onetime penalty of $125" << endl;
        return 125;


}/*end else statement*/
/* Find the Renewal Cost. Implementation provided */
double CarInsuranceAccountRec::findRenewalCost()
{
//TODO: Write your code to compute age by involving the appropriate member function of the base class


    double tempAccRenewalCost;
    int age = getAgeInYears();

    //reduce renewal cost based on the account holder's age
    if (age >= 30)
        tempAccRenewalCost = accRenewalCost*(1-0.06);
    else
        tempAccRenewalCost = accRenewalCost*(1-0.04);

    // add renewal cost incurred from accident records computed by
    // invoking the member function getTotalAccidentCost()
    tempAccRenewalCost = tempAccRenewalCost + accAccidentRecord.getTotalAccidentCost();
    return tempAccRenewalCost;
}

/* TODO: renewInsurance() - Renew the insurance account for another year */
void CarInsuranceAccountRec::renewInsurance()
{
    int renewalStatus = checkValidityRenewal();
   if(renewalStatus > 0) {
       accRenewalCost = findRenewalCost();
       accDateOfExpiry.addYears(1);
       if (renewalStatus == 125) {
           accRenewalCost += 125.0;
       }

       cout << "Account successfully renewed --- COST $" << accRenewalCost << endl;
       cout << "New Expiry Date: ";
       accDateOfExpiry.print();
       cout << endl;
   }


}/*end RenewInsurance*/


/* TODO: displayRenewCost() - Tell the user what the renewal cost is */
void CarInsuranceAccountRec::displayRenewCost()
{
        double temp;
    if(FLAT_RATE == accRenewalCost){
        temp = findRenewalCost();
    cout<<"Renewal Cost: "<<temp <<endl;
    }
    if(checkValidityRenewal()>0){
        cout<<"Renewal Cost: "<<accRenewalCost <<endl;
    }
    else{
        cout<< "Renew not allowed at this moment!"<<endl;
    }
}/*end displayRenewalCost*/


/*display account information to the user*/
void CarInsuranceAccountRec::displayAccountInformation()
{
    cout<<endl;
    cout << "Account Information:" << endl;
//TODO: Write your code to display PersonalRecal information by involing the appropriate member function of the base class

    displayPersonalRec();
    cout << endl;
    cout << "Current Date:  ";
    currentDate.print();
    cout << endl;
    cout << "Date of opening: ";
    accDateOfOpening.print();
    cout << endl;
    cout << "Date of Expiry on:";
    accDateOfExpiry.print();
    cout << endl;
    accAccidentRecord.update();
    accAccidentRecord.print();

}//end display Information



/*Report an Accident*/
void CarInsuranceAccountRec::reportAccident(string description, double cost)
{
    accAccidentRecord.add(description, cost);
    cout << "A new accident is added." << endl;
}/*end Report an Accident*/

void CarInsuranceAccountRec::updateAccidents()
{
    accAccidentRecord.update();
    cout << "Accident records updated." << endl;
}
