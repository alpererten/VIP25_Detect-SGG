# Implementation Plan

## 1. Set Up the ROS Environment

### Install ROS 2 Humble and Dependencies

- Install **ROS 2 Humble** (recommended)
- Install `cv_bridge`, `image_transport`, and `sensor_msgs` for handling camera data
- Install **PyTorch**, **OpenCV**, and **NumPy** for deep learning-based object detection

```bash
sudo apt update
sudo apt install ros-humble-vision-opencv   # check for the exact correct version for ROS 2 Humble
pip install torch torchvision opencv-python numpy
```

### Connect Your TurtleBot Camera (via Gazebo)

If in simulation (Gazebo), launch with:

```bash
roslaunch turtlebot3_gazebo turtlebot3_world.launch
```

Alternatively, test the Python code mentioned below (`YOLO_Detector_ROS2_Humble.py`) using an online simulation environment with ROS and Gazebo. 

I found this website: **The Construct** ([https://app.theconstruct.ai/](https://app.theconstruct.ai/)) that currently allows free simulation time (8hrs/day) with free signup. It also has a free 5-day ROS intro course with other similar courses available.

## 2. Implementing Object Detection

For object detection, we can use **DETIC, ViT, or YOLO** for real-time object detection. Here's a breakdown:

### (a) Using YOLOv8 for Object Detection (Recommended for ROS)

**YOLO** is fast and well-integrated with ROS.

#### Install YOLOv8:

```bash
pip install ultralytics
```

#### Load YOLO in a ROS node:

See the written script saved in `YOLO_Detector_ROS2_Humble.py` in this GitHub repository.

### Brief explanation of the code: `YOLO_Detector_ROS2_Humble.py`

This script is a ROS2 node that performs object detection using YOLOv8 on images from a Gazebo simulation camera. It also publishes detection results as visual markers in a 3D Gazebo environment.

#### Summary:

- Receives images from **Gazebo camera**.
- Detects objects using **YOLOv8**.
- Draws **bounding boxes** on images.
- Publishes **detected objects as 3D markers in Gazebo**.
- Visualizes the **processed image** using OpenCV.

#### The **ObjectDetector** Class

A ROS 2 node that handles image input, runs YOLO inference, and publishes results.

- **Initialization (`__init__`)**
  - Loads the YOLOv8 model.
  - Sets up **ROS2 publishers** (processed images, detected objects) and **subscribers** (camera feed, calibration info).
  - Stores **camera calibration parameters** and initializes **TF2 listener** for coordinate transformations.

- **Camera Info Callback (`camera_info_callback`)**
  - Retrieves and stores **camera intrinsic parameters** for accurate object localization.

- **Image Callback (`image_callback`)**
  - Converts **ROS image** to **OpenCV format**.
  - Runs **YOLO** inference to detect objects.
  - Processes detections: **draws bounding boxes and creates 3D markers** for visualization.
  - Publishes processed images and detected object markers.
  - Optionally displays the image using OpenCV.

- **Helper Functions**
  - `get_color(class_name)`: Generates and caches consistent colors for each object class.
  - `create_marker_gazebo(xyxy, class_name, confidence, timestamp)`: Converts 2D detections to 3D markers in Gazebo.

#### Main Function - `main()`
  - Initializes and runs the **ROS2 node**.
  - Spins until interrupted, then shuts down ROS2 and OpenCV windows.

---
---




# The Following Sections Are Saved For Later, Following A Succesful YOLO Implementation

### Using DETIC for Open-Vocabulary Detection

**DETIC** is powerful for **open-vocabulary detection** but requires a more complex setup.

#### Install DETIC:

```bash
git clone https://github.com/facebookresearch/Detic.git
cd Detic
pip install -r requirements.txt
```

Run DETIC in a **ROS node** by modifying the Detectron2 inference pipeline.

---

### Using Vision Transformer (ViT) for Object Detection

ViT-based object detection is **slower** but works well for certain applications.

#### Use DINO (DETR with ViTs) for object detection:

```bash
pip install transformers
```

Implement inference using the **Facebook DINO model**.

---

## 3. Scene Graph Understanding

**Scene Graph Understanding** helps the robot **reason about object relationships**.

### Using Scene Graph Generation (SGG) with Graph R-CNN

#### Install Scene Graph Benchmark:

```bash
git clone https://github.com/KaihuaTang/Scene-Graph-Benchmark.pytorch.git
cd Scene-Graph-Benchmark.pytorch
pip install -r requirements.txt
```

#### Run SGG model on object detection output:

```python
from scene_graph_benchmark.inference import SceneGraphPredictor

predictor = SceneGraphPredictor(model_path="path/to/sgg_model.pth")
relationships = predictor(image, detections)

print(relationships)
```

---

## 4. ROS Integration and Publishing Results

- Publish **detected objects** as **ROS messages** (Bounding Boxes, Labels).
- Use **tf2_ros** to **transform object coordinates** to the robot’s frame.
- Subscribe to **processed detection data** for **robot decision-making**.

---

## 5. General Notes on Object Detection

**Object detection** identifies objects in images or video feeds. We’re currently considering **YOLO** for initial implementation, with **DETIC and ViT** considered for future implementation.

### A. YOLO (You Only Look Once)
- **Pros**: Fast, real-time performance, good accuracy.
- **Cons**: Fixed object classes unless retrained.
- **Use Case**: Best for **real-time detection with high FPS**.

### B. DETIC (Detecting Everything in Context)
- **Pros**: Open-vocabulary detection (**can recognize objects not in its training set**).
- **Cons**: Requires a **Detectron2 setup**, heavier than YOLO.
- **Use Case**: Best if you need a **wide variety of object classes**.

### C. ViT (Vision Transformer)
- **Pros**: High accuracy, works well with transformers.
- **Cons**: **Slower than YOLO**, needs powerful hardware.
- **Use Case**: Best if **accuracy is more important than speed**.
