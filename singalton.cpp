#include "singalton.h"

singalton *singalton::obj = nullptr;


singalton *singalton::getInstance()
{
        if (obj == nullptr)
            obj = new singalton();
        return obj;
}
