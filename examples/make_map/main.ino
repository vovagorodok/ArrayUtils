#include <MakeMap.h>
#include <Arduino.h>

auto smallMap{makeMap<int, int, 3>({{1, 2}, {3, 4}, {5, 6}})};

void setup() {
    Serial.begin(115200);
    for (const auto& el : smallMap)
        Serial.println(el.first);

    auto found = smallMap.find(3);
    if (found != smallMap.end())
        Serial.println(found->second);
}

void loop() {
}