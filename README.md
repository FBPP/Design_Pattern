## 1 为什么需要面向对象设计模式
+ 不是所有“设计模式”都是“面向对象设计模式”，在其他领域也有设计模式
### 面向对象的思想
+ 底层思维：向下，把握好机器底层，从微观理解面向对象构造
	+ 语言构造
	+ 编译转换
	+ 内存模型
	+ 运行时机制
    + 面向对象的三大对象机制
		+ 封装，隐藏内部实现
		+ 继承，复用现有代码
		+ 多态，改写对象行为 
+ 抽象思维：向上，如何将现实世界的事物抽象成代码
	+ 面向对象
	+ 组件封装
	+ 设计模式
	+ 架构模式
+ 代码是面向对象的，不代表思想也是面向对象的
### 软件领域的复杂性根本原因：变化
+ 客户需求变化
+ 技术平台变化
+ 开发团队变化
+ 市场环境变化
### 如何解决复杂性
+ 分解
	+ 分而治之，解决多个子问题的方式解决整个大问题
	+ 面向过程，结构化设计
+ 抽象
	+ 由于不能掌握全部的复杂对象，忽视非本质的细节，处理泛化和理想化对象模型 
### 好的软件设计应该有极高的复用性
+ 抽象的设计方法就是将多个属于同一抽象类的问题统一处理
	+ 统一的处理方法方法只对于统一的抽象类，处理方法不变，抽象类不变，变的只是继承抽象类的子类
## 2 面向对象八个设计原则
+ 复用的天敌是变化，面向对象的设计原则就是抵御变化
	+ 隔离变化：将变化带来的影响范围减为最小
	+ 各负其责：强调各个类的“责任”，需求变化带来的新增类的实现不应该影响原来类型的实现
		+ 运用多态，接口一样，实现不一样，大家都干这个事，但是你怎么干和我怎么干不一样
### 以文件夹VS中的shap_old.cpp和shap_new.cpp为例
### 依赖倒置原则（DIP）
+ 高层模块（稳定）不应该依赖于低层模块（变化),二者都应依赖于抽象（稳定）
	+ MainFrom是高层模块，如果它依赖于Line和Rect（低层模块）就是不稳定的，依赖于shap（抽象）就是稳定的
+ 抽象（稳定）不应该依赖于实现细节（变化），实现细节应该依赖于抽象（稳定） 
+ 
+ 通过抽象类隔离变化
### 开放封闭原则（OCP）
+ 对扩展开放，对更改封闭
+ 类模块应该是可扩展，但是不可修改的
+  
+ 用扩展去应对需求而不是满大街修改
### 单一职责原则（SRP）
+ 一个类应该仅有一个引起变化的原因。
+ 变化的方向隐含着类的职责
+  
+ 不要把类写的很臃肿，一个类应该只有一个责任 
### Liskvo替换原则（LSP）
+ 子类必须能够替换它们的基类（IS-A）
+ 继承表达类的抽象
+ 
+ 所有需要父类的地方子类都可以传过去使用
### 接口隔离原则（ISP）
+ 不应该强迫客户程序依赖他们不用的方法
+ 接口应该小而完备
+ 
+ 不需要public出去的成员就不要public，接口越少，和客户程序（即使用接口的程序）产生的依赖就越少
### 优先使用对象组合，而不是类继承
+ 类继承通常为“白箱复用”，对象组合通常为“黑箱复用”
+ 继承某种程度上破坏了封装性，子类父类耦合度高
+ 对象组合只要求被组合对象有良好的接口，耦合度低
+ 
+ 面向对象不是继承，不是有继承才叫面向对象，不应误用继承
+ 父类给子类暴露的东西很多，破坏了封装性 
### 封装变化点 
+ 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，而不会对另一侧产生不良影响，从而实现层次间的松耦合
+ 
+ 封装不是为了封装代码和数据，是为了封装变化点
### 针对接口编程，而不是针对实现编程
+ 不将变量类型声明为某个特定的类型，而是声明为某个接口
	+ 例如MainForm里声明的是接口类shap而不是特定的Line和Rect
	+ 对于有些特定场合，还是需要声明具体类型的
+ 客户程序无需获知对象的具体类型，只需知道对所具有的的接口
	+ 例如MainForm里只知道shap里的的Draw()不知道是Line的Draw还是Rect的Draw
+ 减少系统中各部分的依赖关系，从而实现“高聚合，松耦合”的类型设计方案 


