#include <VirtualSmallArray.h>
#include <Arduino.h>

VirtualSmallArray<int, 3> smallArray1{1, 2, 3};
VirtualSmallArray<int, 2> smallArray2{4, 5};

void print(const AbstractArray<int>& array) {
    Serial.println(array.size());
}

void setup() {
    Serial.begin(115200);
    print(smallArray1);
    print(smallArray2);
}

void loop() {
}