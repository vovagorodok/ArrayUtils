#include <ArrayUtils.h>
#include <Arduino.h>

auto pairArray = makePairArray<int, int, 3>({{1, 2}, {3, 4}, {5, 6}});

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const auto& el : pairArray)
        Serial.println(el.first);

    auto found = find(pairArray, 3);
    if (found != pairArray.end())
        Serial.println(found->second);
}

void loop() {
}