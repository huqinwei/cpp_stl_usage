#include <vector>
#include <iostream>
using namespace std;
int main(int argc,char * argv[])
{
        vector<int> myVec;
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        myVec.push_back(1);
        myVec.push_back(2);
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        myVec.push_back(3);
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        myVec.push_back(4);
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        myVec.push_back(5);
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        myVec.push_back(6);
        cout << "size:" << myVec.size() << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        myVec.reserve(100);
        cout << "after reserve(100)" << endl;
        cout << "size:" << myVec.size() << endl;
        cout << "address of myVec[2] is :" << &myVec[2] << endl;
        cout << "capacity:" << myVec.capacity() << endl;
        return 0;

}
/*
每次capacity扩充都意味着重新申请了一块空间，声明了一个更大的数组，所以固定元素myVec[2]的位置会随着capacity改变。
触发空间重分配有两种途径，一种是通过push_back()自动触发，一种是reserve()主动触发。如果频繁增删元素，自动触发看起来会是个很蠢的方法，会很慢（C++什么都慢，编译慢、运行慢）。所以应该用一定的手动算法来减少vector自动申请空间的开销，使之介于纯手动申请数组和全自动的vector之间。
插入元素时，capacity会自适应的从2变4变8。额外的，做一个erase操作，size()可以清零，capacity不会再缩回4和2。相应的，其实那些元素也没被真正删除，可以访问到。
PS：已有四个元素，resize(100)后，不是104，是100，见过一些错误例子的for循环还在当104去遍历，别手动操作了，用个capacity()获取吧。

reserve()和resize()的区别。前者只预留空间，后者等于分配了“0”元素（默认构造吧），区别就是用for()循环的话，按capacity()，会打印到不该打印到的数据（因为封装的自动初始化的原因，比如整型，可能0）。


*/
