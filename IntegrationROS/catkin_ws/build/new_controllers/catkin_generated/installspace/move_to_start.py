#!/usr/bin/env python2

import rospy
from moveit_commander import MoveGroupCommander
from actionlib_msgs.msg import GoalStatusArray

if __name__ == '__main__':
    rospy.init_node('move_to_start')
    rospy.wait_for_message('move_group/status', GoalStatusArray)
    commander = MoveGroupCommander('panda_arm')
    commander.set_named_target('ready')
    commander.go()
    '''rospy.sleep(5)
    r = commander.get_current_joint_values()
    r[0] = -0.5
    commander.set_joint_value_target(r)
    # commander.plan()
    commander.go(wait = True)'''
