#include <SmallMap.h>
#include <Arduino.h>

SmallMap<int, int, 3> smallMap{{1, 2}, {2, 3}, {3, 4}};

void setup() {
    Serial.begin(115200);
    for (const auto& el : smallMap)
        Serial.println(el.key);

    auto found = smallMap.find(3);
    if (found != smallMap.end())
        Serial.println(found->value);
}

void loop() {
}