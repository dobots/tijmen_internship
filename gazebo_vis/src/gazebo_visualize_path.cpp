#include <ros/ros.h>
#include <ignition/transport.hh>
#include <ignition/math.hh>
#include <ignition/msgs.hh>
#include <gazebo/common/Time.hh>
#include <nav_msgs/Path.h>
#include <iostream>
#include <std_msgs/String.h>

ignition::transport::Node node;
void pathCallback(const nav_msgs::Path::ConstPtr& msg){
  ignition::msgs::Marker markerMsg;
  markerMsg.set_action(ignition::msgs::Marker::DELETE_ALL);
  node.Request("/marker", markerMsg);

  ignition::msgs::Material *matMsg = markerMsg.mutable_material();
  matMsg->mutable_script()->set_name("Gazebo/Green");
  
  ///// TRIANGLES /////////////
  markerMsg.set_id(0);
  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
  markerMsg.set_type(ignition::msgs::Marker::TRIANGLE_LIST);
  
  for (int i=0; i < msg->poses.size(); i++){  
  markerMsg.set_id(0);
  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
  markerMsg.set_type(ignition::msgs::Marker::TRIANGLE_LIST);
  markerMsg.clear_point();
  ignition::msgs::Set(markerMsg.mutable_pose(), ignition::math::Pose3d(msg->poses[i].pose.position.x, msg->poses[i].pose.position.y, 0.11,msg->poses[i].pose.orientation.w,  msg->poses[i].pose.orientation.x, msg->poses[i].pose.orientation.y, msg->poses[i].pose.orientation.z));
  
  ignition::msgs::Set(markerMsg.add_point(),
        ignition::math::Vector3d(0.1,0, 0));
  ignition::msgs::Set(markerMsg.add_point(),
      ignition::math::Vector3d(0, 0.02, 0));
  ignition::msgs::Set(markerMsg.add_point(),
      ignition::math::Vector3d(0, -0.02, 0));
  node.Request("/marker", markerMsg);  
                 
 }

}


int main(int argc, char **argv)
{


  std::cout << "Plotting line\n";

  ros::init(argc, argv, "gazebo_visualize_path");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/move_base/TebLocalPlannerROS/local_plan", 1, pathCallback);
 
  
  ros::spin();
  
  return 0;
}
