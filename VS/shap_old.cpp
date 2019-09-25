#include <iostream>

using namespace std;

class Point{
public:
	int x;
	int y;
};

class Line{
public:
	Point start;
	Point end;

	Line(const Point& start, const Point& end){
		this->start = start;
		this->end = end;
	}

};

class Rect{
public:
	Point leftUp;
	int width;
	int height;
	Rect(const Point& leftUp, int width, int height){
		this->leftUp = leftUp;
		this->width = width;
		this->height = height;
	}
};

class MainForm : public Form{
private:
	Point p1;
	point p2;
	vector<Line> lineVector;
	vector<Rect> rectVector;
public:
	MainForm(){

	}
protected:
	virtual void OnMouseDown(const MouseEventArgs& e);
	virtual void OnMouseUp(const MouseEventArgs& e);
	virtual void OnPaint(const PaintEventArgs& e);
	
};

void MainForm::OnMouseDown(const MouseEventArgs& e){
	p1.x = e.X;
	p1.y = e.Y;

	Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
	p2.x = e.X;
	p2.y = e.Y;

	if(rdoLine.Checked)
	{
		Line line(p1, p2);
		lineVector.push_back(line);
	}
	else if(rdoRect.Checked)
	{
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		Rect rect(p1, width, height);
		rectVector.push_back(rect);
	}

	this->Refresh();
	Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e){
	for(int i = 0; i < lineVector.size(); i++)
	{
		e.Graphics.DrawLine(Pens.Red,
				lineVector[i].start.x,
				lineVecotr[i].start,y,
				lineVector[i].end.x,
				lineVector[i].end.y
				);
	}

	for(int i = 0; i < rectVector.size(); i++)
	{
		e.Graohics.DrawRectangle(Pens.Red,
				rectVector[i].leftUp,
				rectVector[i].width,
				rectVector[i].height
				);
	}
	//...
	Form::OnPaint(e);
}








