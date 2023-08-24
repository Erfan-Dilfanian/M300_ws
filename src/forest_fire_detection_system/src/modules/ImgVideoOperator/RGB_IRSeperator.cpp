#include <glog/logging.h>
#include <modules/ImgVideoOperator/RGB_IRSeperator.hpp>
#include <dji_camera_image.hpp>

void show_rgb(CameraRGBImage img, char *name) {
    std::cout << "#### Got image from:\t" << std::string(name) << std::endl;
    cv::Mat mat(img.height, img.width, CV_8UC3, img.rawData.data(), img.width * 3);
    cvtColor(mat, mat, cv::COLOR_RGB2BGR);
    imshow(name, mat);
    cv::waitKey(1);
}

void mainCameraStreamCallBack(const sensor_msgs::Image &msg) {
    CameraRGBImage img;
    img.rawData = msg.data;
    img.height = msg.height;
    img.width = msg.width;
    char Name[] = "MAIN_CAM";
    show_rgb(img, Name);
    std::cout << "height is" << msg.height << std::endl;
    std::cout << "width is" << msg.width << std::endl;
}

FFDS::MODULES::RGB_IRSeperator::RGB_IRSeperator() {
//    image_transport::ImageTransport it(nh);
//    image_transport::Subscriber sub_color = it.subscribe("dji_osdk_ros/main_camera_images", 1,
//                                                         &RGB_IRSeperator::imageCallback, this);
    imgSub = nh.subscribe("dji_osdk_ros/main_camera_images", 1, &mainCameraStreamCallBack);
    imgIRPub = it.advertise("forest_fire_detection_system/main_camera_ir_image", 1);
    imgRGBPub = it.advertise("forest_fire_detection_system/main_camera_rgb_image", 1);
    resizeImgRGBPub = it.advertise("forest_fire_detection_system/main_camera_rgb_resize_image", 1);

    ros::Duration(2.0).sleep();
}

void FFDS::MODULES::RGB_IRSeperator::imageCallback(const sensor_msgs::Image::ConstPtr &img) {
    LOG(INFO) << "In imageCallback(0)";
    if (img->data.empty()) {
        LOG(WARNING) << "image data is empty!";
        return;
    } else {
        LOG(INFO) << img->data.size();
    }
    try {
        LOG(INFO) << "In imageCallback(1)";
//        rawImgPtr = cv_bridge::toCvCopy(img, "bgr8");
        rawImgPtr = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
        LOG(INFO) << "In imageCallback(2)";
        rawImg = rawImgPtr->image;
        LOG(INFO) << "In imageCallback(3)";
//        cv::imshow("camera/main/image_raw", rawImg);
//        cv::waitKey(1);
    }
    catch (cv_bridge::Exception &e) {
        LOG(ERROR) << e.what();
        ROS_ERROR("Could not convert from '%s' to 'rgb8'.", img->encoding.c_str());
    }
    LOG(INFO) << "Out imageCallback()";
}

void FFDS::MODULES::RGB_IRSeperator::run() {
    const std::string package_path =
            ros::package::getPath("forest_fire_detection_system");
    const std::string config_path = package_path + "/config/H20T_Camera.yaml";
    PRINT_INFO("get camera params from %s", config_path.c_str());
    YAML::Node node = YAML::LoadFile(config_path);

    int irImgWid = FFDS::TOOLS::getParam(node, "pure_IR_width", 960);
    int irImgHet = FFDS::TOOLS::getParam(node, "pure_IR_height", 770);

    int rgbImgWid = FFDS::TOOLS::getParam(node, "pure_RGB_width", 960);
    int rgbImgHet = FFDS::TOOLS::getParam(node, "pure_RGB_height", 770);

    int upperBound = FFDS::TOOLS::getParam(node, "upper_bound", 336);
    int lowerBound = FFDS::TOOLS::getParam(node, "lower_bound", 1106);

    int irUpLeft_x = 0;
    int irUpLeft_y = upperBound;

    int rgbUpLeft_x = irImgWid;
    int rgbUpLeft_y = upperBound;

    /**
     * FIXED: the hh DJI change the video size after press the "RECORD" from the
     * FIXED: remoter! YOU GOT BE KIDDING ME!                                                             Ciao: Really?
     * */

    while (ros::ok()) {
        ros::spinOnce();
        LOG(INFO) << "After ROS spinOnce()";
        if (rawImg.empty()) {
            LOG(WARNING) << "raw image is empty!";
            ros::Duration(0.1).sleep();
            continue;
        }

        LOG(INFO) << "Org mixed image shape: rows: " << rawImg.rows
                  << ", cols: " << rawImg.cols;
        LOG(INFO) << "ir image position: rows: " << irUpLeft_x
                  << ", cols: " << irUpLeft_y;
        LOG(INFO) << "ir image shape: rows: " << irImgWid
                  << ", cols: " << irImgHet;
        LOG(INFO) << "rgb image position: rows: " << rgbUpLeft_x
                  << ", cols: " << rgbUpLeft_y;
        LOG(INFO) << "rgb image shape: rows: " << rgbImgWid
                  << ", cols: " << rgbImgHet;

        cv::Mat irImg =
                rawImg(cv::Rect(irUpLeft_x, irUpLeft_y, irImgWid, irImgHet));

        cv::Mat rgbImg =
                rawImg(cv::Rect(rgbUpLeft_x, rgbUpLeft_y, rgbImgWid, rgbImgHet));

        cv::Mat resizeRgbImg;
        cv::resize(rgbImg, resizeRgbImg, cv::Size(resRGBWid, resRGBHet));

        sensor_msgs::ImagePtr irMsg =
                cv_bridge::CvImage(std_msgs::Header(), "bgr8", irImg).toImageMsg();
        sensor_msgs::ImagePtr rgbMsg =
                cv_bridge::CvImage(std_msgs::Header(), "bgr8", rgbImg).toImageMsg();
        sensor_msgs::ImagePtr reszieRgbMsg =
                cv_bridge::CvImage(std_msgs::Header(), "bgr8", resizeRgbImg)
                        .toImageMsg();

        irMsg->header.frame_id = "H20T_IR";
        irMsg->header.stamp = ros::Time::now();

        rgbMsg->header.frame_id = "H20T_RGB";
        rgbMsg->header.stamp = irMsg->header.stamp;

        reszieRgbMsg->header.frame_id = "H20T_RGB_RESIZE";
        reszieRgbMsg->header.stamp = irMsg->header.stamp;

        imgIRPub.publish(irMsg);
        imgRGBPub.publish(rgbMsg);
        resizeImgRGBPub.publish(reszieRgbMsg);

        ros::Rate(10).sleep();
    }
}
