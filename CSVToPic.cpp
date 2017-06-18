/*
 CSVToPic.cpp
 Created on 6/18/2017
 By: Jacob Oost (Jacob_Oost@baylor.edu or jacobobaggins@gmail.com)
 Requires: -the CImg library (included entirely in the CImg.h header file)
	   -X11 libraries (if using Linux)
	   -pthread libraries (if using Linux)
	   -ImageMagick (if using Linux)
	   -Check CImg web site (or compiler error messages) for any extra
	   Windows/Mac requirements, but I don't think there are any)
 Build command:    g++ -std=c++11 -lpthread -lX11 -o PicToCSV PicToCSV.cpp
 
 See the header comments for the PicToCSV program.  This program is the
 reverse of the first, it takes the .csv files and turns them back into pictures.
 */

#include "CImg.h"
#include <iostream>
#include <string>
#include <fstream>

#define RED_CHANNEL 0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL 2

using namespace cimg_library;

using pixtype=unsigned char;

int main()
{
  int width(0),height(0); // stores image height and width
  char comma;
  std::string filename;
  int r, g, b;
  
  /* Next we get the filename, open the file, then read its height and width. */
  std::cout<<"Hi there!  Please enter the name of the .csv image file (must be included in current directory): ";
  std::cin>>filename;
  
  std::ifstream inFile(filename);
  
  inFile>>width>>comma>>height;
  
  std::cout<<"What would you like to call the output image file (end in .jpg, .bmp, or other image file type)\n";
  std::cin>>filename;
  
  CImg<pixtype> image(width,height,1,3,0);
  
  
  for(int i=0;i<height;i++)
  {
    for(int j=0;j<width;j++)
    {
      inFile>>r>>comma>>g>>comma>>b;
      image(j,i,RED_CHANNEL)=(pixtype)r;
      image(j,i,GREEN_CHANNEL)=(pixtype)g;
      image(j,i,BLUE_CHANNEL)=(pixtype)b;
    }
  }
  
  inFile.close();
  
  image.save(filename.c_str(),-1,0);
  
  std::cout<<"Bye!"<<std::endl;
  
  return 0;
}