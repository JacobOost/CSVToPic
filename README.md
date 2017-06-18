# CSVToPic
Converts .csv files into images (see companion program PicToCSV)
Created on 6/18/2017

 By: Jacob Oost (Jacob_Oost@baylor.edu or jacobobaggins@gmail.com)
 
 Requires: -the CImg library (included entirely in the CImg.h header file)
 
	   -X11 libraries (if using Linux)
     
	   -pthread libraries (if using Linux)
     
	   -ImageMagick (if using Linux)
     
	   -Check CImg web site (or compiler error messages) for any extra
     
	   Windows/Mac requirements, but I don't think there are any)
     
 Build command:    g++ -std=c++11 -lpthread -lX11 -o CSVToPic CSVToPic.cpp
 
 See the header comments for the PicToCSV program.  This program is the
 
 reverse of the first, it takes the .csv files and turns them back into pictures.
