#define STEPSPERMM        [80, 80]

#define SELECTOR_CURRENT       700        // (mA) RMS current. Multiply by 1.414 for peak current.
    #define SELECTOR_CURRENT_HOME  SELECTOR_CURRENT  // (mA) RMS current for sensorless homing
    #define SELECTOR_MICROSTEPS     16        // 0..256
    #define SELECTOR_RSENSE          0.11     // Multiplied x1000 for TMC26X
    #define SELECTOR_CHAIN_POS      -1        // -1..0: Not chained. 1: MCU MOSI connected. 2: Next in chain, ...
    //#define X_INTERPOLATE  true      // Enable to override 'INTERPOLATE' for the X axis
    //#define X_HOLD_MULTIPLIER 0.5    // Enable to override 'HOLD_MULTIPLIER' for the X axis
    #define SELECTOR_ADDRESS    0b00
    #define SELECTOR_SPREADCYCLE  false

#define FEEDER_CURRENT       700        // (mA) RMS current. Multiply by 1.414 for peak current.
    #define FEEDER_CURRENT_HOME  FEEDER_CURRENT  // (mA) RMS current for sensorless homing or jamp
    #define FEEDER_MICROSTEPS     16        // 0..256
    #define FEEDER_RSENSE          0.11     // Multiplied x1000 for TMC26X
    #define FEEDER_CHAIN_POS      -1        // -1..0: Not chained. 1: MCU MOSI connected. 2: Next in chain, ...
    //#define X_INTERPOLATE  true      // Enable to override 'INTERPOLATE' for the X axis
    //#define X_HOLD_MULTIPLIER 0.5    // Enable to override 'HOLD_MULTIPLIER' for the X axis
    #define FEEDER_ADDRESS      0b00
    #define FEEDER_SPREADCYCLE  false


  /**
   * Software option for SPI driven drivers (TMC2130, TMC2160, TMC2660, TMC5130 and TMC5160).
   * The default SW SPI pins are defined the respective pins files,
   * but you can override or define them here.
   */
  //#define TMC_USE_SW_SPI
  //#define TMC_SW_MOSI       -1
  //#define TMC_SW_MISO       -1
  //#define TMC_SW_SCK        -1

  // @section tmc/serial

  /**
   * Four TMC2209 drivers can use the same HW/SW serial port with hardware configured addresses.
   * Set the address using jumpers on pins MS1 and MS2.
   * Address | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
   *
   * Set *_SERIAL_TX_PIN and *_SERIAL_RX_PIN to match for all drivers
   * on the same serial port, either here or in your board's pins file.
   */
  #define  SELECTOR_SLAVE_ADDRESS 0b00
  #define  FEEDER_SLAVE_ADDRESS 0b00