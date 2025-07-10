#include <SmallVector.h>
#include <Arduino.h>

SmallVector<int, 7> smallVector{1, 2, 3};
SmallVector<int, 2> otherVector{8, 9};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    smallVector.push(4);
    for (const auto& el : smallVector)
        Serial.println(el);

    Serial.println();
    smallVector.push(otherVector);
    for (const auto& el : smallVector)
        Serial.println(el);
}

void loop() {
}