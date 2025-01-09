# Use the official Ubuntu image as the base
FROM ubuntu:22.04

# Install dependencies
RUN apt update && \
    apt install -y \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libqt5charts5-dev \
    build-essential \
    libgl1-mesa-dev \
    x11-apps \
    libxkbcommon-x11-0 \
    pkg-config

# Set the working directory
WORKDIR /app

# Copy the project files into the container
COPY . .

# Build the project
RUN make

# Run the application
CMD ["./NetworkMonitor"]