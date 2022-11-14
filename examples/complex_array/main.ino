#include <ArrayUtils.h>
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

auto outputs = makeArray<Pin, 3>(createPin, 2, 4, 5);

void setup() {
    Serial.begin(115200);
    for (const Pin& out : outputs)
    {
        Serial.println(out.num);
        pinMode(out.num, out.mode);
        digitalWrite(out.num, HIGH);
    }
}

void loop() {
}