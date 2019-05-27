#ifndef PRIME_SINGALTON_H
#define PRIME_SINGALTON_H



class prime_singalton
{

private:
    static prime_singalton *obj;

 private:
    prime_singalton() {}

        public:
        static prime_singalton *getInstance();

public:
 int prime;
 int result[5000];

};
#endif // PRIME_SINGALTON_H
