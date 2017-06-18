#ifndef IntCell_H
#define IntCell_H

/**
 * 一个模整数单元的类
 */
class IntCell
{
public:
	explicit IntCell {int initialValue = 0};
	// 不改变对象的成员变量，也不能调用类中的任何非const成员函数，传入的参数在函数体内不可变
	int read( ) const;
	void write( int x );

private:
	int storeValue;
};

#endif