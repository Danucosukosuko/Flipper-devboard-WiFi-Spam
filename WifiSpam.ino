#include <WiFi.h>
#include <stdlib.h>
#include <time.h>


//  __          ___        ______ _    _____                       
//  \ \        / (_)      |  ____(_)  / ____|                      
//   \ \  /\  / / _ ______| |__   _  | (___  _ __   __ _ _ __ ___  
//    \ \/  \/ / | |______|  __| | |  \___ \| '_ \ / _` | '_ ` _ \ 
//     \  /\  /  | |      | |    | |  ____) | |_) | (_| | | | | | |
//      \/  \/   |_|      |_|    |_| |_____/| .__/ \__,_|_| |_| |_|
//                                          | |                    
//                                          |_|                    
// Spamea redes Wifi Aleatorias con este diccionario que tienes 6 líneas más abajo
// Si quiere añadir más redes, copie esta línea y colóquela abajo:

// "SSID WIFI",

const char* ssidDictionary[] = {
  "Red_Uno",
  "WiFi_Aventura",
  "Cafeteria_Gigabit",
  "Secret_Network",
  "SkyNet",
  "CoffeeLovers",
  "BananaSplit",
  "QuantumRealm",
  "PixelatedDreams",
  "CosmicWaves",
  "NebulaNet",
  "GalacticGarden",
  "Red_invitados",
  "StarshipEnterprise",
  "TimeTravelers",
  "ParallelUniverse",
  "CyberPirates",
  "SteampunkStation",
  "DreamWeavers",
  "ElectricRainbow",
  "ZigZagZephyr",
  "SuperSonic",
  "MagicMushroom",
  "RainbowDash",
  "ChocolateFactory",
  "JurassicPark",
  "HogwartsExpress",
  "Area51",
  "BlackHole",
  "Fireworks",
  "Moonlight",
  "BlueSky",
  "GreenForest",
  "RedPlanet",
  "OrangeJuice",
  "YellowSubmarine",
  "PurpleRain",
  "PinkFloyd",
  "WhiteNoise",
  "BlackMirror",
  "GoldenGate",
  "SilverSurfer",
  "BronzeMedal",
  "IronMan",
  "CopperWire",
  "PlatinumBlonde",
  "DiamondRing",
  "RubyTuesday",
  "EmeraldCity",
  "SapphireStone",
  "PearlJam",
  "RockyMountain",
  "SandyBeach",
  "SnowyWinter",
  "SunnyDay",
  "RainyNight",
  "StormyWeather",
  "WindyCity",
  "CloudySky",
  "FoggyMemory",
  "ClearVision",
  "HotSpot",
  "CoolZone",
  "SpicyFood",
  "SweetHome",
  "SourGrapes",
  "BitterTruth",
  "SaltySea",
  "UmamiTaste",
  "FreshAir",
  "FrozenHeart",
  "HappyHour",
  "SadSong",
  "AngryBirds",
  "FunnyJoke",
  "ScaryMovie",
  "CrazyTrain",
  "LazyTown",
  "BusyBee",
  "SmartCookie",
  "DumbBlonde",
  // Aquí hay algunos SSID típicos de fábrica de operadores de España que me conozco. Las X deberían ser reemplazadas por números y letras.
  "MOVISTAR_XXXX",
  "Vodafone-XXXX",
  "Orange-XXXX",
  "Yoigo-XXXX",
  "Masmovil-XXXX",
  "Jazztel_XXXX",
  "Lowi_XXXX",
  "O2-XXXX",
  "Pepephone-XXXX",
  "Amena-XXXX"
};

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);

  WiFi.softAP("ESP32_SSID", "1357924680");

  srand(time(0));

  char alfanumerico[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  while (true) {
    // Emitir SSID aleatorios en bucle
    for (int i = 0; i < 40; i++) {
      int randomIndex = random(0, sizeof(ssidDictionary) / sizeof(ssidDictionary[0]));
      String ssid = ssidDictionary[randomIndex];
      if (ssid.endsWith("XXXX")) {
        for (int j = 0; j < 4; j++) {
          // Generar un número aleatorio entre 0 y 35
          int randomInt = rand() % 36;
          // Obtener el carácter alfanumérico correspondiente
          char randomChar = alfanumerico[randomInt];
          // Añadir el carácter al SSID
          ssid += randomChar;
        }
        // Eliminar los XXXX originales
        ssid.remove(8, 4);
      }
      WiFi.softAP(ssid.c_str(), "1357924680");
      Serial.print("SSID emitido: ");
      Serial.println(ssid);
      delay(1000); // EMITE EL SSID ALEATORIO
    }
  }
}

void loop() {
  // No hace falta
}
