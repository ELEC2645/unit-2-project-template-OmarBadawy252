#include <stdio.h>
#include "funcs.h"

void menu_item_1(void) {
    printf("\n>> Menu 1\n");
    printf("\nOhm's Law Calculator\n");
    float V;
    float I;
    float R;
    
    
    /* you can call a function from here that handles menu 1 */
}

void menu_item_2(void) {
    printf("\n>> Menu 2\n");
    printf("\nRC filter helper\n");
    char FilterType;
    float freq;
    float R;
    float C;
    float L;
    printf("what filter type are you building BAND PASS, LOW PASS, or HIGH PASS");
    fgets(FilterType, 100, stdin);
    if ('LOW PASS' || 'low pass' || 'Low Pass'){
        printf("what value do you want your cut off frequency to be?");
        scanf("%fl",&freq);
        printf("whats your resistor value ");
        scanf("%fl",&R);
        C=1/2*3.142*freq*R;
        printf("you should use a %.2f F capacitor", C);
    if ('HIGH PASS' || 'high pass' || 'High Pass'){
        printf("what value do you want your cut off frequency to be?");
        scanf("%fl",&freq);
        printf("whats your resistor value ");
        scanf("%fl",&R);
        C=1/2*3.142*freq*R;
        printf("you should use a %.2f F capacitor", C);
    if ('BAND PASS' || 'band pass' || 'Band Pass'){
        printf("what value do you want your centre frequency to be?");
        scanf("%fl",&freq);
        printf("whats your inductor value ");
        scanf("%fl",&L);
        C=1/(2*3.142*freq)*(2*3.142*freq)*L;
        printf("you should use a %.2f F capacitor", C);
    
    }

    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Menu 3\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 4\n");
    printf("\nSome code here does something useful\n");
    /* you can call a function from here that handles menu 4 */
}