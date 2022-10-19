#include <VirtualSmallMap.h>
#include <Arduino.h>

VirtualSmallMap<int, int, 3> smallMap{{1, 2}, {2, 3}, {3, 4}};

void print(const AbstractMap<int, int>& map) {
    for (const auto& el : map)
        Serial.println(el.key);

    auto found = map.find(3);
    if (found != map.end())
        Serial.println(found->value);
}

void setup() {
    Serial.begin(115200);
    print(smallMap);
}

void loop() {
}