using namespace std;
 mutex m;// to protect  shared data
  condition_variable cv; // thread ko wait /notify krne ke liye
  int turn ;// yeh deciide krega ki kis thread ki turn hai
class Foo {
public:
    Foo() {
       turn =0; 
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        // assume t1 thread aayi
        printFirst();
        turn =1;
        cv.notify_all(); // waitinh threads hai usko jagao
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex>lock(m);// utex ka lock lia to protect turn
        while(turn!=1){
            cv.wait(lock);
        }// jab tak turn 1 ke barabr nhi hai thread w8 krta rhega
        printSecond();
        turn =2;
        cv.notify_all();
       
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex>lock(m);// jb toh lock obj jinda hai kisis aur thread ko acces nhi milega, kisis ne tala lga diya hai jab vo and gya, jb kaam ho jauyeha automatically tala khul jayega
        while(turn!=2){
            cv.wait(lock);
        }
        printThird();
    }
};