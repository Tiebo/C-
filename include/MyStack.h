
#define INIT_SIZE 10

template<typename T>
class stack{
    private:
        T* base;
        int tt;
        int size;
    protected:
        void init(){base=new T[INIT_SIZE],tt=-1,size = INIT_SIZE;}
        void expand()
        {
            T* old=base;
            base=new T[size<<1];//容量倍增
            for(int i=0;i<size;i++){base[i]=old[i];}
            delete[] old;
        }
    public:
        //构造函数并初始化
        stack(){init();}
        //判断是否空
        bool empty()
        {
            if(tt==-1)return true;
            return false;
        }
        //入栈
        void push(T e)
        {
            if(tt+1>size)  expand();
            base[++tt]=e;
        }
        //出栈
        bool pop()
        {
            if(empty()) return false;
            tt--;
            return true;
        }
        //返回端顶元素
        T top()
        {
            return base[tt];
        }
        int Getsize(){return tt;}
};
