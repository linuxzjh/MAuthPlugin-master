#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <ctkPluginContext.h>

//������
class Publisher
{
public:
    Publisher(ctkPluginContext *context);
    //�����¼�
    void Publish();
private:
    ctkPluginContext *pc;
};

#endif // PUBLISHER_H
