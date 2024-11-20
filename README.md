# Soil-Monitoring-Land-Degradation-System-

## **Overview**
This project is an **Arduino-based Land Degradation Monitoring System** that provides real-time environmental data to assess the condition of the soil and surroundings. It uses sensors to monitor soil moisture, temperature, and light intensity (day/night), and provides visual feedback through LEDs. The data is displayed on a 16x2 LCD screen.

## **Features**
- **Soil Moisture Monitoring:** Displays the soil moisture percentage.
- **Temperature Monitoring:** Displays the current temperature in Celsius.
- **Day/Night Detection:** Indicates whether it is daytime or nighttime based on light intensity.
- **LED Indicators:**  
  - **Green LED:** Safe soil conditions.  
  - **Red LED:** Unsafe soil conditions.  
- **16x2 LCD Display:** Shows temperature, soil moisture percentage, and day/night status.

## **Components Used**
- **Arduino Uno**
- **16x2 LCD with I2C Module**
- **DHT11 Temperature and Humidity Sensor**
- **Soil Moisture Sensor**
- **LDR (Light Dependent Resistor)**
- **Red and Green LEDs**
- **Resistors (for LEDs and LDR)**
- **Jumper Wires**
- **Breadboard**

## **Circuit Connections**
| **Component**        | **Arduino Pin**        |
|-----------------------|------------------------|
| LCD (SCL)            | A5                    |
| LCD (SDA)            | A4                    |
| DHT11 (Data)         | 2                     |
| Soil Moisture (AO)   | A1                    |
| LDR                  | A0                    |
| Red LED (Positive)   | 8                     |
| Green LED (Positive) | 9                     |

## **Working Principle**
1. **Data Collection:**
   - The **DHT11** sensor collects temperature data.
   - The **Soil Moisture Sensor** measures soil moisture levels and outputs a percentage.
   - The **LDR** detects light intensity to differentiate between day and night.

2. **Data Processing:**
   - The Arduino reads sensor data and processes the values.
   - Soil moisture is converted into a percentage using `map()`.

3. **Output:**
   - The LCD displays:
     - Temperature in °C.
     - "Day" or "Night" status.
     - Soil moisture percentage.
   - LEDs indicate the soil condition:
     - **Red LED ON:** Unsafe moisture levels (<30%).
     - **Green LED ON:** Safe moisture levels (≥30%).

## **Code Explanation**
The Arduino sketch uses the following libraries:
- **Wire.h**: For I2C communication with the LCD.
- **LiquidCrystal_I2C.h**: To control the LCD.
- **DHT.h**: For reading temperature and humidity data from the DHT11 sensor.

### Key Functions:
- `dht.readTemperature()`: Reads the temperature in Celsius.
- `analogRead()`: Reads analog values from the LDR and soil moisture sensor.
- `lcd.print()`: Displays data on the 16x2 LCD.
- LED control logic ensures the appropriate LED glows based on soil conditions.

## **How to Use**
1. **Set up the hardware:**
   - Assemble the components as per the circuit connections.
   - Connect the Arduino to your computer via USB.
2. **Upload the code:**
   - Open the Arduino IDE.
   - Install the required libraries (`DHT sensor library`, `LiquidCrystal_I2C`).
   - Upload the sketch to the Arduino board.
3. **Monitor the data:**
   - Observe the data on the LCD.
   - Check the LED indicators for soil condition feedback.

## **Installation**
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/land-degradation-monitoring-system.git
   ```
2. Open the code in the Arduino IDE.
3. Install the required libraries via the Library Manager:
   - **DHT sensor library by Adafruit**
   - **LiquidCrystal_I2C**
4. Upload the sketch to the Arduino.
