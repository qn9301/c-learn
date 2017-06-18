/**
 * 一个模拟整数内存的单元类
 */	
class IntCell
{
public:
	// 显式构造
	explicit IntCell (int initialValue = 0)
	// 初始化列表
		: storedValue{ initialValue } { }
	int read() const 
		{ return storedValue; }
	void write( int x )
		{ storedValue = x; }

private:
	int storedValue;
}