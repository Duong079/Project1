#include <Wire.h>
#include <BH1750.h>

#define SDA_PIN 21  
#define SCL_PIN 22  
BH1750 lightMeter;
void setup() {
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN);
    if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("BH1750 sensor initialized");
    } else {
        Serial.println("Error initializing BH1750");
    }
}

void loop() {
    float lux = lightMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lux");
    delay(1000);
}