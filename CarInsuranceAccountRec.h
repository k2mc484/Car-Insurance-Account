
#ifndef INSURANCE_H
#define INSURANCE_H

#define FLAT_RATE 135 // initial flat rate for annual car  insurance

/* TODO: Implement the following member functions and data members into the derived
 * class "CarInsuranceAccountRec". The derived class inherits the base-class "PersonalRec"
 * in the public inheritance mode
 *
 * MEMBER FUNCTIONS:
 *      CarInsuranceAccountRec (string first, string last, Date DoB);
        void renewInsurance();
        void displayRenewCost();
        void displayAccountInformation();
        void reportAccident(string, double);
        void updateAccidents();
        int checkValidityRenewal();
        double findRenewalCost();

 * DATA MEMBERS:
    Date accDateOfOpening; // Date the account was opened
    Date accDateOfExpiry; // Date after which the insurance will expire
    double accRenewalCost; // current cost used during the last renewal of
                           // the insurance account for one year
    Accident accAccidentRecord; // accident records
*/
class CarInsuranceAccountRec:public PersonalRec {
public:
    CarInsuranceAccountRec (string first, string last, Date DoB);
    void renewInsurance();
    void displayRenewCost();
    void displayAccountInformation();
    void reportAccident(string, double);
    void updateAccidents();
    int checkValidityRenewal();
    double findRenewalCost();
private:
    Date accDateOfOpening; // Date the account was opened
    Date accDateOfExpiry; // Date after which the insurance will expire
    double accRenewalCost; // current cost used during the last renewal of the insurance account for one year
    Accident accAccidentRecord; // accident records
};


#endif



