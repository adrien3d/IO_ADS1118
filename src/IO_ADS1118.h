/***************************************************************************
  This is a library for the ADS1118 precision ADC

  Designed to work with all kinds of ADS1118 Breakout

  These sensors use I2C to communicate, 2 pins are required
  to interface.

  Written by Adrien Chapelet for IoThings
 ***************************************************************************/

#ifndef IO_ADS1118_h
#define IO_ADS1118_h

#define G6_144  (0b000)
#define G4_096  (0b001)
#define G2_048  (0b010)
#define G1_024  (0b011)
#define G0_512  (0b100)
#define G0_256  (0b101)

#include "Arduino.h"
#include <SPI.h>

class IO_ADS1118
{
    public:
        IO_ADS1118(int CS_pin);
        void begin();
        double adsRead(word port);
        double readTemp();
        bool setGain(uint16_t GainSet);

        byte self_test();
        word update_config(uint16_t new_config);
        word adsReadRaw(word port);
        double convToFloat(word read);

        //These are defined input pins, diff and single ended.
        const uint16_t DIF01 = 0x0000;
        const uint16_t DIF23 = 0x3000;       
        const word AIN0 = 0x4000;
        const word AIN1 = 0x5000;
        const word AIN2 = 0x6000;
        const word AIN3 = 0x7000;

    private:
        int _cs;                // chip select
        word CURRENT_CONFIG;    // Global variable holding configuration
        const word CONFIG_DEFAULT = 0x008B;
        const word CONFIG_TEMPERATURE = 0x049B;

        // Bit masks
        const word PIN_BITMASK = 0x7000;
        const word PGA_BITMASK = 0x0E00;

        // Gain selections
      //  const word G_6144 = 0x0000;
      //  const word G_4096 = 0x0200;
      //  const word G_2048 = 0x0400;
       // const word G_1024 = 0x0600;
       // const word G_0512 = 0x0800;
        //const word G_0256 = 0x0E00;
};

#endif
