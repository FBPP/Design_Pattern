#include <iostream>

using namespace std;

class Shap{
public:
	virtual void Draw(const Graphics& g) = 0;
	virtual ~Shape(){}
};

class Point{
public:
	int x;
	int y;
};

class Line : public Shape{
public:
	Point start;
	Point end;

	Line(const Point& start, const Point& end){
		this->start = start;
		this->end = end;
	}

	virtual void Draw(const Graphics& g){
		g.DrawLine(Pens.Red,
			start.x, start.y, end.x, end.y
				);
	}
};

class Rect : public Shap{
public:
	Point leftUp;
	int width;
	int height;
	Rect(const Point& leftUp, int width, int height){
		this->leftUp = leftUp;
		this->width = width;
		this->height = height;
	}
	virtual void Draw(const Graphics& g){
		g.DrawRectangle(Pens.Red,
			leftUp, width, height
				);
	}
};
class MainForm : public Form{
private:
	Point p1;
	Point p2;

	vector<Shape*> shapVector;
public:
	MainForm(){
		//...
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
	if(rdoLine.Checked){
		shapeVector.push_back(new Line(p1,p2));
	}else if(rdoRect.Checked){
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		shapeVector.push_back(new Rect(p1, width, height));
	}

	this->Refresh();

	Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e){
	for(int i = 0; i < shapVector.size(); i++){
		shapVector[i]->Draw(e.Graphics);

	}
	Form::OnPaint(e);
}

