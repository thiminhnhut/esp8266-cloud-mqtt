#include <Arduino.h>
#include <ControlDigitalOutput.h>
#include "WiFiSupportESP8266.h"
#include <PubSubClient.h>
#include "Configuration.h"

#define debug_port Serial

WiFiSupportESP8266 wifiSupport(&debug_port, LED_STATUS_WIFI, LED_STATE_WIFI);

WiFiClient espClient;
PubSubClient client(espClient);

ControlDigitalOutput led(LED_BUILTIN, LOW);

void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
void subscribe();

void setup() {
    debug_port.begin(115200);
    wifiSupport.isSmartConfig();

    client.setServer(MQTT_SERVER, MQTT_PORT);
    client.setCallback(callback);

    subscribe();
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
    String topicStr = topic;
    if (topicStr.equals(TOPIC_SUB_LOAD)) {
        if ((char) payload[0] == ON_LOAD) {
            Serial.println("ON");
            led.on();
        } else {
            Serial.println("OFF");
            led.off();
        }
    }
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect(DEVICE_ID, MQTT_USER, MQTT_PASSWORD)) {
            Serial.println("connected");
            subscribe();
        } else {
            Serial.printf("failed, rc= %d try again in 5 seconds", client.state());
            delay(5000);
        }
    }
}

void subscribe() {
    client.subscribe(TOPIC_SUB_LOAD);
}
