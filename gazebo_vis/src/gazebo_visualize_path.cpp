#include <ros/ros.h>
#include <ignition/transport.hh>
#include <ignition/math.hh>
#include <ignition/msgs.hh>
#include <gazebo/common/Time.hh>
#include <nav_msgs/Path.h>
#include <iostream>
#include <std_msgs/String.h>

ignition::transport::Node node;
//ignition::msgs::Marker markerMsg;
//gPlan = nav_msgs::Path(msg);
void pathCallback(const nav_msgs::Path::ConstPtr& msg){
  ignition::msgs::Marker markerMsg;
  //markerMsg.set_ns("default");
  //markerMsg.set_id(1);
  markerMsg.set_action(ignition::msgs::Marker::DELETE_ALL);
  node.Request("/marker", markerMsg);
  //gazebo::common::Time::Sleep(0.5);
//void pathCallback(const std_msgs::String::ConstPtr& msg)

 //ROS_INFO("Blablabla");
 //ROS_INFO("I heard: [%s]", msg->header.frame_id.c_str());
  //ROS_INFO("%f", msg->poses[0].pose.position.x);
  //ROS_INFO("%i", msg->poses.size());
  //float x_begin = msg->poses[0].pose.position.x;
  //float y_begin = msg->poses[0].pose.position.y;
  //float z_begin = msg->poses[0].pose.position.z;
  //float x_end = msg->poses[-1].pose.position.x;
  //float y_end = msg->poses[-1].pose.position.y;
  //float z_end = msg->poses[-1].pose.position.z;
  //ignition::msgs::Set(markerMsg.mutable_pose(),ignition::math::Pose3d(x_begin, y_begin, z_begin, 0, 0, 0));
  
  //ignition::msgs::Set(markerMsg.mutable_point(0), ignition::math::Vector3d(x_begin, y_begin, z_begin));
  //ignition::msgs::Set(markerMsg.mutable_point(1), ignition::math::Vector3d(x_end, y_end, z_end));
  
  //ignition::msgs::Set(markerMsg.mutable_point(0), ignition::math::Vector3d(msg->poses[0].pose.position.x, msg->poses[0].pose.position.y, 0.11));
  //ignition::msgs::Set(markerMsg.mutable_point(1), ignition::math::Vector3d(msg->poses.back().pose.position.x, msg->poses.back().pose.position.y, 0.11));
  //node.Request("/marker", markerMsg);
  //ros::Duration(1).sleep();
  
  ///////////////////////LINE///////////////////////////
//  markerMsg.set_ns("default");
//  markerMsg.set_id(0);
//  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
//  markerMsg.set_type(ignition::msgs::Marker::LINE_STRIP);
//  for (int i=0; i < msg->poses.size(); i++){
//    ignition::msgs::Set(markerMsg.add_point(), ignition::math::Vector3d(msg->poses[i].pose.position.x, msg->poses[i].pose.position.y, 0.11));
//  }
  ignition::msgs::Material *matMsg = markerMsg.mutable_material();
  matMsg->mutable_script()->set_name("Gazebo/Green");
  
  //ignition::msgs::Set(markerMsg.mutable_scale(), ignition::math::Vector3d(3, 1, 1));
  //ignition::msgs::Set(markerMsg.mutable_scale(), ignition::math::Vector3d(2);
  //markerMsg.set_allocated_scale(ignition::msgs::Vector3d(3, 1, 1));
  //ignition::msgs::Set(markerMsg.point_size(2));                  
//  node.Request("/marker", markerMsg);
  
  ///////////////////////////////////////////////////////////
  
  //gazebo::common::Time::Sleep(0.5);
  //markerMsg.set_action(ignition::msgs::Marker::DELETE_ALL);
  //node.Request("/marker", markerMsg);
  
  ///// TRIANGLES /////////////
  markerMsg.set_id(0);
  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
  markerMsg.set_type(ignition::msgs::Marker::TRIANGLE_LIST);
  //markerMsg.clear_point();
  
  //ignition::msgs::Set(markerMsg.mutable_pose(), ignition::math::Pose3d(msg->poses[0].pose.position.x, msg->poses[0].pose.position.y, 0.11,msg->poses[0].pose.orientation.w,  msg->poses[0].pose.orientation.x, msg->poses[0].pose.orientation.y, msg->poses[0].pose.orientation.z));
      
  //for (int i=0; i < msg->poses.size(); i++){  
  
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
                 
//  ignition::msgs::Set(markerMsg.add_point(),
 //       ignition::math::Vector3d(msg->poses[i].pose.position.x, msg->poses[i].pose.position.y, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(),
 //     ignition::math::Vector3d(msg->poses[i].pose.position.x-0.1, msg->poses[i].pose.position.y+0.02, 0.11));
 // ignition::msgs::Set(markerMsg.add_point(),
 //     ignition::math::Vector3d(msg->poses[i].pose.position.x-0.1, msg->poses[i].pose.position.y-0.02, 0.11));
//  node.Request("/marker", markerMsg);
 }
  //node.Request("/marker", markerMsg);
}





