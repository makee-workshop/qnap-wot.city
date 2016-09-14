#include "DHT.h"
#include <Bridge.h>

#define DHTPIN A1     //訊號來源為第2腳位
#define EARTHPIN A0     //訊號來源為第A1腳位
#define DHTTYPE DHT11 //感應器為DHT11
DHT dht(DHTPIN, DHTTYPE); //宣告一個DHT物件

void setup() {
// 開啟 Serial Port，通訊速率為 9600bps (Bits Per Second)
  Bridge.begin();
  Serial.begin(9600); 
  dht.begin();

}
void loop() {
  float humidity = dht.readHumidity();// 取出濕度的數值
  float temperature = dht.readTemperature();//取出溫度的數值
  int moisture = analogRead(2);
  
  // 檢查返回是否是有效的
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Moisture:");
    Serial.print(moisture);
    Serial.print(" %\t");
    Serial.print("Humidity: "); 
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(temperature);
    Serial.println(" *C");

    Bridge.put("moisture", String(moisture));
    Bridge.put("humidity", String(humidity));
    Bridge.put("temperature", String(temperature));
  }

   delay(1000); //每秒回傳一次資料
}
