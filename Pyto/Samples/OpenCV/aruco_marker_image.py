"""
An example of using ArUco markers with OpenCV.
"""

import cv2
import sys
import cv2.aruco as aruco
import numpy as np
from skimage.data import astronaut

device = 0 # Front camera
try:
    device = int(sys.argv[1]) # 0 for back camera
except IndexError:
    pass


cap = cv2.VideoCapture(device)

while cap.isOpened():

    # Capture frame-by-frame
    ret, frame = cap.read()

    # Check if frame is not empty
    if not ret:
        continue

    # Auto rotate camera
    frame = cv2.autorotate(frame, device)

    # Convert from BGR to RGB
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    
    aruco_dict = aruco.Dictionary_get(aruco.DICT_6X6_250)
    parameters = aruco.DetectorParameters_create()
    corners, ids, _ = aruco.detectMarkers(frame, aruco_dict, parameters=parameters)
    if np.all(ids != None):
        x1 = (corners[0][0][0][0], corners[0][0][0][1]) 
        x2 = (corners[0][0][1][0], corners[0][0][1][1]) 
        x3 = (corners[0][0][2][0], corners[0][0][2][1]) 
        x4 = (corners[0][0][3][0], corners[0][0][3][1])  
        im_dst = frame
        im_src = astronaut()
        size = im_src.shape
        pts_dst = np.array([x1, x2, x3, x4])
        pts_src = np.array(
                       [
                        [0,0],
                        [size[1] - 1, 0],
                        [size[1] - 1, size[0] -1],
                        [0, size[0] - 1 ]
                        ],dtype=float
                       );
        h, status = cv2.findHomography(pts_src, pts_dst)
        temp = cv2.warpPerspective(im_src, h, (im_dst.shape[1], im_dst.shape[0])) 
        cv2.fillConvexPoly(im_dst, pts_dst.astype(int), 0, 16);
        frame = im_dst + temp
    
    # Display the resulting frame
    cv2.imshow('frame', frame)
