#include "publisher.h"
#include <service/event/ctkEventAdmin.h>

Publisher::Publisher(ctkPluginContext *context)
    : pc(context)
{

}

void Publisher::Publish()
{
    ctkServiceReference ref = pc->getServiceReference<ctkEventAdmin>();
    if (ref) {
        //�����¼��������
        ctkEventAdmin *eventAdmin = pc->getService<ctkEventAdmin>(ref);

        ctkDictionary props;
        props.insert("name", "zjh");
        props.insert("age", 18);

        //�¼�
        ctkEvent event("org/commontk/login", props);
        //�¼�����������¼�
        eventAdmin->sendEvent(event);
    }
}
