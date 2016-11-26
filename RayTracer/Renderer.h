#pragma once

#include "Scene.h"
#include "Viewer.h"

#include <opencv2/opencv.hpp>

class Renderer {
private:
	Viewer viewer;
	const Scene &scene;
	TraceType traceType;

public:
	Renderer(const Viewer &_viewer, const Scene &_scene, TraceType _type) : viewer(_viewer), scene(_scene), traceType(_type) {}
	~Renderer() {}

	cv::Mat render(bool showBar = false) const;
	Viewer &getViewer() { return viewer; }

private:
	cv::Mat rawRender(bool showBar) const;
	void normalize(cv::Mat &img) const;
	cv::Mat double2uchar(const cv::Mat &img) const;
};