# Network Monitor

A modern, cross-platform network monitoring application built with **C** (backend) and **Qt** (frontend). It displays real-time download and upload speeds in a graphical interface with a smooth, scrolling graph.

![Screenshot](screenshot.png) <!-- Add a screenshot if available -->

---

## Features

- **Real-Time Monitoring**:
  - Displays current download and upload speeds.
  - Updates every 100ms for a smooth experience.

- **Graphical Visualization**:
  - Shows a scrolling graph of network speeds over time.
  - Green line for download speed, red line for upload speed.

- **Modern Dark Theme**:
  - Sleek, dark-themed UI for a modern look.

- **Cross-Platform**:
  - Built with Docker for consistent behavior across Linux, macOS, and Windows.

---

## Prerequisites

- **Docker**: Ensure Docker is installed on your system.
  - [Install Docker](https://docs.docker.com/get-docker/)

- **X11 Forwarding** (for Linux/macOS):
  - Ensure X11 forwarding is enabled to display the GUI.
  - Run `xhost +` to allow Docker to access the X server.

---

## Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/NetworkMonitor.git
cd NetworkMonitor
```
### 2. Build the Docker Image
```bash
docker build -t network-monitor .
```
### 3. Run the Application
```bash
xhost +  # Allow Docker to access the X server
docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    network-monitor
```
![image](https://github.com/user-attachments/assets/fd88f390-7c71-4aee-9c48-da7065fc2dcd)

