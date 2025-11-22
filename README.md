# ColourChase
# ColourChaser – Arduino Color Detection & LED Replication


> A real‑time color sensing and LED replication project using the TCS3200 sensor and Arduino. Ideal for robotics, sorting, and learning applications.

**Hardware Project – HW 531**
**Date:** December 2024

ColourChaser is an Arduino‑based project that uses a TCS3200 color sensor to detect the color of an object and instantly replicate it using an RGB LED. The sensor outputs frequency values corresponding to red, green, and blue light intensities, which the Arduino converts into PWM values to drive the LED.


#  Project Overview

The ColourChaser system works by:

1. Filtering incoming light through the TCS3200 color sensor.
2. Measuring the frequency of light corresponding to red, green, and blue components.
3. Converting those frequency values into intensity values (0–255).
4. Sending PWM outputs to an RGB LED to recreate the detected color.

This results in real‑time color matching, useful for robotics, sorting systems, design tools, and learning applications.


##  Components Required

* **Arduino Uno**
* **TCS3200 / TCS230 color sensor**
* **Common‑cathode RGB LED**
* **220Ω resistors** (for LED)
* **Jumper wires**
* **Breadboard**

---

##  Wiring Diagram

### **TCS3200 to Arduino**

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| S0         | 2           |
| S1         | 3           |
| S2         | 4           |
| S3         | 5           |
| OUT        | 7           |
| VCC        | 5V          |
| GND        | GND         |

### **RGB LED to Arduino**

| LED Pin | Arduino Pin |
| ------- | ----------- |
| Red     | 11          |
| Green   | 10          |
| Blue    | 6           |
| Cathode | GND         |

---

##  How It Works

### 1. **Setting Frequency Scaling**

The sensor output frequency is scaled to 20% using:

```cpp
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);
```

This ensures stable readings.

### 2. **Reading Red, Green, and Blue Values**

The sensor uses S2 and S3 to select a color filter:

* Red: `S2 LOW`, `S3 LOW`
* Green: `S2 HIGH`, `S3 HIGH`
* Blue: `S2 LOW`, `S3 HIGH`

Each color value is captured using `pulseIn(sensorOut, LOW)`.

### 3. **Converting Sensor Output**

The raw pulse value is inverted to an intensity:

```cpp
rcolourstrength = 255 - rcolourstrength;
```

This produces a 0–255 value for LED PWM.

### 4. **Color Matching Logic**

The sketch includes additional logic that exaggerates the dominant color:

* The strongest channel becomes 255
* Other channels are reduced for clearer color reproduction

### 5. **Driving the RGB LED**

The final intensities are applied using:

```cpp
analogWrite(redPin, rcolourstrength);
```

producing the matched color.


##  Serial Monitor Output

The Arduino prints the raw RGB intensity readings for debugging:

```
R= 122  G= 98  B= 67
```

This is useful for calibration and testing.


##  Full Source Code

The project’s full Arduino code is included in this repository. It handles:

* Sensor configuration
* Color value reading
* Data transformation
* LED color output


##  Possible Improvements

* Add automatic calibration routines
* Smooth values using averaging or filtering
* Display detected color name on an OLED
* Send RGB values over Bluetooth or WiFi





