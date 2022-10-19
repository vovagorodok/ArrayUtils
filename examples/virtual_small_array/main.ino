#include <VirtualSmallArray.h>
#include <Arduino.h>

VirtualSmallArray<int, 3> smallArray{1, 2, 3};

void print(const AbstractArray<int>& array) {
    for (const auto& el : array)
        Serial.println(el);
}

void setup() {
    Serial.begin(115200);
    print(smallArray);
}

void loop() {
}