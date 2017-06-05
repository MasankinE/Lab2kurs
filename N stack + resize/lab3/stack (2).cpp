
#include <iostream>
 
class stack {
private:
    int size;
    int* data;
    size_t ptr;
public:
 
    stack(int stack_size) {
        this->size = stack_size;
        this->ptr = 0;
        this->data = new int[stack_size];
    }
 
    ~stack() {
        delete[] data;
    }
 
    void push(int value) {
        if (ptr >= (size_t)size)
            throw "stack is full\n";
        data[ptr++] = value;
 
    }
 
    int pop() {
        if (ptr == 0)
            throw "stack is empty";
 
        return data[--ptr];
 
    }
 
 
};
 ////

class queue {
private:
    int size;
    int* data;
    size_t ptr;
public:
 
    queue(int queue_size) {
        this->size = queue_size;
        this->ptr = 0;
        this->data = new int[queue_size];
    }
 
    ~queue() {
        delete[] data;
    }
 
    void push_queue(int value) {
        if (ptr >= (size_t)size)
            throw "stack is full\n";
        data[ptr++] = value;
 
    }
 
    int pop_queue() {
        if (ptr == 0)
            throw "stack is empty";
 
		int temp=data[0];
		for (int i=0; i<ptr ;i++)
		data[i]=data[i+1];
		ptr--;
		return temp;
    }
 
 
};

///
int main() {
	std::cout<<"stack\n";
    stack* f=new stack(10);
    f->push(1);
    f->push(2);
    f->push(3);
    std::cout<<f->pop()<<"\n";
    std::cout<<f->pop()<<"\n"; 
	//f->push(6);
    std::cout<<f->pop()<<"\n";

	std::cout<<"queue\n";
	queue* f2=new queue(10);
	f2->push_queue(1);
    f2->push_queue(2);
    f2->push_queue(3);
	std::cout<<f2->pop_queue()<<"\n";
	std::cout<<f2->pop_queue()<<"\n";
	std::cout<<f2->pop_queue()<<"\n";
	system("pause");
    return 0;
}