# Lab5_Analog_to_Digital_Conversion
In today's laboratory we will check out the Analog to Digital Conversion (ADC) module. Therefore, we will first configure our ADC-module so that it uses the potentiometer of our development board as an input and print its current voltage level on the display. We will then automate the conversion so that it is performed at regular intervals to automatically receive voltage level updates. Last but not least, we will use our LEDs to show how many quarters of our reference voltage are currently measured by the ADC, like a battery level indicator.

The experts among you will get a simple exercise, a binary counter based on the ADC. But is it really simple, or is there a hidden trap?

> [!TIP]
> In case you need the manual for Git again, click [here](https://github.com/MicrocontrollerApplications/Utilities/blob/main/git.md)
> If you need the development board's schematic, click [here](https://raw.githubusercontent.com/MicrocontrollerApplications/Lab2_InputOutput/refs/heads/main/images/uCquick_Board_2018_01.svg)
> The latest datasheet can be found [here](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18%28L%29F2X-4XK22-Data-Sheet-40001412H.pdf)

## Relevant registers
For today's laboratory we will need the previously used registers to configure our Oscialltor, I/O pins, Timers, CCP Module, and the
registers introduced in the lecture. All those registers are listed below. Please check them to ensure you are aware
of all relevant registers for today.
<details>
<summary><strong>Oscillator</strong></summary>
<table>
<tr><th align="left">OSCCON</th><td>is used to set the frequency (IRCF)</td></tr>
</table>
</details>
<details>
<summary><strong>I/O</strong></summary>
<table>
<tr><th align="left">TRISB</th><td> sets the direction of a pin: "0" = output, "1" = input</td></tr>
<tr><th align="left">PORTB</th><td> reads the logic level at the pin: "0" = 0-0.8 V, "1" = Vdd (1.6-3.3 V or 2.0-5.0 V for TTL inputs)</td></tr>
<tr><th align="left">LATB</th><td> set the output voltage of a pin: "0" = 0 V, "1" = Vdd (3.3 V or 5 V)</td></tr>
<tr><th align="left">ANSELB</th><td> sets a pin as digital or analog: "0" = digital, "1" = analog</td></tr>
<tr><th align="left">OSCCON</th><td> sets the oscillator freq.: 0x50 = 4 MHz, 0x30 = 1 MHz. The instruction freq. are 1 MHz and 250 kHz respectively</td></tr>
<tr><th align="left"><i>Register</i>bits.X</th><td> TRISBbits.TRISB3 or LATBbits.LATB3 or PORTBbits.RB3 is the direct access to the bit 3 via a struct (see structures in C).</td></tr>
</table>
</details>

<details>
<summary><strong>Timer X</strong></summary>
<table>
<tr><th align="left">TxCON</th><td> to configure Timerx (today x will be 0 and 1)</td></tr>
<tr><th align="left">TMRx<i>H/L</i></th><td> to set the timer to a given (initial) value</td></tr>
<tr><th align="left">INTCON</th><td> to check Timer0's interrupt (i.e. overflow) flag</td></tr>
</table>
</details>

<details>
<summary><strong>Capture Compare Module</strong></summary>
<table>
<tr><th align="left">CCPxCON</th><td>configure the Capture Compare Module</td></tr>
<tr><th align="left">CCPRx<i>H/L</i></th><td> set comparison value for comparison mode of Capture Compare Module</td></tr>
<tr><th align="left">CCPTMRS0</th><td> set timer to be compared with CCPx<i>H/L</i></td></tr>
<tr><th align="left">PIR1</th><td> to check Capture Compare Module's interrupt flag</td></tr>
</table>
</details>

<details>
<summary><strong>Interrupts</strong></summary>
<table>
<tr><th align="left">INTCON</th><td>globally enable Interrupts, Peripheral Interrupts and Timer0 Interrupt. Read/Write Timer0 interrupt flag (overflow flag)</td></tr>
<tr><th align="left">INTCON2</th><td>configure interrupt behaviour for external signals (e.g. buttons)</td></tr>
<tr><th align="left">INTCON3</th><td>enable interrupts for special pins and read / write their interrupt flag</td></tr>
<tr><th align="left">PIR</th><td>contains the flags for peripheral interrupts</td></tr>
<tr><th align="left">PIE</th><td>contains the individual enable bits for the peripheral interrupts</td></tr>
</table>
</details>

<details>
<summary><strong>Analogt / Digital Conversion</strong></summary>
<table>
<tr><th align="left">ADCON0</th><td>Select Channel (i.e. pin) as input for conversion, enable ADC-module, and start conversion.</td></tr>
<tr><th align="left">ADCON1</th><td>Select positive and negatie voltage reference.</td></tr>
<tr><th align="left">ADCON2</th><td>Configure justification of conversion result, Acquisition time, and conversion clock. </td></tr>
<tr><th align="left">ADRES</th><td>Read conversion result as 16 bit value. Use ADRESH and ADRESL to read result as two 8 bit values.</td></tr>
</table>
</details>

## Relevant chapters of the datasheet
We will use many of the available modules of our microcontroller today. Thus, the relevant chapters of the datasheet 
for today's laboratory are listed below.
- 2.0 OSCILLATOR MODULE (WITH FAIL-SAFE CLOCK MONITOR)
- 9.0 INTERRUPTS
- 10.0 I/O PORTS
- 12.0 TIMER1/3/5 MODULE WITH GATE CONTROL
- 14.0 CAPTURE/COMPARE/PWM MODULES
- 17.0 ANALOG-TO-DIGITAL CONVERTER (ADC) MODULE

## Exercise 1 - Configuring the ADC
As told in the lecture, you need to configure the ADC-modules timings; $T_{AD}$ sets the time each processing step of the ADC-module consumes (tipically set to 2µs). $T_{ACQ}$ defines the time used to load the capacitor. An exemplary calculation for thi timing is shown in Equation 17-1 in the datasheet. Look at the equation, understand it and use the given $T_{ACQ}$ for your configuration.
The procedure to convert an analog input into a digital value is explained in chapter 17.2.10 of the datasheet. You will find comments in the given main.c showing you where to implement those steps. Follow the instruction from the datasheet and configure your ADC.

> [!NOTE]
> You need to know the Osciallators frequency to determine the clock selection setting for the ADC, make sure to check configuration of the oscillator before configuring ADC-module's clock selection. Additionaly, keep in mind that $2\,\mu s$ is a good value for $T_{AD}$.


## Exercise 2 - Automatize conversion


## Exercise 3 - Battery Level indicator