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

## 概念`左值、右值和引用`
* 除了指针类型外，C++ 还定义了 ***引用类型***。C++11的主要变化之一是新的引用类型的创建，叫做***右值引用***。
* 一个***左值*** 是一个标识为临时性对象的表达式。一个***右值***是一个标识临时性对象的表达式，或者是一个不与任何对象相练习的值（如字面值常熟）
```
vector<string> arr( 3 );
const int x = 2;
int y;
...
int z = x + y;
string str = "foo";
vector<string> *ptr = &arr;
```
* 左值：`arr` `str` `arr[x]` `&x` `y` `z` `*ptr` `(*ptr)[x]`都是左值。`x`也是左值，不过他不是一个课修改的左值。
* 右值：`2` `"foo"` `x+y` `str.substr(0,1)`。`x+y`是右值，因为它的值是临时的。
### 左值引用


```
string str = "hell";
string $ rstr = str ;              // rstr是str的另一个名字 
rstr += 'o';                       // 把str改成"hello"
bool cond = (&str == &rstr);       // true; str 和 rstr是同一个对象
string & bad1 = "hello";           // 非法 "hello"不是可修改的左值
string & bad2 = str + "";          // 非法 str+""不是左值
string & sub = str.substr( 0, 4 ); // 非法 str.substr( 0, 4 )不是左值
```

### 右值引用
```
string str = "hell";                  
string && bad1 = "hello";            // 合法
string && bad2 = str + "";           // 合法
string && bad3 = str.substr( 0, 4 ); // 合法
```

* 左值引用的用途
1. 给结构复杂的名称起别名
```
auto & whichList = theLists[ myhash( x, theLists.size() ) ];
```
2. 范围for循环
```
for ( auto x : arr )
    ++x; // 行不通
    
for ( auto & x : arr )
    ++x; // 行得通
```
3. 避免复制