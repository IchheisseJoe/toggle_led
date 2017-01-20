#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <iostream>
//#include <boost/concept_check.hpp>
#include <toggle_led/getch.h>

using namespace std;

int main(int argc, char* argv[])
{
	ros::init(argc, argv, "toggle_led");
	ros::NodeHandle nh;
	ros::Publisher Pub=nh.advertise<std_msgs::Empty>("toggle_led", 64);
	std_msgs::Empty empty;
	int ch;
	do
	{
		ch=getch(); //getchar();
		printf("\033[A\033[C\n");
		Pub.publish(empty);
		ros::spinOnce();
		
	} while (ch != 'q');
	return 0;
}




