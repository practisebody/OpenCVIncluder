#pragma once

#pragma warning(disable:4819)
#pragma warning(disable:4996)

#include <opencv2/opencv_modules.hpp>
#include <opencv2/opencv.hpp>

#if CV_VERSION_MAJOR < 3
#error Opencv 3.0 needed
#endif

// contrib
#ifdef HAVE_OPENCV_XFEATURES2D
#include <opencv2/xfeatures2d.hpp>
#endif
#ifdef HAVE_OPENCV_XIMGPROC
#include <opencv2/ximgproc.hpp>
#endif

#define STRINGIFY(X) #X
#define TOSTRING(X) STRINGIFY(X)
#ifdef _DEBUG
#define MODULE(X) "opencv_" #X TOSTRING(CV_VERSION_MAJOR) TOSTRING(CV_VERSION_MINOR) "0d.lib"
#else
#define MODULE(X) "opencv_" #X TOSTRING(CV_VERSION_MAJOR) TOSTRING(CV_VERSION_MINOR) "0.lib"
#endif

//#ifdef USE_CUDA
//
//#if CUDA_VERSION < 5.5
//#error Cuda 5.5 needed
//#endif
//
//#include <opencv2/cudaarithm.hpp>
//#include <opencv2/cudabgsegm.hpp>
//#include <opencv2/cudacodec.hpp>
//#include <opencv2/cudafeatures2d.hpp>
//#include <opencv2/cudafilters.hpp>
//#include <opencv2/cudaimgproc.hpp>
//#include <opencv2/cudalegacy.hpp>
//#include <opencv2/cudaobjdetect.hpp>
//#include <opencv2/cudaoptflow.hpp>
//#include <opencv2/cudastereo.hpp>
//#include <opencv2/cudawarping.hpp>
//
//#endif

#ifdef OPENCV_NO_CONSOLE

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#endif

//#ifdef USE_CUDA
//
//#pragma comment(lib, "cudart.lib")
//#pragma comment(lib, "nppi.lib")
//#pragma comment(lib, "nppc.lib")
//#pragma comment(lib, "npps.lib")
//
//#endif

#ifdef HAVE_OPENCV_WORLD

#pragma comment(lib, MODULE("world"))

#else

#ifdef HAVE_OPENCV_CORE
#pragma comment(lib, MODULE("core"))
#endif
#ifdef HAVE_OPENCV_IMGPROC
#pragma comment(lib, MODULE("imgproc"))
#endif
#ifdef HAVE_OPENCV_PHOTO
#pragma comment(lib, MODULE("photo"))
#endif
#ifdef HAVE_OPENCV_VIDEO
#pragma comment(lib, MODULE("video"))
#endif
#ifdef HAVE_OPENCV_FEATURES2D
#pragma comment(lib, MODULE("features2d"))
#endif
#ifdef HAVE_OPENCV_OBJDETECT
#pragma comment(lib, MODULE("objdetect"))
#endif
#ifdef HAVE_OPENCV_CALIB3D
#pragma comment(lib, MODULE("calib3d"))
#endif
#ifdef HAVE_OPENCV_IMGCODECS
#pragma comment(lib, MODULE("imgcodecs"))
#endif
#ifdef HAVE_OPENCV_VIDEOIO
#pragma comment(lib, MODULE("videoio"))
#endif
#ifdef HAVE_OPENCV_HIGHGUI
#pragma comment(lib, MODULE("highgui"))
#endif
#ifdef HAVE_OPENCV_ML
#pragma comment(lib, MODULE("ml"))
#endif
#ifdef HAVE_OPENCV_HAL
#pragma comment(lib, MODULE("hal"))
#endif

// contrib
#ifdef HAVE_OPENCV_XFEATURES2D
#pragma comment(lib, MODULE("xfeatures2d"))
#endif
#ifdef HAVE_OPENCV_XIMGPROC
#pragma comment(lib, MODULE("ximgproc"))
#endif

//#ifdef USE_CUDA
//
//#pragma comment(lib, MODULE("cudaarithm"))
//#pragma comment(lib, MODULE("cudabgsegm"))
//#pragma comment(lib, MODULE("cudacodec"))
//#pragma comment(lib, MODULE("cudafeatures2d"))
//#pragma comment(lib, MODULE("cudafilters"))
//#pragma comment(lib, MODULE("cudaimgproc"))
//#pragma comment(lib, MODULE("cudalegacy"))
//#pragma comment(lib, MODULE("cudaobjdetect"))
//#pragma comment(lib, MODULE("cudaoptflow"))
//#pragma comment(lib, MODULE("cudastereo"))
//#pragma comment(lib, MODULE("cudawarping"))
//
//#endif

#endif