#ifndef Configuration_h
#define Configuration_h

#define LED_STATUS_WIFI 2
#define LED_STATE_WIFI LOW

#define MQTT_SERVER "m16.cloudmqtt.com"
#define MQTT_PORT 14863
const char* MQTT_USER = "mqtt_user";
const char* MQTT_PASSWORD = "mqtt_password";

const char* DEVICE_ID = "esp8266";
const char* TOPIC_SUB_LOAD = "mqtt_topic";

#define ON_LOAD '1'
#define OFF_LOAD '0'
#endif
