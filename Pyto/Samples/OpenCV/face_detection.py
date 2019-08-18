"""
An example of face detection using OpenCV.

(!) Real time camera is displayed on the console whith a green square around faces. As the video is displayed on the console and not on a window, the code is a bit different on Pyto than code on computers.

(!) Face detection is orientation sensitive, so put your device in portrait mode to make this script work better.
"""

import cv2

casc_path = cv2.data.haarcascades+"haarcascade_frontalface_default.xml"
face_cascade = cv2.CascadeClassifier(casc_path)

cap = cv2.VideoCapture(1)

while cap.isOpened():
  # Capture frame-by-frame
  ret, frame = cap.read()
  
  # Needed as `read` may return an invalid value the first time on Pyto
  if not ret:
    continue

  # Convert from BGR to RGB
  frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

  faces = face_cascade.detectMultiScale(
    frame,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30),
    flags=cv2.CASCADE_SCALE_IMAGE
  )

  # Draw a rectangle around the faces
  for (x, y, w, h) in faces:
    cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

  # Display the resulting frame
  cv2.imshow('frame', frame)
