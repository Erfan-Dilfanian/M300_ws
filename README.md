# m300_ws

## Dependencies
```bash
sudo apt install ros-noetic-rosserial-msgs

pip3 install pyserial
```

## Usage

Place the M300 toward the north.

### ssh into the iCrest 2.0

```bash
ssh erfan@192.168.1.26
```

### main launch file
First, you need to source your `setup.bash`:
```bash
cd M300_ws
source devel/setup.bash
```

### Retardant-releasing nodes
Open a new terminal

First, you need to run the following node:
```bash
rosrun arduino_actuator serial_node.py /dev/ttyUSB0
```
Then, whenever you were ready, release the retardant with the following node:
```bash
rosrun arduino_actuator servo_pub.py
```
### To activate H20T camera
Open a new terminal.
```bash
rosrun dji_osdk_ros main_and_fpv_node
```

Then, for H20T usage, enter `1`.

Then, you can see the images from :
```bash
rqt_image_view
```

### To compress video images

```bash
rosrun dji_osdk_ros compress_video_node
```

### To run the fire detection
```bash
rosrun forest_fire_geopositioning fire_detection_v8.py
```

### To visualize the fire bounding boxes
rosrun forest_fire_geopositioning fire_spots_visualization

### To run the fire localization and SLAM
To run the SLAM manually:
```bash
rosrun ORB_SLAM3 fire_localization /home/qin/Downloads/ORB_SLAM3_Ubuntu_20/Vocabulary/ORBvoc.txt /home/qin/Downloads/ORB_SLAM3_Ubuntu_20/Examples_old/Monocular/GoPro.yaml
```
### To run the geopositioning
```bash
rosrun forest_fire_geopositioning geo_positioning
```

### Fighting nodes
```bash
rosrun forest_fire_detection_system InMotionDropping_Flight_control_node
```

### To launch all nodes
roslaunch forest_fire_geopositioning fire_geopositioning.launch


## Dateset available
https://drive.google.com/file/d/1YPX3RgdjjUx_tRMU9sRcODnS2XP0VS_U/view?usp=sharing

### Topics
```
/bounding_boxes/fire_spots
/clock
/dji_osdk_ros/gps_position
/dji_osdk_ros/main_wide_RGB
/position/camera_pose
/position/fire_spots
/position/fire_spots_GPS
/position/real_scale
```