
#include<iostream>
#include<string>
#include <vector>
#include<math.h>

#ifndef ACCIDENT_H
#define ACCIDENT_H

using namespace std;

/* c++ class to keep records of an individual accident*/
class IndividualAccidentRecord {
    public:
        IndividualAccidentRecord(string accDescription, Date accDate, double accCost )
                : descriptionOfAccident(accDescription), dateOfAccident(accDate), costOfAccident(accCost) {}
        void setDescription(string accDescription) {descriptionOfAccident = accDescription;}
        void setDateOfAccident (Date accDate) {dateOfAccident = accDate;}
        void setCostOfAccident (double accCost) {costOfAccident = accCost;}
        string getDescripton() const {return descriptionOfAccident;}
        Date getDateOfAccident() const {return dateOfAccident;}
        double getCostOfAccident() const {return costOfAccident;}

    private:
        string descriptionOfAccident;
        Date dateOfAccident;
        double costOfAccident;
}; /* end class individualAccidentRecord */


class Accident {
/* TODO: DEFINE THE "Accident" CLASS WITH PUBLIC/PRIVATE ATTRIBUTES/BEHAVIORS */
public:
    void print();
    void add(string description, double cost);
    int count();
    void update();
    double getTotalAccidentCost();
    bool isNoAccident();
    ~Accident();
private:
    vector <IndividualAccidentRecord> myAccidents;
    };

#endif



