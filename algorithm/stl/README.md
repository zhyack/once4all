## 定长数组
### c++
`int a[100]` 是c风格的数组，直接指定size，在堆中初始化为全0，栈中初始化随机
`array<int, 100> a` 是c++11之后的数组，具有stl数据类型的现代化特点，有`size()`, `begin()`, `end()` 等成员函数，可以使用`iterator` 遍历，初始化同c风格数组

## 动态数组
### c++
`vector<int> a (100,0)` 可以初始化一个长度为100，初始值为0的数组，除了array的特性，vector还可以`erase(iterator)`，`insert(iterator, ...)`，`push_back(x)`， `pop_back()`， `resize(n, val)`, `clear()` 等

### python
`a = [0]*100`，操作更加随意，甚至可以容纳不同的数据类型。常用操作 `a.append(x)`, `a.extend([x])`, `del(a[i])`, `a[i:j]` ... 但是慢

## 链表
### c++
`forward_list<int> a (100, 0)` c++11之后的单向链表， 通过`assign`（类似初始化）和`=`(从另一个list)赋值，`erase_after`做删除操作，其他如字面义函数 `push_front`,`insert_after`,`pop_front`,`merge`,`splice_after`,`sort`...
`list<int> a (100, 0)` 双向链表，不同的函数有`erase`,`insert`,`push_back`,`pop_back`
链表只能通过iterator来访问和操作

## 双端队列
### c++
几乎同vector，存取更快，但内存占用更多，多了`push_front`和`pop_front`

### python
`from collections import deque`， 跟list区别不大，可以`extendleft()`,`appendleft()`,`popleft()`...

## 栈

### c++
`stack<int> s`， 使用`pop()`, `push()`操作， `top()`调取栈顶，`size()`和`empty()`查看大小

## 队列

### c++
`queue<int> q`，使用`pop()`, `push()`操作， `front()`调取队首，`back()`调取队尾，`size()`和`empty()`查看大小

## 堆
### c++
`priority_queue<int, vector<int>, std::greater<int> > q` 这是一个大顶堆

### python
`import heapq` 总是一个小顶堆, 直接对list操作， `heappush(l, item)`, `heappop(l)`， `heapify(l)`, 排序的键值为item[0]，大顶堆的操作方式为把item[0]取反

## 集合 和词典
### c++
`set<int> s` 函数有`insert`, `erase`, `find`, `lower_bound`, `upper_bound`
`unordered_set<int> s` 不再有序，但更快
`map<int,int> m` 多了一个映射的值，访问时使用`it->first`, `it->second` 分别获得键和值
`unordered_map<int,int> m` 不再有序
### python
`set()` 甚至支持集合操作 `&`交集， `|`并集， `-`差集 ， `in`判断存在， `add`, `remove` ...
`dict()` 
`from collections import OrderedDict` 有序