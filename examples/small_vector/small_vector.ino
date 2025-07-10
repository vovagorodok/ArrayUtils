#include <SmallVector.h>
#include <Arduino.h>

SmallVector<int, 7> vector{1, 2, 3};
SmallVector<int, 2> other{8, 9};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    vector.push(4);
    for (const auto& el : vector)
        Serial.println(el);

    Serial.println();
    vector.push(other);
    for (const auto& el : vector)
        Serial.println(el);
}

void loop() {
}