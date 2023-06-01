#! /usr/bin/env python

# rospy for the subscriber
import rospy
# ROS Image message
from sensor_msgs.msg import Image
# ROS Image message -> OpenCV2 image converter
from cv_bridge import CvBridge, CvBridgeError
# OpenCV2 for saving an image
import cv2

left = False
right = False
bridge = CvBridge()
def image_callback1(msg):
    global right
    if right:
        return
    print("Received an image!")
    try:
        # Convert your ROS Image message to OpenCV2
        cv2_img = bridge.imgmsg_to_cv2(msg, "bgr8")
    except CvBridgeError, e:
        print(e)
    else:
        # Save your OpenCV2 image as a jpeg 
        time = msg.header.stamp
        cv2.imwrite('right'+str(time)+'.jpeg', cv2_img)
        right = True
        #rospy.sleep(1)

def image_callback2(msg):
    global left
    if left:
        return
    print("Received an image!")
    try:
        # Convert your ROS Image message to OpenCV2
        cv2_img = bridge.imgmsg_to_cv2(msg, "bgr8")
    except CvBridgeError, e:
        print(e)
    else:
        # Save your OpenCV2 image as a jpeg 
        time = msg.header.stamp
        cv2.imwrite('left'+str(time)+'.jpeg', cv2_img)
        left = True
        #rospy.sleep(1)

def main():
    global left, right
    rospy.init_node('save_cloud')
    # Define your image topic
    image_topic1 = "/zed2/zed_node/right_raw/image_raw_color"
    image_topic2 = "/zed2/zed_node/left_raw/image_raw_color"
    # Set up your subscriber and define its callback
    rospy.Subscriber(image_topic1, Image, image_callback1)
    rospy.Subscriber(image_topic2, Image, image_callback2)

    while(not(left) and not(right)):
        rospy.sleep(0.1)

if __name__ == '__main__':
    main()