+ 设计模式不仅限于这些常用设计模式，也可以实现自己的设计模式
+ 设计模式都是由这八个设计原则推导出来的，所有设计模式必须遵循，如果违背，就不是好的设计模式

### 模式分类
+ 从目的来看
    + 创建型: 解决对象创建的工作
    + 结构型: 解决需求变化对对象结构的冲击
    + 行为型: 多个类之间的交互过程中对对象责任的划分
+ 范围
    + 类模式: 类与子类的静态关系 继承方案
    + 对象模式: 对象之间的动态关系 组合方案

+ 从封装变化角度分类
```txt
    组件协作: 
        Template Method
        Strategy
        Observer/Event
    单一职责:
        Decorator
        Bridge
    对象创建:
        Factory Method
        Abstract Factoty
        Prototype
        Builder
    对象性能:
        Singleton
        Flyweight
    接口隔离:
        Facade
        Proxy
        Mediator
        Apapter
    状态变化:
        Memento
        State
    数据结构:
        Composite
        Iterator
        Chain of
        Resposibility
    行为变化
        Command
        Visitor
    领域问题
        Interpreter
```
### 重构获得模式 Refactoring to Patterns
面向对象设计模式一定要: 应对变化, 提高复用  

现代软件的特征是: 需求的频繁变化, 设计模式的要点是: 寻找变化点, 然后在变化点处应用设计模式, 即 把变化和稳定的部分分离开 

设计模式不应先入为主, 不要一上来就使用设计模式, 没有一步到位的设计模式
,往往需要重构原有代码, 找到原代码的毛病, 并观察是否有合适的设计模式改进它

重构的关键技法:
+ 静态绑定 -> 动态绑定
+ 早绑定 -> 晚绑定
+ 继承 -> 组合
+ 编译时依赖 -> 运行时依赖
+ 紧耦合 -> 松耦合

# 组件协作
现代软件专业分工后的第一个结果是 "框架与应用"   
组件协作 模式通过晚期绑定, 来实现框架与应用之间的松耦合
## 1. Template Method 模板方法
软件构建过程中, 对于某一项任务, 常常有稳定的整体结构, 但各个子步骤中确有很多改变的需求    
以及(比如框架和应用) 子步骤无法和任务的整体结构同时实现

如何在确定操作结构的前提下, 来灵活应对各个子步骤的变化或者晚期的实现需求

模式定义:
定义一个操作中的算法的骨架(稳定), 而将一些步骤延迟(变化)到子类中, Template Method使得子类可以复用一个算法的结构即可重定义(override)该算法的某些步骤

不好的设计
```cc
    //Library Developer
class Library
{
public:
	void Step1()
	{

	}
	void Step3()
	{

	}
	void step5()
	{

	}

};

//Application Developer
class Application
{
public:
	bool Step2()
	{

	}
	void Step4()
	{

	}
};

int main()
{
	Library lib;
	Application app;
	
	lib.Step1();
	if(app.Step2())
		lib.Step3();
	for(int i = 0; i < 4; i++)
		app.Step4();
	lib.Step5();
	return 0;
}	

```
这种设计让很多的方法交给了应用程序去调用, 导致代码重用, 为了提高复用性, 应该使用继承, 让基类调用子类

好的设计:
```cc
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

int main()
{
	Library * pLib = new Application;
	pLib->Run();
	delete pLib;
	return 0;
}
```

+ 适用范围
    + 算法的骨架必须长时间是稳定的
    + 算法必须有不稳定的部分, 并将实现此部分的任务交给实现者
+ 缺点
    + 屏蔽了核心算法, 让应用程序开发人员看不到程序的主流程, 完成的都是零散的子步骤

应用程序开发人员应该试图去了解框架里做了什么

+ 要点
    + 虚函数为框架提供灵活的可扩展点
    + 由高层模块去调用低层模块
    + 可以设置成 虚函数 或 纯虚函数, 一般是protected方法

## 2. Strategy 策略模式
在软件的构建过程中, 某些对象使用的算法可能多种多样, 经常改变
如果将这些算法都编码到对象中, 会使得对象异常复杂, 而且有时候使用不支持的算法也是一种性能负担

如何在运行时根据需要透明的更改对象的算法? 将算法和对象本身解耦, 从而避免上述问题?

