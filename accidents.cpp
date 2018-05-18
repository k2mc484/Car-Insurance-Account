#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#include "Date.h"
#include "accidents.h"

/*** Global variables ***/
 extern Date currentDate;


/* TODO: DEFINE THE DESTRUCTOR  */
Accident::~Accident()
{
myAccidents.clear();
}// end destructor

/* TODO: Print the Queue */
void Accident::print()
{
for(int i=0;i<myAccidents.size();i++){
    cout<< "Accident No.   "<< i+1<<endl;
   cout<< "Accident description: "<<myAccidents[i].getDescripton()<<endl;
    cout<<"Accident Date: ";
    myAccidents[i].getDateOfAccident().print();
    cout<<endl;
    cout<< "Accident Cost: "<< myAccidents[i].getCostOfAccident()<<endl;

}

}//end function print


/* TODO: add a new accident */
void Accident::add(string description, double cost)
{
    myAccidents.push_back(IndividualAccidentRecord(description,currentDate,cost));

}/* end function add */



/* TODO: compute the number of active accidents */
int Accident::count()
{
return myAccidents.size();
}//end count


/* TODO: determine if the accident record of the underlying Accident object is empty or not */
bool Accident::isNoAccident()
{
    return myAccidents.empty();
}//end function isEmpty


/* TODO: update the record of accidents; drop all accidents 3 years or older */
void Accident::update()
{
    std::vector<IndividualAccidentRecord>tempList;
for(int i=0;i<myAccidents.size();i++){
    Date tempDate(myAccidents[i].getDateOfAccident());
    tempDate.addYears(3);
    if(tempDate > myAccidents[i].getDateOfAccident()){
    tempList.push_back(myAccidents[i]);
    }
}
    myAccidents.swap(tempList);


}/*end function update*/



/* compute the the part of the renewal cost incurred from  accident records       */
/* implementation provided in accidents.cpp        */

double Accident::getTotalAccidentCost()
{
    double totalAccidentCost = 0;  // initialize totalAccidentCost

// construct the iterator it to traverse the accident record myAccidents
    vector<IndividualAccidentRecord>::iterator it;

// traverse the accident record myAccidents using iterator it
    for (it = myAccidents.begin(); it != myAccidents.end(); it++)
    {
        if (it->getCostOfAccident() > 5000)
            totalAccidentCost +=  50; // add $50 for a severe accident
        else if (it->getCostOfAccident() > 1000)
            totalAccidentCost += 20; // add $50 for a severe accident
    }
    return totalAccidentCost; // return the total accident cost

}

