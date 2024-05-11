//#undef PICO_DEFAULT_LED_PIN
#define LED_PIN                     17
#define STOP_PIN                    20
#define ENCODER_PIN                 15

#define Selector_RX                 0       //C S pin motor 1
//#define Selector_TX2 0
#define Selector_DIAG_PIN           22      // STALL motor 1
#define Selector_EN_PIN             3       // Enable 
#define Selector_DIR_PIN            1       // Direction
#define Selector_STEP_PIN           2       // Step


#define Feeder_RX                   9
// Feeder_RX 9;      // CS pin motor 2
#define Feeder_DIAG_PIN             23      // STALL motor 2
#define Feeder_EN_PIN               6
#define Feeder_DIR_PIN              8
#define Feeder_STEP_PIN             7

#define MOT_SPI_SCK_PIN             19
#define MOT_SPI_MOSI_PIN            18
//int MOT_SPI_MOSI_PIN 18;
#define MOT_SPI_MISO_PIN            16

#define SERVO_PIN                   21

#define CAN_RX_PIN                  4
#define CAN_TX_PIN                  5

#define SDA_PIN                     26
#define SCL_PIN                     27