不好的设计:
```cc
//税法
emum TaxBase 
{
    CN_Tax,
    US_Tax,
    DE_Tax
};

class SalesOrder
{
public:
    double CalcoulateTax()
    {
        if(m_tax == CN_Tax){
            //CN...
        }
        else if(m_tax == US_Tax){
            //US...
        }
        else if(m_tax == DE_Tax){
            //DE...   
        }
        
        //...
    }
private:
    TaxBase m_tax;
};
    
```
作为程序员, 一定要有时间轴的概念, 从长远的角度, 动态的去看问题  
如果未来支持更多国家的税法呢?  就需要改TaxBase 和 SalesOrder    
违背了 开放封闭原则, 对扩展开放, 而不是去修改源代码来应对未来的变化

好的设计:
```cc
//基类
class TaxStrategy 
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStrategy();
};

//这些子类可以单独放到另一个文件编译, 防止修改影响稳定的文件
class CNTax : public TaxStrategy
{
public:
    double Calculate(const Context &context) override
    {
        //CN.....
    }
};

class USTax : public TaxStrategy
{
public:
    double Calculate(const Context &context) override
    {
        //US.....
    }
};

class DETax : public TaxStrategy
{
public:
    double Calculate(const Context &context) override
    {
        //DE.....
    }
};

class SalesOrder
{
public:
    //用到了工厂模式
    SalesOrder(StarategyFactory *strateFactory)
    {
        m_strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder()
    {
        delete m_strategy;
    }
    
    double CalculateTax()
    {
        Context context;
        
        double val = m_strategy->Calculate(context);
    }
private:
    TaxStrategy *m_strategy;
};

```

真正的复用性是编译单位的复用性, 源代码的拷贝不算是复用性

模式定义:   
定义一系列算法, 把它们封装起来, 并且使它们可互相替换(变化), 该模式使得算法可独立于使用它的客户程序(稳定)而变化(扩展, 子类化)

+ 要点
    + Strategy 及其子类为组件提供了一系列可重用的算法, 从而可以使得到的类型在运行时方便的根据需求在各个算法之间进行切换
    + Strategy模式提供了条件判断语句以外的另一种选择, 消除条件判断语句, 就是在解耦合. 含有许多条件判断语句的代码通常都需要Strategy模式  
        只有在if else 或 switch 在绝对不变的情况下, 才不需要使用strategy
    + 如果Strategy对象没有实例变量, 那么各个上下文可以共享同一个Staregy变量, 从而节省对象开销

## 3. Observer / Event 观察者模式
在软件构建过程中, 需要为某些对象建立一种 通知依赖关系   
一个对象(目标对象)的状态发生变化, 所有依赖对象(观察值对象)都将得到通知  
如果这样的依赖过于紧密, 将使软件不能很好的抵御变化

使用面向对象, 弱化这种依赖关系, 形成稳定依赖, 实现松耦合

不好的设计:
```cc
    class FileSplitter
    {
    private:
        string m_filePath;
        int m_fileNumber;
    public:
        FileSplitter(const string &filepath, int filenumber):
            m_filePath(filePath),
            m_fileNumber(fileNumber)
        {
            
        }
        
        void spilt()
        {
            //1. 读取大文件
            
            //2. 分批向小文件写入
            for(int i = 0; i < m_filename; +=i)
            {
                //...
            }
        }
    };
    
    class MainForm : public Form
    {
    public:
        void Button1_Click()
        {
            string filepath = txtFilePath->getText();
            int number = atoi(txtFileNumber->getText().c_str());
            
            FileSplitter splitter(filepath, number);
            
            splitter.split();
        }
    private:
        TextBox *txtFilePath;
        TextBox *textFileNumber;
    };
```

假设有一个用户需求, 需要显示一个进度条呢?   
按照上边的设计, 需要做一下修改:

```cc
    class FileSplitter
    {
    public:
        FileSplitter(const string &filepath, int filenumber, 
            ProgressBar *progressBar) //添加新的参数
            :m_filePath(filePath)
            ,m_fileNumber(fileNumber)
            ,m_ProgressBar(progressBar) //添加新的初始化
        {
            
        }
        
        void spilt()
        {
            //1. 读取大文件
            
            //2. 分批向小文件写入
            for(int i = 0; i < m_filename; ++i)
            {
                //...
                
                //添加更新进度条的算法
                if(m_progressBar != nullptr)
                    m_progressBar->setValue((i + 1) / m_fileNumber);
            }
        }
    private:
        string m_filePath;
        int m_fileNumber;
        ProgressBar *m_progressBar; //添加进度条
    };
    
    class MainForm : public Form
    {
    public:
        void Button1_Click()
        {
            string filepath = txtFilePath->getText();
            int number = atoi(txtFileNumber->getText().c_str());
            
            FileSplitter splitter(filepath, number, m_progressBar); //传入新的参数
            
            splitter.split();
        }
    private:
        TextBox *txtFilePath;
        TextBox *textFileNumber;
        
        ProgressBar *m_progressBar; //添加进度条
    };
    
```

