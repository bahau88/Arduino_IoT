#include "Wire.h"
#include "Seeed_SHT35.h"

#define SDA_PIN A4
#define SCL_PIN A5

SHT35 sensor(0x45);  // Provide the I2C address of your sensor

void setup() {
    Serial.begin(115200);
    Wire.begin();
    delay(10);
    Serial.println("Serial started!!");
    if (!sensor.init()) {
        Serial.println("Sensor initialization failed!!");
    }
    delay(1000);
}

void loop() {
    float temp, hum;
    if (NO_ERROR != sensor.read_meas_data_single_shot(HIGH_REP_WITH_STRCH, &temp, &hum)) {
        Serial.println("Read temperature failed!!");
        Serial.println("   ");
        Serial.println("   ");
        Serial.println("   ");
    } else {
        Serial.println("Printer Temperature:");
        Serial.print("Temperature = ");
        Serial.print(temp);
        Serial.println(" ℃ ");

        Serial.print("Humidity = ");
        Serial.print(hum);
        Serial.println(" % ");

        Serial.println("   ");
        Serial.println("   ");
        Serial.println("   ");
    }
    delay(5000);
}
