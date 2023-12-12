#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 
const char* ssid = "Jaspernet"; 
const char* password = NULL; 
const String url = "http://api.coindesk.com/v1/bpi/currentprice/BTC.json";

const int redPin = 15;   
const int greenPin = 2; 
static double previousPrice = 0.0;

void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.backlight();
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  lcd.clear();
  lcd.print("WiFi Connected");
  delay(2000);
}

void loop() {
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    StaticJsonDocument<2000> doc;
    deserializeJson(doc, payload);
    String BTCUSDPrice = doc["bpi"]["USD"]["rate_float"].as<String>();
     double currentPrice = BTCUSDPrice.toDouble();
  if (currentPrice > previousPrice) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    Serial.print("Green");
  } else if (currentPrice < previousPrice) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    Serial.print("Red");
  } else {
    // Turn off both LEDs if there is no change in price
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    Serial.print("Off");
  }
    previousPrice = currentPrice;
    lcd.clear();
    lcd.print("BTC/USD: ");
    lcd.setCursor(0, 1);
    lcd.print("$" + BTCUSDPrice);
  } else {
    lcd.clear();
    lcd.print("HTTP error: ");
    lcd.setCursor(0, 1);
    lcd.print(httpCode);
  }
  http.end();
  delay(10000);
}
