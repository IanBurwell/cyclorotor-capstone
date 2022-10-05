# Cyclorotor Capstone

### Dev environment
1. [Install Arduino 2.0](https://www.arduino.cc/en/software)
2. [Install STM32 boards](https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json)
3. Setup the board: 
    - `Tools > Board > STM32 > Generic STM32H7` 
    - `Tools > Board > STM32 > Board Part Number > Generic H743VITx`
    - `Tools > Board > STM32 > Upload Method > DFU`  
    - `Tools > Board > STM32 > Upload Method > USB generic serial`

### Uploading Code
1. Put board into BOOT mode (hold boot button and apply power)
2. Upload via Arduino IDE

### Resources
- [FC we are using](https://pyrodrone.com/collections/30x30mm-flight-controllers/products/lumenier-lux-h7-hd-ultimate-flight-controller-30x30mm)
    - Betaflight firmware target: MATEKH743 
- [FC config file in betaflight](https://github.com/betaflight/unified-targets/blob/master/configs/default/MTKS-MATEKH743.config) (aka pinmapping for us)
