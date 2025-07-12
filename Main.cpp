#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>
#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h>
// Initialize the MLX90614 sensor
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
// Initialize the LCD screen with the pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Define the analog pin for AD8232 ECG sensor
const int ecgPin = A0;
// Pulse Sensor pin and instance
const int PulseSensorPin = A1;
PulseSensorPlayground pulseSensor;
// Software serial for ESP-01
SoftwareSerial espSerial(10, 9); // RX, TX
// Wi-Fi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
// Variables to store sensor readings
float temperature;
int ecgValue;
int heartRate;
void setup() {
 // Initialize serial communication for debugging
 Serial.begin(9600);
 espSerial.begin(115200);
 // Initialize the MLX90614 sensor
 mlx.begin();
 // Initialize the LCD screen
 lcd.begin(16, 2);
 lcd.print("Initializing...");
 // Initialize the pulse sensor
 pulseSensor.analogInput(PulseSensorPin);
 pulseSensor.setThreshold(550);
 pulseSensor.begin();
 // Initialize the Wi-Fi module
 connectToWiFi();
 // Clear the LCD screen
 lcd.clear();
}
void loop() {
 // Read temperature from MLX90614
 temperature = mlx.readObjectTempC();
 // Read ECG value from AD8232
 ecgValue = analogRead(ecgPin);
 // Read heart rate from Pulse Sensor
 heartRate = pulseSensor.getBeatsPerMinute();
 // Print the values to the serial monitor
 Serial.print("Temp: ");
 Serial.print(temperature);
 Serial.print(" C, ECG: ");
 Serial.print(ecgValue);
 Serial.print(", Heart Rate: ");
 Serial.println(heartRate);
 // Display the values on the LCD screen
 lcd.setCursor(0, 0);
 lcd.print("Temp:");
 lcd.print(temperature);
 lcd.print("C");
 lcd.setCursor(0, 1);
 lcd.print("HR:");
 lcd.print(heartRate);
 lcd.print(" ECG:");
 lcd.print(ecgValue);
 // Delay before the next loop
 delay(1000);
}
void connectToWiFi() {
 // Reset the module
 espSerial.println("AT+RST");
 delay(1000);
 if (checkResponse("OK")) {
 Serial.println("Module Reset");
 }
 // Set WiFi mode to station
 espSerial.println("AT+CWMODE=1");
 delay(1000);
 if (checkResponse("OK")) {
 Serial.println("Set WiFi mode to Station");
 }
 // Connect to WiFi network
 String cmd = "AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) 
+ "\"";
 espSerial.println(cmd);
 delay(5000); // Wait for connection
 if (checkResponse("OK")) {
 Serial.println("Connected to WiFi");
 } else {
 Serial.println("Failed to connect to WiFi");
 }
}
bool checkResponse(const char* expected) {
 String response = espSerial.readStringUntil('\n');
 return response.indexOf(expected) != -1;
}