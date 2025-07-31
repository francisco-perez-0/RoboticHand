# Robotic Hand Control System

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

A complete robotic hand control system that uses computer vision to track hand movements and translate them into servo motor commands for a robotic hand.

## 📋 Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Components](#components)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Hardware Setup](#hardware-setup)
- [Configuration](#configuration)
- [Building and Flashing](#building-and-flashing)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This project consists of two main components:

1. **Python Computer Vision Application** (`/ManoRobot/`) - Tracks hand movements using a webcam and MediaPipe
2. **Embedded C Firmware** (`/examples/c/app/`) - Runs on EDU-CIAA-NXP board to control servo motors

The system captures hand gestures through a webcam, processes the finger positions using computer vision, and sends control signals to servo motors that drive a robotic hand.

## 📁 Project Structure

```
RoboticHand/
├── ManoRobot/                    # Python computer vision application
│   ├── main.py                   # Main hand tracking application
│   ├── interpolacion.py          # Interpolation utilities
│   └── main.spec                 # PyInstaller specification
├── examples/c/app/               # Embedded C firmware
│   ├── src/                      # Source files
│   │   ├── app.c                 # Main application
│   │   ├── mef.c                 # State machine
│   │   ├── timer.c               # Timer management
│   │   ├── usb.c                 # USB communication
│   │   └── resolucion.c          # Resolution and angle calculations
│   ├── inc/                      # Header files
│   └── config.mk                 # Build configuration
├── libs/                         # Embedded libraries
├── scripts/                      # Build and utility scripts
└── documentation/                # Project documentation
```

## 🔧 Components

### Python Application (`ManoRobot/`)

- **Hand Detection**: Uses MediaPipe and OpenCV for real-time hand tracking
- **Finger Tracking**: Tracks 5 fingers (thumb, index, middle, ring, pinky)
- **Serial Communication**: Sends control data to the embedded board
- **Resolution Control**: Configurable precision levels (1-8 bits)

### Embedded Firmware (`examples/c/app/`)

- **State Machine**: Manages different operating states
- **Servo Control**: Controls 5 servo motors for finger movement
- **USB Communication**: Receives data from Python application
- **Timer Management**: Handles timing and interrupts

## 📋 Requirements

### Python Application
- Python 3.7+
- OpenCV
- MediaPipe
- NumPy
- PySerial
- CVZone

### Embedded Development
- ARM GCC toolchain
- OpenOCD (for flashing)
- EDU-CIAA-NXP board
- 5 servo motors

## 🚀 Installation

### Python Application

1. Navigate to the ManoRobot directory:
```bash
cd ManoRobot
```

2. Install required packages:
```bash
pip install opencv-python mediapipe numpy pyserial cvzone
```

3. Run the application:
```bash
python main.py
```

### Embedded Firmware

1. Install ARM GCC toolchain:
```bash
# For Ubuntu/Debian
sudo apt-get install gcc-arm-none-eabi
```

2. Install OpenOCD:
```bash
sudo apt-get install openocd
```

3. Build the firmware:
```bash
make clean
make all
```

## 🎮 Usage

### Starting the System

1. **Connect Hardware**:
   - Connect EDU-CIAA-NXP board via USB
   - Connect servo motors to pins: SERVO4, SERVO8, SERVO1, SERVO2, SERVO3
   - Connect webcam to computer

2. **Flash Firmware**:
```bash
make download
```

3. **Run Python Application**:
```bash
cd ManoRobot
python main.py
```

4. **Configure Settings**:
   - Choose serial connection (if available)
   - Set resolution level (1-8)
   - Position hand in front of camera

### Controls

- **ENTER**: Exit application
- **N**: Change resolution level during execution
- **Hand Gestures**: Move fingers to control robotic hand

## 🔌 Hardware Setup

### EDU-CIAA-NXP Pin Mapping

| Servo | Pin | Function |
|-------|-----|----------|
| SERVO4 | GPIO8 | Thumb |
| SERVO8 | GPIO2 | Index |
| SERVO1 | T_COL0 | Middle |
| SERVO2 | T_FIL2 | Ring |
| SERVO3 | T_FIL3 | Pinky |

### LED Indicators

- **Red LED (GPIO1)**: Error state
- **Green LED (GPIO3)**: Success/Control state
- **Blue LED (GPIO7)**: Waiting state

## ⚙️ Configuration

### Resolution Levels

The system supports 8 resolution levels (1-8):
- Level 1: 2 positions per finger
- Level 2: 4 positions per finger
- ...
- Level 8: 256 positions per finger

### Serial Communication

- **Baud Rate**: 115200
- **Data Format**: 5 bytes per frame
- **Protocol**: ASCII commands ('a' for init, 'b' for data, 'c' for ack)

## 🔨 Building and Flashing

### Build Options

Edit `examples/c/app/config.mk`:
```makefile
VERBOSE=n          # Verbose output
OPT=g              # Optimization level
USE_NANO=y         # Use newlib nano
SEMIHOST=n         # Semihosting
USE_FPU=y          # Use FPU
```

### Build Commands

```bash
# Clean build
make clean

# Build firmware
make all

# Flash to board
make download

# Erase flash
make erase
```

## 🐛 Troubleshooting

### Common Issues

1. **Camera not detected**:
   - Check camera connection
   - Verify camera permissions
   - Try different camera index

2. **Serial communication fails**:
   - Check USB connection
   - Verify correct COM port
   - Ensure baud rate matches (115200)

3. **Servo motors not responding**:
   - Check power supply
   - Verify pin connections
   - Test individual servos

4. **Build errors**:
   - Install ARM GCC toolchain
   - Check board configuration
   - Verify library dependencies

### Debug Mode

Enable verbose output in `config.mk`:
```makefile
VERBOSE=y
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

This project is licensed under the BSD 3-Clause License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- EDU-CIAA-NXP development team
- MediaPipe for hand tracking
- OpenCV community
- SAPI library contributors

---


