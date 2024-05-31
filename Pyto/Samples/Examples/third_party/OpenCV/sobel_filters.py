"""
An example of using convolution filters with OpenCV.
"""

import cv2
import sys


device = 1 # Front camera
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
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    sobelX = cv2.Sobel(gray, cv2.CV_16S, 1, 0)
    sobelY = cv2.Sobel(gray, cv2.CV_16S, 0, 1)
    sobel=abs(sobelX)+abs(sobelY)
    sobmin = 0
    sobmax=0
    sobmin, sobmax, min_loc, mac_loc = cv2.minMaxLoc(sobel)
    frame =  cv2.convertScaleAbs(sobel, alpha=255.0/(sobmax - sobmin), beta=0)
    frame = cv2.bitwise_not(frame)  # invert
    # Display the resulting frame
    cv2.imshow('frame', frame)
