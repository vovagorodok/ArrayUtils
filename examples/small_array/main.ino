#include <SmallArray.h>
#include <Arduino.h>

SmallArray<int, 3> smallArray{1, 2, 3};

void setup() {
    Serial.begin(115200);
    for (auto el : smallArray)
        Serial.println(el);
}

void loop() {
}

