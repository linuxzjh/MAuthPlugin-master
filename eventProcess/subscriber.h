#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>
#include <ctkPluginContext.h>

class Subscriber : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)
public:
    explicit Subscriber(ctkPluginContext *context);
    //为事件注册服务
    void registerService();
    //处理事件
    void handleEvent(const ctkEvent &event) Q_DECL_OVERRIDE;
private:
    ctkPluginContext *pc;
};

#endif // SUBSCRIBER_H
