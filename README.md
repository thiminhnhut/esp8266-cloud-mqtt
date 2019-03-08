# Ví dụ kết nối ESP8266 với Cloud MQTT

* **Thực hiện:** Thi Minh Nhựt - **Email:** <thiminhnhut@gmail.com>

* **Thời gian:** Ngày 08 tháng 03 năm 2019

## Nội dung thực hiện

* Cloud MQTT: <https://www.cloudmqtt.com/>: đăng ký tài khoản và Config: (Xem hướng dẫn cách config Cloud MQTT: <https://hocarm.org/mqtt-va-esp8266/>)

* Thay đổi một số config trong `include/Configuration.h`:

    ```cpp
    #define MQTT_SERVER "m16.cloudmqtt.com"
    #define MQTT_PORT 14863
    const char* MQTT_USER = "mqtt_user";
    const char* MQTT_PASSWORD = "mqtt_password";
    const char* TOPIC_SUB_LOAD = "mqtt_topic";
    ```

* Sử dụng LED để test (trong `include/Configuration.h`):

    ```cpp
    #define LED_STATUS_WIFI 2
    #define LED_STATE_WIFI LOW

    #define ON_LOAD '1'
    #define OFF_LOAD '0'
    ```
* Kết nối WiFi với giao thức `SmartConfig` (sử dụng App `Esptouch` hoặc `ESP8266 SmartConfig`).

* Gửi `1` thì `LED_STATUS_WIFI` sáng, gửi `0` thì `LED_STATUS_WIFI` không sáng.


* Các file trong chương trình:

    * Config project [platformio.ini](https://github.com/thiminhnhut/esp8266-cloud-mqtt/blob/master/platformio.ini)

    * File: [Configuration.h](https://github.com/thiminhnhut/esp8266-cloud-mqtt/blob/master/include/Configuration.h)

    * File [main.cpp](https://github.com/thiminhnhut/esp8266-cloud-mqtt/blob/master/src/main.cpp)