违背了依赖倒置原则: 高层模块不应依赖于低层模块, 二者都应依赖于抽象  
抽象不能依赖实现细节, 实现细节应该依赖抽象

改进版:

```cc
    
    class IProgress
    {
    public:
        virtual void DoProgress(float vlaue) = 0;
        virtual ~IProgress();
    };
    
    class FileSplitter
    {
    public:
        FileSplitter(const string &filepath, int filenumber, 
            IProgress *iprogress) //添加抽象参数
            :m_filePath(filePath)
            ,m_fileNumber(fileNumber)
            ,m_iprogress(iprogress) //添加新的初始化
        {
            
        }
        
        void spilt()
        {
            //1. 读取大文件
            
            //2. 分批向小文件写入
            for(int i = 0; i < m_filename; ++i)
            {
                //...
                
                //添加更新进度条的算法
                float progressValue = m_fileNumber
                progressValue = (i + 1) /  progressValue
                onProgrress(progressValue);
            }
        }
    protected:
        void onProgress(float value)
        {
            if(m_iprogress != nullptr)
                m_progress->DoProgress(value);
        }
    private:
        string m_filePath;
        int m_fileNumber;
        //ProgressBar *m_progressBar; //具体的通知控件
        
        IProgress *m_iprogress; //抽象的通知机制
    };
    
    class MainForm : public Form, public IProgress
    {
    public:
        void Button1_Click()
        {
            string filepath = txtFilePath->getText();
            int number = atoi(txtFileNumber->getText().c_str());
            
            FileSplitter splitter(filepath, number, this); //传入this
            
            splitter.split();
        }
        
        void DoProgress(float vlaue) override
        {
            m_progressBar->setValue(value);
        }
    private:
        TextBox *txtFilePath;
        TextBox *textFileNumber;
        
        ProgressBar *m_progressBar;
    };
    
```

使用IProgress抽象使得MainFrom 和 Filespliter分离开来, 二者同都依赖于IProgress

多继承虽然不推荐使用, 但是可以单继承一个父类, 其他继承都是接口

但是无发添加多个观察者:

```cc
    class IProgress
    {
    public:
        virtual void DoProgress(float vlaue) = 0;
        virtual ~IProgress();
    };
    
    class FileSplitter
    {
    public:
        FileSplitter(const string &filepath, int filenumber, 
            IProgress *iprogress) //添加抽象参数
            :m_filePath(filePath)
            ,m_fileNumber(fileNumber)
            ,m_iprogress(iprogress) //添加新的初始化
        {
            
        }
        
        void spilt()
        {
            //1. 读取大文件
            
            //2. 分批向小文件写入
            for(int i = 0; i < m_filename; ++i)
            {
                //...
                
                //添加更新进度条的算法
                float progressValue = m_fileNumber
                progressValue = (i + 1) /  progressValue
                onProgrress(progressValue);
            }
        }
    protected:
        void onProgress(float value)
        {
            if(m_iprogress != nullptr)
                m_progress->DoProgress(value);
        }
    private:
        string m_filePath;
        int m_fileNumber;
        //ProgressBar *m_progressBar; //具体的通知控件
        
        IProgress *m_iprogress; //抽象的通知机制
    };
    
    class ConsoleNotfier : public IProgress //新的通知
    {
        virtual void DoProgress(float value)
        cout << ".";
    };
    
    class MainForm : public Form, public IProgress
    {
    public:
        void Button1_Click()
        {
            string filepath = txtFilePath->getText();
            int number = atoi(txtFileNumber->getText().c_str());
            
            consoleNotifier cn;
            //这里传递了cn不能传递this, 只能传递一个观察者
            FileSplitter splitter(filepath, number, &cn); 
            
            splitter.split();
        }
        
        void DoProgress(float vlaue) override
        {
            m_progressBar->setValue(value);
        }
    private:
        TextBox *txtFilePath;
        TextBox *textFileNumber;
        
        ProgressBar *m_progressBar;
    };
    
```

