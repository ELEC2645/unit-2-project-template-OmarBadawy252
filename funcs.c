#include <stdio.h>          // Standard input/output library
#include "funcs.h"          // Custom header file
#include <string.h>         // String handling library
#include <math.h>           // Math library
#include <ctype.h>          // Character type library

void menu_item_1(void) {
    printf("\n>> Menu 1\n");
    printf("\nHey, i'm your Ohm's Law Calculator\n");

    float V;    //voltage 
    float I;    // current    
    float R;    // resistance
    float P;    // power

    char Response[10];      // Buffer for user selection (V/I/R)
    char Response2[10];     // Buffer for yes/no follow-up question

    printf("Are you looking for V or I or R\n");
    fgets(Response,sizeof(Response),stdin);     // Read user choice

    // Check if user wants to solve for Voltage
    if(strncmp(Response, "V",1)==0 || strncmp(Response, "v",1)==0){
        printf("great what is your resistor value");
        scanf("%fl",&R);        // Read Resistance
        printf("what is your Current value");
        scanf("%fl",&I);        // Read current
        V=I*R;                  // Compute voltage using V=IR
        printf("The Voltage is %g\n",V);
        printf("do you want me to calculate the power next?\n");
        fgets(Response2,10,stdin);      // Read yes/no response
        if(strncmp(Response2, "yes",3)==0 || (strncmp(Response2, "Yes",3)==0) || strncmp(Response2,"y",1)==0){
            P=V*I;      // Compute power P = VI
            printf("The power is %g",P);}
        else{printf("okay, returning you to the main menu");}
    }

    // Check if user wants to solve for Current
    else if(strncmp(Response, "I",1)==0 || strncmp(Response, "i",1)==0){
        printf("great what is your Voltage value\n");
        scanf("%fl",&V);        // Read voltage
        printf("what is the Resistance\n");
        scanf("%fl",&R);        // Read resistance
        I=V/R;          // Compute current
        printf("The Current is %.6g\n",I);
        printf("do you want me to calculate the power next?");
        fgets(Response2,10,stdin);      //Read yes/no response
        if(strncmp(Response2, "yes",3)==0 || (strncmp(Response2, "Yes",3)==0 || strncmp(Response2,"y",1)==0)){
            P=V*I;
            printf("The power is %g",P);  
        }
        else{printf("okay, returning you to the main menu");}
    }

    // Check if user wants to solve for Resistance
    else if(strncmp(Response, "R",1)==0 || strncmp(Response, "r",1)==0){
        printf("what is your current value\n");
        scanf("%fl",&I);        // Read current
        printf("what is the Voltage\n");
        scanf("%fl",&V);        // Read voltage
        R=V/I;          // Compute resistance
        printf("The Resistance is %g\n",R);}
        printf("do you want me to calculate the power next?");
        fgets(Response2,10,stdin);      // Read yes/no response
        if(strncmp(Response2, "yes",3)==0 || (strncmp(Response2, "Yes",3)==0) || strncmp(Response2,"y",1)==0){
            P=V*I;          // Compute power
            printf("The power is %g",P);}
    else{printf("\nsorry i can only understand V, I or R\n");}
 
}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nWelcome to the RC filter design helper\n");

    char FilterType[100];             // Buffer for input filter type
    float freq;                       // Cutoff frequency
    float R;                          // Resistance
    float C;                          // Computed capacitor
    float L;                          // Inductor for band-pass case

    printf("what filter type are you building BAND PASS, LOW PASS, or HIGH PASS");
    fgets(FilterType, 100, stdin);          // Read user input

    // Low pass branch
    if (strncmp(FilterType, "low pass",8) == 0 ||strncmp(FilterType, "Low Pass",8) == 0 ||
    strncmp(FilterType, "LOW PASS",8) == 0){
        printf("what value do you want your cut off frequency to be?");
        scanf("%f",&freq);
        printf("whats your resistor value ");
        scanf("%f",&R);
        C=1/(2*3.14*freq*R);        // Compute capacitor for LPF

        printf("Designing a LOW-PASS RC filter...\n");
        printf("you should use a %g F capacitor\n", C);

        // Diagram for a low pass filter
        printf("------R|_|%.2fl-----------out\n",R);
        printf("                  |\n");
        printf("                  |\n");                     
        printf("                  %g\n",C);
        printf("                  _\n") ;                           
        printf("                  _\n");
        printf("                  |\n");
        printf("               ground");}
    
    //High pass branch
    else if (strncmp(FilterType, "high pass",9) == 0 ||
    strncmp(FilterType, "High Pass",9) == 0 ||
    strncmp(FilterType, "HIGH PASS",9) == 0){
        printf("what value do you want your cut off frequency to be?");
        scanf("%f",&freq);
        printf("whats your resistor value ");
        scanf("%f",&R);
        C=1/(2*3.142*freq*R);       // Compute capacitor for HPF

        printf("you should use a %gF capacitor\n", C);
        printf("Designing a HIGH-PASS RC filter...\n");
        printf("------||%g-----------------out\n",C);
        printf("                  |\n");
        printf("                  |\n");                     
        printf("                 %.2fl\n");
        printf("                  _\n") ;                           
        printf("                 |_\n");
        printf("                  |\n");
        printf("               ground\n");}
    
    // Band pass branch
    else if (strncmp(FilterType, "band pass",9) == 0 ||
    strncmp(FilterType, "Band Pass",9) == 0 ||
    strncmp(FilterType, "BAND PASS",9) == 0){
        printf("what value do you want your centre frequency to be?");
        scanf("%f",&freq);
        printf("whats your inductor value ");
        scanf("%f",&L);
        C=1/((2*3.142*freq)*(2*3.142*freq)*L);      // Compute band pass capacitor
        printf("you should use a %g F capacitor\n", C);
        printf("Designing a BAND PASS LC filter...\n");
        printf("      Vin\n");
        printf("       |\n");
        printf("       L\n");
        printf("       |\n");
        printf("      ----   (series LC passes only resonant frequency)\n");
        printf("       |\n");
        printf("       C\n");
        printf("       |\n");
        printf("     Vout\n");
        printf("       |\n");
        printf("      GND\n\n");}
    else{printf("The input you provided is not within this menu item?");}
    
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nReady for some DC-DC converters\n");

    char Choice[10];        // Converter choice  
    float Vin;              // Input voltage
    float Duty;             // Duty cycle
    float Vout;             // Output voltage

    printf("choose converter type between Buck or Boost or Cuk converter\n");
    fgets(Choice,sizeof(Choice),stdin);

    // Buck converter equation
    if(strncmp(Choice,"Buck",4)==0 || strncmp(Choice,"buck",4)==0){
        printf("Enter the Voltage in");
        scanf("%fl",&Vin);
        printf("enter the duty cycle");
        scanf("%fl",&Duty);
        Vout= Duty*Vin;         // Buck converter formula
        printf("The Voltage output for this topology should be %.2f", Vout);
    }

    // Boost converter equation
    else if(strncmp(Choice,"Boost",5)==0 || strncmp(Choice,"boost",5)==0){
        printf("Enter the Voltage in");
        scanf("%fl",&Vin);
        printf("enter the duty cycle");
        scanf("%fl",&Duty);
        Vout= Vin/(1-Duty);      // Boost gain
        printf("The Voltage output for this topology should be %.2f", Vout);
    }

    // Cuk converter equation
    else if(strncmp(Choice,"Cuk",3)==0 || strncmp(Choice,"cuk",3)==0){
        printf("Enter the Voltage in");
        scanf("%fl",&Vin);
        printf("enter the duty cycle");
        scanf("%fl",&Duty);
        Vout= -Vin*(Duty/(1-Duty));       // Inverting gain
        printf("The Voltage output for this topology should be %.2f", Vout);  
    }
    else{printf("The input you provided is not within this menu item");}
    }
    /* you can call a function from here that handles menu 3 */


