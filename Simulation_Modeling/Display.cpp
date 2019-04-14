#include <QMouseEvent>
#include <QtOpenGL>

#include "stdafx.h"
#include "Display.h"
#include "Texture.h"
#include "Window.h"
#include "IL/include/IL/il.h"
#include "Util/Vec2.h"
#include "Util/Point.h"
#include "Util/Line.h"

Display::Display(QWidget* parent) : QOpenGLWidget(parent), window(nullptr)
{
	this->setMouseTracking(true); 

	ilInit();

	QTimer *timer = new QTimer;
	connect(timer, SIGNAL(timeout()), SLOT(changeFrame()));
	timer->start(1000 / fps);

	QRect rect = this->geometry();
	this->width = rect.width();
	this->height = rect.height();

	BackGroudTexPath = "images/background.tga";
	PlainBackGroundTexPath = "images/fillBack.tga";
}

Display::~Display()
{
	this->window = nullptr;
}

void Display::initializeGL()
{
	this->makeCurrent();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);

	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

}

void Display::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	this->width = w;
	this->height = h;

	if (this->window->simulation)
		this->window->simulation->setWndParams(w, h);

}


void Display::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT );

	glLoadIdentity();

	if (!this->window)
		return;

	glPushMatrix();
	drawBackGround();
	if (this->window->simulation)
	{
		const auto& tl = this->window->simulation->timberLoader;
		drawObject(tl.texPath, tl.position.x, tl.position.y, tl.size.x, tl.size.y, tl.isActive);

		this->window->simulation->timberMutex.lock();
		for (auto& timber : this->window->simulation->shownTimbers)
			if (timber.isToPSBench())
				drawObject(timber.texPath, timber.position.x, timber.position.y, timber.size.x, timber.size.y, false);
		this->window->simulation->timberMutex.unlock();

		this->window->simulation->boardMutex.lock();
		for (auto& board : this->window->simulation->shownBoards)
			if (board.isToDryerBench() || board.isToSortingBench() || board.isToMillingBench() || board.isToAssemblingBench())
				drawObject(board.texPath, board.position.x, board.position.y, board.size.x, board.size.y, false);
		this->window->simulation->boardMutex.unlock();

		const auto& psb = this->window->simulation->pSBench;
		drawObject(psb.texPath, psb.position.x, psb.position.y, psb.size.x, psb.size.y, psb.isActive);

		const auto& dr = this->window->simulation->dryerBench;
		drawObject(dr.texPath, dr.position.x, dr.position.y, dr.size.x, dr.size.y, dr.isActive);

		const auto& sb = this->window->simulation->sortingBench;
		drawObject(sb.texPath, sb.position.x, sb.position.y, sb.size.x, sb.size.y, sb.isActive);

		for each(auto& bench in this->window->simulation->millingBenchs)
			drawObject(bench.texPath, bench.position.x, bench.position.y, bench.size.x, bench.size.y, bench.isActive);


		for each(auto& bench in this->window->simulation->assemblingBenchs)
			drawObject(bench.texPath, bench.position.x, bench.position.y, bench.size.x, bench.size.y, bench.isActive);

		const auto& pcb = this->window->simulation->packingBench;
		drawObject(pcb.texPath, pcb.position.x, pcb.position.y, pcb.size.x, pcb.size.y, pcb.isActive);

		this->window->simulation->doorMutex.lock();
		for (auto& door : this->window->simulation->shownDoors)
			if (door.isToPaintingBench() || door.isToPackingBench() || door.isDoneAndShow() || door.isIdle())
				drawObject(door.texPath, door.position.x, door.position.y, door.size.x, door.size.y, false);
		this->window->simulation->doorMutex.unlock();

		const auto& pb = this->window->simulation->paintingBench;
		drawObject(pb.texPath, pb.position.x, pb.position.y, pb.size.x, pb.size.y, pb.isActive);

		const auto& fnb = this->window->simulation->fnBench;
		drawObject(fnb.texPath, fnb.position.x, fnb.position.y, fnb.size.x, fnb.size.y, fnb.isActive);

		for (auto& brigade : this->window->simulation->brigades)
		{
			if (brigade.isActive)
			{
				drawObject(brigade.employee1.texPath, brigade.employee1.position.x, brigade.employee1.position.y, brigade.employee1.size.x, brigade.employee1.size.y, brigade.employee1.isActive);
				drawObject(brigade.employee2.texPath, brigade.employee2.position.x, brigade.employee2.position.y, brigade.employee2.size.x, brigade.employee2.size.y, brigade.employee2.isActive);
				drawObject(brigade.employee3.texPath, brigade.employee3.position.x, brigade.employee3.position.y, brigade.employee3.size.x, brigade.employee3.size.y, brigade.employee3.isActive);
			}
		}

		const auto& fgdb = this->window->simulation->firstGradeDoorButton;
		drawObject(fgdb.texPath, fgdb.position.x, fgdb.position.y, fgdb.size.x, fgdb.size.y, fgdb.isActive);

		const auto& sgdb = this->window->simulation->secondGradeDoorButton;
		drawObject(sgdb.texPath, sgdb.position.x, sgdb.position.y, sgdb.size.x, sgdb.size.y, sgdb.isActive);

		const auto& tgdb = this->window->simulation->thirdGradeDoorButton;
		drawObject(tgdb.texPath, tgdb.position.x, tgdb.position.y, tgdb.size.x, tgdb.size.y, tgdb.isActive);

	}

	glPopMatrix();

}

