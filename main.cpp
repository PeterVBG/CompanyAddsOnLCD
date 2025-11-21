#include "millis.h"
#include "lcd_driver.hpp"
#include "CompanyAdds.h"
#include <stdlib.h>
#include <time.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

/*
    Medelvärde betalat är 4170 kr.
    1750 sek / 4170 sek = 0.42 ==> motsvarar 3 slots. Antar att ett företag har tre annonser och att alla ska visas en gång. Betyder att 1 slot motsvarar 0.14
    Company1: 5000/4170=1.20, 8.6 slots ==> 9 slots
    Company2: 2500/4170=0.60, 4.3 slots ==> 4 slots
    Company3: 4900/4170=1.18, 8.4 slots ==> 8 slots
    Company4: 1750/4170=0.42, 2.99 slots ==> 3 slots
    Company5: 6700/4170=1.61, 11.5 slots ==> 11 slots
    Totalt antalet slots i varje "Eternal loop" är 35. Av dessa 35 vigs 9 st åt första företaget, 4 åt andra etc. Detta skapar "rättvisa".
*/

int main(void) 
{
    //Initialization
    millis_init();
    sei();

    //hd44780 is a class with some public methods that we can use. First an object must be created
    hd44780 LCD; //Create an object LCD of class hd44780. Constructor, see lcd_driver.cpp. Här sker det jag skrev, dvs att man sitter alla pinnar som out-ports, initierar några till LOW, med mera.
    
    //Create 5 objects of class CompanyAdds, one for each company
    CompanyAdds CompAdd1(5000, "CoolCars LLC",  "Drive me crazy!",  "30-day moneyback guarantee",  "",  0,  0,  0);
    CompanyAdds CompAdd2(2500, "Pie People",  "Making people float",  "They are hot and jammy",  "",  1,  0,  0);
    CompanyAdds CompAdd3(4900, "Washomania",  "Clean customers happy customers",  "",  "",  1,  0,  0);
    CompanyAdds CompAdd4(1750, "Holy Burgers",  "Free drinks included in menu",  "Burgermania! 2 for 59 SEK",  "Badabim... Bada BURGER!",  0,  1,  1);
    CompanyAdds CompAdd5(6700, "Grymbo James",  "No more excuses! Only GAINS!",  "Pro Gymbono - 14 days free",  "",  1,  0,  0);
    CompanyAdds compAddsArray[5] = {CompAdd1, CompAdd2, CompAdd3, CompAdd4, CompAdd5};

    //Eternal loop
    while(1) 
    {
        int shallItBlink, addNbr, compNbr;

        //In the for loop, select company and which add to show. Not very nice coded...
        for (int j = 1; j < 36; j++)
        {
            if (j == 18 || j == 4 || j == 6 || j == 12 || j == 15 || j == 22 || j == 26 || j == 30 || j == 33)
            {
                //Company: CoolCars LLC
                compNbr = 0;
                //Show add1 or 2
                if (j == 18 || j == 6 || j == 15 || j == 26 || j == 33) {addNbr = 1;}
                else {addNbr = 2;}
            }
            else if (j == 2 || j == 9 || j == 24 || j == 35)
            {
                //Company: Pie People
                compNbr = 1;
                //Show add1 or 2
                if (j == 2 || j == 35) {addNbr = 1;}
                else {addNbr = 2;}
            }
            else if (j == 3 || j == 10 || j == 16 || j == 20 || j == 25 || j == 28 || j == 31 || j == 34)
            {
                //Company: Washomania
                compNbr = 2;
                //Only 1 add
                addNbr = 1;
            }
            else if (j == 7 || j == 14 || j == 32)
            {
                //Company: Holy Burgers
                compNbr = 3;
                //Show add1, 2 or 3
                if (j == 7) {addNbr = 1;}
                else if (j == 14) {addNbr = 2;}
                else {addNbr = 3;}
            }
            else if (j == 1 || j == 5 || j == 8 || j == 11 || j == 13 || j == 17 || j == 19 || j == 21 || j == 23 || j == 27 || j == 29)
            {
                //Company: Grymbo James
                compNbr = 4;
                //Show add1 or 2
                if (j == 1 || j == 8 || j == 13 || j == 19 || j == 23 || j == 29) {addNbr = 1;}
                else {addNbr = 2;}
            }

            //Show company name for 5 seconds, no blinking
            LCD.write_text(compAddsArray[compNbr].getCompanyName());
            millis_wait_ms(5000);
            //Check if the add shall blink
            shallItBlink = compAddsArray[compNbr].getAddBlink(addNbr);
            //Show selected add for 10 seconds, blinking or not blinking
            if (shallItBlink)
            {
                LCD.blink_text(compAddsArray[compNbr].getAdd(addNbr)); //Blinks for 10 s
            }
            else
            {
                LCD.write_text(compAddsArray[compNbr].getAdd(addNbr));
                millis_wait_ms(10000);
            }
        }
    }

    return 0;
}
    
    
