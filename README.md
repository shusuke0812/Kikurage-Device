Kikurage Cultivation Device  
===

## Development

### Setup

- Install PlatformIO by VSCOde plugin
- Install M5Stack libraries
  - PIO Home > Libraries > M5Stack > Add Project
  - After that theses are set in /.pio/libdeps

### Run

1. Build
2. Write to devices

<img width="820" alt="スクリーンショット 2023-01-21 14 53 34" src="https://user-images.githubusercontent.com/33107697/213896397-924c891c-9b28-45fa-b22b-d903cad799bd.png">


### Debug

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