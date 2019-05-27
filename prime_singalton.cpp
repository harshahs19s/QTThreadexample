#include "prime_singalton.h"

prime_singalton *prime_singalton::obj = nullptr;

prime_singalton *prime_singalton::getInstance()
{
        if (obj == nullptr)
            obj = new prime_singalton();
        return obj;
}
