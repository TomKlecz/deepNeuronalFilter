#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <boost/circular_buffer.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <Iir.h>
#include <Fir1.h>
#include <string>
#include <numeric>
#include <memory>
#include <opencv2/opencv.hpp>
#include "cvui.h"

using namespace std;

namespace cv {
	class Mat;
}

class dynaPlots{
public:
	dynaPlots(cv::Mat &_learningFrame, int _plotW, int _plotH);
	~dynaPlots();
	
	void plotMainSignals(std::vector<double> outer,
			     std::vector<double> inner,
			     std::vector<double> remover,
			     std::vector<double> fnn,
			     std::vector<double> lms_output,
			     int _positionOPEN);
	void plotVariables();
	
	void plotTitle(std:: string title, long count, int duration);
	
	inline double get_wEta() {return (wEta * pow(10, wEtaPower));}
	inline double get_bEta() {return (bEta * pow(10, bEtaPower));}
	inline double get_outer_gain() {return outer_gain;}
	inline double get_inner_gain() {return inner_gain;}
	inline double get_remover_gain() {return remover_gain;}
	inline double get_feedback_gain() {return feedback_gain;}
	
private:
	cv::Mat frame;
	
	double outer_gain    = 100;
	double inner_gain    = 100;
	double remover_gain  = 10;
	double feedback_gain = 1;
	double wEta          = 1;
	double wEtaPower     = 0;
	double bEta          = 2;
	double bEtaPower     = 0;
	
	double gainStart = 0.0;
	double gainEnd = 20.0;
	
	int topOffset = 30;
	int graphDX = 360;
	int graphDY = 110;
	int graphY = 0;
	int gapY = 30;
	int gapX = 15;
	int barY = 60;
	int lineEnter = 15;
	int barDX = 200;
	int bar_p = 1;
	int titleY = 2;
	
	int plotH;
	int plotW;
};

