class Fraction{
    int numerator;
    int denominator;
    public:
    void simplify(){
        int gcd=1;
        int j=min(this->numerator,this->denominator);
        for(int i=1;i<=j;i++){
            if(numerator%i==0 && denominator%i==0){                
                gcd=i;
        }
        }
        this->numerator=this->numerator/gcd;
        this->denominator=this->denominator/gcd;    
    }
    Fraction(int num,int den){
        numerator=num;
        denominator=den;
    }
    Fraction operator+(Fraction const &f) const{
        int lcm=denominator*f.denominator;
        int p=lcm/f.denominator;
        int q=lcm/denominator;
        int num=p*f.numerator+q*numerator;
        Fraction newf(num,lcm);
        newf.simplify();
        return newf;
    }
    // We are using return type as reference 
    //so that the buffer memory that is created by the system points to the current object and does not create any copy.
    // Pre-Increment
    Fraction& operator++(){
        numerator=numerator+denominator;
        simplify();
        return *this;
    }
    void display() const{
        cout << numerator << "/" << denominator << endl;
    }
    // Post-Increment
    Fraction operator++(int){
        Fraction fnew(*this);
        numerator=numerator+denominator;
        simplify();
        return fnew;
    }
    Fraction& operator+=(Fraction const &f){
        int lcm=denominator*f.denominator;
        int p=lcm/f.denominator;
        int q=lcm/denominator;
        int num=p*f.numerator+q*numerator;
        numerator=num;
        denominator=lcm;
        simplify();
        return *this;
    }
};