 #include "CompanyAdds.h"
 #include <string.h>

 // Implementations of CompanyAdds methods declared in the header

 CompanyAdds::CompanyAdds()
 {
     paidAmount = 0;
     strcpy(companyName, "Company name");
     strcpy(add1, "Add text number 1");
     strcpy(add2, "Add text number 2");
     strcpy(add3, "Add text number 3");
     blinkAdd1 = 0;
     blinkAdd2 = 0;
     blinkAdd3 = 0;
 }

 CompanyAdds::CompanyAdds(int money, const char name[], const char _add1[], const char _add2[], const char _add3[],
                          int _blinkAdd1, int _blinkAdd2, int _blinkAdd3)
 {
     paidAmount = money;
     strcpy(companyName, name);
     strcpy(add1, _add1);
     strcpy(add2, _add2);
     strcpy(add3, _add3);
     blinkAdd1 = _blinkAdd1;
     blinkAdd2 = _blinkAdd2;
     blinkAdd3 = _blinkAdd3;
 }

 int CompanyAdds::getPaidAmount() const { return paidAmount; }

 /*
 companyName is an array. 
 Function returns a pointer to where companyName is stored in memory. The return value shall be a pointer since write_text (that is the calling function) expects a pointer
 First const: The function returns a pointer to a constant char. This char cannot be modified. It protects the data from accidental modification by the caller (companyName shall not be changed). It signals that the return value is read-only.
 Second const: It means the function is a const member function. It cannot modify any member variables of the object, eg. company name cannot be changed*/
 const char* CompanyAdds::getCompanyName() const { return companyName; }

 const char* CompanyAdds::getAdd(int i) const
 {
     if (i == 1) return add1;
     else if (i == 2) return add2;
     else return add3;
 }

 int CompanyAdds::getAddBlink(int i) const
 {
     if (i == 1) return blinkAdd1;
     else if (i == 2) return blinkAdd2;
     else return blinkAdd3;
 }
