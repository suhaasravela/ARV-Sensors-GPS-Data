This code will look through a ROS standard GPS formatted output and take only Longitude and Latitude Coordinates

The only thing the user needs to do is run the command line. To get the desired output files, make sure that
you know what files you want to parse through. Type the exact name of the file into the command line. If
you have multiple files, make sure to separate the files by a space. 

DO NOT FORGET TO INCLUDE .txt	AT THE END OF THE FILE NAME ON THE COMMAND LINE!!!!!

Here is an example:

./gps.exe gps_out_square.txt gps_out_stationary.txt gps_out_straight_line_217inches.txt