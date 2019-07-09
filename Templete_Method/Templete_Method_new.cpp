class Library
{
public:
	// template method (stable)
	void Run()
	{
		Step1();
		if(Step2())
			Step3();
		for(int i = 0; i < 4; i++)
			Step4();
		Step5();
	}
	virtual ~Library(){}
protected:
	void Step1()
	{

	}
	void Step3()
	{

	}
	void Step5()
	{

	}
	virtual bool Step2() = 0; //(changeable)
	virtual void Step4() = 0; //(changeable)

};

//------------------------------------------------------------------------------
class Application : public Library
{
protected:
	virtual bool Step2()
	{
		return false;	
	}
	virtual void Step4()
	{

	}

};

//---------------------------------------------------------------------
int main()
{
	Library * pLib = new Application();
	pLib->Run();
	delete pLib;
	return 0;
}

