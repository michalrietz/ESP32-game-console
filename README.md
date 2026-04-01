# ESP32 Game Console

## Cel
Stworzenie przenośnej konsoli do gier retro opartej na mikrokontrolerze ESP32.

## Środowisko programistyczne
* Visual Studio Code z rozszerzeniem PlatformIO
* Framework - Arduino

## Status
- [x] Ustalenie połączeń wszystkich elementów
- [ ] Oczekiwanie na dostawę reszty komponentów
- [ ] zrobienie prototypu na płytkach stykowych
- [ ] Wgranie i konfiguracja emulatora
- [ ] Projekt docelowej płytki PCB oraz obudowy do niej.

## Lista zakupionych części
* DOIT ESP32 DEVKIT V1
* 2x Breadboard
* Wzmacniacz dźwięku: MAX98357 I2S 3W Class D
* Głośnik: 4 ohm 3W (Ultra-Thin Box Speaker)
* Ekran: 2.8 inch TFT LCD SPI z czytnikiem MicroSD
* Karta MicroSD 8GB
* 4x małe przyciski (tact-switch)
* Joystick KY-023

## Pinout

### Ekran i Karta SD
* SCK -> GPIO 18
* MOSI -> GPIO 23
* MISO -> GPIO 19
* TFT_CS -> GPIO 5
* TFT_DC -> GPIO 21
* TFT_RST -> GPIO 22
* SD_CS -> GPIO 4

### Dźwięk
* LRC -> GPIO 25
* BCLK -> GPIO 26
* DIN -> GPIO 27

### Sterowanie
* Joystick VRx -> GPIO 34
* Joystick VRy -> GPIO 35
* Przycisk A -> GPIO 32
* Przycisk B -> GPIO 33
* Przycisk START -> GPIO 13
* Przycisk SELECT -> GPIO 14
