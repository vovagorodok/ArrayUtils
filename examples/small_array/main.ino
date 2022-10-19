#include <SmallArray.h>
#include <Arduino.h>

struct Pin
{
    int num;
    bool activeHigh;
};
constexpr Pin createPin(int num)
{
    return {num, true};
}

SmallArray<Pin, 3> smallArray{createPin, 1, 2, 3};

void setup() {
    Serial.begin(115200);
    for (auto el : smallArray)
        Serial.println(el.num);
}

void loop() {
}