#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <ctkPluginContext.h>

//发布者
class Publisher
{
public:
    Publisher(ctkPluginContext *context);
    //发布事件
    void Publish();
private:
    ctkPluginContext *pc;
};

#endif // PUBLISHER_H
