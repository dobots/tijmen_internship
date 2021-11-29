
# tijmen_internship
# README Tijmen internship
hi,
This readme will tell you more about how to run my visualization project for the Husarion rosbot @ dobots. In the project multiple approaches were attempted to visualize the sensor data of a robot. An extensive overview of these approaches can be found in the accompanying report, see *Internship_DoBots_report_Tijmen_van_Enckevort.pdf*. 

The basis of the project is a simulation based on the Husarion Rosbot. The rosbot is simulated in Gazebo, and makes use of standard ROS packages. The algorithms can also be run on the real Rosbot without a simulation environment. 
First you have to clone everything in this repo into a separate catkin_workspace.
There are two options to run the project, one is in a simulation environment in gazebo, the other is on the real husarion robot. 
## Simulated environment in Gazebo
To run the project in a simulated environment run: 
```
roslaunch rosbot_gazebo husarion_simulation.launch
```
## Real husarion
to run the project on the real husarion first connect to the husarion with ssh. Then run 
```
roslaunch rosbot_bringup rosbot_visualisation.launch
```
on the husarion robot at dobots. 
Then run
```
roslaunch rosbot_gazebo husarion_real.launch
```
on your pc terminal. 

## Rviz
Both roslaunches as decribed above will launch iviz with the correct settings. In the left displays tab you can select which sensor data you want to show/hide. 
Rviz image overview
Rviz image detail

## Gazebo
There are two main options of visualizing directly in Gazebo. The first one is the lidar sensor, and can be done by setting the `<visualize>` tag to true in `rosbot.gazebo`.
Gazebo lidar image

To display the robot path you will have to run the`rosrun gazebo_visualize_path`node. This is a cpp node in the `gazebo_vis` folder. It makes use of ignition messages, and publishes a triangle list based on the poses of its PoseArray subscription.
Gazebo path image

It is also possible to display an image using a projector. This can be done by uncommenting the `libgazebo_ros_projector.so` plugin in `rosbot_gazebo`. The image you want to display should be put in the `usr/share/gazebo-11/media/materials/textures` folder.
 
## Iviz
The Iviz application can be downloaded from its [github page.](https://github.com/KIT-ISAS/iviz). It is recommended to read [the Iviz readme](https://github.com/KIT-ISAS/iviz/tree/master/iviz), as it explains the way to install/use the Iviz tool well. On this repo the meshes in the URDF have already been changed to .dae files. If you cannot see your robot after using the model service it might be a good idea to check if your meshes are .dae file. Filetypes like .stl can be changed to .dae in [Blender](https://www.blender.org/).

## Photogrammetry/Meshroom
The Meshroom application can be downloaded from its [website.](https://alicevision.org/#) It is recommended to read [the meshroom website](https://alicevision.org/#meshroom) and watch its videos to get a good understanding of the meshroom pipeline. There is also a test dataset, which can be used as a validated test. The images from the test dataset can be found [here](https://meshroom-manual.readthedocs.io/en/latest/first-steps/test/index.html). There might also be a problem arising saying you need to enable a CUDA enable GPU when you have a Nvidia GPU installed. It is recommended to google how to enable it, as it is different per GPU. If using Ubuntu 20.04 it could be that the program NVIDIA X Server Settings is installed on your laptop, here you can go to PRIME Profiles and select your NVIDIA gpu in performance mode. To check if it has worked, restart your computer, go to settings, about, and check the gpu under graphics. If it is not the NVIDIA gpu it might be solved by booting your laptop in insecure mode, and doing all the steps again. 






## Changes wrt original os code.
### both environments
First of all there are the 5 params.yaml files in the tutorial_pkg/config folder. They mostly contain default values for the husarion robot, but some values are altered to let the robot drive closer to obstacles for example. 

In the rplidar_ros pkg nothing is changed. 

In the rosbot_ekf pkg nothing is changed.

### real environment
In rosbot_description/src/rosbot_gazebo/launch there is a launch file husarion_real.launch that launches all the necessary files to run the robot in the real environment. Here, there is also an added frame for the camera_broadcoaster to get the camera in the right position to be able to view it under the camera topic in rviz. This frame might not be exactly accurate, and is done purely on a guess so that it looked sort of at the right place. If any problems occur with an exact placement of the camera image this might be a good place to start problemsolving. 

In rosbot_description/src/rosbot_gazebo/rviz there is a maze_real.rviz file that will make sure all the necessary displays are there for the visualisation.
### simulated environment
In rosbot_description/src/rosbot_description/urdf/rosbot.gazebo the visualize parameter for the laserscanner is set to true to be able to see it in gazebo. There are also a added projector, and 2 more cameras which were used to test if the robot would work with a rig of camera's instead of just one. They can be used by uncommenting the respective parts in the code. 

In rosbot_description/src/rosbot_gazebo/launch there is a launch file husarion_simulation.launch that launches all the necessary files to run the robot in the simulated environment.

In rosbot_description/src/rosbot_gazebo/rviz there is a maze_simulation.rviz file that will make sure all the necessary displays are there for the visualisation.

For the projector you will need to add a picture in your /usr/share/gazebo-11/media/materials/textures folder. Right now it is called dobots.jpeg, and can also be found in the /home/tijmen/hus_ws/src/tijmen_internship/gazebo_vis/src folder. To change this picture because it is not of your liking you can add a different picture in the /usr/share/gazebo-11/media/materials/textures folder and change the name of the picture in the /home/tijmen/hus_ws/src/tijmen_internship/rosbot_description/src/rosbot_description/urdf/rosbot.gazebo file in lines 432 and 443. 

### video output
To be able to save a video stream for the Gazebo camera streams you will have to alter the openni camera plugin in the src/tijmen_internship/rosbot_description/src/rosbot_description/urdf/rosbot.gazebo file. Here you will have to set the save tag to true, and specify the path to which you want to save the images. To get a video out of the images run (with the correct path to your camera images)

```
ffmpeg -r 10 -pattern_type glob -i '/home/tijmen/gazebo_vids/temp_video/default_default_openni_camera_camera*.jpg' -c:v libx264 my_camera_video.mp4
```

### Augmented reality
In order to run the simulation with augmented reality you will have to follow the Iviz tutorial. The stl files of the Husarion Robot have been changed to .dae files in order to be able to see them in Unity. 