继续改进:
```cc
    class IProgress
    {
    public:
        virtual void DoProgress(float vlaue) = 0;
        virtual ~IProgress();
    };
    
    class FileSplitter
    {
    public:
        FileSplitter(const string &filepath, int filenumber)
            :m_filePath(filePath)
            ,m_fileNumber(fileNumber)
        {
            
        }
        
        void addIProgress(IProgress *iprogress)
        {
            m_iprogress.insert(iprogress))
        }
        
        void removeIProgress(IProgress *iprogress))
        {
            m_iprogress.erase(iprogress);
        }
        
        void spilt()
        {
            //1. 读取大文件
            
            //2. 分批向小文件写入
            for(int i = 0; i < m_filename; ++i)
            {
                //...
                
                //添加更新进度条的算法
                float progressValue = m_fileNumber
                progressValue = (i + 1) /  progressValue
                onProgrress(progressValue);
            }
        }
    protected:
        void onProgress(float value)
        {
            for(auto a : m_iprogressBar)
            	a->DoProgress(value);
        }
    private:
        string m_filePath;
        int m_fileNumber;
        
        unordered_set<ProgressBar *> m_iprogressBar; //支持多个观察者
    };
    
    class ConsoleNotfier : public IProgress //新的通知
    {
        void DoProgress(float value) override;
        cout << ".";
    };
    
    class MainForm : public Form, IProgress
    {
    public:
        void Button1_Click()
        {
            string filepath = txtFilePath->getText();
            int number = atoi(txtFileNumber->getText().c_str());
            
            consoleNotifier cn;
           
            FileSplitter splitter(filepath, number); 

            consoleNotifier cn;

            splitter.addIProgress(this); //订阅通知
            splitter.addProgeress(&cn); // 订阅通知 
            
            splitter.split();
        }
        
        void DoProgress(float vlaue) override
        {
            m_progressBar->setValue(value);
        }
    private:
        TextBox *txtFilePath;
        TextBox *textFileNumber;
		
		 ProgressBar *m_progressBar;        
        
    };
    
```

+ 模式定义:   
    + 定义对象一种一对多(变化)的依赖关系,
    + 以便当一个对象的状态发生改变的时候, 所有依赖他的对象, 都得到通知, 并自动更新  

+ 要点总结:
    + 使用抽象, 独立地改变目标(FileSplitter)和观察者(MainForm)使二者之间达到松耦合
    + 目标发送通知时, 无序指定观察者, 通知会自动传播(onProgress)
    + 观察者自己决定是否订阅通知, 目标对象对此一无所知
    + Observer是基于事件的UI框架的非常常用的设计模式, 也是MVC的一个重要组成部分

# 单一职责
在软件组件设计中, 如果责任划分不清, 使用继承得到结果往往是随着需求的变化,子类急剧膨胀, 同时充斥重复代码, 这时候关键是换分责任

## 1. Decorator 装饰模式
过度的使用继承扩展对象功能会让子类引入很多静态特征, 使得这种扩展缺乏灵活性, 并且随着子类的增多(扩展功能增多), 各种子类的组合会导致子类数目指数型增长

不好的设计:
```cc
    //流的操作
    //业务操作
    class stream
    {
    public:
        virtual void Read(int number) = 0;
        virtual void Seek(int position) = 0;
        virtual void Write(char data) = 0;
        
        virtual ~Stream();
    };
    
    //文件流
    class FileStream : public Steam
    {
    public:
        char Read(int number) override
        {
            
        }
        
        void Seek(int position) overide
        {
            
        }
        
        void Write(char data) override
        {
            
        }
    };
    
    //网络流
    class NetworkStream : public Steam
    {
    public:
        char Read(int number) override
        {
            
        }
        
        void Seek(int position) overide
        {
            
        }
        
        void Write(char data) override
        {
            
        }
    };
    
    //内存流
    class MemoryStream : public Steam
    {
    public:
        char Read(int number) override
        {
            
        }
        
        void Seek(int position) overide
        {
            
        }
        
        void Write(char data) override
        {
            
        }
    };
    
    //加密 文件流
    class CryptoFileStream : public FileStream
    {
    public:
        char Read(int number) override
        {
            //额外的加密操作
            FileSream::Read(number);
        }
        
        char Seek(int number) override
        {
            //额外的加密操作
            FileSream::Seek(number);
            //额外的加密操作
        }
        
        char Write(int number) override
        {
            //额外的加密操作
            FileSream::Read(number);
            //额外的加密操作
        }
    };
    
    //加密网络流
    //加密内存流
    
    //缓冲文件
    class BufferFileStream : public FileStream
    {
        
    };
    //...
    
    //既加密又缓冲
    //...
```

