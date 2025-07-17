class FooBar {
private:
    int n;
    mutex m;// ensure shared data ko ek tym pr sirf ek thread access kre
    condition_variable cv;// ek sycn tool jo allow krta hai threads ko w8 krne ke liye jab tak koi condition satisfy na ho jaye
    // analogy
    // mutex tala
    //cv ki condition hum while loop ke andr likhte hai
    bool turn;

public:
    FooBar(int n) {
        this->n = n;
         turn =0; //0->foo,1->bar
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(m);// unique->ek hi banda kisi taale ki chaabi le skta hau ..u can lock/unlock manually
            while(turn==1){
                cv.wait(lock);// unlock m,sleep,relock  m when notified
// //              \U0001f9e0 Now Understand cv.wait(lock) Again:
// \U0001f504 It means:
// Thread bolta hai:

// “Mujhe andar jaana hai — but abhi koi aur hai — to main ruk jaata hoon”

// mutex unlock hota hai so doosra thread andar ja sake

// Jab koi notify() karta hai, ye thread dubara lock karega, fir while() condition check karega

// Agar condition ab sahi hai → ye thread andar chala jaayega (CS)
            }
        	printFoo();
            turn =1;
            cv.notify_all();// wake up other thread
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock<mutex>lock(m);
            while(turn ==0){
                cv.wait(lock);
            }

        	printBar();
            turn =0;
            cv.notify_all();
        }
    }
};
// kuki 2 threads hai toh we want t1->    t1->
                             //   t2->     t2->