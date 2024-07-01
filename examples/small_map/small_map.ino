#include <SmallMap.h>
#include <Arduino.h>

SmallMap<int, int, 3> smallMap{{1, 2}, {3, 4}, {5, 6}};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const auto& el : smallMap)
        Serial.println(el.first);

    auto found = smallMap.find(3);
    if (found != smallMap.end())
        Serial.println(found->second);
}

void loop() {
}