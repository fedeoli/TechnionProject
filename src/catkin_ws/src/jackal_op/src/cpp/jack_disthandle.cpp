// node handling a single tag and doing the trilateration
#include "MelodicAPI.h"

// dummy calback just for test
void DummyCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("ARARMAX");
}

/**
 * Node used to get distance measurements from UWB plugin and divide them into the related anchors and tags
 */
int main(int argc, char **argv)
{
    /**
     * ros::init() the node
     */
    ros::init(argc, argv, "jack_disthandle");

    /**
     * define nodehandle instance (general purpose)
     */
    ros::NodeHandle np;

    // general stuff
    int cnt = 0;
    int rate = 5;

    /**
     * define topic to subscribe to. Get the topics name from params server. Then create handle for subscribing.
     */
    std::string subNameT, subNameA, pubNameT, pubNameTril, jackName, pubNameTrilodom;
    int Nanchors, tagID, GradientFlag;    

    // get tagID - default 7
    if (argc > 1){
        std::string value_from_cl = argv[1];
        tagID = atoi(value_from_cl.c_str());
    }
    else{
        tagID = 7;
    }

    // check params
    std::string tmp;
    std::vector<bool> flags;
    tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_subT";
    flags.push_back(np.hasParam(tmp));
    tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_pubDist";
    flags.push_back(np.hasParam(tmp));
    tmp = "/DT" + std::to_string(tagID) + "/jackAPIName";
    flags.push_back(np.hasParam(tmp));
    tmp = "/DT" + std::to_string(tagID) + "/NanchorMesh";
    flags.push_back(np.hasParam(tmp));
    tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_subA";
    flags.push_back(np.hasParam(tmp));
    tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_pubGrad";
    flags.push_back(np.hasParam(tmp));

    // init rate for the node
    tmp = "/DT" + std::to_string(tagID) + "/UWBrate";
    if (np.hasParam(tmp)){
        np.getParam(tmp, rate);
    }
    ros::Rate loop_rate(rate);

    // read distances from UWB and simplify them (publish on /disthandle_pub)
    if (std::all_of(std::begin(flags), std::end(flags),[](bool b){return b;})) {

        // params found
        ROS_INFO("Params found");

        // get topics and init data
        std::string tmp;
        std::vector<bool> flags;
        tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_subT";
        np.getParam(tmp, subNameT);  
        tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_pubDist";
        np.getParam(tmp, pubNameT);  
        tmp = "/DT" + std::to_string(tagID) + "/jackAPIName";
        np.getParam(tmp, jackName);  
        tmp = "/DT" + std::to_string(tagID) + "/NanchorMesh";
        np.getParam(tmp, Nanchors);  
        tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_subA";
        np.getParam(tmp, subNameA);  
        tmp = "/DT" + std::to_string(tagID) + "/jack_disthandle_pubGrad";
        np.getParam(tmp, pubNameTril);  
        
        // concatenate string - odom
        pubNameTrilodom = pubNameTril + "Odom";

        // instance of a class
        jackAPI jackNode = jackAPI(jackName, Nanchors, tagID);
        ROS_INFO("jackAPI - Class instance created");

        // set gradient flag if param is present
        tmp = "/DT" + std::to_string(tagID) + "/GradientFlag";
        if (np.hasParam(tmp)){
            np.getParam(tmp, GradientFlag);
            jackNode._GradientFlag = GradientFlag;
        }

        // subscribe
        jackNode._jack_disthandle_ST = np.subscribe(subNameT, 1000, &jackAPI::ChatterCallbackT, &jackNode);
        jackNode._jack_disthandle_SA = np.subscribe(subNameA, 1000, &jackAPI::ChatterCallbackA, &jackNode);

        ROS_INFO("Subscriptions done");

        // publisher
        jackNode._jack_disthandle_P = np.advertise<jackal_op::MeshUWB>(pubNameT, 1000);
        jackNode._jack_trilateration_P = np.advertise<jackal_op::GradientDescent>(pubNameTril, 1000);
        jackNode._jack_odometry_P = np.advertise<nav_msgs::Odometry>(pubNameTrilodom, 1000);    
        ROS_INFO("Publishers initialized");

        // spin
        ROS_INFO("Spinning");

        // spin with loop rate
        while (ros::ok()) {
            ros::spinOnce();
            loop_rate.sleep();
            ++cnt;
        }

    }
    else {

        // throw error
        ROS_ERROR("Params not found for jackal_op - jack_disthandle - get UWB");
        return -1;
    }
}