void Display::mouseMoveEvent(QMouseEvent* event)
{
	if (!this->window || !this->window->simulation)
		return;

	Point p = { event->x(), event->y() };

	this->window->simulation->timberLoader.texPath = "images/benches/timberCarrier.tga";
	this->window->simulation->pSBench.texPath = "images/benches/PSBench.tga";
	this->window->simulation->dryerBench.texPath = "images/benches/dryingBench.tga";
	this->window->simulation->sortingBench.texPath = "images/benches/sortingBench.tga";
	this->window->simulation->millingBenchs[0].texPath = "images/benches/millingBench1.tga";
	this->window->simulation->millingBenchs[1].texPath = "images/benches/millingBench2.tga";
	this->window->simulation->millingBenchs[2].texPath = "images/benches/millingBench3.tga";
	this->window->simulation->assemblingBenchs[0].texPath = "images/benches/assemblingBench1.tga";
	this->window->simulation->assemblingBenchs[1].texPath = "images/benches/assemblingBench2.tga";
	this->window->simulation->assemblingBenchs[2].texPath = "images/benches/assemblingBench3.tga";
	this->window->simulation->paintingBench.texPath = "images/benches/paintingBench.tga";
	this->window->simulation->brigades[0].employee1.texPath = "images/benches/1brigade1employee.tga";
	this->window->simulation->brigades[0].employee2.texPath = "images/benches/1brigade2employee.tga";
	this->window->simulation->brigades[0].employee3.texPath = "images/benches/1brigade3employee.tga";
	this->window->simulation->brigades[1].employee1.texPath = "images/benches/2brigade1employee.tga";
	this->window->simulation->brigades[1].employee2.texPath = "images/benches/2brigade2employee.tga";
	this->window->simulation->brigades[1].employee3.texPath = "images/benches/2brigade3employee.tga";
	this->window->simulation->brigades[2].employee1.texPath = "images/benches/3brigade1employee.tga";
	this->window->simulation->brigades[2].employee2.texPath = "images/benches/3brigade2employee.tga";
	this->window->simulation->brigades[2].employee3.texPath = "images/benches/3brigade3employee.tga";
	this->window->simulation->firstGradeDoorButton.texPath = "images/button.tga";
	this->window->simulation->secondGradeDoorButton.texPath = "images/button.tga";
	this->window->simulation->thirdGradeDoorButton.texPath = "images/button.tga";
	this->setCursor(Qt::ArrowCursor);

	if (this->window->simulation->timberLoader.isMouseOn(p))
	{
		this->window->simulation->timberLoader.texPath = "images/benches/timberCarrier+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->pSBench.isMouseOn(p))
	{
		this->window->simulation->pSBench.texPath = "images/benches/PSBench+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if(this->window->simulation->dryerBench.isMouseOn(p))
	{
		this->window->simulation->dryerBench.texPath = "images/benches/dryingBench+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if(this->window->simulation->sortingBench.isMouseOn(p))
	{
		this->window->simulation->sortingBench.texPath = "images/benches/sortingBench+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if(this->window->simulation->millingBenchs[0].isMouseOn(p))
	{
		this->window->simulation->millingBenchs[0].texPath = "images/benches/millingBench1+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if(this->window->simulation->millingBenchs[1].isMouseOn(p))
	{
		this->window->simulation->millingBenchs[1].texPath = "images/benches/millingBench2+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if(this->window->simulation->millingBenchs[2].isMouseOn(p))
	{
		this->window->simulation->millingBenchs[2].texPath = "images/benches/millingBench3+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->assemblingBenchs[0].isMouseOn(p))
	{
		this->window->simulation->assemblingBenchs[0].texPath = "images/benches/assemblingBench1+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->assemblingBenchs[1].isMouseOn(p))
	{
		this->window->simulation->assemblingBenchs[1].texPath = "images/benches/assemblingBench2+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->assemblingBenchs[2].isMouseOn(p))
	{
		this->window->simulation->assemblingBenchs[2].texPath = "images/benches/assemblingBench3+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->paintingBench.isMouseOn(p))
	{
		this->window->simulation->paintingBench.texPath = "images/benches/paintingBench+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->firstGradeDoorButton.isMouseOn(p))
	{
		this->window->simulation->firstGradeDoorButton.texPath = "images/button+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->secondGradeDoorButton.isMouseOn(p))
	{
		this->window->simulation->secondGradeDoorButton.texPath = "images/button+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	else if (this->window->simulation->thirdGradeDoorButton.isMouseOn(p))
	{
		this->window->simulation->thirdGradeDoorButton.texPath = "images/button+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	if (this->window->simulation->brigades[0].employee1.isMouseOn(p) || this->window->simulation->brigades[0].employee2.isMouseOn(p) || this->window->simulation->brigades[0].employee3.isMouseOn(p))
	{
		this->window->simulation->brigades[0].employee1.texPath = "images/benches/1brigade1employee+.tga";
		this->window->simulation->brigades[0].employee2.texPath = "images/benches/1brigade2employee+.tga";
		this->window->simulation->brigades[0].employee3.texPath = "images/benches/1brigade3employee+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	if (this->window->simulation->brigades[1].employee1.isMouseOn(p) || this->window->simulation->brigades[1].employee2.isMouseOn(p) || this->window->simulation->brigades[1].employee3.isMouseOn(p))
	{
		this->window->simulation->brigades[1].employee1.texPath = "images/benches/2brigade1employee+.tga";
		this->window->simulation->brigades[1].employee2.texPath = "images/benches/2brigade2employee+.tga";
		this->window->simulation->brigades[1].employee3.texPath = "images/benches/2brigade3employee+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}
	if (this->window->simulation->brigades[2].employee1.isMouseOn(p) || this->window->simulation->brigades[2].employee2.isMouseOn(p) || this->window->simulation->brigades[2].employee3.isMouseOn(p))
	{
		this->window->simulation->brigades[2].employee1.texPath = "images/benches/3brigade1employee+.tga";
		this->window->simulation->brigades[2].employee2.texPath = "images/benches/3brigade2employee+.tga";
		this->window->simulation->brigades[2].employee3.texPath = "images/benches/3brigade3employee+.tga";
		this->setCursor(Qt::PointingHandCursor);
	}

	this->update();
}

void Display::mousePressEvent(QMouseEvent* event)
{
	if (!this->window || !this->window->simulation)
		return;

	Point p = { event->x(), event->y() };

	if (event->buttons() == Qt::LeftButton)
	{
		if (this->window->simulation->settings.isVisible())
			this->window->simulation->settings.close();

		this->window->simulation->timberLoader.isActive = false;
		this->window->simulation->pSBench.isActive = false;
		this->window->simulation->dryerBench.isActive = false;
		this->window->simulation->sortingBench.isActive = false;
		this->window->simulation->millingBenchs[0].isActive = false;
		this->window->simulation->millingBenchs[1].isActive = false;
		this->window->simulation->millingBenchs[2].isActive = false;
		this->window->simulation->assemblingBenchs[0].isActive = false;
		this->window->simulation->assemblingBenchs[1].isActive = false;
		this->window->simulation->assemblingBenchs[2].isActive = false;
		this->window->simulation->paintingBench.isActive = false;
		this->window->simulation->firstGradeDoorButton.isActive = false;
		this->window->simulation->secondGradeDoorButton.isActive = false;
		this->window->simulation->thirdGradeDoorButton.isActive = false;
		this->window->simulation->fnBench.isActive = false;
		this->window->simulation->packingBench.isActive = false;

		for (auto& br : this->window->simulation->brigades)
		{
			br.employee1.isActive = false;
			br.employee2.isActive = false;
			br.employee3.isActive = false;
		}

		const auto& tl = this->window->simulation->timberLoader;
		if (tl.isMouseOn(p))
		{
			this->window->simulation->timberLoader.isActive = true;
			this->window->simulation->settings.skipTimbersBatch(this->window->simulation->money, this->window->simulation->getLastInBatch());
		}

		const auto& psb = this->window->simulation->pSBench;
		if (psb.isMouseOn(p))
		{
			this->window->simulation->pSBench.isActive = true;
			this->window->simulation->settings.repairPSBench(this->window->simulation->money);
		}

		const auto& db = this->window->simulation->dryerBench;
		if (db.isMouseOn(p))
		{
			this->window->simulation->dryerBench.isActive = true;
			this->window->simulation->settings.repairDryingBench(this->window->simulation->money);
		}

		const auto& sb = this->window->simulation->sortingBench;
		if (sb.isMouseOn(p))
		{
			this->window->simulation->sortingBench.isActive = true;
			this->window->simulation->settings.repairSortingBench(this->window->simulation->money);
		}

		const auto& mb1 = this->window->simulation->millingBenchs[0];
		if (mb1.isMouseOn(p))
		{
			this->window->simulation->millingBenchs[0].isActive = true;
			this->window->simulation->settings.repairMillingBench1(this->window->simulation->money);
		}

		const auto& mb2 = this->window->simulation->millingBenchs[1];
		if (mb2.isMouseOn(p))
		{
			this->window->simulation->millingBenchs[1].isActive = true;
			this->window->simulation->settings.repairMillingBench2(this->window->simulation->money);
		}

		const auto& mb3 = this->window->simulation->millingBenchs[2];
		if (mb3.isMouseOn(p))
		{
			this->window->simulation->millingBenchs[2].isActive = true;
			this->window->simulation->settings.repairMillingBench3(this->window->simulation->money);
		}

		const auto& ab1 = this->window->simulation->assemblingBenchs[0];
		if (ab1.isMouseOn(p))
		{
			this->window->simulation->assemblingBenchs[0].isActive = true;
			this->window->simulation->settings.repairAssemblingBench1(this->window->simulation->money);
		}

		const auto& ab2 = this->window->simulation->assemblingBenchs[1];
		if (ab2.isMouseOn(p))
		{
			this->window->simulation->assemblingBenchs[1].isActive = true;
			this->window->simulation->settings.repairAssemblingBench2(this->window->simulation->money);
		}

		const auto& ab3 = this->window->simulation->assemblingBenchs[2];
		if (ab3.isMouseOn(p))
		{
			this->window->simulation->assemblingBenchs[2].isActive = true;
			this->window->simulation->settings.repairAssemblingBench3(this->window->simulation->money);
		}

		const auto& pb = this->window->simulation->paintingBench;
		if (pb.isMouseOn(p))
		{
			this->window->simulation->paintingBench.isActive = true;
			this->window->simulation->settings.repairPaintingBench(this->window->simulation->money);
		}

		for (auto& br : this->window->simulation->brigades)
		{
			if (br.isActive)
			{
				auto& emp1 = br.employee1;
				auto& emp2 = br.employee2;
				auto& emp3 = br.employee3;
				if (emp1.isMouseOn(p) || emp2.isMouseOn(p) || emp3.isMouseOn(p))
				{
					emp1.isActive = true;
					emp2.isActive = true;
					emp3.isActive = true;
					this->window->simulation->settings.trainBrigades(this->window->simulation->money);
				}
			}
		}

		const auto& fgdb = this->window->simulation->firstGradeDoorButton;
		if (fgdb.isMouseOn(p))
		{
			this->window->simulation->firstGradeDoorButton.isActive = true;
			this->window->simulation->settings.showFirstGradeDoorsStat(this->window->simulation->getFirstGradeDoorsCount(), this->window->simulation->getFirstGradeDoorDefectsCount());
		}

		const auto& sgdb = this->window->simulation->secondGradeDoorButton;
		if (sgdb.isMouseOn(p))
		{
			this->window->simulation->secondGradeDoorButton.isActive = true;
			this->window->simulation->settings.showSecondGradeDoorsStat(this->window->simulation->getSecondGradeDoorsCount(), this->window->simulation->getFSecondGradeDoorDefectsCount());
		}

		const auto& tgdb = this->window->simulation->thirdGradeDoorButton;
		if (tgdb.isMouseOn(p))
		{
			this->window->simulation->thirdGradeDoorButton.isActive = true;
			this->window->simulation->settings.showThirdGradeDoorsStat(this->window->simulation->getThirdGradeDoorsCount(), this->window->simulation->getThirdGradeDoorDefectsCount());
		}
	}
}


void Display::drawObject(const string& TexPath, double x, double y, double w, double h, bool isInActiveMode)
{
	glPushMatrix();

	CTexture tex(TexPath);
	glBindTexture(GL_TEXTURE_2D, tex.uId);

	if (this->window->simulation->settings.isVisible() && !isInActiveMode)
		glColor3f(0.5f, 0.5f, 0.5f);
	else
		glColor3f(1.0f, 1.0f, 1.0f);

	glTranslated(x,y, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex2d(0, 0);
	glTexCoord2f(0, 0);
	glVertex2d(0, h);
	glTexCoord2f(1, 0);
	glVertex2d(w, h);
	glTexCoord2f(1, 1);
	glVertex2d(w, 0);
	glEnd();

	glPopMatrix();
}

void Display::drawBackGround()
{
	glPushMatrix();

	CTexture tex;
	if (this->window->simulation)
		tex.loadTex(BackGroudTexPath);
	else
		tex.loadTex(PlainBackGroundTexPath);

	glBindTexture(GL_TEXTURE_2D, tex.uId);
	if (this->window->simulation && this->window->simulation->settings.isVisible())
		glColor3f(0.5f, 0.5f, 0.5f);
	else
		glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex2i(0, 0);
	glTexCoord2f(0, 0);
	glVertex2i(0, height);
	glTexCoord2f(1, 0);
	glVertex2i(width, height);
	glTexCoord2f(1, 1);
	glVertex2i(width, 0);
	glEnd();

	glPopMatrix();
}


void Display::changeFrame()
{
	update();
}