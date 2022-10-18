#include <SmallArray.h>
#include <Arduino.h>

struct S
{
    int a;
    int b;
};

SmallArray<S, 3> smallArray{{1, 1}, {2, 2}, {3, 3}};

void setup() {
    Serial.begin(115200);
    for (auto el : smallArray)
        Serial.println(el.a);
}

void loop() {
}

