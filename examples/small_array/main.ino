#include <SmallArray.h>
#include <Arduino.h>

struct Pin
{
    uint8_t num;
    uint8_t mode;
};
constexpr Pin createPin(uint8_t num)
{
    return {num, OUTPUT};
}

SmallArray<Pin, 3> pins{createPin, 2, 4, 5};

void setup() {
    Serial.begin(115200);
    for (const Pin& pin : pins)
    {
        Serial.println(pin.num);
        pinMode(pin.num, pin.mode);
        digitalWrite(pin.num, HIGH);
    }
}

void loop() {
}