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

SmallArray<Pin, 3> smallArray{createPin, 2, 4, 5};

void setup() {
    Serial.begin(115200);
    for (const auto& el : smallArray)
    {
        Serial.println(el.num);
        pinMode(el.num, el.mode);
        digitalWrite(el.num, HIGH);
    }
}

void loop() {
}