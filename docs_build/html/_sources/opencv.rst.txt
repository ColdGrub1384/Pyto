OpenCV
======

Pyto includes OpenCV. However, video output does not work the exact same way that on computers. Frames are displayed on the console and no other window is presented. So ``cv2.destroyAllWindows`` and ``cv2.waitKey`` will throw errors.

Pyto specific API
-----------------

.. currentmodule:: cv2

.. autofunction:: autorotate

Face detection example
----------------------

.. highlight:: python
.. code-block:: python
    
    """
    An example of face detection using OpenCV.
    """

    import cv2
    import sys

    casc_path = cv2.data.haarcascades+"haarcascade_frontalface_default.xml"
    face_cascade = cv2.CascadeClassifier(casc_path)

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
