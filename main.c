/* 	
 *  	Starting off: 
 *  	1. Load an image and copy it to another location 
 *  	2. Load an image, convert to gray scale and copy to another location 
 *
 *  	@ 	Nidhi Gupta 
 */

# include "cv.h" 
# include "highgui.h" 
# include <stdio.h> 

#define CV_IMWRITE_JPEG_QUALITY 1 
#define CV_IMWRITE_PNG_COMPRESSION 16 
#define CV_IMWRITE_PXM_BINARY 32 


void runF() 
{ 
	IplImage * image=NULL, *smallerImage=NULL; 
	int sizes[3] ; // to obtain the size of the image
	int compressionFactor[3]; 
	int i;
	
	image = cvLoadImage("dots.png", 1); 
	
	int dims = cvGetDims(image, sizes); 
	for(i=0; i<dims; i++) 
	{ 
		sizes[i] = dims; 
	} 

	smallerImage = cvCreateImage(cvGetSize(image), 8, 1); 
	
	cvCvtColor(image, smallerImage, CV_RGB2GRAY); 

	compressionFactor[0] = CV_IMWRITE_JPEG_QUALITY; 
	compressionFactor[1] = 10; 
	compressionFactor[2] = 0; 

	if(cvSaveImage("smaller.jpg", smallerImage, compressionFactor)) 
	{
		printf("Unable to write image"); 
	}

	cvReleaseImage(&image); 
	cvReleaseImage(&smallerImage); 

}

void main() 

{ 

	runF(); 

} 
