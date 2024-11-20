#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT11 Setup
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Pin Definitions
#define SOIL_MOISTURE_PIN A1
#define LDR_PIN A0
#define RED_LED 8
#define GREEN_LED 9

// Variables
int soilMoistureValue = 0;
int ldrValue = 0;
float temperature = 0.0;
float humidity = 0.0;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize DHT sensor
  dht.begin();

  // Initialize LED pins
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Serial monitor for debugging
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Land Monitoring");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read DHT11 data
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Read Soil Moisture data
  soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);
  int soilMoisturePercent = map(soilMoistureValue, 1023, 0, 0, 100); // Map to percentage

  // Read LDR value
  ldrValue = analogRead(LDR_PIN);
  String dayOrNight = (ldrValue > 500) ? "Day" : "Night"; // Threshold for Day/Night

  // Determine LED status
  if (soilMoisturePercent < 30) { // Adjust threshold as needed
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print("C ");
  lcd.print(dayOrNight);
  if (dayOrNight == "Day") {
    lcd.print("   "); // Add spaces to clear leftover characters
  }
  lcd.setCursor(0, 1);
  lcd.print("Moist:");
  lcd.print(soilMoisturePercent);
  lcd.print("%");

  // Debugging in Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Soil Moisture: ");
  Serial.print(soilMoisturePercent);
  Serial.print("%, Day/Night: ");
  Serial.println(dayOrNight);

  delay(2000); // Update every 2 seconds
}
