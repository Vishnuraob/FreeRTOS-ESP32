#ESP32 FreeRTOS Real-Time Monitoring & Logging System

Overview

This project demonstrates a production-style embedded firmware architecture using ESP32 and FreeRTOS, focused on real-time task management, inter-task communication, fault detection, and system reliability.

The goal of this project is to showcase how a real embedded system is designed, structured, and reasoned, not just how code runs.

Problem Statement

In real-world embedded systems, multiple activities such as sensor acquisition, data processing, logging, and communication must run concurrently and deterministically.
A monolithic loop-based design quickly becomes unreliable and unscalable.

This project addresses:


•	Real-time task separation

•	Predictable timing behavior

•	Safe data sharing between tasks

•	Fault detection and recovery


Hardware Used

•	ESP32 Dev Module

•	I2C-based sensor (IMU / temperature sensor)

•	USB Serial (for logging)

•	Optional: SD Card / WiFi

The firmware is designed so that optional modules can be enabled or disabled without affecting core functionality.



Software Stack

•	ESP-IDF

•	FreeRTOS (native ESP-IDF integration)

•	C language

| Task Name       | Priority | Period       | Responsibility                            |
| --------------- | -------- | ------------ | ----------------------------------------- |
| Sensor Task     | High     | 50 ms        | Read raw sensor data and push to queue    |
| Processing Task | Medium   | Event-driven | Filter, validate, and process sensor data |
| Logger Task     | Low      | 500 ms       | Log processed data to Serial / SD         |
| Comm Task       | Low      | 1 s          | System status reporting (optional WiFi)   |
| Health Task     | Highest  | 2 s          | Monitor system health and task heartbeats |


Design rationale

•	Time-critical tasks have higher priority

•	Logging and communication are intentionally deprioritized

•	Event-driven tasks reduce CPU usage and improve responsiveness



Inter-Task Communication

The following RTOS mechanisms are used:

•	Queues

o	Sensor Task → Processing Task

•	Mutexes

o	Protected access to shared resources (logging interface)

•	Event Groups

o	System state signaling and fault flags

This prevents race conditions and ensures deterministic behavior.



Fault Detection & Reliability

A dedicated Health Task monitors:

•	Task execution timing

•	Missed heartbeats

•	Queue overflows

•	Unexpected delays

If abnormal behavior is detected:

•	Error flags are raised

•	Recovery actions can be triggered

•	System state is logged for debugging

This mimics real-world safety-oriented firmware design.



Project Structure

esp32-freertos-real-time-monitor/

│

├── main/

│   ├── app_main.c

│   ├── sensor_task.c

│   ├── processing_task.c

│   ├── logger_task.c

│   ├── comm_task.c

│   ├── health_task.c

│   └── system_init.c


│

├── drivers/

│   ├── sensor_driver.c

│   └── sensor_driver.h

│

├── utils/

│   ├── ring_buffer.c

│   ├── ring_buffer.h

│   └── error_handler.c

│

├── include/

├── README.md

└── architecture.png

This modular structure improves readability, testability, and scalability.



Timing & Scheduling Considerations

•	vTaskDelayUntil() is used for precise periodic execution

•	Blocking calls are avoided in high-priority tasks

•	Queue depths are chosen based on worst-case execution timing

•	Stack sizes are tuned per task to avoid memory waste

All timing values are documented and justified.



Build & Run Instructions

1.	Install ESP-IDF

2.	Clone this repository

3.	Configure the target:

4.	idf.py set-target esp32

5.	Build and flash:

6.	idf.py build flash monitor



Output & Results

•	Periodic sensor readings visible on serial monitor

•	Processed and validated data logs

•	Health task status messages

•	Fault detection messages under induced delays

The system continues operating safely under load.



Key Learnings

•	Practical FreeRTOS task design

•	Safe inter-task communication

•	Real-time scheduling trade-offs

•	Embedded system fault handling

•	Scalable firmware architecture



Future Improvements

•	Add SD card logging

•	Add WiFi/MQTT communication

•	Extend to multi-sensor fusion

•	Add persistent fault storage

