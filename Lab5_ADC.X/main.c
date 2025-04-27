/*
 * File:   main.c
 * Author: Sebastian Moosbauer
 *
 * Created on April 25, 2025, 11:58 AM
 */


#include <xc.h>

#include <LCD/GLCD_library.h>

void __init(void);
void __interrupt(high_priority) __isr(void);
uint16_t ADRES_to_mV(uint16_t register_val){
    // calculate measured voltage from register_val
    
    return 9999;
}

void main(void) {
    __init();

    while (1) {
        /*
         * ADC Conversion - Step 3: Start conversion
         */

        
        /*
         * ADC Conversion - Step 4: Wait for conversion to complete by polling the GO/DONE bit
         */
        while(/*find a sufficient value to check*/){
            Nop();
        }

        /*
         * ADC Conversion - Step 5: Read ADC result (and write it to display)
         */
        uint16_t voltage = ADRES_to_mV(/*what's missing here?*/);
        GLCD_Value2Out_00(1, 1, voltage, 4);
        

        // waste some time to not update the display to often
        for (unsigned int ii = 0; ii < 10000; ++ii)
            Nop();

    }

    return;
}

void __init(void) {
    OSCCONbits.IRCF = 5; // Fosc = ?
    GLCD_Init();
    GLCD_Text2Out(1, 1, "    mV");
    
    /*
     * ADC Conversion - Step 1: Configure Port
     */
    
    
    /*
     * ADC Conversion - Step 2: Configure the ADC module
     */
}
