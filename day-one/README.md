```
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
```
* 第八行用到的语法
`: storeValue{ initialValue } {}`
* 而不是传统的
`：storeValue( initialValue ) {}`

*使用花括号代替圆括号在C++11版中是新规定，并且是该版更大尝试的一部分，以提供该各处使用初始化的地方一个统一的语法标准，在任何能够初始化的地方，我们都可以这么做，即使初始化用花括号括起来*

## 概念`初始化列表`
    struct foo
    {
        string name ;
        int id ;
        foo(string s, int i):name(s), id(i){} ; // 初始化列表
    };
* 将`name`初始化为传入的s的值，将id初始化为传入的i的值
### 注意：成员变量的初始化顺序
```
struct foo
{
    int i ;
    int j ;
    foo(int x):i(x), j(i){}; // ok, 先初始化i，后初始化j
};
```
    
```
struct foo
{
    int i ;
    int j ;
    foo(int x):j(x), i(j){} // i值未定义
};
```
* ***成员是按照他们在类中出现的顺序进行初始化的，而不是按照他们在初始化列表出现的顺序初始化的***
* ***这里`i`的值是未定义的，虽然`j`在初始化列表里面出现在i前面，但是`i`先于`j`定义，所以先初始化`i`，但`i`由`j`初始化，此时`j`尚未初始化，所以导致`i`的值未定义。所以，一个好的习惯是，按照成员定义的顺序进行初始化***

---
[部分文字抄录于这里](http://www.cnblogs.com/graphics/archive/2010/07/04/1770900.html)http://www.cnblogs.com/graphics/archive/2010/07/04/1770900.html

## 概念`显式构造`
***在C++中存在隐式构造，而显式构造就是为了避免程序自动的隐式构造带来的不必要的麻烦***
* ***具体可以看[这里](http://blog.csdn.net/starlee/article/details/1331268)http://blog.csdn.net/starlee/article/details/1331268***