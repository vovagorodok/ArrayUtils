#include <SmallMap.h>
#include <Arduino.h>

SmallMap<int, int, 3> smallMap{{1, 2}, {2, 3}, {3, 4}};

void setup() {
    Serial.begin(115200);
    for (auto& el : smallMap)
        Serial.println(el.key);
}

void loop() {
}

