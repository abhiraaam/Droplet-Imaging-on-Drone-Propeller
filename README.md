# Droplet-Imaging-on-Drone-Propeller

This experiment is to study the effect of droplets on the drone propeller. Later on, we intend to do image segmentation and edge detection using Python. 

It is powered using an Arduino UNO R3, along with a L293D IC for the Arduino, DSLR Camera using a prime lens, and octocoupler for detecting the droplets. 

    1) The file alignment_check.ino is used to conduct a test for the experimental setup.
    2) The file propeller_control.ino was merged into setup_control.ino so that by the time the DC Motor completes one rotation, the probability of impacting the            propeller becomes high. It can be adjusted by varying th time delay in the code. 