int main(int argc, char **argv)
{
//  ignition::transport::Node node;

  // Create the marker message
//  ignition::msgs::Marker markerMsg;
//  markerMsg.set_ns("default");
  // 0 has a special meaning of representing an id which hasn't been set
  // Thus, when 0 is given as an argument to set_id, it generates a random (but unique) id,
  // and sets the marker's id value to that randomly generated id.
  // A new marker is created at every invocation of set_id(0).
  
//  markerMsg.set_id(1);
// markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
//  markerMsg.set_type(ignition::msgs::Marker::SPHERE);

  // ignition::msgs::Material *matMsg = markerMsg.mutable_material();
  // matMsg->mutable_script()->set_name("Gazebo/BlueLaser");

  // The rest of this function adds different shapes and/or modifies shapes.
  // Read the terminal statements to figure out what each node.Request
  // call accomplishes.

//  std::cout << "Spawning a sphere at the origin\n";
// gazebo::common::Time::Sleep(4);
//  node.Request("/marker", markerMsg);
  
//  std::cout << "Adding a square around the origin\n";
//  gazebo::common::Time::Sleep(4);
  
//  markerMsg.set_id(4);
//  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
// markerMsg.set_type(ignition::msgs::Marker::LINE_STRIP);
  
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(0.5, 0.5, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(0.5, -0.5, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(-0.5, -0.5, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(-0.5, 0.5, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(0.5, 0.5, 0.11));
//  node.Request("/marker", markerMsg);
  
//  std::cout << "Big square in 3 sec\n";
//  gazebo::common::Time::Sleep(1);
//  std::cout << "Big square in 2 sec\n";
//  gazebo::common::Time::Sleep(1);
//  std::cout << "Big square in 1 sec\n";
//  gazebo::common::Time::Sleep(1);
//  markerMsg.set_id(4);
//  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
//  markerMsg.set_type(ignition::msgs::Marker::LINE_STRIP);
  
//  ignition::msgs::Set(markerMsg.mutable_point(0),
//      ignition::math::Vector3d(1, 1, 0.11));
//  ignition::msgs::Set(markerMsg.mutable_point(1),
//      ignition::math::Vector3d(1, -1, 0.11));
//  ignition::msgs::Set(markerMsg.mutable_point(2),
//      ignition::math::Vector3d(-1, -1, 0.11));
//  ignition::msgs::Set(markerMsg.mutable_point(3),
//      ignition::math::Vector3d(-1, 1, 0.11));
//  ignition::msgs::Set(markerMsg.mutable_point(4),
//      ignition::math::Vector3d(1, 1, 0.11));
//  node.Request("/marker", markerMsg);
///////////////////////////////////////////////////
  //ignition::transport::Node node;
  //ignition::msgs::Marker markerMsg;
//  markerMsg.set_ns("default");
  
//  markerMsg.set_id(0);
//  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
  //markerMsg.set_type(ignition::msgs::Marker::SPHERE);
//  markerMsg.set_type(ignition::msgs::Marker::LINE_STRIP);
  
//  ignition::msgs::Set(markerMsg.add_point(), ignition::math::Vector3d(0.5, 0.5, 0.11));
//  ignition::msgs::Set(markerMsg.add_point(), ignition::math::Vector3d(0.5, -0.5, 0.11));

  std::cout << "Plotting line\n";
  //gazebo::common::Time::Sleep(4);
//  node.Request("/marker", markerMsg);
  
  //gazebo::common::Time::Sleep(4);
  //std::cout << "Deleting line\n";  
  //markerMsg.set_action(ignition::msgs::Marker::DELETE_ALL);
  //node.Request("/marker", markerMsg);
  
  //////////////////////////////////////////////////////////////////////// marker.cc example
//  ignition::msgs::Marker markerMsg;
//  std::cout << "Adding two triangles using a triangle list\n";
  //gazebo::common::Time::Sleep(4);
//  markerMsg.set_id(8);
//  markerMsg.set_action(ignition::msgs::Marker::ADD_MODIFY);
//  markerMsg.set_type(ignition::msgs::Marker::TRIANGLE_LIST);
//  markerMsg.clear_point();
//  ignition::msgs::Set(markerMsg.mutable_pose(),
//                    ignition::math::Pose3d(0, -1.5, 0, 0, 0, -1.57));
//  ignition::msgs::Set(markerMsg.add_point(),
//        ignition::math::Vector3d(0, 0, 0.05));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(1, 0, 0.05));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(1, 1, 0.05));

//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(1, 1, 0.05));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(2, 1, 0.05));
//  ignition::msgs::Set(markerMsg.add_point(),
//      ignition::math::Vector3d(3, 2, 0.05));

//  node.Request("/marker", markerMsg);
  
  
  
  ////////////////////////////////////////////////////////////////////////
  ros::init(argc, argv, "gazebo_visualize_path");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/move_base/TebLocalPlannerROS/local_plan", 1, pathCallback);
 
  
  ros::spin();
  
  return 0;
}
