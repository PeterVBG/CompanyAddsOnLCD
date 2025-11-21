
#ifndef COMPANY_ADDS_HPP
#define COMPANY_ADDS_HPP

//#include <cstring> // For strcpy. acc to Copilot this is NOT included in AVR
#include <string.h> //acc to Copilot this is included in AVR

class CompanyAdds
{
private:
    int paidAmount;
    char companyName[32];
    char add1[32];
    char add2[32];
    char add3[32];
    int blinkAdd1;
    int blinkAdd2;
    int blinkAdd3;

public:
    // Default constructor
    CompanyAdds();

    // Overloaded constructor
    CompanyAdds(int money, const char name[], const char _add1[], const char _add2[], const char _add3[],
                int _blinkAdd1, int _blinkAdd2, int _blinkAdd3);

    // Getters
    int getPaidAmount() const;
    const char* getCompanyName() const;
    const char* getAdd(int i) const;
    int getAddBlink(int i) const;

    // No setters
};

#endif // COMPANY_ADDS_HPP
