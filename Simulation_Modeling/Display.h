#pragma once

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <QOpenGLWidget>
#include <QTimer>
#include "stdafx.h"

class Window;

class Display : public QOpenGLWidget
{
	Q_OBJECT

public:
	Window* window;

	UINT width;
	UINT height;

	Display(QWidget* parent = nullptr);

	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;

	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;

	virtual ~Display();

private:
	UINT fps = 60; // frame per second :)

	string BackGroudTexPath;
	string PlainBackGroundTexPath;

	void drawBackGround();
	void drawObject(const string& TexPath, double x, double y, double w, double h, bool isInActiveMode);

private slots:
	void changeFrame();
};

#endif // _DISPLAY_H_
