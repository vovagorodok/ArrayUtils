#include <SmallQueue.h>
#include <Arduino.h>

SmallQueue<int, 3> queue{};

void setup() {
    Serial.begin(115200);
    while (not Serial);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();

    while (!queue.empty()) {
        Serial.println(queue.pop());
    }
}

void loop() {
}