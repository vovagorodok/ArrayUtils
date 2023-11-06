#include <ArrayUtils.h>
#include <Arduino.h>

struct Pin {
    uint8_t num;
    uint8_t mode;
};

constexpr Pin createOutput(uint8_t num) {
    return {num, OUTPUT};
}

auto outputs = makeArray<Pin, 3>(createOutput, 2, 4, 5);

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const Pin& out : outputs)
    {
        Serial.println(out.num);
        pinMode(out.num, out.mode);
        digitalWrite(out.num, HIGH);
    }
}

void loop() {
}
