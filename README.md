# tijmen_internship
# README Tijmen internship
hi,
This readme will tell you more about how to run my visualization project for the Husarion robot @ dobots.
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

## Changes wrt original os code.
### both environments
First of all there are the 5 params.yaml files in the tutorial_pkg/config folder. They mostly contain default values for the husarion robot, but some values are altered to let the robot drive closer to obstacles for example. 
In the rplidar_ros pkg nothing is changed. 
In the rosbot_ekf pkg nothing is changed. (this is maybe not true, need to check this)

### real environment
In rosbot_description/src/rosbot_gazebo/launch there is a launch file husarion_real.launch that launches all the necessary files to run the robot in the real environment. Here, there is also an added frame for the camere_broadcoaster to get the camera in the right position to be able to view it under the camera topic in rviz. This frame might not be exactly accurate, and is done purely on a guess so that it looked sort of at the right place. If any problems occur with an exact placement of the camera image this might be a good place to start problemsolving. 
In rosbot_description/src/rosbot_gazebo/rviz there is a maze_real.rviz file that will make sure all the necessary displays are there for the visualisation.
### simulated environment
In rosbot_description/src/rosbot_description/urdf/rosbot.gazebo the visualize parameter for the laserscanner is set to true to be able to see it in gazebo.
In rosbot_description/src/rosbot_gazebo/launch there is a launch file husarion_simulation.launch that launches all the necessary files to run the robot in the simulated environment.
In rosbot_description/src/rosbot_gazebo/rviz there is a maze_simulation.rviz file that will make sure all the necessary displays are there for the visualisation.
