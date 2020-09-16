/*  Exercise 4-14. 
    Define a macro swap(t,x,y) that interchanges two arguments of type t. 
    (Block structure will help.)

    定义宏 swap(t, x, y)以交换 t 类型的两个参数
    (使用程序块结构会对你有所帮助)
*/

#define swap(t, x, y) { t _z; \
                        _z = y; \
                        y = x; \
                        x = _z;}