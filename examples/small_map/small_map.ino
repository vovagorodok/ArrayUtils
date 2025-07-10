#include <SmallMap.h>
#include <Arduino.h>

SmallMap<int, int, 3> map{{1, 2}, {3, 4}, {5, 6}};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const auto& el : map)
        Serial.println(el.first);

    auto found = map.find(3);
    if (found != map.end())
        Serial.println(found->second);
}

void loop() {
}