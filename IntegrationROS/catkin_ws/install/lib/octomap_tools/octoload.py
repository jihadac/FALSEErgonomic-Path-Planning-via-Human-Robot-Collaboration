#! /usr/bin/env python

import rospy
from octomap_msgs.msg import Octomap
from moveit_msgs.msg import PlanningScene, PlanningSceneWorld
import sys

class OctoHandler():
    mapMsg = None

    def __init__(self):
        rospy.init_node('moveit_octomap_handler')
        rospy.Subscriber('octomap_full', Octomap, self.cb, queue_size=1)
        pub = rospy.Publisher('move_group/monitored_planning_scene', PlanningScene, queue_size=1)
        pub2 = rospy.Publisher('/planning_scene', PlanningScene, queue_size=1)
        r = rospy.Rate(0.25)
        while(not rospy.is_shutdown()):
            if(self.mapMsg is not None):
                pub.publish(self.mapMsg)
                pub2.publish(self.mapMsg)
            else:
                pass
            r.sleep()

    def cb(self, msg):
        psw = PlanningSceneWorld()
        psw.octomap.header.stamp = rospy.Time.now()
        psw.octomap.header.frame_id = 'map_octomap'
        psw.octomap.octomap = msg

        '''psw.octomap.origin.position.x =1.3
        psw.octomap.origin.position.y =0.06
        psw.octomap.origin.position.z =0.38
        psw.octomap.origin.orientation.x = 0
        psw.octomap.origin.orientation.y = 0
        psw.octomap.origin.orientation.z = 1
        psw.octomap.origin.orientation.w = 0'''

        ps = PlanningScene()
        ps.world = psw
        ps.is_diff = True
        self.mapMsg = ps

if __name__ == '__main__':
    octomap_object = OctoHandler()
