#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <DHT.h>

// Wifi network station credentials
#define WIFI_SSID "Xiaomi 11T Pro"
#define WIFI_PASSWORD "kt23ncdrt9msa77"


// Initialize Telegram BOT
#define BOTtoken "6053654511:AAHLi5Abfo-RwPG9jAQj-fp1qHb_DWA9L_o"  // your Bot Token (Get from Botfather)
#define DHTPIN D7
#define LED1 D2
#define LED2 D3
#define LED3 D4
#define LED4 D6
int led1Status = 0;
int led2Status = 0;
int led3Status = 0;
int led4Status = 0;

#define DHTTYPE DHT11
// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "-4143647812"

#ifdef ESP8266
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;
bool ledState = LOW;

DHT dht(DHTPIN, DHTTYPE);

// Track which user controls which light
String user1ControlledLight = "1876565849"; // Filipus
String user2ControlledLight = "1941055053"; // rifan
String user3ControlledLight = "1799522585"; // arif

void handleNewMessages(int numNewMessages) {
  Serial.print("Handle New Messages: ");
  Serial.println(numNewMessages);

  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = bot.messages[i].chat_id;
    String text = bot.messages[i].text;
    // String from_name = bot.messages[i].from_name;
    // if (from_name == "")
    //   from_name = "Guest";

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    
    if (text == "/LED1on" || text == "/LED1on") {
      String from_name = bot.messages[i].from_id;
      Serial.println(from_name);
      if (from_name == user1ControlledLight){
        digitalWrite(LED1, HIGH); // turn the LED on (HIGH is the voltage level)
        led1Status = 1;
        bot.sendMessage(chat_id, "Led1 is ON", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }

    if (text == "/LED1off" || text == "/LED1off") {
      String from_name = bot.messages[i].from_id;
      if (from_name == user1ControlledLight){
        digitalWrite(LED1, LOW); // turn the LED on (HIGH is the voltage level)
        led1Status = 0;
        bot.sendMessage(chat_id, "Led1 is OFF", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }

    if (text == "/LED2on" || text == "/LED2on") {
      String from_name = bot.messages[i].from_id;
      if (from_name == user2ControlledLight){
        digitalWrite(LED2, HIGH); // turn the LED on (HIGH is the voltage level)
        led2Status = 1;
        bot.sendMessage(chat_id, "Led2 is ON", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }

    if (text == "/LED2off" || text == "/LED2off" ) {
      String from_name = bot.messages[i].from_id;
      if (from_name == user2ControlledLight){
        digitalWrite(LED2, LOW); 
        led2Status = 0;
        bot.sendMessage(chat_id, "Led2 is OFF", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }

    if (text == "/LED3on" || text == "/LED3on") {
      String from_name = bot.messages[i].from_id;
      if (from_name == user3ControlledLight){
        digitalWrite(LED3, HIGH); // turn the LED on (HIGH is the voltage level)
        led3Status = 1;
        bot.sendMessage(chat_id, "Led3 is ON", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }

    if (text == "/LED3off" || text == "/LED3off") {
      String from_name = bot.messages[i].from_id;
      if (from_name == user3ControlledLight){
        digitalWrite(LED3, LOW); 
        led3Status = 0;
        bot.sendMessage(chat_id, "Led3 is OFF", "");
      } else{
        bot.sendMessage(chat_id, "Anda tidak memiliki akses", "");
      }
    }


    if (text == "/LED4on" || text =="/LED4on") {
      digitalWrite(LED4, HIGH);
      led4Status = 1;
      bot.sendMessage(chat_id, "Led is ON", "");
    }

    if (text == "/LED4off" || text == "/LED4off") {
      led4Status = 0;
      digitalWrite(LED4, LOW); // turn the LED off (LOW is the voltage level)
      bot.sendMessage(chat_id, "Led is OFF", "");
    }

    if (text == "/ledstatus" || text == "/ledstatus") {
      String led1;
      String led2;
      String led3;
      String led4;
      String message = "LED Status: \n";
      if(led1Status == 1) {
        led1 = "Menyala";
      } else {
        led1 = "Mati";
      }
      if(led2Status == 1) {
        led2 = "Menyala";
      } else {
        led2 = "Mati";
      }
      if(led3Status == 1) {
        led3 = "Menyala";
      } else {
        led3 = "Mati";
      }
      if(led4Status == 1) {
        led4 = "Menyala";
      } else {
        led4 = "Mati";
      }

      message+= "LED1 sedang " + led1 + "\n";
      message+= "LED2 sedang " + led2 + "\n";
      message+= "LED3 sedang " + led3 + "\n";
      message+= "LED4 sedang " + led4 + "\n";
      
      bot.sendMessage(chat_id, message, "");
    }
    
    if (text == "/dhtstatus" || text == "/ledstatus") {
      String message = "";
      message += "Suhu : "+ String(t) + "°C\n";
      message += "Kelembapan : "+ String(h) + " %";
      bot.sendMessage(chat_id, message, "");
    }

    if (text == "/start") {
      String welcome = "Welcome to IoT Telegram Bot \n";
      welcome += "List of Commands:\n\n";
      welcome += "/LED1on : to switch the Led ON\n";
      welcome += "/LED1off : to switch the Led OFF\n";
      welcome += "/LED2on : to switch the Led ON\n";
      welcome += "/LED2off : to switch the Led OFF\n";
      welcome += "/LED3on : to switch the Led ON\n";
      welcome += "/LED3off : to switch the Led OFF\n";
      welcome += "/LED4on : to switch the Led ON\n";
      welcome += "/LED4off : to switch the Led OFF\n";
      welcome += "/ledstatus : Returns current status of LED\n";
      welcome += "/dhtstatus : Returns temperature and humidity status of DHT11\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println();

  // Sensor Pin Mode
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  dht.begin();

  // attempt to connect to Wifi network:
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  // Check NTP/Time, usually it is instantaneous and you can delete the code below.
  Serial.print("Retrieving time: ");
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);
}

void loop() {
  if (millis() - lastTimeBotRan > botRequestDelay) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    
    while (numNewMessages) {
      Serial.println("Got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    lastTimeBotRan = millis();
  }
}