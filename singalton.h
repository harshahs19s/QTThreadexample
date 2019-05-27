#ifndef SINGALTON_H
#define SINGALTON_H


class singalton
{

private:
    static singalton *obj;

 private:
    singalton() {}

        public:
        static singalton *getInstance();

public:
 int factn;
 long int result;
 int flag;

};

#endif // SINGALTON_H