这样的设计滥用继承导致含有大量的重复代码(加密)
违背了设计原则: 优先使用类组合而不是继承

改进:
```cc
//流的操作
    //业务操作
   
    
    //加密 文件流
    class CryptoFileStream 
    {
    public:
        char Read(int number) 
        {
            //额外的加密操作
            m_steam->Read(number);
        }
        
        char Seek(int number) 
        {
            //额外的加密操作
            m_steam->Seek(number);
            //额外的加密操作
        }
        
        char Write(int number) 
        {
            //额外的加密操作
            m_steam->Read(number);
            //额外的加密操作
        }
    private:
        FileStream *m_stream;
    };
    
    //加密网络流
    class CryptoNetworkStream
    {
    public:
    private:
        NetworkStream *m_stream;   
    };
    //加密内存流
    class CryptoMemoryStream
    {
    private:
        MemoryStream *m_stream;
    };
    
    //缓冲
    class BufferFileStream 
    {
        
    };
    //....
    
    //既加密又缓冲
```
从上边会发现, 将继承变为组合后, 会出现新的多态性, 每个子类类型的steam都继承自steam

继续改进:

```cc

    //流的操作

    
    //加密 文件流
    class CryptoFileStream 
    {
    public:
        char Read(int number) 
        {
            //额外的加密操作
            m_steam->Read(number);
        }
        
        char Seek(int number)
        {
            //额外的加密操作
            m_steam->Seek(number);
            //额外的加密操作
        }
        
        char Write(int number) 
        {
            //额外的加密操作
           m_steam->Read(number);
            //额外的加密操作
        }
    private:
        Stream *m_stream;
    };
    
    //加密网络流
    class CryptoNetworkStream
    {
    public:
    private:
        Stream *m_stream;   
    };
    //加密内存流
    class CryptoMemoryStream
    {
    private:
       Stream *m_stream;
    };
    
    //缓冲
    class BufferFileStream 
    {
        
    };
    //....
    
    //既加密又缓冲
```

从以上代码发现, 三个类是一样的

好的设计:
```cc
    //流的操作
    
    
    DecoratorStream : public Stream
    {
    protected:
        DecoratorStream(Stream *stm): m_stream(stm)
        Stream *m_stream;
    };
    //加密 文件流
    class CryptoStream : public DecoratorStream
    {
    public:
    
        CryptoStream(Stream *stm) : DecoratorStream(stm)
        char Read(int number) override
        {
            //额外的加密操作
            m_steam->Read(number);
        }
        
        char Seek(int number) override
        {
            //额外的加密操作
             m_steam->Seek(number);
            //额外的加密操作
        }
        
        char Write(int number) override
        {
            //额外的加密操作
             m_steam->Read(number);
            //额外的加密操作
        }
        
    };
    
     //缓冲
    class BufferStream 
    {
        
    };
    
    void progress()
    {
        FileStream *s1 = new FileStream;
        CryptoStream *s2 = new CryptoStream(s1);
        BufferedStream *s3 = new BufferedStream(s1);
    }
    
```

+ 模式定义:
    + 动态(组合)的给一个对象增加一些额外的职责, 就增加工能而言, Decorator模式比生成子类(继承)更为灵活(消除重复代码 & 减少子类个数)

+ 要点:
    + 通过采用组合而非继承, Decorator在运行时提供扩展对象的功能, 而且可以根据需要扩展多个功能, 避免了使用继承带来 灵活性差 和 多子类衍生 的问题
    + Decorator类在接口上表现为 is-a 的继承关系, 但在实现上表现为has-a的组合关系
    + Decorator并不不是为了解决 多子类衍生问题, 而是为了解决 主体类在多个放向上的扩展功能, 即 装饰


扩展操作不是继承, 扩展是has-a的关系, 他并不能代替基类

## 2. Bridge 桥模式
由于某些类型固有的实现逻辑, 使得他们具有多个变化的维度

