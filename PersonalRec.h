#ifndef PersonalRec_H
#define PersonalRec_H


/*** TODO: Implement following member functions and data members
 *  for the base class "PersonalRec". Remember that DoB is a constant data member.
 *  MEMBER FUNCTIONS:
 *      PersonalRec (string first, string last, Date DoB);
 *      void displayPersonalRec() const;
 *      int getAgeInYears() const;
 *
 *  DATA MEMBERS:
 *      string firstName;
 *      string lastName;
 *      const Date DoB;
 */


 class PersonalRec
{
public:
    PersonalRec (string first, string last, Date DoB);
    void displayPersonalRec() const;
    int getAgeInYears() const;
private:
    string firstName;
    string lastName;
    const Date DoB;
};

#endif



