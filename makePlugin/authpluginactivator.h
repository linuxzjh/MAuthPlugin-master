#ifndef AUTH_PLUGIN_ACTIVATOR_H
#define AUTH_PLUGIN_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include "authpluginservice.h"

class AuthPluginActivator : public QObject,
        public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "auth_plugin")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    QScopedPointer<AuthPluginService> s;
};

#endif // AUTH_PLUGIN_ACTIVATOR_H
