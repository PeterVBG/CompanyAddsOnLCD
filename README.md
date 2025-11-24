**Description of the assignment**

1. Code is based on: https://github.com/lafftale1999/cpp_embedded_assignment and https://wokwi.com/projects/445497618841194497

2. The program always run while powered on

3. The company adds are shown based on what they have paid:
    Medelvärde betalat är 4170 kr.
    1750 sek / 4170 sek = 0.42 ==> motsvarar 3 slots. Antar att ett företag har tre annonser och att alla ska visas en gång. Betyder att 1 slot motsvarar 0.14
    Company1: 5000/4170=1.20, 8.6 slots ==> 9 slots
    Company2: 2500/4170=0.60, 4.3 slots ==> 4 slots
    Company3: 4900/4170=1.18, 8.4 slots ==> 8 slots
    Company4: 1750/4170=0.42, 2.99 slots ==> 3 slots
    Company5: 6700/4170=1.61, 11.5 slots ==> 11 slots
    Totalt antalet slots i varje "Eternal loop" är 35. Av dessa 35 vigs 9 st åt första företaget, 4 åt andra etc. Detta skapar "rättvisa". 
    Detta sätt att göra det på är så klart inte det snyggaste men det fungerar. Jag förstod också att fokus i denna uppgift låg på hanteringar av bitar.

4. The company name is shown for 5 s

5. The add is shown for 10 s

6. The add blinks according to specification

7. The order of how the companies and adds are shown are not based on random values (based on what's described in bullet 3)

8. No heap allocation

9.  millis_wait_ms() is used

10. Folder structure according to specification

11. Code separation, every file represents a specific functionality for the program (see files in /src and /include folder)

12. Code delivered via Github

13. Executable .hex 

**Screenshot when .hex file is uploaded to https://wokwi.com/projects/445497618841194497**

<img width="548" height="662" alt="Image" src="https://github.com/user-attachments/assets/6b4fdbdd-5046-4890-a74a-13d5b0a3b4dc" />


**COMPANY AD SCREEN**

You have been tasked with writing the application logic for the Ad Screen used by your company and finishing the driver initialization of the LCD. The company's ad screen prints out the advertiser's name and then their ad message.

Sources
For this project you will use the Requirements Specification down below, a provided Wokwi sketch and the template codebase.

Link to template is here: https://github.com/lafftale1999/cpp_embedded_assignment 

Link to the sketch is here: https://wokwi.com/projects/445497618841194497

Grading
1. Deliverable
The complete program must be submitted via a private GitHub repository and shared with the examiner (@lafftale1999). There should be a .hex file ready to run the program available in the GitHub repository.
The student must also perform a live demonstration in a small group, where the program is run and key features are shown.
During the demo, the student must be able to explain key design and implementation decisions, as well as answer questions regarding the codebase.
2. Grading
This assignment can only be failed (IG) or passed (G). To pass:

All functional and non-functional requirements are met to a level that demonstrates the intended behavior and stability of the system.
The system runs without crashes.
The student can clearly explain how the program works.
The code should be well-structured, readable and logically divided per the specified deliverable requirements.
Assignment #2 - Embedded (1).pdf (see files in repo)

