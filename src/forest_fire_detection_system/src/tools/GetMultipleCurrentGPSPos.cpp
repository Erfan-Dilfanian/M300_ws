/*******************************************************************************
 *   Copyright (C) 2022 Concordia NAVlab. All rights reserved.
 *
 *   @Filename: GetCurrentGPSPos.cpp
 *
 *   @Author: Shun Li
 *
 *   @Email: 2015097272@qq.com
 *
 *   @Date: 2022-01-13
 *
 *   @Description:
 *
 *******************************************************************************/

#include <sensor_msgs/NavSatFix.h>
#include <tools/PositionHelper.hpp>
#include <tools/PrintControl/FileWritter.hpp>
#include <tools/SystemLib.hpp>
#include <iostream>
#include <yaml-cpp/yaml.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "get_multiple_current_gps_pos_node");
    int average_times = 10;
    FFDS::TOOLS::PositionHelper posHelper;

    YAML::Node yaml_nodes;
    int point_id = 1;

    char user_input;
    do {
        sensor_msgs::NavSatFix gps = posHelper.getAverageGPS(average_times);
        PRINT_INFO(
                "current GPS position under %d average times is lon: %.9f, lat: %.9f, alt: %.9f",
                average_times, gps.longitude, gps.latitude, gps.altitude);

        YAML::Node new_node;
        new_node["id"] = point_id++;
        new_node["x"] = gps.latitude;
        new_node["y"] = gps.longitude;
        new_node["z"] = gps.altitude;

        yaml_nodes.push_back(new_node);

        std::cout << "Move the drone and type 'y' to get new GPS position or any other key to exit: ";
        std::cin >> user_input;
        /*
        if (user_input == 'y' || user_input == 'Y') {
            continue;
        }
         */

    } while (user_input == 'y' || user_input == 'Y');

    // Write the YAML nodes to a file
    std::ofstream fout("gps_positions.yaml");
    fout << yaml_nodes;
    fout.close();


    return 0;
}
