#include <ArrayUtils.h>
#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    while (not Serial);

    Serial.println(countSize(5, 6, 7, 8));
}

void loop() {
}