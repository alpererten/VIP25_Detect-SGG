Commands to activate the YOLOv8 detection package:

Launch RViz2 (Terminal 1\)  
source /home/simulations/ros2\_sims\_ws/install/setup.bash  
rviz2 \-d /home/simulations/ros2\_sims\_ws/src/course\_perception\_ros2\_files/perception\_ros2/rviz/yolo\_object\_detection.rviz

Create the fruits in simulation (Terminal 2\)  
source /home/simulations/ros2\_sims\_ws/install/setup.bash  
ros2 launch perception\_ros2 spawn\_fruits.launch.py

Activate robot controller (Terminal 2\)  
ros2 run teleop\_twist\_keyboard teleop\_twist\_keyboard

Tilt Robots head down (Terminal 3\)  
source /home/simulations/ros2\_sims\_ws/install/setup.bash  
ros2 run deepmind\_bot\_trajectory\_sender move\_head.py 0.0 0.5 1

Turn on yolo detection node (Terminal 4\)  
cd \~/ros2\_ws/  
colcon build;source install/setup.bash  
ros2 run advanced\_perception yolo\_object\_detection  


