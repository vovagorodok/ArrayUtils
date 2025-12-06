#include <SmallMap.h>
#include <Arduino.h>

SmallMap<int, int, 3> m{{1, 2}, {3, 4}, {5, 6}};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const auto& el : m)
        Serial.println(el.first);

    auto found = m.find(3);
    if (found != m.end())
        Serial.println(found->second);
}

void loop() {
}