# Cyclorotor Capstone

### Dev environment
1. [Install Arduino 2.0](https://www.arduino.cc/en/software)
2. [Install STM32 boards](https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json)
3. Setup the board: 
    - `Tools > Board > STM32 > Generic STM32F7` 
    - `Tools > Board > STM32 > Board Part Number > Generic F722RETx`
    - `Tools > Board > STM32 > Upload Method > DFU`  
    - `Tools > Board > STM32 > Upload Method > USB generic serial`

### Uploading Code
1. Put board into BOOT mode (hold boot button and apply power)
2. Upload via Arduino IDE

### Resources
- [FC we are using](https://pyrodrone.com/collections/flight-controllers/products/t-motor-f7-flight-controller)
    - Betaflight firmware target: Firmware Target: TMOTORF7
- [FC config file in betaflight](https://github.com/betaflight/unified-targets/blob/master/configs/default/TMTR-TMOTORF7.config) (aka pinmapping for us)
