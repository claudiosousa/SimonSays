#include <avr/sleep.h>
#include <avr/power.h>
#define WAKEPIN 2                 // pin used for waking up

void someBtnPress()        // here the interrupt is handled after wakeup
{
  //keyPressed = true;
}


void setupSleep(){
  ADCSRA = 0; //disabel analog noise correction

  pinMode(WAKEPIN, INPUT);
}

void sleepNow()         // here we put the arduino to sleep
{
  attachInterrupt(0, someBtnPress, LOW); // use interrupt 0 (pin 2) and run function
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here

  sleep_enable();
  //attachInterrupt(0, btnPress, LOW); // use interrupt 0 (pin 2) and run function
  // Disable all peripheral power
  //power_all_disable();

  power_adc_disable();
  power_spi_disable();
  power_twi_disable();
  power_usart0_disable();

  sleep_mode();            // here the device is actually put to sleep!!

  sleep_disable();         // first thing after waking from sleep:
  detachInterrupt(0);      // disables interrupt 0 on pin 2 so the
}

