#include <SmallArray.h>
#include <Arduino.h>
#include <iostream>

struct ToConv
{
    int a;
    bool b;
};

SmallArray<ToConv, 3> smallArray{};

void setup() {
    Serial.begin(115200);
    delay(2000);
    smallArray = {ToConv{8, false}, ToConv{6, false}, ToConv{7, false}};
    SmallArray<ToConv, 3> copy{smallArray};
    for (auto& el : copy)
        std::cout << el.a << " " << std::endl;
}

void loop() {
}

