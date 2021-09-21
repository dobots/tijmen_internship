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


