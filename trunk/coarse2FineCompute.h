#pragma once


#include "highgui.h" 
#include "cv.h"
#include "GaussPyramid.h"
#include "toolsKit.h"
#include "flowUV.h"
#include "IplImageIterator.h"
#include "constructMatrix_brox.h"

class coarse2FineCompute
{
public:
	double _ERROR_CONST;
	int _imageDepth;
	coarse2FineCompute(int imageDepth,double error);
	void Coarse2FineFlow(IplImage* vx, 
						 IplImage* vy, 
						 const IplImage &Im1, 
						 const IplImage &Im2, 
						 double alpha,
						 double gamma,
						 double ratio, 
						 int minWidth,
						 int nOuterFPIterations, 
						 int nInnerFPIterations);
						
	virtual ~coarse2FineCompute(void);
private:
	

	IplImage* LaplaceCompute(IplImage* input,IplImage* input2);
	IplImage* coarse2FineCompute::createWarp(IplImage*WarpImage2,IplImage* img1,IplImage* img2,IplImage* vx,IplImage* vy);
	
	void coarse2FineCompute::constructMatrix_brox(IplImage* Ikx,IplImage* Iky,IplImage* Ikz,IplImage* Ixx,IplImage* Ixy,IplImage* Iyy,IplImage* Ixz,
												  IplImage* Iyz,IplImage* psidash,IplImage* psidashFS1,IplImage* psidashFS2,IplImage*  u,IplImage*  v,double gamma,int nInnerFPIterations );
	flowUV* SmoothFlowPDE( IplImage* Im1, 
						   IplImage* Im2, 
						   IplImage* warpIm2, 
						   IplImage* du, 
						   IplImage* dv, 
						   double alpha,
						   double gamma,
						   int nOuterFPIterations, 
						   int nInnerFPIterations);
	void computePsidashFS_brox(IplImage* iterU,IplImage* iterV,int width,int height,int channels,flowUV* UV);

};
