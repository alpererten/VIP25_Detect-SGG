# Build stage
FROM osrf/ros:jazzy-desktop-full AS builder

# Set non-interactive installation
ENV DEBIAN_FRONTEND=noninteractive

# Add Gazebo package repository first (this rarely changes)
RUN apt-get update && apt-get install -y \
    lsb-release \
    wget \
    gnupg \
    git \
    && wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg \
    && echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null

# Install system dependencies (group similar packages together)
RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    python3-pip \
    python3-venv \
    python3-full \
    python3-catkin-pkg \
    python3-catkin-pkg-modules \
    python3-empy \
    python3-opencv \
    ros-jazzy-ros-gz-sim \
    ros-jazzy-ros-gz-bridge \
    ros-jazzy-ros-gz-interfaces \
    ros-jazzy-gz-ros2-control \
    ros-jazzy-cv-bridge \
    ros-jazzy-joy \
    ros-jazzy-rosidl-generator-py \
    gz-garden \
    ros-humble-ros-gz \
    ros-humble-ros-gz-bridge \
    ros-humble-ros-gz-interfaces \
    && rm -rf /var/lib/apt/lists/*

# Set up Python virtual environment with system packages
ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV --system-site-packages
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Install Python packages
COPY requirements.txt /tmp/
RUN pip3 install -r /tmp/requirements.txt && \
    rm -rf /root/.cache/pip/* && \
    rm -rf /tmp/*

# Set up workspace and build
WORKDIR /ros2_ws
COPY src /ros2_ws/src
RUN . /opt/ros/jazzy/setup.sh && \
    colcon build --symlink-install --cmake-args -DPYTHON_EXECUTABLE=/opt/venv/bin/python3

# Final stage
FROM osrf/ros:jazzy-desktop-full

# Copy Python environment and built workspace
COPY --from=builder /opt/venv /opt/venv
COPY --from=builder /ros2_ws/install /ros2_ws/install
COPY --from=builder /ros2_ws/build /ros2_ws/build

# Set up environment variables
ENV VIRTUAL_ENV=/opt/venv
ENV PATH="$VIRTUAL_ENV/bin:$PATH"
ENV GZ_SIM_RESOURCE_PATH=/usr/share/gz/models

# Copy source, models and textures
COPY src /ros2_ws/src
COPY models /usr/share/gz/models/
COPY textures /usr/share/gz/models/textures/

# Set up Gazebo models and fix texture paths
RUN chmod +x /ros2_ws/src/yolobot_gazebo/scripts/setup_gz_models.bash && \
    /ros2_ws/src/yolobot_gazebo/scripts/setup_gz_models.bash

# Set up environment
RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc && \
    echo "source /ros2_ws/install/setup.bash" >> ~/.bashrc && \
    echo "source /opt/venv/bin/activate" >> ~/.bashrc

# Use the default ROS 2 entrypoint
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"] 