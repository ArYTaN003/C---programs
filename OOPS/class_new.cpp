
class Student{
    public:
    char name[100];
    int rollno;
    Student(int rollno){
        this->rollno=rollno;
    }
    //desturctor
    // NO input Arguments
    // It takes palce when the function is about to end
    // If a memory is allocated dynamically , the desturctor is not called for that memory as it is created in heap memory
    ~Student(){
        cout << "Destructor called!" << endl;
    }
    //to create a only read reference
    // int const &k;
};