#include <ArrayUtils.h>
#include <Arduino.h>

auto pairs = makePairArray<int, int, 3>({{1, 2}, {3, 4}, {5, 6}});

void setup() {
    Serial.begin(115200);
    while (not Serial);

    for (const auto& el : pairs)
        Serial.println(el.first);

    auto found = find(pairs, 3);
    if (found != pairs.end())
        Serial.println(found->second);
}

void loop() {
}