Kikurage Cultivation Device  
===

## Development

### Setup

- Install PlatformIO by VSCOde plugin
- Install M5Stack libraries
  - PIO Home > Libraries > M5Stack > Add Project
  - After that theses are set in /.pio/libdeps
- microSD card
  - Image Data
    - An image size must be set 320*240, because M5 libraries does not have zooming image method.
    - Sad.jpg and Smile.jpg are saved on SD. (Jan, 2023)
    - format is FAT32
- Include libraries
  - Go to PIO Home
  - Select `Libraries` tab on side menu
  - Search and select libraries
  - Tap `Add to Project` button
- Search libraries([ref](https://registry.platformio.org/search?t=library&f=espidf&f=arduino))
- Generate Bluetooth Service UUID and Characteristic UUID on [this page](https://www.uuidgenerator.net/).

### Run

1. Build
2. Write to devices

<img width="820" alt="スクリーンショット 2023-01-21 14 53 34" src="https://user-images.githubusercontent.com/33107697/213896397-924c891c-9b28-45fa-b22b-d903cad799bd.png">


### Debug

#### Checking Serial Monitor

1. setup as following

```c
// main.cpp

void setup() {
  Serial.begin(115200); // 115200 is serial port number
}

// platformio.ini
monitor_speed = 115200
```

2. build and run source files
3. open serial monitor

<img width="985" alt="スクリーンショット 2023-01-22 13 21 09" src="https://user-images.githubusercontent.com/33107697/213900500-c2d2350f-f345-490f-bcd2-0f7a5f8c6998.png">

<br />

#### Analyzing Backtraces

https://github.com/shusuke0812/Kikurage-Device/issues/1#issuecomment-1446436848



### Reference

- [How to create header and source files](https://skpme.com/621/)