不好的设计
```cc
class Messager
{
public:
    virtual ~Messager(){}

    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPircure(Image image) = 0;
    
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    
};

//pc平台
class PCMessagerBase : public Messager
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }
};

//Mobile平台
class MobileMessagerBase : public Messager
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }   
};

//精简版
class PCMessagerLite : public PCMessagerBase
{
public:
    void Login(String username, String password) override
    {
        PCMessagerBase::Connect();
    }
    void SendMessage(String message) override
    {
        PCMessagerBase::WriteText();
    }
    
    void SendPicture(Image image) override
    {
        PCMessagerBase::DrawShap();
    }
    
};

//华丽版
class PCMessagerPerfect : public PCMessagerBase
{
public:
    void Login(String username, String password) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::Connect();
    }
    void SendMessage(String message) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::WriteText();
    }
    
    void SendPicture(Image image) override
    {
        PCMessagerBase::PlaySound();
        PCMessagerBase::DrawShap();
    }
};

//
class MobileMessagerLite : public MobileMessagerBase
{
    //...
};

//
class MoblieMessagerPerfact : public MobileMessagerBase
{
    //....  
};

void Process()
{
    //编译时装配
    Messager *msg = new MobileMessagerPerfect();   
}

    


```
类似于装饰模式的优化方式, 将继承变为组合, 减少大量重复的代码, 减少子类的数目

改进:

```cc
class Messager
{
public:
    virtual ~Messager(){}

    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPircure(Image image) = 0;
    
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    
};

//pc平台
class PCMessagerBase : public Messager
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }
};

//Mobile平台
class MobileMessagerBase : public Messager
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }   
};

class MessagerLite  
{
public:
    void Login(String username, String password) override
    {
        msg->Connect();
    }
    void SendMessage(String message) override
    {
        msg->WriteText();
    }
    
    void SendPicture(Image image) override
    {
        msg->DrawShap();
    }
private:
    Messager *msg; 
    
};



class MessagerPerfect
public:
    void Login(String username, String password) override
    {
        msg->PlaySound();
        msg->PConnect();
    }
    void SendMessage(String message) override
    {
        msg->PPlaySound();
        msg->PWriteText();
    }
    
    void SendPicture(Image image) override
    {
        msg->PPlaySound();
        msg->PDrawShap();
    }
private:
    Messaer *msg;
};

```
优化之后, 仍然存在问题, msg = new PCMessaeBase 不成立 PCMessageBase是一个 抽象类, 不能被实例化

原因在于Messager类中的两类纯虚函数的功能属于两个不同的方向, 应该把他们分开
```cc
class Messager
{
public:
    virtual ~Messager(){}

    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPircure(Image image) = 0;
protected:
    MessagerImp *msg; 
};

class MessagerImp
{
public:
    virtual ~MessagerImp(){}

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
    
};

//pc平台
class PCMessager : public MessagerImp
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }
};

//Mobile平台
class MobileMessager : public MessagerImp
{
public:
    void PlaySound() override
    {
        
    }
    
    void  DrawShape() override
    {
        
    }
    
    void WriteText() override
    {
        
    }
    
    void Connect() override
    {
        
    }   
};

class MessagerLite : public Messager
{
public:
    void Login(String username, String password) override
    {
        msg->Connect();
    }
    void SendMessage(String message) override
    {
        msg->WriteText();
    }
    
    void SendPicture(Image image) override
    {
        msg->DrawShap();
    }
    
};



class MessagerPerfect : public Messager
public:
    void Login(String username, String password) override
    {
        msg->PlaySound();
        msg->PConnect();
    }
    void SendMessage(String message) override
    {
        msg->PPlaySound();
        msg->PWriteText();
    }
    
    void SendPicture(Image image) override
    {
        msg->PPlaySound();
        msg->PDrawShap();
    }

};


void Process()
{
    MessagerImp *msg = new PCMessager();
    Messager *m = new MessagerPerfec(msg);
}
```

+ 模式定义:
    + 将抽象部分(业务功能) 和 实现部分(平台实现)分离, 使得它们都可以独立的变化
+ 要点:
    + Bridge模式使用"对象间组合关系"解耦合抽象和实现之间的固有绑定关系, 是抽象和实现沿着各自的维度变化, 即"子类化"它们
    + Bridege模式有时候类似多继承方案, 但多继承方案往往违背单一职责原则, 复用性比较差, Bridge方案往往比多继承方案更好
    + Bridge模式应用在"两个非常强的变换维度", 如果一个类多于两个变化的维度, 则用Bridge模式拆分它们

