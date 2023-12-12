# ESP32-Bitcoin-Ticker

The Bitcoin Price Tracker project is a real-time Bitcoin price monitoring system using the ESP32 microcontroller. This system fetches the current Bitcoin price in USD from the Coindesk API and displays it on an LCD 1602 screen. Additionally, an RGB LED is used to indicate whether the Bitcoin price is rising or falling. The project is an excellent educational tool for understanding the basics of interfacing ESP32 with APIs and external hardware components like LCDs and LEDs.

### Hardware Requirements
* ESP32-DevKitC1 
* LCD 1602 Display with I2C Interface
* RGB LED
* 100 ohm Resistors
* Breadboard and Jumper Wires

### Software Requirements
* Arduino IDE
* LiquidCrystal_I2C Library
* WiFi Library
* HTTPClient Library
* ArduinoJson Library

  ### Setup and Configuration
1. ESP32 Setup: Ensure that the ESP32 board manager is installed in the Arduino IDE.
2. Libraries: Install the LiquidCrystal_I2C, WiFi, HTTPClient, and ArduinoJson libraries.
3. Circuit Connection: Connect the LCD 1602 display and RGB LED to the ESP32 according to the schematic provided.
4. Network Configuration: Replace ssid and password in the code with your WiFi credentials.

### Code Explanation
* LCD Initialization: The LCD screen is initialized using the LiquidCrystal_I2C library.
* WiFi Connection: The ESP32 connects to a WiFi network to access the internet.
* API Request: The system makes HTTP requests to the Coindesk API to retrieve the current Bitcoin price.
* Price Display: The Bitcoin price in USD is displayed on the LCD screen.
* LED Indicator: The RGB LED changes color to indicate the price trend. Green for an increase, red for a decrease, and off for no change.
* Error Handling: The system displays HTTP error codes on the LCD in case of a failed API request.

### Usage
* Power up the ESP32 module.
* The system will automatically connect to WiFi and start fetching the Bitcoin price.
* Observe the price updates on the LCD screen every 10 seconds.
* Watch the RGB LED for visual indications of the price trend.

  ### Schematic
![Screenshot 2023-12-11 180954](https://github.com/hasanm02/ESP32-Bitcoin-Ticker/assets/133940432/f1d06559-8aa6-4aae-950d-775bd07b86f5)

  ### Code
  ![Screenshot 2023-12-11 200806](https://github.com/hasanm02/ESP32-Bitcoin-Ticker/assets/133940432/31e7cadb-13cc-45fd-bc46-8ee66858e05f)
  
![Screenshot 2023-12-11 200829](https://github.com/hasanm02/ESP32-Bitcoin-Ticker/assets/133940432/5f249c98-d6f8-49a3-83de-e1fd4f3c9f54)

![Screenshot 2023-12-11 200851](https://github.com/hasanm02/ESP32-Bitcoin-Ticker/assets/133940432/cc794263-47ee-42bf-9369-243a570d099b)
