## Introduction

The original package of the robot simulation is found here:  https://github.com/biorobotics/snake_ws.git

## Installation
It was originally designed for ROS Kinetic, but i tested it on ROS Indigo and it works as it depends on common ros packages. 
You may need to install these packages in case you do not already have them on your machine. For instance: 

Gazebo Effort Controllers:
```
$ sudo apt-get install ros-indigo-effort-controllers
```
and the controller_manager , etc 

I developed two nodes. One is supposed for cpg implementation and the second is for mapping the angle commands to joint comamnds that the robot joints can understand and should subscribe to the cpg node.
Both can be found ~/snake_ws/src/snake_monster_control/src
1- cpg.cpp
2- walking_ctrl.cpp

## how to run basic tests
```sh
$ cd snake_ws
$ source devel/setup.bash
$ roslaunch snake_monster_control gaz_control.launch
```

In another terminal to visualise the joints commands. This node is simply printing the names of the joints topics ready for commands from cpg (if it was having an output). 

```sh
$ rosrun snake_monster_control walking_ctrl
```

## results
I tested the first node, with fake angle for example on leg 1 joint 2 ( intermediate joint). The output is as follows 

[image of the joint output in Gazebo](https://bitbucket.org/marknabil/cpg_submit/src/master/images_output/output_joints.png)