void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nquiz time!!\n");
    int score = 0;
    const int total = 4;
    char ans[32];

    /* Q1: Ohm's law */
    printf("Q1) Which equation is Ohm's law?\n");
    printf("    a) V = I / R\n");
    printf("    b) V = I * R\n");
    printf("    c) V = R / I\n");
    printf("Your answer (a/b/c): ");
    if (fgets(ans, sizeof(ans), stdin)) {
        char a = (char)tolower((unsigned char)ans[0]);
        if (a == 'b') {
            printf("  Correct!\n\n");
            score++;
        } else {
            printf("  Wrong – the correct answer is b) V = I * R\n\n");
        }
    }

    /* Q2: RC low-pass cutoff frequency */
    printf("Q2) The cutoff frequency of a simple RC low-pass filter is:\n");
    printf("    a) f_c = R * C\n");
    printf("    b) f_c = 2πRC\n");
    printf("    c) f_c = 1 / (2πRC)\n");
    printf("Your answer (a/b/c): ");
    if (fgets(ans, sizeof(ans), stdin)) {
        char a = (char)tolower((unsigned char)ans[0]);
        if (a == 'c') {
            printf("  Correct!\n\n");
            score++;
        } else {
            printf("  Wrong – the correct answer is c) 1 / (2πRC)\n\n");
        }
    }

    /* Q3: Buck converter gain */
    printf("Q3) For an ideal buck converter, the output voltage is:\n");
    printf("    a) Vout = Vin / (1 - D)\n");
    printf("    b) Vout = D * Vin\n");
    printf("    c) Vout = -D / (1 - D) * Vin\n");
    printf("Your answer (a/b/c): ");
    if (fgets(ans, sizeof(ans), stdin)) {
        char a = (char)tolower((unsigned char)ans[0]);
        if (a == 'b') {
            printf("  Correct!\n\n");
            score++;
        } else {
            printf("  Wrong – the correct answer is b) Vout = D * Vin\n\n");
        }
    }

    /* Q4: Inverting converter */
    printf("Q4) Which topology can produce a negative output from a positive input (ideal case)?\n");
    printf("    a) Buck\n");
    printf("    b) Boost\n");
    printf("    c) Cuk (Ćuk) converter\n");
    printf("Your answer (a/b/c): ");
    if (fgets(ans, sizeof(ans), stdin)) {
        char a = (char)tolower((unsigned char)ans[0]);
        if (a == 'c') {
            printf("  Correct!\n\n");
            score++;
        } else {
            printf("  Wrong – the correct answer is c) Cuk converter\n\n");
        }
    }
    printf("Analyzing your answers...\n\n");
    printf("Quiz finished! You scored %d out of %d.\n", score, total);
    printf("Use this to revise Ohm's law, filters, and converters.\n");
}
