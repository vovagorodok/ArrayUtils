#include <ArrayUtils.h>
#include <Arduino.h>

auto arrayOfPairs = makeArrayOfPairs<int, int, 3>({{1, 2}, {3, 4}, {5, 6}});

void setup() {
    Serial.begin(115200);
    for (const auto& el : arrayOfPairs)
        Serial.println(el.first);

    auto found = find(arrayOfPairs, 3);
    if (found != arrayOfPairs.end())
        Serial.println(found->second);
}

void loop() {
}